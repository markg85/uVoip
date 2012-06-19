import QtQuick 1.1

Item
{
    property alias color: level.color
    property alias micLevel: level.micLevel


    Rectangle
    {
        anchors.fill: parent
        border.width: 1
        border.color: "black"

        Rectangle
        {
            id: level
            property real micLevel: 0
            y: parent.border.width
            x: parent.border.width
            height: parent.height - parent.border.width
            width: parent.width * micLevel
        }
    }
}
