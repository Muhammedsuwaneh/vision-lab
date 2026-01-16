#ifndef CAMERAIMAGEPROVIDER_H
#define CAMERAIMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QMutex>

class CameraImageProvider: public QQuickImageProvider
{
public:
    CameraImageProvider();

private:
    QImage m_image;
    QMutex m_mutex;
public:
    virtual QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;
    void updateImage(const QImage& image);
};

#endif // CAMERAIMAGEPROVIDER_H
