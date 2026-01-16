#include "VisionController.h"
#include <QDebug>

VisionController::VisionController(CameraManager* cam, QObject *parent) : QObject{parent}, m_camera(cam)
{}

QString VisionController::mode() const
{
    return this->m_mode;
}

void VisionController::setMode(QString newMode)
{
    if (this->m_mode == newMode)
        return;

    qDebug() << newMode;

    this->m_mode = newMode;
    this->m_camera->setMode(newMode);
    emit modeChanged();
}

bool VisionController::startCamera()
{
    return this->m_camera->start();
}

bool VisionController::stopCamera()
{
    return this->m_camera->stop();
}
