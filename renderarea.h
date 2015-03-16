#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <vector>
#include <QWidget>
#include <QPainter>

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    explicit RenderArea(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int pixelsBetweenStaffLines;
    int numStaffs;
    std::vector<int> staffPositions;

    void drawTabStaff(QPainter &painter, int topPixel);
    void resizeEvent(QResizeEvent *);
    void setStaffPositions();
};

#endif // RENDERAREA_H
