#include "messagebox.h"

MessageBox::MessageBox()
{

}

QMessageBox* MessageBox::getMeessageBox(QMessageBox::Icon icon, QMessageBox::StandardButtons buttons, string *message)
{
    QMessageBox *msgBox = new QMessageBox();
    msgBox->setIcon(icon);
    msgBox->setText(QString::fromStdString(*message));
    msgBox->setStandardButtons(buttons);

    return msgBox;
}

void MessageBox::Error(string *message)
{
    QMessageBox *msgBox = getMeessageBox(QMessageBox::Critical, QMessageBox::Ok, message);

    msgBox->exec();
}

bool MessageBox::Ask(string *message)
{
    QMessageBox *msgBox = getMeessageBox(QMessageBox::Question, QMessageBox::Ok|QMessageBox::No, message);

    return msgBox->exec();
}
