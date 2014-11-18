#include "projectguiwindow.h"
#include "ui_projectguiwindow.h"

projectGuiWindow::projectGuiWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::projectGuiWindow)
{
    this->setFixedWidth(512);
    this->setFixedHeight(512);
}

projectGuiWindow::~projectGuiWindow()
{
    delete ui;
}
