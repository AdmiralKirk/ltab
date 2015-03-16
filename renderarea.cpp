#include <QPainter>

#include "renderarea.h"

RenderArea::RenderArea()
{
    pixelsBetweenStaffLines = 10;
}

void RenderArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    drawTabStaff(painter, 100);
}

void RenderArea::drawTabStaff(QPainter &painter, int topPixel)
{
    int numLines = 6;
    for (int i = 0; i < numLines; i++)
    {
        int currentY = topPixel + (i * pixelsBetweenStaffLines);
        painter.drawLine(0, currentY, width(), currentY);
    }
}

//void RenderArea::drawFrenchTabNote(QPainter &painter, )
