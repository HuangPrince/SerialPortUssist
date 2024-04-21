/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *cmb_SerailPort;
    QComboBox *cmb_BaundRate;
    QComboBox *cmb_DataBit;
    QComboBox *cmb_StopBit;
    QComboBox *cmb_CheckBit;
    QPushButton *btn_CheckSerail;
    QPushButton *btn_OpenSerail;
    QGroupBox *groupBox_2;
    QPushButton *btn_ClearRecive;
    QCheckBox *chk_HexRecive;
    QCheckBox *chk_TimeRecive;
    QCheckBox *chk_ChangeLine;
    QGroupBox *groupBox_3;
    QCheckBox *chk_HexSend;
    QCheckBox *chk_SendNewLine;
    QCheckBox *chk_AutoSend;
    QSpinBox *spb_Time;
    QLabel *label_6;
    QPlainTextEdit *edit_ReciveMsg;
    QTextEdit *edit_SendMsg;
    QPushButton *btn_SendMsg;
    QPushButton *btn_ClearSendMsg;
    QPushButton *btn_LockEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(487, 408);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 151, 228));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 40, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 50, 40, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 80, 40, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 110, 40, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 140, 40, 16));
        cmb_SerailPort = new QComboBox(groupBox);
        cmb_SerailPort->setObjectName("cmb_SerailPort");
        cmb_SerailPort->setGeometry(QRect(60, 20, 71, 16));
        cmb_BaundRate = new QComboBox(groupBox);
        cmb_BaundRate->addItem(QString());
        cmb_BaundRate->addItem(QString());
        cmb_BaundRate->addItem(QString());
        cmb_BaundRate->addItem(QString());
        cmb_BaundRate->addItem(QString());
        cmb_BaundRate->addItem(QString());
        cmb_BaundRate->addItem(QString());
        cmb_BaundRate->addItem(QString());
        cmb_BaundRate->setObjectName("cmb_BaundRate");
        cmb_BaundRate->setGeometry(QRect(60, 50, 71, 16));
        cmb_DataBit = new QComboBox(groupBox);
        cmb_DataBit->addItem(QString());
        cmb_DataBit->addItem(QString());
        cmb_DataBit->addItem(QString());
        cmb_DataBit->addItem(QString());
        cmb_DataBit->setObjectName("cmb_DataBit");
        cmb_DataBit->setGeometry(QRect(60, 80, 71, 16));
        cmb_StopBit = new QComboBox(groupBox);
        cmb_StopBit->addItem(QString());
        cmb_StopBit->addItem(QString());
        cmb_StopBit->addItem(QString());
        cmb_StopBit->setObjectName("cmb_StopBit");
        cmb_StopBit->setGeometry(QRect(60, 110, 71, 16));
        cmb_CheckBit = new QComboBox(groupBox);
        cmb_CheckBit->addItem(QString());
        cmb_CheckBit->addItem(QString());
        cmb_CheckBit->addItem(QString());
        cmb_CheckBit->setObjectName("cmb_CheckBit");
        cmb_CheckBit->setGeometry(QRect(60, 140, 71, 16));
        btn_CheckSerail = new QPushButton(groupBox);
        btn_CheckSerail->setObjectName("btn_CheckSerail");
        btn_CheckSerail->setGeometry(QRect(30, 170, 80, 21));
        btn_OpenSerail = new QPushButton(groupBox);
        btn_OpenSerail->setObjectName("btn_OpenSerail");
        btn_OpenSerail->setGeometry(QRect(30, 200, 80, 21));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 230, 151, 71));
        btn_ClearRecive = new QPushButton(groupBox_2);
        btn_ClearRecive->setObjectName("btn_ClearRecive");
        btn_ClearRecive->setGeometry(QRect(10, 20, 61, 21));
        chk_HexRecive = new QCheckBox(groupBox_2);
        chk_HexRecive->setObjectName("chk_HexRecive");
        chk_HexRecive->setGeometry(QRect(80, 20, 71, 18));
        chk_TimeRecive = new QCheckBox(groupBox_2);
        chk_TimeRecive->setObjectName("chk_TimeRecive");
        chk_TimeRecive->setGeometry(QRect(10, 50, 61, 18));
        chk_ChangeLine = new QCheckBox(groupBox_2);
        chk_ChangeLine->setObjectName("chk_ChangeLine");
        chk_ChangeLine->setGeometry(QRect(80, 50, 71, 18));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 300, 161, 71));
        chk_HexSend = new QCheckBox(groupBox_3);
        chk_HexSend->setObjectName("chk_HexSend");
        chk_HexSend->setGeometry(QRect(10, 20, 71, 18));
        chk_SendNewLine = new QCheckBox(groupBox_3);
        chk_SendNewLine->setObjectName("chk_SendNewLine");
        chk_SendNewLine->setGeometry(QRect(80, 20, 71, 18));
        chk_AutoSend = new QCheckBox(groupBox_3);
        chk_AutoSend->setObjectName("chk_AutoSend");
        chk_AutoSend->setGeometry(QRect(10, 50, 71, 18));
        spb_Time = new QSpinBox(groupBox_3);
        spb_Time->setObjectName("spb_Time");
        spb_Time->setGeometry(QRect(80, 50, 51, 21));
        spb_Time->setMaximum(2000);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(140, 50, 40, 20));
        edit_ReciveMsg = new QPlainTextEdit(centralwidget);
        edit_ReciveMsg->setObjectName("edit_ReciveMsg");
        edit_ReciveMsg->setGeometry(QRect(180, 10, 301, 251));
        edit_ReciveMsg->setReadOnly(true);
        edit_SendMsg = new QTextEdit(centralwidget);
        edit_SendMsg->setObjectName("edit_SendMsg");
        edit_SendMsg->setGeometry(QRect(180, 271, 211, 101));
        btn_SendMsg = new QPushButton(centralwidget);
        btn_SendMsg->setObjectName("btn_SendMsg");
        btn_SendMsg->setGeometry(QRect(410, 270, 71, 41));
        btn_ClearSendMsg = new QPushButton(centralwidget);
        btn_ClearSendMsg->setObjectName("btn_ClearSendMsg");
        btn_ClearSendMsg->setGeometry(QRect(410, 320, 71, 21));
        btn_LockEdit = new QPushButton(centralwidget);
        btn_LockEdit->setObjectName("btn_LockEdit");
        btn_LockEdit->setGeometry(QRect(410, 350, 71, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 487, 17));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        cmb_BaundRate->setCurrentIndex(3);
        cmb_DataBit->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\263\242\347\211\271\347\216\207</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\225\260\346\215\256\344\275\215</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\201\234\346\255\242\344\275\215</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\240\241\351\252\214\344\275\215</p></body></html>", nullptr));
        cmb_BaundRate->setItemText(0, QCoreApplication::translate("MainWindow", "1200", nullptr));
        cmb_BaundRate->setItemText(1, QCoreApplication::translate("MainWindow", "2400", nullptr));
        cmb_BaundRate->setItemText(2, QCoreApplication::translate("MainWindow", "4800", nullptr));
        cmb_BaundRate->setItemText(3, QCoreApplication::translate("MainWindow", "9600", nullptr));
        cmb_BaundRate->setItemText(4, QCoreApplication::translate("MainWindow", "19200", nullptr));
        cmb_BaundRate->setItemText(5, QCoreApplication::translate("MainWindow", "38400", nullptr));
        cmb_BaundRate->setItemText(6, QCoreApplication::translate("MainWindow", "57600", nullptr));
        cmb_BaundRate->setItemText(7, QCoreApplication::translate("MainWindow", "115200", nullptr));

        cmb_DataBit->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        cmb_DataBit->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        cmb_DataBit->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        cmb_DataBit->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        cmb_StopBit->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        cmb_StopBit->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        cmb_StopBit->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        cmb_CheckBit->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        cmb_CheckBit->setItemText(1, QCoreApplication::translate("MainWindow", "\345\245\207\346\240\241\351\252\214", nullptr));
        cmb_CheckBit->setItemText(2, QCoreApplication::translate("MainWindow", "\345\201\266\346\240\241\351\252\214", nullptr));

        btn_CheckSerail->setText(QCoreApplication::translate("MainWindow", "\346\243\200\346\265\213\344\270\262\345\217\243", nullptr));
        btn_OpenSerail->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\350\256\276\347\275\256", nullptr));
        btn_ClearRecive->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266", nullptr));
        chk_HexRecive->setText(QCoreApplication::translate("MainWindow", "Hex\346\216\245\346\224\266", nullptr));
        chk_TimeRecive->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\346\210\263", nullptr));
        chk_ChangeLine->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\350\256\276\347\275\256", nullptr));
        chk_HexSend->setText(QCoreApplication::translate("MainWindow", "Hex\345\217\221\351\200\201", nullptr));
        chk_SendNewLine->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\226\260\350\241\214", nullptr));
        chk_AutoSend->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\345\217\221\351\200\201", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>ms</p></body></html>", nullptr));
        btn_SendMsg->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        btn_ClearSendMsg->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\217\221\351\200\201", nullptr));
        btn_LockEdit->setText(QCoreApplication::translate("MainWindow", "\351\224\201\345\256\232\345\217\221\351\200\201\346\241\206", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\350\260\203\350\257\225\345\212\251\346\211\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
