import QtQuick 2.0

Canvas {
    id: winnerLine
    anchors.fill: parent
    property int point1:0
    property int point2:2
    onPaint: {
        var diff = point2 - point1
        console.log(diff)
        var ctx = getContext("2d");
        ctx.lineWidth = 5;
        ctx.beginPath();
//            //horizontally
        if(diff === 2)
        {
            ctx.moveTo(1/6 * width, 1/6 * height);
            ctx.lineTo(5/6 * width, 1/6 * height);
        }

//            //vertically
//            if(diff == 6)

//            if(diff == 4 || diff == 8)
//                ;

        ctx.stroke();
        ctx.save();
    }
}
