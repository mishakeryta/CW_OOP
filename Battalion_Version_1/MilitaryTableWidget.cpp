#include "MilitaryTableWidget.hpp"
#include <vector>
#include <string>
#include <QString>
#include <algorithm>
#include "Converter.hpp"
MilitaryTableWidget::MilitaryTableWidget(QWidget* perent):QTableWidget (perent)
{

    std::vector<std::string> columnNames = {"№"  ,   "Прізвище"   ,   "Ім‘я"   , "вік"   ,  "група крові"  ,  "звання"  ,  "боєкомплект "  };
    setColumnCount(static_cast<int>(columnNames.size()));
    for(size_t i = 0; i < columnNames.size();++i)
    {
        setHorizontalHeaderItem(static_cast<int>(i),new QTableWidgetItem(QString::fromStdString(columnNames[i])));
    }
}

MilitaryTableWidget& MilitaryTableWidget::setMilitaries(const vector<Military>& militaries)
{
    setRowCount(static_cast<int>(militaries.size()));

    for(size_t row = 0; row < militaries.size();++row)
    {
        // items with property of military
        vector<QTableWidgetItem*> rowItems =
        {
            new QTableWidgetItem(QString::number(militaries[row].getNumber())),
            new QTableWidgetItem(QString::fromStdString(militaries[row].getSurname())),
            new QTableWidgetItem(QString::fromStdString(militaries[row].getName())),
            new QTableWidgetItem(QString::number(militaries[row].getAge())),
            new QTableWidgetItem(QString::fromStdString(militaries[row].getBloodType())),
            new QTableWidgetItem(QString::fromStdString(militaries[row].getRunk())),
        };
        string listOfAmmunitions = accumulate(militaries[row].getAmmunition().begin(),
                                              militaries[row].getAmmunition().end(),
                                              string(),[](const string& item1,const string& item2)
        {
            return item1 + '\n' + item2;
        });
        rowItems.push_back(new QTableWidgetItem(QString::fromStdString(listOfAmmunitions)));
        for(size_t column = 0; column < rowItems.size();++column)
        {
            setItem(static_cast<int>(row),static_cast<int>(column),rowItems[column]);
        }

    }

    return *this;
}
