import QtQuick 2.12
import QtQuick.Window 2.12
//import DataSet 1.0


Window {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("")
    color: "#081c15"

    property var data: []

    Component.onCompleted: {
//        console.log('a', dataSet.data[0]);
        for (let i=0; i < dataSet.data.length; i = i + 2){
            data.push(new Object({x: dataSet.data[i], y: dataSet.data[i + 1]}))
        }
    }

//    DataSet {
//        id: dataSet
//        Component.onCompleted: {
//            console.log(dataSet.records)
//        }
//    }


//    Rectangle {
//        width: 50
//        height: parent.height
//        x: parent.width - 50
//        y: 0
//        color: "#1B4332"
//    }

    Canvas {
        id: mainCanvas
        width: 640
        height: 480
        x: 0
        y: 0

//        Rectangle {
//            width: parent.width
//            height: parent.height
//            x: parent.x
//            y: parent.y
//            color: "#D8F3DC"
//            radius: 10
//        }
        onPaint: {
            var ctx = getContext("2d");
            ctx.fillStyle = "#D8F3DC"
            ctx.fillRect(0, 0, width, height);
            let centerX = Math.random() * (640 - 0) + 0;
            let centerY = Math.random() * (480 - 0) + 0;
            console.log(centerX, centerY);


            var centreX = width / 2;
            var centreY = height / 2;
            let r = 5;

            context.beginPath();
            context.arc(centerX, centerY, r, 0, 2 * Math.PI, false);
            context.fillStyle = 'green';
            context.fill();
            context.lineWidth = 5;
            ctx.save();
        }
    }

//    Item {
//        Timer {
//            interval: 1000; running: true; repeat: true
//            onTriggered: mainCanvas.requestPaint()
//        }

//        Text { id: time }
//    }
}
