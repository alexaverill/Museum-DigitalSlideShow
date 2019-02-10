import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("SlideShow")
    Connections{
        target: GPIO
        onGpioActivated: imageDisplay.pos= (imageDisplay.pos +1)%60;
        //onGPIOActivated: imageDisplay.pos= (imageDisplay.pos +1)%60;
    }

    Image {
       id: imageDisplay
       property int pos: 1;
        anchors.fill: parent;
        source: Files.fileList[pos]
//        NumberAnimation on pos{
//            duration:30000
//            from:1
//            to:60
//            loops:Animation.Infinite;
//        }
    }
}
