#ifndef LIMITEDDATALISTS_H
#define LIMITEDDATALISTS_H

#include <vector>
#include <string>
using namespace std;
class LimitedDataLists
{
    static LimitedDataLists* data;
    static LimitedDataLists& GetLimitedDataLists();
public:

private:
    vector<string> runks;
    vector<string> ammunitions;
    LimitedDataLists();
    ~LimitedDataLists(){};
};

#endif // LIMITEDDATALISTS_H
