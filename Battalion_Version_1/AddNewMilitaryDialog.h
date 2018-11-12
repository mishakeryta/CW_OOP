#ifndef ADDNEWMILITARYDIALOG_H
#define ADDNEWMILITARYDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QLineEdit>
#include <set>
#include <string>
#include <functional>
#include <array>
#include "Military.hpp"
namespace Ui {
class AddNewMilitaryDialog;
}

class AddNewMilitaryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewMilitaryDialog(QWidget *parent = nullptr);
    ~AddNewMilitaryDialog();
    Military toMilitary() const;
private slots:
    void on_leSurname_textChanged(const QString &text);

    void on_leAge_textChanged(const QString &arg1);

    void on_leName_textChanged(const QString &arg1);

private:
    void addIfChecked(vector<QString>& dest,QListWidget& source) const;
    std::array<bool,3> correctness;
    char numberOfComplete = 3;
    void validateText(const QString& input,std::function<bool(const QString&)> check,QLineEdit& elInputSource,bool& isCorrect);
    void fillWithCheckBox(QListWidget& lwDestination,const std::set<QString>& source);
    Ui::AddNewMilitaryDialog *ui;
};


#endif // ADDNEWMILITARYDIALOG_H
