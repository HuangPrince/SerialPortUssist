#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QPainter>
#include <QLabel>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /*手动连接的槽函数*/
    //读到信号的触发函数
    void SetConnectSerialPortReadyRead();

    void on_btn_CheckSerail_clicked();

    void on_btn_OpenSerail_clicked();

    void on_btn_SendMsg_clicked();

    void on_btn_ClearSendMsg_clicked();

    void on_btn_ClearRecive_clicked();

    void on_chk_AutoSend_stateChanged(int arg1);

    void on_btn_LockEdit_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort* m_serialPort;

private:
    //发送、接收字节计数
    long m_lSendNum;
    long m_lRecvNum;
    QLabel *m_qlbSendNum;
    QLabel *m_qlbRecvNum;
    QLabel *m_qlbPortState;
    void SetNumOnLabel(QLabel *lable,QString qstrContent,long num);     //往Label中设置次数函数

    //定时发送的定时器
    QTimer *m_qtSendTime;
};
#endif // MAINWINDOW_H
