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
        Main.qml
        TitleBar.qml

    RESOURCES
        assets/logo.png
        assets/logo.ico
        data/coco.names
        data/slim.onnx
        data/yolov5s.onnx

    SOURCES
        WindowController.h
        WindowController.cpp
        QML_FILES ControlButton.qml
        SOURCES CameraManager.h CameraManager.cpp
        SOURCES VisionController.h VisionController.cpp
        SOURCES
        SOURCES ObjectDetector.h ObjectDetector.cpp
        SOURCES TextRecognizer.h TextRecognizer.cpp
        QML_FILES CameraView.qml
        SOURCES FaceDetector.h FaceDetector.cpp
        SOURCES CameraImageProvider.h CameraImageProviderr.cpp
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

