/*
 * Author - Muhammed Suwaneh
*/

#include "TextRecognizer.h"
#include <QDebug>

TextRecognizer::TextRecognizer(QObject *parent)
    : QObject{parent}
{}

void TextRecognizer::detect(cv::Mat &frame)
{
    qDebug() << "detecting text";
}
