#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "WindowController.h"
#include "VisionController.h"
#include "CameraImageProvider.h"
#include "CameraManager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("VisionLab", "Main");

    if(engine.rootObjects().isEmpty()) return -1;

    // IMAGE PROVIDER
    auto* imageProvider = new CameraImageProvider();
    engine.addImageProvider("camera", imageProvider);

    // CAMERA PROVIDER
    CameraManager camera(imageProvider);

    // VISION PROVIDER
    VisionController visionController(&camera);
    engine.rootContext()->setContextProperty("VisionController", &visionController);


    QWindow *window = qobject_cast<QWindow*>(engine.rootObjects().first());
    WindowController controller(window);

    engine.rootContext()->setContextProperty("WindowController", &controller);

    return app.exec();
}
