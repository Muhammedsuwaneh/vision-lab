#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <opencv2/opencv.hpp>
#include <FaceDetector.h>
#include <ObjectDetector.h>
#include <TextRecognizer.h>
#include "CameraImageProvider.h"

class CameraManager
{
public:
    explicit CameraManager(CameraImageProvider* imageProvider);
    bool start();
    bool stop();
    void setMode(QString m);
    cv::Mat getFrame();
signals:
private:
    QString currentMode;
    cv::VideoCapture cap;
    FaceDetector faceDetector;
    ObjectDetector object;
    TextRecognizer text;
    void processFrame();

    CameraImageProvider* imageProvider;
};

#endif // CAMERAMANAGER_H
