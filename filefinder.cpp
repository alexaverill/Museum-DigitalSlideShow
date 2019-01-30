#include "filefinder.h"
#include<QJsonDocument>
#include <QDir>
#include<QStringList>
#include<QDebug>
FileFinder::FileFinder(QString imagePath)
{
    //load file list from directory;
    QDir fileDir(imagePath);
    QStringList fileFilter;
    fileFilter << "*.jpg";//potentially will add all image files or through json
    _fileList =fileDir.entryList(fileFilter);
    for(int x=0; x<_fileList.length();x++){
        _fileList[x] = "file:///"+imagePath +"/"+_fileList[x]; //fix filepath so QML is happy
        qDebug()<<_fileList[x]<<endl;
    }

}

QStringList FileFinder::getFileList()
{
 return _fileList;
}
