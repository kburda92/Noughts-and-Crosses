import QtQuick 2.0

//class which paints line after one of player wins

Canvas {
    id: winnerLine
    anchors.fill: parent
    property int point1
    property int point2
    onPaint: {
        //here we must check first and last point1
        //its difference points out the line direction
        //if we know difference we can only check first point
        var diff = point2 - point1
        var ctx = getContext("2d");
        ctx.lineWidth = 5;
        ctx.beginPath();
        //board indexes:
        //0   1   2
        //3   4   5
        //6   7   8

        //values we must multiply board weight and height to get right line
        var k_w_start, k_w_stop, k_h_start, k_h_stop;
        var tol = 0.1
        //horizontally
        if(diff === 2)
        {
            k_w_start = 1/6 - tol;
            k_w_stop = 5/6 + tol;
            if(point1 == 0)
                k_h_start = 1/6;
            if(point1 == 3)
                k_h_start = 1/2;
            else if(point1 == 6)
                k_h_start = 5/6;
            k_h_stop = k_h_start;
        }
        //vertically
        else if(diff == 6)
        {
            k_h_start = 1/6 - tol;
            k_h_stop = 5/6 + tol;
            if(point1 == 0)
                k_w_start = 1/6;
            if(point1 == 1)
                k_w_start = 1/2;
            else if(point1 == 2)
                k_w_start = 5/6;
            k_w_stop = k_w_start;
        }
        //diagonally
        else if(diff == 4 || diff == 8)
        {
            k_h_start = 1/6 - tol;
            k_h_stop = 5/6 + tol;
            if(point1 == 0)
            {
                k_w_start = k_h_start;
                k_w_stop = k_h_stop;
            }
            else if(point1 == 2)
            {
                k_w_start = k_h_stop;
                k_w_stop = k_h_start;
            }
        }

        ctx.moveTo(k_w_start * width, k_h_start * height);
        ctx.lineTo(k_w_stop * width, k_h_stop * height);
        ctx.stroke();
    }
}
