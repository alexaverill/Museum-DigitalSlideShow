#ifndef GPIOLISTENER_H
#define GPIOLISTENER_H

#include <QObject>

class GPIOListener : public QObject
{
    Q_OBJECT
public:
    explicit GPIOListener(QObject *parent = 0);

signals:

public slots:
};

#endif // GPIOLISTENER_H