#include "uvoip.h"

#include <QLabel>
#include <QDebug>

UVoip::UVoip(QWidget *parent)
    : QMainWindow(parent)
    , m_hLayout()
    , m_vLayoutLeft()
    , m_vLayoutRight()
    , m_recordMicrophone()
    , m_playbackMicrophone()
    , m_audioLevelLeft()
    , m_audioLevelRight()
    , m_stream()
    , m_playback()
    , isRecording(false)
    , isPlaying(false)
{
    initializeLayout();
    m_playback = new AudioPlayback();
}

void UVoip::initializeLayout()
{
    QScopedPointer<QWidget> window(new QWidget);

    // Layout objects
    m_hLayout = new QHBoxLayout();
    m_vLayoutLeft = new QVBoxLayout();
    m_vLayoutRight = new QVBoxLayout();

    // Widgets to display the audio level
    m_audioLevelLeft = new VisualAudioLevel();
    m_audioLevelRight = new VisualAudioLevel();

    // Buttons
    m_recordMicrophone = new QPushButton("Record Micorphone");
    connect(m_recordMicrophone, SIGNAL(clicked()), this, SLOT(toggleRecord()));

    m_playbackMicrophone = new QPushButton("Playback Microphone");
    connect(m_playbackMicrophone, SIGNAL(clicked()), this, SLOT(togglePlayback()));

    // Fill the left part
    m_vLayoutLeft->addWidget(m_audioLevelLeft);
    m_vLayoutLeft->addWidget(m_recordMicrophone);

    // Fill the right part
    m_vLayoutRight->addWidget(m_audioLevelRight);
    m_vLayoutRight->addWidget(m_playbackMicrophone);

    // put everything together
    m_hLayout->addLayout(m_vLayoutLeft);
    m_hLayout->addLayout(m_vLayoutRight);

    window->setLayout(m_hLayout);
    setCentralWidget(window.data());
    QWidget *const windowPtr = window.take(); // ownership transferred
    windowPtr->show();

    initializeMicrophone();
}

void UVoip::initializeMicrophone()
{
    m_stream = new AudioStream(this);
    connect(m_stream, SIGNAL(update()), SLOT(refreshMicSoundLevel()));
}

void UVoip::toggleRecord()
{
    if(isRecording)
    {
        m_stream->stop();
        m_recordMicrophone->setText("Record Microphone");
    }
    else
    {
        // We are not recording. We start recording here and set the button text to "Stop recording".
        m_stream->start("");
        m_recordMicrophone->setText("Stop recording");
    }

    isRecording = !isRecording;

    qDebug() << "toggleRecord pressed...";
}

void UVoip::togglePlayback()
{
    if(isPlaying)
    {
        m_playbackMicrophone->setText("Playback Microphone");
    }
    else
    {
        m_playback->startPlaying();
        m_playbackMicrophone->setText("Stop playing");
    }

    isPlaying = !isPlaying;

    qDebug() << "togglePlayback pressed...";
}

void UVoip::refreshMicSoundLevel()
{
    m_audioLevelLeft->setLevel(m_stream->level());
}
