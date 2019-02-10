#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QQmlContext>
#include<filefinder.h>
#include<jsonsettings.h>
#include<gpiolistener.h>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    JSONSettings* json = JSONSettings::getInstance();
    FileFinder *ff = new FileFinder(json->getImageDirectory());
    GPIOListener *gpio = new GPIOListener(4);
    QQmlApplicationEngine engine;
 engine.rootContext()->setContextProperty("Files",ff);
 engine.rootContext()->setContextProperty("GPIO",gpio);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
