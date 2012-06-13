#ifndef VISUALAUDIOLEVEL_H
#define VISUALAUDIOLEVEL_H

#include <QWidget>

class VisualAudioLevel : public QWidget
{
    Q_OBJECT
public:
    explicit VisualAudioLevel(QWidget *parent = 0);
    void setLevel(qreal value);

protected:
    void paintEvent(QPaintEvent *event);

signals:
    
public slots:
    
private:
    qreal m_level;
};

#endif // VISUALAUDIOLEVEL_H
