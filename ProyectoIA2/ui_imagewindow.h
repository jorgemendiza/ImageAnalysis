/********************************************************************************
** Form generated from reading UI file 'imagewindow.ui'
**
** Created: Wed Aug 28 09:35:15 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEWINDOW_H
#define UI_IMAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <mylabel.h>

QT_BEGIN_NAMESPACE

class Ui_imageWindow
{
public:
    QGridLayout *gridLayout;
    MyLabel *label;

    void setupUi(QDialog *imageWindow)
    {
        if (imageWindow->objectName().isEmpty())
            imageWindow->setObjectName(QString::fromUtf8("imageWindow"));
        imageWindow->resize(1000, 1000);
        gridLayout = new QGridLayout(imageWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new MyLabel(imageWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setCursor(QCursor(Qt::CrossCursor));
        label->setMouseTracking(true);

        gridLayout->addWidget(label, 0, 0, 100, 100);


        retranslateUi(imageWindow);

        QMetaObject::connectSlotsByName(imageWindow);
    } // setupUi

    void retranslateUi(QDialog *imageWindow)
    {
        imageWindow->setWindowTitle(QApplication::translate("imageWindow", "Dialog", 0));
        label->setText(QApplication::translate("imageWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class imageWindow: public Ui_imageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEWINDOW_H
