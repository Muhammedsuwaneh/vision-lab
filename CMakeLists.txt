cmake_minimum_required(VERSION 3.16)

project(VisionLab VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib")
find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appVisionLab
    main.cpp
)

qt_add_qml_module(appVisionLab
    URI VisionLab
    QML_FILES
        views/Main.qml
        views/TitleBar.qml

    RESOURCES
        assets/logo.png
        assets/logo.ico

        models/coco.names
        models/yolov4-tiny.cfg
        models/yolov4-tiny.weights
        models/res10_300x300_ssd_iter_140000.caffemodel
        models/deploy.prototxt

    SOURCES
        controllers/WindowController.h
        controllers/WindowController.cpp
        QML_FILES views/ControlButton.qml
        SOURCES utilities/CameraManager.h utilities/CameraManager.cpp
        SOURCES controllers/VisionController.h controllers/VisionController.cpp
        SOURCES detectors/ObjectDetector.h detectors/ObjectDetector.cpp
        SOURCES detectors/MotionDetector.h detectors/MotionDetector.cpp
        QML_FILES views/CameraView.qml
        SOURCES detectors/FaceDetector.h detectors/FaceDetector.cpp
        SOURCES utilities/CameraImageProvider.h utilities/CameraImageProvider.cpp
)

set_target_properties(appVisionLab PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appVisionLab
    PRIVATE Qt6::Quick ${OPEN}
)
target_link_libraries(appVisionLab PRIVATE Qt6::Core ${OpenCV_LIBS})
target_link_libraries(appVisionLab PRIVATE Qt6::Core)
target_link_libraries(appVisionLab PRIVATE Qt6::Core)
target_link_libraries(appVisionLab PRIVATE Qt6::Widgets)
target_link_libraries(appVisionLab PRIVATE Qt6::Core)
target_link_libraries(appVisionLab PRIVATE Qt6::Core)
target_link_libraries(appVisionLab PRIVATE Qt6::Core)
target_link_libraries(appVisionLab PRIVATE Qt6::Core)
target_link_libraries(appVisionLab PRIVATE Qt6::Core)
target_link_libraries(appVisionLab PRIVATE Qt6::Core)
target_link_libraries(appVisionLab PRIVATE Qt6::Core)
target_link_libraries(appVisionLab PRIVATE Qt6::Core)
target_link_libraries(appVisionLab PRIVATE Qt6::Core)
target_link_libraries(appVisionLab PRIVATE Qt6::Core)
target_link_libraries(appVisionLab PRIVATE Qt6::Core)

include(GNUInstallDirs)
install(TARGETS appVisionLab BUNDLE DESTINATION . LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} )

