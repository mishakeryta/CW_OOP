#include "mainwindow.hpp"
#include "ui_MainWindow.h"

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
