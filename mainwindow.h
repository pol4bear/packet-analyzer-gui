#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <ifaddrs.h>
#include <stdexcept>
#include "packetmanager.h"
#include "guiutil.h"
#include "messagebox.h"
#include "selectinterfacewindow.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnStart_clicked();
    void on_btnStop_clicked();

    void on_btnSelectInterface_clicked();

    void on_btnPause_clicked();

private:
    class ErrorMessages
    {
    public:
        string setLstInterface = "Failed to load network interfaces";
    };

    Ui::MainWindow *ui;
    GUIUtil util;
    MessageBox messageBox;
    ErrorMessages errorMessages;
    SelectInterfaceWindow *selectInterfaceWindow = nullptr;
    int selectedInterface;
    vector<string> interfaces;
    PacketManager capture;
    u_char *packet;
    uint size;

    void initialize();
    void showInterfaceSelection();
    void hideInterfaceSelection();
    void changeStateToStart();
    void changeStateToPause();
    void changeStateToStop();
    void showMessage();
    void onInterfaceSelected();
};

#endif // MAINWINDOW_H
