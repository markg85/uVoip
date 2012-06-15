#include "visualaudiolevel.h"
#include <QPainter>

VisualAudioLevel::VisualAudioLevel(QWidget *parent) :
    QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    m_level = 0;
    setMinimumHeight(30);
    setMinimumWidth(200);
}

void VisualAudioLevel::setLevel(qreal value)
{
    m_level = value;
    repaint();
}

void VisualAudioLevel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setPen(Qt::black);
    painter.drawRect(QRect(painter.viewport().left()+10,
                           painter.viewport().top()+10,
                           painter.viewport().right()-20,
                           painter.viewport().bottom()-20));
    if (m_level == 0.0)
        return;

    painter.setPen(Qt::red);
    painter.setBrush(QBrush(Qt::red));

    int pos = ((painter.viewport().right()-20)-(painter.viewport().left()+11))*m_level;

    painter.drawRect(QRect(painter.viewport().left()+10 + 1,
                           painter.viewport().top()+10 + 1,
                           painter.viewport().left()+10 + pos - 1,
                           painter.viewport().bottom()-20 - 2));
}
