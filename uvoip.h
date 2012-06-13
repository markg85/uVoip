#ifndef UVOIP_H
#define UVOIP_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "visualaudiolevel.h"
#include "audiostream.h"
#include "audioplayback.h"

class UVoip : public QMainWindow
{
    Q_OBJECT
public:
    explicit UVoip(QWidget *parent = 0);

    void initializeLayout();
    void initializeMicrophone();
    
signals:
    
public slots:
    void toggleRecord();
    void togglePlayback();
    void refreshMicSoundLevel();

private:
    QHBoxLayout* m_hLayout;
    QVBoxLayout* m_vLayoutLeft;
    QVBoxLayout* m_vLayoutRight;

    QPushButton* m_recordMicrophone;
    QPushButton* m_playbackMicrophone;
    
    VisualAudioLevel* m_audioLevelLeft;
    VisualAudioLevel* m_audioLevelRight;

    AudioStream* m_stream;
    AudioPlayback* m_playback;

    bool isRecording;
    bool isPlaying;
};

#endif // UVOIP_H
