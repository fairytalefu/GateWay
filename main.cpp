#include "gateway.h"
#include "model.h"
#include "serial.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GateWay w;
    Model m;
    m.connectTOMySQL();
    Serial s;
    s.testSerialPortAvailable();
    s.initSerialPort();
    w.show();

    return a.exec();
}
