#ifndef LIMITEDDATALISTS_H
#define LIMITEDDATALISTS_H

#include <vector>
#include <string>
#include <set>
#include <QString>
using namespace std;
class LimitedDataLists
{
    static LimitedDataLists* data;

public:
    static LimitedDataLists& Get();
    const vector<QString> &getMilitaryProperties()const{return militaryProperties;}
    const vector<QString>& getBloodTypes() const { return bloodTypes;}
    const vector<QString>& getRunks() const {return runks;}
    const set<QString>& getAutomatic() const { return  automatic;}
    const set<QString>& getPistols() const { return pistols;}
    const set<QString>& getGrenageLauncher() const { return grenadeLauncher; }
private:
    vector<QString> runks;
    vector<QString> bloodTypes;
    set<QString> automatic;
    set<QString> pistols;
    set<QString> grenadeLauncher;
    vector<QString> militaryProperties;
    LimitedDataLists();
    ~LimitedDataLists(){}
};

#endif // LIMITEDDATALISTS_H
