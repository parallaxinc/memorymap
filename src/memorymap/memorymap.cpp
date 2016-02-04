#include "memorymap.h"

#include <QDataStream>
#include <QFileDialog>
#include <QIntValidator>

#include <PropellerLoader>

Q_LOGGING_CATEGORY(memorymap, "memorymap")

MemoryMap::MemoryMap(PropellerManager * manager, QWidget *parent) : QWidget(parent)
{
    this->manager = manager;
    ui.setupUi(this);
    ui.memorybar->configure(0, image.eepromSize()/4, 0, 0, 0); 
    ui.clockFrequency->setValidator(new QIntValidator(0, 150000000, this));

    foreach (QString m, image.listClockModes())
    {
        ui.clockMode->addItem(m, image.clockModeValue(m));
    }

//    connect(ui.memorymap, SIGNAL(widthChanged(int)), this, SLOT(fixWidth(int)));
    connect(ui.buttonOpen, SIGNAL(clicked()), this, SLOT(open()));
    connect(ui.buttonSave, SIGNAL(clicked()), this, SLOT(save()));
    connect(ui.buttonRun, SIGNAL(clicked()), this, SLOT(sendRun()));
    connect(ui.buttonWrite, SIGNAL(clicked()), this, SLOT(sendWrite()));

    connect(ui.clockMode,       SIGNAL(currentIndexChanged(const QString &)),
            this,               SLOT(updateClockMode(const QString &)));
    connect(ui.clockFrequency,  SIGNAL(editingFinished()),
            this,               SLOT(updateClockFrequency()));
}

void MemoryMap::openFile(QString binaryfile)
{
    QFile file(binaryfile);
    if (!file.open(QIODevice::ReadOnly)) return;
    openData(file.readAll());
}

void MemoryMap::setModel(QStandardItemModel * model)
{
    ui.projectview->setModel(model);
}

void MemoryMap::openData(QByteArray binarydata)
{
    image.setData(binarydata);
    refreshView();
}

void MemoryMap::refreshView()
{
    ui.memorymap->loadData(image.data());

    ui.memorybar->configure(
            0,
            image.eepromSize()/4,
            image.codeSize()/4,
            image.variableSize()/4, 
            image.stackSize()/4
            ); 

    ui.longsProgram->setText(QString::number(image.codeSize()/4));
    ui.longsVariable->setText(QString::number(image.variableSize()/4));
    ui.longsStack->setText(QString::number(image.stackSize()/4));

    ui.clockMode->setCurrentIndex(ui.clockMode->findText(image.clockModeText()));
    ui.clockFrequency->setText(QString::number(image.clockFrequency()));
}

void MemoryMap::open()
{
    QString fn = QFileDialog::getOpenFileName(this, tr("Open binary..."),
            QString(), tr("Binary images (*.binary);;EEPROM images (*.eeprom);;All files (*)"));
        if (!fn.isEmpty())
            openFile(fn);
}

void MemoryMap::save()
{
    QString fn = QFileDialog::getSaveFileName(this, tr("Save as..."),
            QString(), tr("Binary images (*.binary);;EEPROM images (*.eeprom);;All files (*)"));

    if (fn.isEmpty())
        return;

    QFile file(fn);
    if (file.open(QIODevice::WriteOnly))
    {
        QDataStream stream(&file);
        stream << image.data();
    }
}

void MemoryMap::setFont(QFont font)
{
    ui.memorymap->setFont(font);
}

void MemoryMap::recolor(
            QColor hex_background,
            QColor hex_line,
            QColor hex_text,
            QColor hex_text_alt,
            QColor addr_background,
            QColor addr_text,
            QColor addr_highlight)
{
    ui.memorymap->recolor(
            hex_background,
            hex_line,
            hex_text,
            hex_text_alt,
            addr_background,
            addr_text,
            addr_highlight);

    // QHexEdit would require non-trivial refactoring to 
    // allow updating hex_text color without reloading data
    ui.memorymap->loadData(image.data()); 
}

void MemoryMap::fixWidth(int width)
{
    Q_UNUSED(width);
//    int w = width + qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent);
//    setFixedWidth(w);
}

void MemoryMap::updateColors()
{
    emit getRecolor(this);
}

void MemoryMap::sendRun()
{
    emit run(image.data());
}

void MemoryMap::sendWrite()
{
    emit write(image.data());
}

void MemoryMap::keyPressEvent(QKeyEvent* event)
{
    switch (event->key())
    {
        case Qt::Key_W:
        case Qt::Key_Escape:
            close();
            break;
        default:
            event->ignore();
            break;
    }
}

void MemoryMap::updateClockMode(const QString & name)
{
    qCDebug(memorymap) << "new clock mode:" << name;

    image.setClockMode(image.clockModeValue(name));
    ui.memorymap->loadData(image.data());
}

void MemoryMap::updateClockFrequency()
{
    QString name = ui.clockFrequency->text();
    bool ok;
    int n = name.toInt(&ok);
    if (!ok)
    {
        qCDebug(memorymap) << "invalid clock frequency:" << name;
        return;
    }

    qCDebug(memorymap) << "new clock frequency:" << n;
    image.setClockFrequency(n);
    refreshView();
}

