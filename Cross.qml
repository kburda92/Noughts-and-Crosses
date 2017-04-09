import QtQuick 2.0

Canvas {
    anchors.fill: parent
    onPaint: {
        var ctx = getContext("2d");
        ctx.lineWidth = 2;
        ctx.beginPath();
        ctx.moveTo(1/4 * width, 1/4 * height);
        ctx.lineTo(3/4 * width, 3/4 * height);
        ctx.stroke();
        ctx.lineWidth = 2;
        ctx.beginPath();
        ctx.moveTo(3/4 * width, 1/4 * height);
        ctx.lineTo(1/4 * width, 3/4 * height);
        ctx.stroke();
    }
}
