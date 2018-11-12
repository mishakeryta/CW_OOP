#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include "AddNewMilitaryDialog.h"
#include <algorithm>
#include <utility>
#include "Converter.hpp"
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
    ui->lBattlionName->setText("Назва батальйону" + battalion.getName());
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

void MainWindow::on_actionSave_triggered()
{
    on_pbSave_clicked();
}


void MainWindow::on_actionPrevSave_triggered()
{
    on_pbReadFromFile_clicked();
}
void MainWindow::on_actionAddNewMilitary_triggered()
{
    on_pbAdd_clicked();

}

void MainWindow::on_action_task3_triggered()
{

}
void MainWindow::showThatSuit(QString& condtionText,function<bool(const Military&)> condition)
{
    QString output =condtionText;

    vector<Military> suitMilitary = battalion.getMilitaries(condition);
    output+= Converter::toString(suitMilitary.begin(),suitMilitary.end(),[](const Military& military){
        return "Боєць №" + QString::number(military.getNumber())+ ": " + military.getSurname() + " " +military.getName() + "\n";
    });
    ui->pteOutput->setPlainText(output);
}
void MainWindow::on_action_task3_1_triggered()
{
    QString conditionText = "Бійці ,які мають більше однієї одиниці зброї:\n";
    auto condition = [](const Military& military)
    {
        if(military.getAmmunition().size() > 1) return true;
        return false;
    };
    showThatSuit(conditionText,condition);
}

void MainWindow::on_action_task3_2_triggered()
{
    QString conditionText = "Бійці ,які  мають АК-47 і гранатомет:\n";
    auto condition = [](const Military& military)
    {
        const vector<QString>& ammunition = military.getAmmunition();
        if(ammunition.size() <2) return false;
        char wasAk47AndGL = false;
        for(const auto& weapon:ammunition)
        {
            if(weapon == "AK-47"){
                ++wasAk47AndGL;
                break;
            }
        }

        set<QString> allGrenadeLaunchers = LimitedDataLists::Get().getGrenageLauncher();
        for(const auto& weapon:ammunition)
        {
            if(allGrenadeLaunchers.find(weapon) != allGrenadeLaunchers.end()) {
                ++wasAk47AndGL;
                break;
            }
        }
        if(wasAk47AndGL != 2) return false;
        return true;
     };
    showThatSuit(conditionText,condition);
}

void MainWindow::on_action_task3_3_triggered()
{
    QString conditionText = "Бійці, які мають пістолет і будь-який автомат:\n";
    auto condition = [](const Military& military)
    {
        const vector<QString>& ammunition = military.getAmmunition();
        if(ammunition.size() <2) return false;
        char wasAutoAndPist= 0;
        set<QString> allPistols = LimitedDataLists::Get().getPistols();
        for(const auto& weapon:ammunition)
        {
            if(allPistols.find(weapon) != allPistols.end()) {
                ++wasAutoAndPist;
                break;
            }
        }

        set<QString> allAutomatic = LimitedDataLists::Get().getAutomatic();
        for(const auto& weapon:ammunition)
        {
            if(allAutomatic.find(weapon) != allAutomatic.end()) {
                ++wasAutoAndPist;
                break;
            }
        }
        if(wasAutoAndPist != 2) return false;
        return true;
     };
     showThatSuit(conditionText,condition);
}

void MainWindow::on_action_task4_triggered()
{
     QString conditionText = "Бійці ,які мають першу групу крові резус мінус і четверту групу резус плюс віком до 25 років:\n";
     auto condition = [](const Military& military)
     {
        if((military.getBloodType() != "4+" && military.getBloodType() != "1-") || military.getAge()> 25)
        {
            return false;
        }
        return true;
     };
     showThatSuit(conditionText,condition);
}

void MainWindow::on_action_task5_triggered()
{
    QString conditionText = "Рядові віком до 20 років без боєкомплекту\n";
    auto condition = [](const Military& military)
    {
        if((military.getRunk() != "Солдат"  && military.getRunk() != "Старший солдат") || military.getAmmunition().size()) return false;
        return true;
    };
    showThatSuit(conditionText,condition);
}

void MainWindow::on_actionTask1_triggered()
{
    QString output;
    vector<Military> sortedMilitaries = battalion.getMilitaries();
    std::sort(sortedMilitaries.begin(),sortedMilitaries.end(),[](const Military& m1,const Military& m2)
    {
        return m1.getRunk() < m2.getRunk();
    });
    QString prevRunk;
    size_t count = 0;
    for(const auto& military:sortedMilitaries)
    {
        if(military.getRunk() != prevRunk)
        {
            prevRunk = military.getRunk();
            output+= "Бійці зі званням " + prevRunk + ":\n";
        }
        output += "Боєць №" + QString::number(military.getNumber())+ ": " + military.getSurname() + " " +military.getName() + "\n";
        count += military.getAmmunition().size();
    }
    output+= "Кількість одиниць озброєння: "+QString::number(count) + "\n";
    ui->pteOutput->setPlainText(output);
}


void MainWindow::on_actionTask2_triggered()
{
    QString output;
    map<QString,pair<size_t,size_t>> runksAgeData;
    size_t sumOfAge = 0;
    vector<Military>& militaries = battalion.getMilitaries();
    for(const auto& military:militaries)
    {
        if(runksAgeData.find(military.getRunk()) != runksAgeData.end())
        {
            ++runksAgeData[military.getRunk()].second;
        }
        else
        {
            runksAgeData[military.getRunk()].first = 0;
            runksAgeData[military.getRunk()].second = 1;
        }
        runksAgeData[military.getRunk()].first+= military.getAge();
        sumOfAge += military.getAge();
    }
    if(militaries.size())
    {
        output += "Середні вік усіх солдатів: " +QString::number(sumOfAge/militaries.size())+'\n';
    }
    else
    {
        output +="Батальйон пустий\n";
    }
    for(const auto& runkData:runksAgeData)
    {
        output += "Середній вік солдатів з рангом " + runkData.first + ": " +
                QString::number(static_cast<double>(runkData.second.first)/runkData.second.second) + "\n";

    }
    ui->pteOutput->setPlainText(output);
}
