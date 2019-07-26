#ifndef GUIUTIL_H
#define GUIUTIL_H

#include <QWidget>
#include <QDesktopWidget>
#include <QApplication>


class GUIUtil
{
public:
    GUIUtil();
    void changeLocationToCenter(QWidget* widget);
};

#endif // GUIUTIL_H
