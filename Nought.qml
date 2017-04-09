import QtQuick 2.0

Canvas {
    anchors.fill: parent
    onPaint: {
        var ctx = getContext("2d");
        ctx.lineWidth = 2;
        ctx.beginPath();
        var centerX = width / 2;
        var centerY = height / 2
        var radius = width / 4;
        ctx.arc(centerX, centerY, radius, 0, 2 * Math.PI);
        ctx.stroke();
    }
}
