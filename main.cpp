#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QQmlContext>
#include<filefinder.h>
#include<jsonsettings.h>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    JSONSettings* json = JSONSettings::getInstance();
    FileFinder *ff = new FileFinder(json->getImageDirectory());
    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    engine.rootContext()->setContextProperty("Files",ff);
    return app.exec();
}
