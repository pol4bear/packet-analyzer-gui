#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <string>
#include <QMessageBox>

using namespace std;

class MessageBox
{
public:
    MessageBox();
    void Error(string *message);
    void Info(string *message);
    bool Ask(string *message);
private:
    QMessageBox* getMeessageBox(QMessageBox::Icon icon, QMessageBox::StandardButtons buttons, string *message);
};

#endif // MESSAGEBOX_H
