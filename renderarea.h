#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPainter>

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    RenderArea();

protected:
    void paintEvent(QPaintEvent *event);

private:
    int pixelsBetweenStaffLines;

    void drawTabStaff(QPainter &painter, int topPixel);

};

#endif // RENDERAREA_H
