/*
 * Author - Muhammed Suwaneh
*/

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

    CameraManager camera;
    engine.addImageProvider("camera", new CameraImageProvider(&camera));
    engine.rootContext()->setContextProperty("camera", &camera);


    VisionController visionController(&camera);
    engine.rootContext()->setContextProperty("VisionController", &visionController);

    engine.loadFromModule("VisionLab", "Main");

    if (engine.rootObjects().isEmpty())
        return -1;

    QWindow *window = qobject_cast<QWindow*>(engine.rootObjects().first());
    if (!window)
        return -1;

    WindowController controller(window);
    engine.rootContext()->setContextProperty("WindowController", &controller);


    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    return app.exec();
}
