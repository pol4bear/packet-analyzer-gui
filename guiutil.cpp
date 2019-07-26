#include "guiutil.h"

GUIUtil::GUIUtil()
{

}

void GUIUtil::changeLocationToCenter(QWidget *widget)
{
    QSize size = widget->geometry().size();
    QDesktopWidget* desktop = QApplication::desktop();
    int dWidth = desktop->width();
    int dHeight = desktop->height();
    int width = size.width();
    int height = size.height();
    int centerW = (dWidth/2) - (width/2);
    int centerH = (dHeight/2) - (height/2);
    widget->move(centerW, centerH);
}
