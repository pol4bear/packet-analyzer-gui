#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <ifaddrs.h>
#include <stdexcept>

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
    string getInterface();

private:
    Ui::MainWindow *ui;
    bool initialize();
    void setLstInterface();
};

#endif // MAINWINDOW_H
