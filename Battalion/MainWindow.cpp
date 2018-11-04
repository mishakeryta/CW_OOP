#include "MainWindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Battalion battalion;
    battalion.readFormJson(":/BattalionData.json");
}

MainWindow::~MainWindow()
{
    delete ui;
}
