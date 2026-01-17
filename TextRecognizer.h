#ifndef TEXTRECOGNIZER_H
#define TEXTRECOGNIZER_H

#include <QObject>
#include <opencv2/opencv.hpp>

class TextRecognizer : public QObject
{
    Q_OBJECT
public:
    explicit TextRecognizer(QObject *parent = nullptr);
    void detect(cv::Mat frame);

signals:
};

#endif // TEXTRECOGNIZER_H

