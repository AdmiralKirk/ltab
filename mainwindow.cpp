#include <QSize>

#include "mainwindow.h"
#include "renderarea.h"

MainWindow::MainWindow()
{
    renderArea = new RenderArea();

    setWindowTitle("ltab");
    setCentralWidget(renderArea);
}

MainWindow::~MainWindow()
{
    delete renderArea;
}

QSize MainWindow::sizeHint() const
{
    return QSize(600, 400);
}
