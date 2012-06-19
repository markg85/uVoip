import QtQuick 1.1

Rectangle
{
    id: root
    width: 400
    height: 200

    LevelData
    {
        id: levelDataItem
        onHostMicrophoneLevelChanged:
        {
            hostMicrophone.micLevel = hostMicrophoneLevel
        }
        onRemoteMicrophoneLevelChanged:
        {
            remoteMicrophone.micLevel = remoteMicrophoneLevel
        }
    }

    Item
    {
        id: subRoot
        width: parent.width - 22
        y: 10
        anchors.horizontalCenter: parent.horizontalCenter

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
    }
}
