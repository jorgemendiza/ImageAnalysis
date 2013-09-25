#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include <QDialog>
#include <mylabel.h>
#include <QStatusBar>
#include <QScrollArea>

namespace Ui {
class imageWindow;
}

class imageWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit imageWindow(QWidget *parent = 0);
    ~imageWindow();

    void setFileName(QString f);
    void setStatusBar(QStatusBar *sb);
    
private:
    Ui::imageWindow *ui;
    QString FileName;
    QScrollArea *scrollArea;
};

#endif // IMAGEWINDOW_H
