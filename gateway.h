#ifndef GATEWAY_H
#define GATEWAY_H

#include <QMainWindow>
#include  "video.h"
namespace Ui {
class GateWay;
}

class GateWay : public QMainWindow
{
    Q_OBJECT

public:
    explicit GateWay(QWidget *parent = 0);
    ~GateWay();
public:
    Ui::GateWay *homePage;
    Video video;
    QTimer *freshFrameTimer;
public slots:
    void OnVideoTimeOut();

private slots:
    void on_video_start_clicked();
    void on_video_stop_clicked();
};

#endif // GATEWAY_H
