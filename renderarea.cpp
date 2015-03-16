#include <QPainter>
#include <QDebug>
#include <QSize>
#include <QKeyEvent>

#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent), pixelsBetweenStaffLines(10),
    numStaffs(3), staffPositions(numStaffs), blankPixelsOnSide(30)
{
}

void RenderArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    for (int pos : staffPositions)
    {
        drawTabStaff(painter, pos);
    }
}

void RenderArea::drawTabStaff(QPainter &painter, int midPos)
{
    int topPos = midPos - (pixelsBetweenStaffLines * 3);
    int rightSide = width() - blankPixelsOnSide;
    for (int i = 0; i < 6; ++i)
    {
        int yPos = topPos + (i * pixelsBetweenStaffLines);
        painter.drawLine(blankPixelsOnSide, yPos,
                         rightSide, yPos);
    }
    painter.drawLine(blankPixelsOnSide, topPos,
                     blankPixelsOnSide,
                     topPos + (pixelsBetweenStaffLines * 5));
    painter.drawLine(rightSide, topPos,
                     rightSide,
                     topPos + (pixelsBetweenStaffLines * 5));
}

void RenderArea::resizeEvent(QResizeEvent *)
{
    setStaffPositions();
}

void RenderArea::setStaffPositions()
{
    for (int i = 0; i < numStaffs; ++i)
    {
        staffPositions.at(i) = (height() / (numStaffs+1)) * (i+1);
    }
    if (staffPositions.empty())
    {
        staffPositions.push_back(height() / 2);
    }
}

void RenderArea::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_1)
    {
        removeStaff();
    }
    else if (e->key() == Qt::Key_2)
    {
        addStaff();
    }
    else if (e->key() == Qt::Key_3)
    {
        shrinkStaff();
    }
    else if (e->key() == Qt::Key_4)
    {
        widenStaff();
    }
    update();
}

void RenderArea::removeStaff()
{
    if (numStaffs > 1)
    {
        --numStaffs;
        staffPositions.pop_back();
        setStaffPositions();
    }
}

void RenderArea::addStaff()
{
    ++numStaffs;
    staffPositions.push_back(0);
    setStaffPositions();
}

void RenderArea::shrinkStaff()
{
    if (pixelsBetweenStaffLines > 0)
    {
        pixelsBetweenStaffLines -= 1;
    }
}

void RenderArea::widenStaff()
{
    pixelsBetweenStaffLines += 1;
}
