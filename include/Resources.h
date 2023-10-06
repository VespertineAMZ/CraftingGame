#ifndef RESOURCES_H
#define RESOURCES_H

#include <fstream>
#include "Location.h"

using std::string;
using std::ofstream;
using std::ios;
using std::cout;

class Resources : public Location
{
    public:
        Resources(string l_name, string name, string description):Location(l_name), name(name), description(description), canSee(false), gatherAmount(1), amount(0) {}
        //void fileInventory(const Resources& r);
        //void fileLocations(const Resources& r, string name, int num);
        //void clearInventory();
        //void clearLocations();
        void gather();
        void subtractAmount(int);
        int getAmount();
        void setGatherAmount(int);
        bool getViewable();
        void setViewable();
        friend ostream& operator<<(ostream &out, const Resources& );


    protected:
        string name;
        string description;
        bool canSee;
        int gatherAmount;
        int amount;

};

#endif // RESOURCES_H
