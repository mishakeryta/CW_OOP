#include "AddNewMilitaryDialog.h"
#include "ui_AddNewMilitaryDialog.h"
#include "LimitedDataLists.hpp"
#include <QListWidgetItem>
#include <QPushButton>
#include <string>
#include "Military.hpp"
using namespace std;
//конструктор діалогу додавання нового елементу
AddNewMilitaryDialog::AddNewMilitaryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewMilitaryDialog)
{
    ui->setupUi(this);
    const vector<QString>& allRunks = LimitedDataLists::Get().getRunks();
    for(const auto& runk:allRunks)
    {
        ui->cbRunk->addItem(runk);
    }
    const vector<QString>& allBloodTypes = LimitedDataLists::Get().getBloodTypes();
    for(const auto& bloodType:allBloodTypes)
    {
        ui->cbBloodType->addItem(bloodType);
    }
    ui->bubOk->button(QDialogButtonBox::Ok)->setEnabled(false);
    fillWithCheckBox(*ui->lwAutomatic,LimitedDataLists::Get().getAutomatic());
    fillWithCheckBox(*ui->lwPistols,LimitedDataLists::Get().getPistols());
    fillWithCheckBox(*ui->lwGrenadeLaunchers,LimitedDataLists::Get().getGrenageLauncher());
}

AddNewMilitaryDialog::~AddNewMilitaryDialog()
{
    delete ui;
}
void AddNewMilitaryDialog::fillWithCheckBox(QListWidget& lwDestination,const set<QString>& source)
{
    for(const auto& item:source)
    {
        QListWidgetItem* listItem = new QListWidgetItem(item);
        listItem->setCheckState(Qt::Unchecked);
        lwDestination.addItem(listItem);
    }
}

void AddNewMilitaryDialog::on_leSurname_textChanged(const QString &surname)
{
    validateText(surname,Military::isSurnameOrName,*ui->leSurname,correctness[0]);
}
void AddNewMilitaryDialog::validateText(const QString& input,std::function<bool(const QString&)>check,QLineEdit& elInputSource,bool& isCorrect)
{
    if(!input.size())
    {
        elInputSource.setStyleSheet("");
        isCorrect = false;
        ui->bubOk->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
    else if(check(input))
    {
        elInputSource.setStyleSheet("");
        isCorrect = true;
        for(size_t i = 0; i < correctness.size();++i)
        {
            if(!correctness[i]) return;
        }
        ui->bubOk->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
    else
    {
        elInputSource.setStyleSheet("background-color: rgb(255, 200, 200);");
        isCorrect = false;
        ui->bubOk->button(QDialogButtonBox::Ok)->setEnabled(false);
    }




}
void AddNewMilitaryDialog::on_leName_textChanged(const QString &name)
{
    validateText(name,Military::isSurnameOrName,*ui->leName,correctness[1]);
}


void AddNewMilitaryDialog::on_leAge_textChanged(const QString &age)
{
    validateText(age,[](const QString& age){
          for(int i = 0; i < age.size();++i)
          {
              if(!age[i].isDigit())
                  return false;
          }
          return true;
    },
    *ui->leAge,correctness[2]);
}
Military AddNewMilitaryDialog::toMilitary() const
{
    Military newMilitary;
    newMilitary.setSurname(ui->leSurname->text());
    newMilitary.setName(ui->leName->text());
    newMilitary.setAge(ui->leAge->text().toUInt());
    newMilitary.setBloodType(ui->cbBloodType->currentText());
    newMilitary.setRunk(ui->cbRunk->currentText());
    addIfChecked(newMilitary.getAmmunition(),*ui->lwAutomatic);
    addIfChecked(newMilitary.getAmmunition(),*ui->lwPistols);
    addIfChecked(newMilitary.getAmmunition(),*ui->lwGrenadeLaunchers);
    return newMilitary;
}
void AddNewMilitaryDialog::addIfChecked(vector<QString>& dest,QListWidget& source) const
{
    for(int row = 0; row < source.count();++row)
    {
        if(source.item(row)->checkState() == Qt::Checked)
        {
            dest.push_back(source.item(row)->text());
        }
    }
}
