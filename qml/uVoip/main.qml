import QtQuick 1.1

Rectangle
{
    id: root
    width: 400
    height: 200

    signal socketRequestConnect(string socket)

    UVoipData
    {
        id: uvoipDataItem
        onHostMicrophoneLevelChanged:
        {
            hostMicrophone.micLevel = hostMicrophoneLevel
        }
        onRemoteMicrophoneLevelChanged:
        {
            remoteMicrophone.micLevel = remoteMicrophoneLevel
        }

        onConnectedChanged:
        {
            if(connected)
            {
                connectionBackground.color = "green"
                connectionText.text = "CONNECTED"
                console.log("QML, client: Connected!")
            }
            else
            {
                connectionBackground.color = "blue"
                connectionText.text = "CONNECT"
                console.log("QML, client: Disconnected!")
            }
        }
    }

    Item
    {
        id: subRoot
        width: parent.width - 22
        height: content.height
        y: 10
        anchors.horizontalCenter: parent.horizontalCenter

        Column
        {
            id: content
            spacing: 2
            Row
            {
                spacing: 2
                Column
                {
                    Text
                    {
                        text: "Host microphone"
                    }
                    VisualAudioLevel
                    {
                        id: hostMicrophone
                        color: "red"
                        width: subRoot.width / 2
                        height: 50
                    }
                }

                Column
                {
                    Text
                    {
                        text: "Remote microphone"
                    }
                    VisualAudioLevel
                    {
                        id: remoteMicrophone
                        color: "orange"
                        width: subRoot.width / 2
                        height: 50

                        Text
                        {
                            anchors.centerIn: parent
                            text: "NOT AVAILABLE"
                        }
                    }
                }
            }
            TextInput
            {
                width: 100
                height: 20
                text: "Socket connection"
            }

            Rectangle
            {
                color: "silver"
                width: parent.width
                height: 30

                Rectangle
                {
                    id: connectionBackground
                    height: parent.height
                    width: 100
                    anchors.right: parent.right
                    color: "blue"
                    Text
                    {
                        id: connectionText
                        anchors.centerIn: parent
                        text: "CONNECT"
                    }
                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked:
                        {
                            if(uvoipDataItem.connected)
                            {
                                uvoipData.requestDisconnect()
                                console.log("Requested to disconnect")
                            }
                            else
                            {
                                uvoipData.requestConnect()
                                console.log("Requested to connect")
                            }
                        }
                    }
                }

                Text
                {
                    id: connectionUrl
                    anchors.verticalCenter: parent.verticalCenter
                    x: 10

                    text: "URL: "
                }
                TextInput
                {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: connectionUrl.right
                    text: "127.0.0.1:1985"

                    Component.onCompleted:
                    {
                        uvoipData.socketUrl = text
                    }

                    onAccepted:
                    {
                        console.log("Enter pressed")
                        uvoipData.socketUrl = text
                    }
                }
            }
        }
    }
}
