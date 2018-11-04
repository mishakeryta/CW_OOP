#ifndef LIMITEDDATALISTS_H
#define LIMITEDDATALISTS_H

#include <vector>
#include <string>
using namespace std;
class LimitedDataLists
{
    static LimitedDataLists* data;

public:
    static LimitedDataLists& LimitedDataListsSingletone();

    const vector<string>& getMilitaryProperties()const{return militaryProperties;}
private:
    vector<string> runks;
    vector<string> ammunitions;
    vector<string> militaryProperties;
    LimitedDataLists();
    ~LimitedDataLists(){}
};

#endif // LIMITEDDATALISTS_H
