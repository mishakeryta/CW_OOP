#ifndef LIMITEDDATALISTS_H
#define LIMITEDDATALISTS_H

#include <vector>
#include <string>
using namespace std;
class LimitedDataLists
{
    static LimitedDataLists* data;

public:
    static LimitedDataLists& Get();

    const vector<string>& getMilitaryProperties()const{return militaryProperties;}
    const vector<string>& getBloodTypes() const { return bloodTypes;}
private:
    vector<string> runks;
    vector<string> bloodTypes;
    vector<string> ammunitions;
    vector<string> militaryProperties;
    LimitedDataLists();
    ~LimitedDataLists(){}
};

#endif // LIMITEDDATALISTS_H
