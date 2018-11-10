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

    try {
        battalion.readFormJson(":/BattalionData.json");
    } catch (ParsingException& exc) {
        QMessageBox::warning(ui->centralWidget,"Проблеми з фалом зберження даних",QString::fromStdString(exc.what()));
    }
    ui->lBattlionName->setText(QString::fromStdString(battalion.getName()));
    ui->mtwMilitaries->setMilitaries(battalion.getMilitaries());
}


void MainWindow::on_pbSave_clicked()
{
    QFile jsonFile(":/BattalionData.json");
    if(!jsonFile.open(QIODevice::ReadOnly))//Відкриття файлу з запитаннями і перевірка чи правильно відкрився
    {
        throw QMessageBox::warning(this,"Проблеми з файлом","Не можливо відкрити файл, можливо, його не існує");
    }
    Military newMilitary(battalion.getMilitary(battalion.getMilitaries().size()-1));
    battalion.getMilitaries().push_back(newMilitary.setNumber(newMilitary.getNumber()+1));
    QJsonDocument jsonBattalion (battalion.toJsonOnject());
    jsonFile.write(jsonBattalion.toJson(QJsonDocument::Indented));
}
