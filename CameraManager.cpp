#include "CameraManager.h"
#include <thread>
#include <QImage>
#include <QDebug>

CameraManager::CameraManager(CameraImageProvider* imageProvider) : imageProvider(imageProvider) {}

inline QImage matToQImage(const cv::Mat& mat)
{
    switch (mat.type())
    {
    case CV_8UC3:
        return QImage(
                   mat.data,
                   mat.cols,
                   mat.rows,
                   mat.step,
                   QImage::Format_BGR888
                   ).copy();

    case CV_8UC1:
        return QImage(
                   mat.data,
                   mat.cols,
                   mat.rows,
                   mat.step,
                   QImage::Format_Grayscale8
                   ).copy();

    default:
        return QImage();
    }
}

bool CameraManager::start()
{
    try
    {
        cap.open(0);
        std::thread([this]() { processFrame(); }).detach();
        return true;
    }
    catch (const char* msg)
    {
        qDebug() << msg;
        return false;
    }
}

void CameraManager::setMode(QString mode)
{
    this->currentMode = mode;
}

void CameraManager::processFrame()
{
    cv::Mat frame;
    while(cap.isOpened())
    {
        cap >> frame;
        if(frame.empty()) continue;

        if(this->currentMode == "Face Detection") faceDetector.detect(frame);
        else if(this->currentMode == "Object Detection") qDebug() << "";
        else if(this->currentMode == "Text Detection")  qDebug() << "";

        QImage img = matToQImage(frame);
        this->imageProvider->updateImage(img);

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
