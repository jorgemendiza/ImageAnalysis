#include "imagewindow.h"
#include "ui_imagewindow.h"
#include <QScrollarea.h>
#include <QPixmap>
#include <QImage>
#include <QPalette.h>


imageWindow::imageWindow(QWidget *parent) : QDialog(parent), ui(new Ui::imageWindow){
    ui->setupUi(this);
}

imageWindow::~imageWindow(){
    delete ui;
}

void imageWindow::setFileName(QString f) {

    FileName = f;

    QImage *img = new QImage(FileName);

    ui->label->setPixmap(QPixmap::fromImage(*img));
    ui->label->setFileName(f);
    ui->label->setBackgroundRole(QPalette::Dark);ui->label->scroll(9,9);
    delete img;
}

void imageWindow::setStatusBar(QStatusBar *sb) {
    ui->label->setStatusBar(sb);
}
