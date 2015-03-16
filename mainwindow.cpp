#include <QSize>

#include "mainwindow.h"
#include "renderarea.h"

MainWindow::MainWindow()
{
    renderArea = new RenderArea(this);

    setWindowTitle("ltab");
    setCentralWidget(renderArea);

    resize(QSize(600, 400));
}

MainWindow::~MainWindow()
{
    delete renderArea;
}
