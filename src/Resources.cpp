#include "Resources.h"
/*
void Resources::fileInventory(const Resources& r){
    ofstream fout("Inventory.csv", ios::app);
    fout << r.name << ", " << r.amount << endl;
    fout.close();
}

void Resources::clearInventory() {
    ofstream fout("Inventory.csv", ios::trunc);
    fout.close();
}

void Resources::fileLocations(const Resources& r, string name, int num){
    ofstream fout("Locations.csv", ios::app);
    fout << num << ", " << name << ", " << r.canSee << endl;
    fout.close();
}

void Resources::clearLocations(){
    ofstream fout("Locations.csv", ios::app);
    fout.close();
}
*/

void Resources::gather() {
    cout << description << endl;
    cout << "You gather " << gatherAmount << " " << name << "." << endl;
    amount += gatherAmount;
}

int Resources::getAmount(){
    return amount;
}

void Resources::subtractAmount(int subtract){
    amount -= subtract;
}

void Resources::setGatherAmount(int num){
    gatherAmount = num;
}

bool Resources::getViewable(){
    return canSee;
}

void Resources::setViewable(){
    canSee = true;
}

ostream& operator<<(ostream &out, const Resources& r){
   out << "-----------------------" << endl;
   out << r.name << " ---- " << r.amount << endl;
   return out;
}
