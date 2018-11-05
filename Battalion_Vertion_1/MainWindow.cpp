
#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbReadFromFile_clicked()
{
    Battalion battalion;
    try {
        battalion.readFormJson(":/BattalionData.json");
    } catch (ParsingException& exc) {
        QMessageBox::warning(ui->centralWidget,"Проблеми з фалом зберження даних",QString::fromStdString(exc.what()));
    }
    ui->lBattlionName->setText(QString::fromStdString(battalion.getName()));

}
