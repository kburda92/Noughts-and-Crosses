import QtQuick 2.0

Item {
    // our delegate
    Component {
        id: delegate
        Rectangle {
            id: rect

            border.color: "black"
            border.width: 2
            width: parent.width/3
            height: parent.height/3

            Text {
                text: index
            }
        }
    }

    GridView {
        id: grid
        anchors.fill: parent
        //we added 2 to hide borders
        height: parent.height + 20
        width: parent.width + 20
        cellHeight: height/3
        cellWidth: width/3
        model: 9
        delegate: delegate
    }
}
