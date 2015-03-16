#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

#include "renderarea.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    RenderArea *renderArea;

    void keyPressEvent(QKeyEvent *);
};

#endif // MAINWINDOW_H
