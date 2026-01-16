#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include <QObject>

class FaceDetector : public QObject
{
    Q_OBJECT
public:
    explicit FaceDetector(QObject *parent = nullptr);

signals:
};

#endif // FACEDETECTOR_H
