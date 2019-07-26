#ifndef STATUSWINDOW_H
#define STATUSWINDOW_H

#include <QDialog>

namespace Ui {
class StatusWindow;
}

class StatusWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StatusWindow(QWidget *parent = nullptr);
    ~StatusWindow();

private:
    Ui::StatusWindow *ui;
};

#endif // STATUSWINDOW_H
