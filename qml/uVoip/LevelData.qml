import QtQuick 1.1

Item
{
    id: root
    property real hostMicrophoneLevel: 0
    property real remoteMicrophoneLevel: 0

    Connections
    {
        target: levelData
        onHostMicrophoneLevelChanged:
        {
            root.hostMicrophoneLevel = levelData.hostMicrophoneLevel
        }
        onRemoteMicrophoneLevelChanged:
        {
            root.remoteMicrophoneLevel = levelData.remoteMicrophoneLevel
        }
    }
}
