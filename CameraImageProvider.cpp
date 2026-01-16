#include "CameraImageProvider.h"

CameraImageProvider::CameraImageProvider() : QQuickImageProvider(QQuickImageProvider::Image) {}

QImage CameraImageProvider::requestImage(
    const QString &,
    QSize *size,
    const QSize &requestedSize)
{
    QMutexLocker locker(&m_mutex);
    if (size)
        *size = m_image.size();
    return m_image;
}

void CameraImageProvider::updateImage(const QImage &image)
{
    QMutexLocker locker(&m_mutex);
    m_image = image.copy();
}
