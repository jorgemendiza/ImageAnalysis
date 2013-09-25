#include "mylabel.h"
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent){
    status=NULL;
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev) {

    unsigned int x=0,y=0, r=0, g= 0, b=0;

    x = ev->x();
    y = ev->y();

    if (status) {
        status->showMessage("listos!",1000);
    }

    if (this->pixmap()) {

       QString texto;

       const QRgb p=this->pixmap()->toImage().pixel(x,y);

       r = (p >> 16) &0x000000ff;
       g = (p >> 8)  &0x000000ff;
       b = (p >> 0)  &0x000000ff;

       texto.sprintf("[%dx%d] X=%d, Y=%d, R=%d, G=%d, B=%d",this->pixmap()->toImage().height(),this->pixmap()->toImage().width(),x,y,r,g,b);
       status->showMessage(texto,-1);

    }
}

void MyLabel::setStatusBar(QStatusBar *sb) {
    status = sb;
}

QString MyLabel::getFileName(){

    return filename;
}

void MyLabel::setFileName(QString a){

    filename = a;
}
