#ifndef SERIAL_H
#define SERIAL_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
class Serial
{
public:
    Serial();
    void testSerialPortAvailable();
    void readFromZigBeeSerialPort();
    void initSerialPort();
    void Read_Data();
    void Write_Data();
public:
     QSerialPort availSerial;
     QSerialPort *serial;
};

#endif // SERIAL_H
