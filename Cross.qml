import QtQuick 2.0

Item {
    anchors.fill: parent
    Canvas {
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d");
            ctx.lineWidth = 2;
            ctx.beginPath();
            ctx.moveTo(0, 0);
            ctx.lineTo(width / 2, height / 2);
            ctx.stroke();
            ctx.lineWidth = 1;
            ctx.beginPath();
            ctx.moveTo(width / 2, 0);
            ctx.lineTo(0, height / 2);
            ctx.stroke();
        }
    }
}
