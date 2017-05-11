#include "video.h"
#include "gateway.h"
using namespace cv;
Video::Video()
{
    capture.set(CV_CAP_PROP_FRAME_WIDTH, 1920);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT, 1080);
    capture.open(0);
}
QPixmap Video::readFrame()
{
    if(capture.isOpened())
    {
            //qDebug()<<"open camera ok!"<<endl;
            capture >> frame;
            if (!frame.empty())
            {
              cvtColor(frame,frame,CV_BGR2GRAY);
              // Canny(frame,frame,3,9,3);
             // GaussianBlur(frame,frame,Size(21,21),0,0);
              image = cvMat2QImage(frame);
            }
            else
            {
                //判断图像是否载入
                qDebug()<<"not frame captured"<<endl;
                image.load("/home/pi/QtProject/GateWay/lena.jpg");
            }
          //  homePage->video_label->setPixmap(QPixmap::fromImage(image));
           // homePage->video_label->show();
           // qDebug()<<"convert frame capture ok!"<<endl;
    }
    else
    {
        //判断图像是否载入
        qDebug()<<"Camara open failed!"<<endl;
    }
    return QPixmap::fromImage(image);
}
QImage Video::cvMat2QImage(const cv::Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}
