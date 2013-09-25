#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMdiArea>
#include <QMdiSubWindow>
#include "imagewindow.h"
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow){

    ui->setupUi(this);
    MdiArea = new QMdiArea();
    setCentralWidget(MdiArea);

    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(open()));
    connect(ui->actionSAve_as,SIGNAL(triggered()),this,SLOT(save_as()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(save()));
    connect(ui->actionClose,SIGNAL(triggered()),this,SLOT(close()));

}

MainWindow::~MainWindow(){

    delete MdiArea;
    delete ui;
}

void MainWindow::open() {

    QFileDialog selectFiles(this);
    QStringList files;
    QString file;


    selectFiles.setFileMode(QFileDialog::ExistingFile);
    selectFiles.setNameFilter(tr("Image (* jpeg *.jpg *.png *.bmp)"));
    selectFiles.setAcceptMode(QFileDialog::AcceptOpen);

    if (selectFiles.exec()) {
        files = selectFiles.selectedFiles();
        file = files.at(0);
        //setStatus("Loading "+file+"...");
        ui->statusBar->showMessage(file,20000);

        imageWindow *newImg;
        newImg = new imageWindow(MdiArea);

        newImg->setStatusBar(ui->statusBar);

        MdiArea->addSubWindow(newImg);

        newImg->show();
        newImg->setFileName(file);

    }
}

void MainWindow::save_as() {

    QFileDialog selectFiles(this);
    QStringList files;
    QString filePath;
    QMdiSubWindow *qs= MdiArea->activeSubWindow();
    QList<QWidget*>lista= qs->findChildren<QWidget*>("label");
    selectFiles.setFileMode(QFileDialog::AnyFile);
    selectFiles.setNameFilter(tr("Imagen (* jpeg *.jpg *.png *.bmp)"));
    selectFiles.setAcceptMode(QFileDialog::AcceptSave);

    if (selectFiles.exec()) {
        files = selectFiles.selectedFiles();
        filePath = files.at(0);
        ui->statusBar->showMessage(filePath,20000);

        QFile  file(filePath);
        MyLabel *etiq = (MyLabel*) lista.at(0);
        file.open(QIODevice::WriteOnly);
        etiq->pixmap()->save(&file);
        ui->statusBar->showMessage("Guardada en " + etiq->getFileName() + "." );

    }
}
void MainWindow::save(){

   QMdiSubWindow *qs = MdiArea->activeSubWindow();
   QList<QWidget*>lista = qs->findChildren<QWidget*>("label");
   MyLabel *etiq = (MyLabel*)lista.at(0);
   QFile file(etiq->getFileName());
   file.open(QIODevice::WriteOnly);
   etiq->pixmap()->save(&file);
   ui->statusBar->showMessage("Guardada en " + etiq->getFileName() + "." );
}
void MainWindow::close(){
    exit(0);
}

