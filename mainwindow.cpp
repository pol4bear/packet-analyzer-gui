#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <pcap/pcap.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::initialize()
{
    setLstInterface();
}

void MainWindow::setLstInterface()
{
    ifaddrs *addrs;
    int res = getifaddrs(&addrs);

    if(res == -1) return;// trhow exception

    string startAddr = addrs->ifa_name;
    do
    {
        ui->lstInterface->addItem(QString(addrs->ifa_name));
        addrs = addrs->ifa_next;
    } while(addrs->ifa_name != startAddr);
}

string MainWindow::getInterface()
{
    if(ui->lstInterface->selectedItems().length() < 1) return "";

    return ui->lstInterface->selectedItems()[0]->text().toUtf8().constData();
}
