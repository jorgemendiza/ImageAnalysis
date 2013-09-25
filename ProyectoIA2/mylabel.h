#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QStatusBar>

class MyLabel : public QLabel{

    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
    void setStatusBar(QStatusBar *sb);
    QString getFileName();
    void setFileName(QString a);
signals:
    
public slots:

protected:
    void mouseMoveEvent(QMouseEvent *ev);

private:
    QStatusBar *status;
    QString filename;

};

#endif // MYLABEL_H
