#ifndef OBJECTDETECTOR_H
#define OBJECTDETECTOR_H

#include <QObject>

class ObjectDetector : public QObject
{
    Q_OBJECT
public:
    explicit ObjectDetector(QObject *parent = nullptr);

signals:
};

#endif // OBJECTDETECTOR_H
