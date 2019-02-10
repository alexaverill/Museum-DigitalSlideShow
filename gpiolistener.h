#ifndef GPIOLISTENER_H
#define GPIOLISTENER_H
#include <QObject>
#include <QFile>
#include<QThread>
class GPIOWorker : public QObject{
    Q_OBJECT;
public:
    GPIOWorker(int pin, QString filePath);
    ~GPIOWorker();
public slots:
    void listenOnGpio();
signals:
    void gpioTriggered(int pinNum);
private:
    QString filePath;
    int pinNum;
    bool isRunning =true;
};



class GPIOListener : public QObject
{
    Q_OBJECT
    QThread worker;
public:
    GPIOListener(int physicalPinNum);
    ~GPIOListener();
signals:
    void gpioActivated();
    void startListening();
public slots:
    void gpioInterupt(int sock);
private:


     //QSocketNotifier *note;
};

#endif // GPIOLISTENER_H
