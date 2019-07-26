#ifndef SELECTINTERFACEWINDOW_H
#define SELECTINTERFACEWINDOW_H

#include <QDialog>
#include <QCloseEvent>
#include <string>
#include <vector>
#include <functional>

using namespace std;

namespace Ui {
class SelectInterfaceWindow;
}

class SelectInterfaceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SelectInterfaceWindow(vector<string> *interfaces, int *index, function<void()> onSelect);
    ~SelectInterfaceWindow();

private slots:
    void on_btnStart_clicked();

private:
    Ui::SelectInterfaceWindow *ui;
    vector<string> *interfaces = nullptr;
    int *index = nullptr;
    function<void()> onSelect = nullptr;

    void initialize();
    void listInterfaces();

    void keyPressEvent(QKeyEvent *pressed);
};

#endif // SELECTINTERFACEWINDOW_H
