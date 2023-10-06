#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>

using std::ostream;
using std::string;
using std::endl;

class Location {
    public:
      Location(string name) : name(name){}
      friend ostream& operator<<(ostream &out, const Location& );

    protected:
        string name;

};

#endif // LOCATION_H
