#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <vector>
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    explicit RenderArea(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int pixelsBetweenStaffLines;
    int numStaffs;
    std::vector<int> staffPositions;

    void drawTabStaff(QPainter &painter, int topPixel);
    void resizeEvent(QResizeEvent *);
    void setStaffPositions();
    void removeStaff();
    void addStaff();
    void shrinkStaff();
    void widenStaff();
};

#endif // RENDERAREA_H
