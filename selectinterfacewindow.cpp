#include "selectinterfacewindow.h"
#include "ui_selectinterfacewindow.h"

// GUI START
SelectInterfaceWindow::SelectInterfaceWindow(vector<string> *interfaces, int *index, function<void()> onSelect) :
    QDialog(nullptr),
    ui(new Ui::SelectInterfaceWindow)
{
    ui->setupUi(this);
    this->interfaces = interfaces;
    this->index = index;
    this->onSelect = onSelect;
    initialize();
}

SelectInterfaceWindow::~SelectInterfaceWindow()
{
    delete ui;
}

void SelectInterfaceWindow::initialize()
{
    listInterfaces();
}

void SelectInterfaceWindow::listInterfaces()
{
    if(interfaces == nullptr) return;

    for(int ifIndex = 0; ifIndex < interfaces->size(); ifIndex++)
    {
        ui->lstInterface->addItem(
                    QString::fromStdString(
                            interfaces->at(ifIndex)
                        )
                    );
    }
}
// GUI END


// EVENT START
void SelectInterfaceWindow::on_btnStart_clicked()
{
    onSelect();
}

void SelectInterfaceWindow::keyPressEvent(QKeyEvent *pressed)
{
    if(pressed->key() == Qt::Key_Escape)
        pressed->ignore();
}
// EVENT END
