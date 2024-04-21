#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDateTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(500,430);
    setFixedSize(width(),height());
    m_serialPort = new QSerialPort(this);
    on_btn_CheckSerail_clicked();           //打开软件就刷新串口端口号

    /*信号与槽函数的连接*/
    //connect(m_serialPort,readyRead(),this,SetConnectSerialPortReadyRead());
    connect(m_serialPort,SIGNAL(readyRead()),this,SLOT(SetConnectSerialPortReadyRead()));
    /*初始化成员变量*/
    m_lSendNum = 0;
    m_lRecvNum = 0;

    /*初始化就打开时间戳选项*/
    ui->chk_TimeRecive->setCheckState(Qt::Checked);

    /*初始化状态栏*/
    QStatusBar* qstaBar = statusBar();
    m_qlbSendNum = new QLabel(this);
    m_qlbRecvNum = new QLabel(this);
    m_qlbPortState = new QLabel(this);
    m_qlbPortState->setText("Connected");
    //设置窗口状态标签为绿色，表示为已连接状态
    m_qlbPortState->setStyleSheet("color:red");
    //设置标签最小大小
    m_qlbSendNum->setMinimumSize(100,20);
    m_qlbRecvNum->setMinimumSize(100,20);
    m_qlbPortState->setMinimumSize(550,20);
    SetNumOnLabel(m_qlbSendNum,"S: ",m_lSendNum);
    SetNumOnLabel(m_qlbRecvNum,"R: ",m_lRecvNum);
    //从右往左依次添加
    qstaBar->addPermanentWidget(m_qlbPortState);
    qstaBar->addPermanentWidget(m_qlbSendNum);
    qstaBar->addPermanentWidget(m_qlbRecvNum);

    /*初始化定义定时器*/
    m_qtSendTime = new QTimer;
    m_qtSendTime->setInterval(1000);        //默认定时时长1000ms
    connect(m_qtSendTime,&QTimer::timeout,this,[=](){on_btn_SendMsg_clicked();});
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_serialPort;
}

//接收信息函数槽
void MainWindow::SetConnectSerialPortReadyRead()
{
    QByteArray qbRecBuf = m_serialPort->readAll();
    QString qstrRecv;
    //接收字节数
    m_lRecvNum += qbRecBuf.size();
    //状态栏显示计数
    SetNumOnLabel(m_qlbRecvNum,"R: ",m_lRecvNum);
    if(ui->chk_HexRecive->checkState() == false)
    {
        if(ui->chk_TimeRecive->checkState() == Qt::Checked)
        {
            QDateTime qdtNowTime = QDateTime::currentDateTime();
            qstrRecv = "["+qdtNowTime.toString("yyyy-MM-dd hh:mm:ss")+"]";
            qstrRecv += QString::fromLocal8Bit(qbRecBuf).append("\r\n");
            qDebug()<<qstrRecv;     //QDebug控制台输出查看收到信息
        }
        else
        {
            if(ui->chk_ChangeLine->checkState() == Qt::Checked)
            {
                qstrRecv = QString::fromLocal8Bit(qbRecBuf).append("\r\n");
            }
            else
            {
                qstrRecv = QString::fromLocal8Bit(qbRecBuf);
            }
        }
    }
    else
    {      
        //十六进制显示，并转换为大写
        QString qstrRecvMsg = qbRecBuf.toHex(' ').toUpper();
        if(ui->chk_TimeRecive->checkState() == Qt::Checked)
        {
            QDateTime qNowtime = QDateTime::currentDateTime();
            qstrRecv = "[" + qNowtime.toString("yyyy-MM-dd hh:mm:ss") + "] ";
            qstrRecv += qstrRecvMsg.append("\r\n");
        }
        else
        {
            if(ui->chk_ChangeLine->checkState() == Qt::Checked)
            {
                qstrRecv += qstrRecvMsg.append("\r\n");
            }
            else
            {
                qstrRecv = qstrRecvMsg;
            }
        }

    }
    //ui->edit_ReciveMsg->insertPlainText(QString::fromUtf8(qstrRecv.toUtf8().data()));
    ui->edit_ReciveMsg->insertPlainText(qstrRecv);
    ui->edit_ReciveMsg->moveCursor(QTextCursor::End);
}

//检测串口端口号槽函数
void MainWindow::on_btn_CheckSerail_clicked()
{
    ui->cmb_SerailPort->clear();
    //通过QSerialPortInfo查找可用串口
    foreach(const QSerialPortInfo& info,QSerialPortInfo::availablePorts())
    {
        ui->cmb_SerailPort->addItem(info.portName());
    }
}

//打开串口槽函数
void MainWindow::on_btn_OpenSerail_clicked()
{
    /*串口参数声明*/
    QSerialPort::BaudRate baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::StopBits stopBits;
    QSerialPort::Parity parity;

    /*将串口中串口参数赋值到变量中*/

    //波特率
    //baudRate = ui->cmb_BaundRate->currentText().toInt();
    if(ui->cmb_BaundRate->currentText()=="1200")
        baudRate=QSerialPort::Baud1200;
    else if(ui->cmb_BaundRate->currentText()=="2400")
        baudRate=QSerialPort::Baud2400;
    else if(ui->cmb_BaundRate->currentText()=="4800")
        baudRate=QSerialPort::Baud4800;
    else if(ui->cmb_BaundRate->currentText()=="9600")
        baudRate=QSerialPort::Baud9600;
    else if(ui->cmb_BaundRate->currentText()=="19200")
        baudRate=QSerialPort::Baud19200;
    else if(ui->cmb_BaundRate->currentText()=="38400")
        baudRate=QSerialPort::Baud38400;
    else if(ui->cmb_BaundRate->currentText()=="57600")
        baudRate=QSerialPort::Baud57600;
    else if(ui->cmb_BaundRate->currentText()=="115200")
        baudRate=QSerialPort::Baud115200;

    //数据位
    if(ui->cmb_DataBit->currentText()=="5")
        dataBits=QSerialPort::Data5;
    else if(ui->cmb_DataBit->currentText()=="6")
        dataBits=QSerialPort::Data6;
    else if(ui->cmb_DataBit->currentText()=="7")
        dataBits=QSerialPort::Data7;
    else if(ui->cmb_DataBit->currentText()=="8")
        dataBits=QSerialPort::Data8;

    // 停止位
    if(ui->cmb_StopBit->currentText()=="1")
        stopBits=QSerialPort::OneStop;
    else if(ui->cmb_StopBit->currentText()=="1.5")
        stopBits=QSerialPort::OneAndHalfStop;
    else if(ui->cmb_StopBit->currentText()=="2")
        stopBits=QSerialPort::TwoStop;

    // 奇偶校验位
    if(ui->cmb_CheckBit->currentText() == "None")
        parity = QSerialPort::NoParity;
    else if(ui->cmb_CheckBit->currentText() == "奇校验")
        parity = QSerialPort::OddParity;
    else if(ui->cmb_CheckBit->currentText() == "偶校验")
        parity = QSerialPort::EvenParity;

    /*串口参数设置*/
    m_serialPort->setPortName(ui->cmb_SerailPort->currentText());
    m_serialPort->setBaudRate(baudRate);
    m_serialPort->setDataBits(dataBits);
    m_serialPort->setStopBits(stopBits);
    m_serialPort->setParity(parity);

    //打开串口
    if(ui->btn_OpenSerail->text() == "打开串口")
    {
        if(m_serialPort->open(QIODevice::ReadWrite) == true)
        {
            ui->btn_OpenSerail->setText("关闭串口");
            ui->cmb_SerailPort->setEnabled(false);      //串口打开后设置串口端口号下拉框不可用
        }
        else
        {
            QMessageBox::critical(this,"错误提示","串口打开失败！！");
        }
        //状态栏显示端口状态
        QString qstrState = "%1 OPENED-[%2]";
        qstrState = qstrState.arg(m_serialPort->portName()).arg(m_serialPort->baudRate());
        m_qlbPortState->setText(qstrState);
        m_qlbPortState->setStyleSheet("color:green");
    }
    else
    {
        m_serialPort->close();
        ui->btn_OpenSerail->setText("打开串口");
        ui->cmb_SerailPort->setEnabled(true);      //串口打开后设置串口端口号下拉框可用
        //状态栏显示端口状态
        QString qstrState = "%1 CLOSED";
        qstrState = qstrState.arg(m_serialPort->portName());
        m_qlbPortState->setText(qstrState);
        m_qlbPortState->setStyleSheet("color:red");
    }
}

//状态栏显示计数值
void MainWindow::SetNumOnLabel(QLabel *lable, QString qstrContent, long num)
{
    QString qstrShowMsg = QString::number(num);
    QString qstrRes = qstrContent+qstrShowMsg;
    lable->setText(qstrRes);
}

//发送数据
void MainWindow::on_btn_SendMsg_clicked()
{
    QByteArray qArray;
    //Hex复选框
    if(ui->chk_HexSend->checkState() == Qt::Checked)
    {   //16进制
        //qArray = QByteArray::fromHex(ui->edit_SendMsg->toPlainText().toUtf8());
        qArray = ui->edit_SendMsg->toPlainText().toUtf8().data();
    }
    else
    {   //ASCII
        qArray = ui->edit_SendMsg->toPlainText().toLocal8Bit().data();
    }
    if(ui->chk_SendNewLine->checkState() == Qt::Checked)
    {
        qArray.append("\r\n");
    }
    int iLongRes = m_serialPort->write(qArray);     //如果发送成功，会返回发送的字节长度，失败返回-1
    if(-1 == iLongRes)
    {
        QMessageBox::critical(this,"错误提示","串口发送信息失败！！");
        return;
    }
    else
    {
        m_lSendNum += iLongRes;     //发送字节计数
        SetNumOnLabel(m_qlbSendNum,"S: ",m_lSendNum);   //状态栏显示计数值
    }
}

//清空发送框
void MainWindow::on_btn_ClearSendMsg_clicked()
{
    ui->edit_SendMsg->clear();
    //清除发送字节计数
    m_lSendNum = 0;
    //状态栏显示计数
    SetNumOnLabel(m_qlbSendNum,"S: ",m_lSendNum);
}

//清空接受框
void MainWindow::on_btn_ClearRecive_clicked()
{
    ui->edit_ReciveMsg->clear();
    //清除接受字节数
    m_lRecvNum = 0;
    //状态栏显示计数
    SetNumOnLabel(m_qlbRecvNum,"R: ",m_lRecvNum);
}


//定时发送槽函数
void MainWindow::on_chk_AutoSend_stateChanged(int arg1)
{
    //获取复选框状态，未选为0，选中为2
    if(arg1 == 0)
    {
        m_qtSendTime->stop();
        ui->spb_Time->setEnabled(true);     //时间输入框可选
    }
    else
    {
        if(ui->spb_Time->text().toInt()>=10)
        {
            m_qtSendTime->start(ui->spb_Time->text().toInt());
            ui->spb_Time->setEnabled(false);    //时间输入框不可选
        }
        else
        {
            ui->chk_AutoSend->setCheckState(Qt::Unchecked);
            QMessageBox::critical(this,"错误提示","定时时间小于10ms，请重新输入");
        }
    }
}

//锁定发送框槽函数
void MainWindow::on_btn_LockEdit_clicked()
{
    if(ui->btn_LockEdit->text() == "锁定发送框")
    {
        ui->edit_SendMsg->setReadOnly(true);
        ui->btn_LockEdit->setText("解锁发送框");
    }
    else
    {
        ui->edit_SendMsg->setReadOnly(false);
        ui->btn_LockEdit->setText("锁定发送框");
    }

}

