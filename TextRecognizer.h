#ifndef TEXTRECOGNIZER_H
#define TEXTRECOGNIZER_H

#include <QObject>

class TextRecognizer : public QObject
{
    Q_OBJECT
public:
    explicit TextRecognizer(QObject *parent = nullptr);

signals:
};

#endif // TEXTRECOGNIZER_H

// MODEL - https://github.com/oyyd/frozen_east_text_detection.pb
