#ifndef QMILITARYTABLEWIGET_H
#define QMILITARYTABLEWIGET_H

#include <QWidget>
#include <QTableWidget>
#include <Military.hpp>
#include <vector>
class MilitaryTableWidget : public QTableWidget
{
public:
    MilitaryTableWidget(QWidget* perent);
    MilitaryTableWidget& setMilitaries(const std::vector<Military>& militaries);

};

#endif // QMILITARYTABLEWIGET_H
