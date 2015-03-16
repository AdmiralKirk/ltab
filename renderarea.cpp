#include <QPainter>
#include <QDebug>
#include <QSize>

#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent), pixelsBetweenStaffLines(10),
    numStaffs(1), staffPositions(numStaffs)
{
}

void RenderArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    for (int pos : staffPositions)
    {
        drawTabStaff(painter, pos);
    }

    for (auto p : staffPositions)
    {
        qDebug() << p;
    }
}

void RenderArea::drawTabStaff(QPainter &painter, int midPos)
{
    int topPos = midPos - (pixelsBetweenStaffLines * 3);
    for (int i = 0; i < 6; ++i)
    {
        int yPos = topPos + (i * pixelsBetweenStaffLines);
        painter.drawLine(0, yPos, width(), yPos);
    }
}

void RenderArea::resizeEvent(QResizeEvent *)
{
    setStaffPositions();
}

void RenderArea::setStaffPositions()
{
    for (int i = 0; i < numStaffs; ++i)
    {
        int j = i+1;
        staffPositions.at(i) = (height() / (numStaffs+1)) * j;
    }
}
