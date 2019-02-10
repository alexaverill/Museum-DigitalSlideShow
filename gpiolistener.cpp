#include "gpiolistener.h"
#include <QDebug>
#include<QThread>

GPIOListener::GPIOListener(int physicalPinNum)
{
     //manually setup GPIO pin access
    QString pathPortion = "/sys/class/gpio/gpio"+QString::number(physicalPinNum)+"/";
    QFile exportFile("/sys/class/gpio/export");
    exportFile.open(QIODevice::WriteOnly);
    exportFile.write(QString::number(physicalPinNum).toLatin1());

    QFile directionFile(pathPortion+"direction");
    directionFile.open(QIODevice::WriteOnly);
    directionFile.write("in");

    QFile edgeFile(pathPortion+"edge");
    edgeFile.open(QIODevice::WriteOnly);
    edgeFile.write("falling");
    GPIOWorker *listener = new GPIOWorker(physicalPinNum,pathPortion+"value");
    listener->moveToThread(&worker);
    connect(&worker,&QThread::finished, listener, &QObject::deleteLater);
    connect(this,&GPIOListener::startListening, listener, &GPIOWorker::listenOnGpio);
    connect(listener,&GPIOWorker::gpioTriggered,this, &GPIOListener::gpioInterupt);
    worker.start();
    emit startListening();
//    int x =-1000;
//    while(x<1000000){
//        val.open(QIODevice::ReadOnly);
//        qDebug() << val.readAll();
//        val.close();
//    }



}

GPIOListener::~GPIOListener()
{
        worker.quit();
        worker.wait();
}

void GPIOListener::gpioInterupt(int pin)
{
    emit gpioActivated();
}


GPIOWorker::GPIOWorker(int pin, QString _filePath):pinNum(pin),filePath(_filePath)
{
}

GPIOWorker::~GPIOWorker()
{
    isRunning = false;
}

void GPIOWorker::listenOnGpio()
{
    qDebug()<<"starting Thread";
    QFile val(filePath);
    int prevVal = 1;
    while(isRunning){
        val.open(QIODevice::ReadOnly);
        QString contents = val.readAll();
        val.close();
        int value = contents.toInt();
        if(value == 0 && prevVal == 1){
            prevVal = 0;
            emit gpioTriggered(pinNum);
        }
        if(prevVal == 0 && value == 1){
            prevVal = 1;
        }
        QThread::msleep(100);
    }
}
