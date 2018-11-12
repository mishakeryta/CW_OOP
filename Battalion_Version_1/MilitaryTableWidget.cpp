#include "MilitaryTableWidget.hpp"
#include <vector>
#include <string>
#include <QString>
#include <algorithm>
#include "Converter.hpp"
MilitaryTableWidget::MilitaryTableWidget(QWidget* perent):QTableWidget (perent)
{

    std::vector<QString> columnNames = {"№"  ,   "Прізвище"   ,   "Ім‘я"   , "вік"   ,  "група крові"  ,  "звання"  ,  "боєкомплект "  };
    setColumnCount(static_cast<int>(columnNames.size()));
    for(size_t i = 0; i < columnNames.size();++i)
    {
        setHorizontalHeaderItem(static_cast<int>(i),new QTableWidgetItem(columnNames[i]));
    }
    setEditTriggers(QAbstractItemView::NoEditTriggers);
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
            new QTableWidgetItem(militaries[row].getSurname()),
            new QTableWidgetItem(militaries[row].getName()),
            new QTableWidgetItem(QString::number(militaries[row].getAge())),
            new QTableWidgetItem(militaries[row].getBloodType()),
            new QTableWidgetItem(militaries[row].getRunk()),
        };
        QString listOfAmmunitions = accumulate(militaries[row].getAmmunition().begin(),
                                              militaries[row].getAmmunition().end(),
                                              QString(),[](const QString& item1,const QString& item2)
        {
            return item1 + '\n' + item2;
        });

        rowItems.push_back(new QTableWidgetItem(listOfAmmunitions));
        for(size_t column = 0; column < rowItems.size();++column)
        {
            setItem(static_cast<int>(row),static_cast<int>(column),rowItems[column]);
        }
        resizeRowToContents(static_cast<int>(row));
    }

    return *this;
}
