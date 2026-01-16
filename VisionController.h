#ifndef VISIONCONTROLLER_H
#define VISIONCONTROLLER_H

#include <QObject>
#include "CameraManager.h"

class VisionController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString mode READ mode WRITE setMode NOTIFY modeChanged)
public:
    explicit VisionController(CameraManager* cam, QObject *parent = nullptr);

    QString mode() const;
    Q_INVOKABLE void setMode(QString newMode);
    Q_INVOKABLE bool startCamera();
    Q_INVOKABLE bool stopCamera();

signals:
    void modeChanged();
private:
    QString m_mode = "";
    CameraManager* m_camera;
};

#endif // VISIONCONTROLLER_H
