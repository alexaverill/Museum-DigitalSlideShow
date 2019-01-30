#ifndef JSONSETTINGS_H
#define JSONSETTINGS_H

#include <QObject>

class JSONSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString imageDirectory READ getImageDirectory CONSTANT)
public:
    inline QString getImageDirectory();
    static JSONSettings* getInstance();
private:
    QString _imageDir;
    QString _jsonFile = "/home/pi/SlideShow.json";
    JSONSettings();
    static JSONSettings* instance;

};
inline QString JSONSettings::getImageDirectory(){
    return _imageDir;
}

#endif // JSONSETTINGS_H
