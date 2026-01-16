#ifndef VISIONCONTROLLER_H
#define VISIONCONTROLLER_H

#include <QObject>

class VisionController : public QObject
{
    Q_OBJECT
public:
    explicit VisionController(QObject *parent = nullptr);

signals:
};

#endif // VISIONCONTROLLER_H
