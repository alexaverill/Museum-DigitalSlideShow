#ifndef FILEFINDER_H
#define FILEFINDER_H

#include <QObject>
#include <QStringListModel>
class FileFinder : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList fileList READ getFileList CONSTANT)
public:
    FileFinder(QString imagePath);
    QStringList getFileList();
private:
    QStringList _fileList;
};

#endif // FILEFINDER_H
