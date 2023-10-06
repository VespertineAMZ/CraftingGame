#include "Location.h"

ostream& operator<<(ostream &out, const Location& l){
   out << "You are in the " << l.name << endl;
   return out;
}
