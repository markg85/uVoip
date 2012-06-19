import QtQuick 1.1

Item
{
    id: root
    property real hostMicrophoneLevel: 0
    property real remoteMicrophoneLevel: 0
    property bool connected: false

    Connections
    {
        target: uvoipData
        onHostMicrophoneLevelChanged:
        {
            root.hostMicrophoneLevel = uvoipData.hostMicrophoneLevel
        }
        onRemoteMicrophoneLevelChanged:
        {
            root.remoteMicrophoneLevel = uvoipData.remoteMicrophoneLevel
        }

        onConnectedChanged:
        {
            root.connected = uvoipData.connected
        }
    }
}
