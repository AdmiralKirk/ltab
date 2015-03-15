#include <QSize>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    renderArea = new RenderArea();

    setCentralWidget(renderArea);

}

QSize MainWindow::sizeHint() const
{
    return QSize(600, 400);
}
