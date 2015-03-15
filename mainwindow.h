#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "renderarea.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    QSize sizeHint() const;

private:
    RenderArea *renderArea;
};

#endif // MAINWINDOW_H
