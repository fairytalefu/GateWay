#ifndef VIDEO_H
#define VIDEO_H
#include <QDebug>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QImage>
#include <QTimer>
class Video
{
public:
    Video();
    QPixmap readFrame();
    QImage cvMat2QImage(const cv::Mat& mat);
public:
    cv::Mat frame;
    QImage image;
    cv::VideoCapture capture;
};

#endif // VIDEO_H
