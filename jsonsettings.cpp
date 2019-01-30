#include "jsonsettings.h"
#include <QFile>
#include <QJsonDocument>
#include <QDebug>
#include<QJsonObject>
//create singleton
JSONSettings* JSONSettings::instance = 0;

JSONSettings::JSONSettings()
{
    //Deal with QTJSON boiler plate to open JSON file and read it into a usable object;
    QString jsonString;
    QFile jsonFile;
    jsonFile.setFileName(_jsonFile);
    jsonFile.open(QIODevice::ReadOnly |QIODevice::Text);
    jsonString = jsonFile.readAll();
    jsonFile.close();
    QJsonDocument settings = QJsonDocument::fromJson(jsonString.toUtf8());
    QJsonObject json = settings.object();

    //save JSON settings to use
    _imageDir = json["imageDirectory"].toString();
}
JSONSettings* JSONSettings::getInstance(){
    if(instance == 0){
        instance = new JSONSettings();
    }
    return instance;
}
