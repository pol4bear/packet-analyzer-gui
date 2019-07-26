#include "mainwindow.h"
#include "ui_mainwindow.h"

// GUI START
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize()
{
    try{
        util.changeLocationToCenter(this);
        capture.getInterfaces(&interfaces);
        showInterfaceSelection();
    }
    catch(runtime_error e){
        string message = e.what();
        messageBox.Error(&message);
    }
}

void MainWindow::showInterfaceSelection()
{
    if(selectInterfaceWindow == nullptr)
        selectInterfaceWindow = new SelectInterfaceWindow(&interfaces, &selectedInterface, std::bind(&MainWindow::onInterfaceSelected,this));

    this->setEnabled(false);
    selectInterfaceWindow->show();
}

void MainWindow::hideInterfaceSelection()
{
    this->setEnabled(true);
    selectInterfaceWindow->hide();
}

void MainWindow::changeStateToStart()
{
    ui->btnStart->setEnabled(false);
    ui->btnPause->setEnabled(true);
    ui->btnStop->setEnabled(true);
    ui->btnSelectInterface->setEnabled(false);
}

void MainWindow::changeStateToPause()
{
    ui->btnStart->setEnabled(true);
    ui->btnPause->setEnabled(false);
    ui->btnStop->setEnabled(true);
    ui->btnSelectInterface->setEnabled(false);
}

void MainWindow::changeStateToStop()
{
    ui->btnStart->setEnabled(true);
    ui->btnPause->setEnabled(false);
    ui->btnStop->setEnabled(false);
    ui->btnSelectInterface->setEnabled(true);

    //reset listview
}
// GUI END

// CALLBACKS START
void MainWindow::onInterfaceSelected()
{
    hideInterfaceSelection();
}
// CALLBACKS END

// EVENT START
void MainWindow::on_btnStart_clicked()
{
    changeStateToStart();
}

void MainWindow::on_btnPause_clicked()
{
    changeStateToPause();
}
void MainWindow::on_btnStop_clicked()
{
    changeStateToStop();
}

void MainWindow::on_btnSelectInterface_clicked()
{
    showInterfaceSelection();
}
// EVENT END


