#include "gateway.h"
#include "ui_gateway.h"

GateWay::GateWay(QWidget *parent) :
    QMainWindow(parent),
    homePage(new Ui::GateWay)
{
    homePage->setupUi(this);
    freshFrameTimer = new QTimer(this);
    freshFrameTimer->setInterval(1);
    video.readFrame();
    connect(freshFrameTimer,SIGNAL(timeout()),this,SLOT(OnVideoTimeOut()));

}

void GateWay::OnVideoTimeOut()
{
      QPixmap qPixmapImage = video.readFrame();
      homePage->video_label->setPixmap(qPixmapImage);
      homePage->video_label->show();
}

GateWay::~GateWay()
{
    delete homePage;
}

void GateWay::on_video_start_clicked()
{
    freshFrameTimer->start();
}

void GateWay::on_video_stop_clicked()
{
    freshFrameTimer->stop();
}
