import QtQuick 1.1

Item
{
    id: root
    property real hostMicrophoneLevel: 0
    property real remoteMicrophoneLevel: 0
    property bool clientConnected: false
    property bool serverConnected: false
    property bool clientConnectionFailed: false

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

        onClientConnectedChanged:
        {
            root.clientConnected = uvoipData.clientConnected
        }

        onServerConnectedChanged:
        {
            root.serverConnected = uvoipData.serverConnected
        }
    }
}
