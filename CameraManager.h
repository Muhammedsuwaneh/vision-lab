#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <QObject>

class CameraManager : public QObject
{
    Q_OBJECT
public:
    explicit CameraManager(QObject *parent = nullptr);

signals:
};

#endif // CAMERAMANAGER_H
