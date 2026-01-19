/*
 * Author - Muhammed Suwaneh
*/

#include "MotionDetector.h"
#include <QDebug>

MotionDetector::MotionDetector(QObject *parent)
    : QObject{parent}
{}

void MotionDetector::detect(cv::Mat &frame)
{
    qDebug() << "detecting motion";
}
