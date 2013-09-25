#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>


namespace Ui {
   class MainWindow;
}

class MainWindow : public QMainWindow{

    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void open();
    void save_as();
    void save();
    void close();
    
private:
    Ui::MainWindow *ui;
    QMdiArea *MdiArea;
};

#endif // MAINWINDOW_H
