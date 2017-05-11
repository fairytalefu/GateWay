#include "serial.h"

Serial::Serial()
{

}
void Serial::testSerialPortAvailable()
{
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
          qDebug() << "Name        : " << info.portName();
          qDebug() << "Description : " << info.description();
          qDebug() << "Manufacturer: " << info.manufacturer();
          // Example use QSerialPort
          availSerial.setPort(info);
          if (availSerial.open(QIODevice::ReadWrite))
              availSerial.close();
      }
}
void Serial::initSerialPort()
{
    QString portName = availSerial.portName();
    int BaudRate = 9600;
    serial = new QSerialPort;
    //设置串口名
    serial->setPortName(portName);
    //打开串口
    serial->open(QIODevice::ReadWrite);
    //设置波特率
    serial->setBaudRate(BaudRate);
    //设置数据位数
    serial->setDataBits(QSerialPort::Data8);
     //设置奇偶校验
     serial->setParity(QSerialPort::NoParity);
    //设置停止位
    serial->setStopBits(QSerialPort::OneStop);
    //设置流控制
    serial->setFlowControl(QSerialPort::NoFlowControl);
    qDebug() << "initializating SerialPort OK!" << endl;
}
void Serial::Read_Data()
{
    QByteArray buf;
    buf = serial->readAll();
    if(!buf.isEmpty())
    {
//      QString str = ui->textEdit->toPlainText();
//      str+=tr(buf);
//      ui->textEdit->clear();
//      ui->textEdit->append(str);
    }
    buf.clear();
}

//发送数据
void Serial::Write_Data()
{
    serial->write("111");
}
void Serial::readFromZigBeeSerialPort()
{

}
