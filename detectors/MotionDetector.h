#ifndef MOTIONDETECTOR_H
#define MOTIONDETECTOR_H

#include <QObject>
#include <opencv2/opencv.hpp>

class MotionDetector : public QObject
{
    Q_OBJECT
public:
    explicit MotionDetector(QObject *parent = nullptr);
    void detect(cv::Mat& frame);

signals:
};

#endif // MOTIONDETECTOR_H

