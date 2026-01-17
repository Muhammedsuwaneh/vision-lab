#include "ObjectDetector.h"
#include <QDebug>
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QTextStream>

ObjectDetector::ObjectDetector(QObject *parent)
    : QObject{parent}
{
    try {

        QDir appDir(QCoreApplication::applicationDirPath());

        QString cfgPath     = appDir.filePath("VisionLab/data/yolov4-tiny.cfg");
        QString weightsPath = appDir.filePath("VisionLab/data/yolov4-tiny.weights");
        QString namesPath   = appDir.filePath("VisionLab/data/coco.names");

        if (!QFile::exists(cfgPath) || !QFile::exists(weightsPath))
        {
            qDebug() << "YOLOv4-tiny files not found";
            return;
        }

        net = cv::dnn::readNetFromDarknet(
            cfgPath.toStdString(),
            weightsPath.toStdString()
            );

        if (net.empty())
        {
            qDebug() << "Failed to load YOLOv4-tiny network";
            return;
        }


        net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
        net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);

        loadClassNames(namesPath);

        qDebug() << "YOLOv4-tiny loaded successfully";
    }
    catch(const char* msg)
    {
        qDebug() << msg;
    }
}

void ObjectDetector::detect(cv::Mat frame)
{
    qDebug() << "detecting objects";

    if (frame.empty())
        return;

    // Create YOLO input blob
    cv::Mat blob = cv::dnn::blobFromImage(
        frame,
        1.0 / 255.0,
        cv::Size(416, 416),
        cv::Scalar(),
        true,
        false
            );

    net.setInput(blob);

    std::vector<cv::Mat> outputs;
    net.forward(outputs, net.getUnconnectedOutLayersNames());

    std::vector<int> classIds;
    std::vector<float> confidences;
    std::vector<cv::Rect> boxes;

    int w = frame.cols;
    int h = frame.rows;

    // Parse YOLO output
    for (const cv::Mat& output : outputs)
    {
        const float* data = (float*)output.data;

        for (int i = 0; i < output.rows; ++i, data += output.cols)
        {
            float objectness = data[4];

            if (objectness < confidenceThreshold)
                continue;

            cv::Mat scores(1, output.cols - 5, CV_32F, (void*)(data + 5));
            cv::Point classId;
            double classScore;
            cv::minMaxLoc(scores, 0, &classScore, 0, &classId);

            float confidence = objectness * (float)classScore;

            if (confidence > confidenceThreshold)
            {
                int centerX = int(data[0] * w);
                int centerY = int(data[1] * h);
                int width   = int(data[2] * w);
                int height  = int(data[3] * h);

                int left = centerX - width / 2;
                int top  = centerY - height / 2;

                boxes.emplace_back(left, top, width, height);
                confidences.push_back(confidence);
                classIds.push_back(classId.x);
            }
        }
    }

    // Apply Non-Maximum Suppression
    std::vector<int> indices;
    cv::dnn::NMSBoxes(
        boxes,
        confidences,
        confidenceThreshold,
        nmsThreashold,
        indices
        );

    // Draw final detections
    for (int idx : indices)
    {
        cv::Rect box = boxes[idx];
        int classId = classIds[idx];

        cv::rectangle(frame, box, cv::Scalar(0, 255, 0), 2);

        QString label =
            (classId < classNames.size())
                ? classNames[classId]
                : "Object";

        cv::putText(
            frame,
            label.toStdString(),
            cv::Point(box.x, box.y - 8),
            cv::FONT_HERSHEY_SIMPLEX,
            0.5,
            cv::Scalar(0, 255, 0),
            2
            );
    }
}

void ObjectDetector::loadClassNames(const QString &path)
{
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd())
        classNames.push_back(in.readLine());
}

