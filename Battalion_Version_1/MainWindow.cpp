#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include "AddNewMilitaryDialog.h"
#include <algorithm>
using namespace std;
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
    QString nameOfFile = "BattalionData.json";
    QFile file(nameOfFile);
    if(!file.exists())
    {
        QMessageBox::critical(this,"Баттальйон відстуній","Файл з даними відсутній, він створився автоматично");
        if(file.open(QIODevice::NewOnly))
        {
            QMessageBox::warning(this, "Проблеми з файлом","Файл з даними не можливо ставорити");
        }
        return;
    }
    try {

        battalion.readFormJson("BattalionData.json");
    } catch (ParsingException& exc) {
        QMessageBox::warning(ui->centralWidget,"Проблеми з фалом зберження даних",exc.what());
    }
    ui->lBattlionName->setText(battalion.getName());
    ui->mtwMilitaries->setMilitaries(battalion.getMilitaries());
}


void MainWindow::on_pbSave_clicked()
{
    QFile jsonFile("BattalionData.json");
    if(!jsonFile.open(QIODevice::WriteOnly))//Відкриття файлу з запитаннями і перевірка чи правильно відкрився
    {
        throw QMessageBox::warning(this,"Проблеми з файлом","Не можливо відкрити файл, можливо, його не існує");
    }
    QJsonDocument jsonBattalion (battalion.toJsonOnject());
    jsonFile.write(jsonBattalion.toJson(QJsonDocument::Indented));
}

void MainWindow::on_pbAdd_clicked()
{
    AddNewMilitaryDialog addDialog;
    int result = addDialog.exec();
    if(result == QDialog::Accepted)
    {
        auto& militaries = battalion.getMilitaries();
        unsigned number = 1;
        if(militaries.size())
        {

            number = (*max_element(militaries.cbegin(),militaries.cend(),[](const Military& m1, const Military& m2)
            {
                return m1.getNumber() < m2.getNumber();
            }
            )).getNumber() + 1;
        }
        Military newMilitary = addDialog.toMilitary();
        newMilitary.setNumber(number);
        battalion.getMilitaries().push_back(newMilitary);
        ui->mtwMilitaries->setMilitaries(battalion.getMilitaries());
    }



}
