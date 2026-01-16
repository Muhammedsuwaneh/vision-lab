#include "VisionController.h"
#include <QDebug>

VisionController::VisionController(QObject *parent)
    : QObject{parent}
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
    // set cam mode here
    emit modeChanged();
}
