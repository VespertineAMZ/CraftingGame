#include <iostream>
#include <vector>
#include "Location.h"
#include "Resources.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

enum MainChoices {GATHER = 1, MAKE, EXPLORE, QUIT};
enum GatherChoices {FOREST = 1, CAVE, VILLAGE};
enum itemsNumbered {BRIDGE=3, SHOVEL, TORCH, HOOK, BOAT};
string itemsCraftable[9] = {"Axe", "Mining Pick", "Bag", "Bridge", "Shovel", "Torch", "Grappling Hook", "Boat", "Nothing"};
string itemsDescription[9] = {" --- Gather more wood --- 5 wood, 5 iron", " --- Gather more iron --- 20 wood, 5 iron", " --- Gather more cloth --- 5 cloth", " --- 4 wood", " --- 3 wood, 3 iron", " --- 5 wood, 5 cloth", " --- 20 cloth, 10 iron", " --- 20 wood, 20 cloth", " "};
bool itemsMade[9] = {false, false, false, false, false, false, false, false, false};
const int ARRAYSIZE = 9;
int menu();
void makeMenu(string a[], bool b[], string c[], vector<string> &vect, vector<int> &vect2, const int ARRAYSIZE);

int main()
{
     Resources forest("Forest Path", "Wood", "Large trees with knotted branches surround you.");
     forest.setViewable();
     Resources cave("Forgotten Cave", "Iron", "It's cool and dark, and water trickles down the rough stone walls.");
     Resources village("Abandoned Village", "Cloth", "The houses are run down and empty. Nobody lives here anymore.");

     //forest.fileInventory(forest);

      vector<string> items;
      vector<int> itemID;

     int choice;
     int gatherChoice;
     int makeChoice;

     int explore = 0;

      do{
        cout << endl << "Inventory" << endl;
        cout << forest;
        cout << cave;
        cout << village;
        cout << "-----------------------" << endl << endl;
        choice = menu();
        switch(choice){
            case GATHER:
                cout << "Where would you like to gather?" << endl;
                    if(forest.getViewable()){
                        cout << "1. Forest Path" << endl;
                    }
                    if(cave.getViewable()){
                        cout << "2. Forgotten Cave" << endl;
                    }
                    if(village.getViewable()){
                        cout << "3. Abandoned Village" << endl;
                    }
                    cin >> gatherChoice;
                    cin.ignore();

                    switch(gatherChoice){
                        case FOREST:
                            if(forest.getViewable()){
                                forest.gather();
                            }
                            else{
                                cout << "You haven't discovered this area yet." << endl;
                            }
                        break;

                        case CAVE:
                            if(cave.getViewable()){
                                cave.gather();
                            }
                            else{
                                cout << "You haven't discovered this area yet." << endl;
                            }
                        break;

                        case VILLAGE:
                            if(village.getViewable()){
                                village.gather();
                            }
                            else {
                                cout << "You haven't discovered this area yet." << endl;

                            }
                        break;

                        default:
                            cout << "That's not a valid area." << endl;
                        break;

                    }
            break;

            case MAKE:
               makeMenu(itemsCraftable, itemsMade, itemsDescription, items, itemID, ARRAYSIZE);
                cout << "What would you like to make?" << endl;
                for(int i = 0; i < items.size(); i++){
                        cout << i+1 << ". " << items[i] << endl;
                }
                cin >> makeChoice;
                cin.ignore();

                switch(itemID[makeChoice - 1]){
                    case 0:
                        if(forest.getAmount() >= 5 && cave.getAmount() >= 5){
                            itemsMade[0] = true;
                            forest.subtractAmount(5);
                            cave.subtractAmount(5);
                            forest.setGatherAmount(5);
                            cout << "You have made an Axe.";
                        }
                        else{
                            cout << "You don't have enough to make that.";
                        }
                    break;

                    case 1:
                        if(forest.getAmount() >= 20 && cave.getAmount() >= 5){
                            itemsMade[1] = true;
                            forest.subtractAmount(20);
                            cave.subtractAmount(5);
                            cave.setGatherAmount(5);
                            cout << "You have made a Mining Pick.";
                        }
                        else{
                            cout << "You don't have enough to make that.";
                        }
                    break;

                    case 2:
                        if(village.getAmount() >= 5){
                            itemsMade[2] = true;
                            village.subtractAmount(5);
                            village.setGatherAmount(5);
                            cout << "You have made a Bag.";
                        }
                        else{
                            cout << "You don't have enough to make that.";
                        }
                    break;

                    case 3:
                         if(forest.getAmount() >= 4){
                            itemsMade[3] = true;
                            forest.subtractAmount(4);
                            cout << "You have made a Bridge.";
                        }
                        else{
                            cout << "You don't have enough to make that.";
                        }
                    break;

                    case 4:
                        if(forest.getAmount() >= 3 && cave.getAmount() >= 3){
                            itemsMade[4] = true;
                            forest.subtractAmount(3);
                            cave.subtractAmount(3);
                            cout << "You have made a Shovel.";
                        }
                        else{
                            cout << "You don't have enough to make that.";
                        }
                    break;

                    case 5:
                        if(forest.getAmount() >= 5 && village.getAmount() >= 5){
                            itemsMade[5] = true;
                            village.subtractAmount(5);
                            forest.subtractAmount(5);
                            cout << "You have made a Torch.";
                        }
                        else{
                            cout << "You don't have enough to make that.";
                        }
                    break;

                    case 6:
                        if(cave.getAmount() >= 10 && village.getAmount() >= 20){
                            itemsMade[6] = true;
                            cave.subtractAmount(10);
                            village.subtractAmount(20);
                            cout << "You have made a Grappling Hook.";
                        }
                        else{
                            cout << "You don't have enough to make that.";
                        }
                    break;

                    case 7:
                        if(forest.getAmount() >= 20 && village.getAmount() >= 20){
                            itemsMade[7] = true;
                            forest.subtractAmount(20);
                            village.subtractAmount(20);
                            cout << "You have made a Boat.";
                        }
                        else{
                            cout << "You don't have enough to make that.";
                        }

                    break;

                    case 8:
                        cout << "Back" << endl;
                    break;

                    default:
                        cout << "That's not a valid item." << endl;

                }

                items.clear();
                itemID.clear();


            break;

            case EXPLORE:
                switch(explore){
                    case 0:
                        cout << "A crevice in the earth spans across the path ahead. It's impossible to jump over without falling into the darkness." << endl;
                        if(itemsMade[BRIDGE]){
                            cout << "You place a bridge across the crevice, and manage to cross safely. You now pass through a cave rich with iron, but a pile of stones blocks the path ahead. They'll need to be dug away." << endl;
                            explore += 1;
                            cave.setViewable();
                        }
                    break;

                    case 1:
                        cout << "You're in a cave dark and winding, and a pile of stones block the path ahead. They'll need to be dug away." << endl;
                        if(itemsMade[SHOVEL]){
                            cout << "With much toil you dig the stones away, and are able to proceed. A little village is ahead, you call, but no one answers. It's then that you notice the houses are all in a state of decay. The path ahead is covered in thorny brambles." << endl;
                            explore += 1;
                            village.setViewable();
                        }
                    break;

                    case 2:
                        cout << "Brambles cover the path ahead, thick, and covered with sharp thorns. Blades won't be enough to make your way past them. They must be burned." << endl;
                        if(itemsMade[TORCH]){
                            cout << "Lifting your torch, you set the thorny brambles ablaze. They crackle with an orange glow until they burn away to ash. The path ahead is cleared but it leads to a steep cliff." << endl;
                            explore += 1;
                        }
                    break;

                    case 3:
                        cout << "A cliff looms above you, steep and foreboding. It wouldn't be safe to climb with your bare hands." << endl;
                        if(itemsMade[HOOK]){
                            cout << "Your grappling hook is swung until it lodges itself in the top of the cliff. The rope makes it far easier to climb. At the top a lake with crystal clear waters blocks the way forward." << endl;
                            explore += 1;
                        }
                    break;

                    case 4:
                        cout << "A lake, clear, cold and deep blocks the path ahead. Swimming across would be unwise." << endl;
                        if(itemsMade[BOAT]){
                            cout << "You sail ahead until you reach the far shore. A tower of weathered stone stands tall on the other side. You call out, and instead of silence, a voice calls back." << endl;
                            cout << "Congratulations! You win the game!" << endl;
                            return 0;
                        }
                    break;

                }

            break;
        }
      }while(choice != QUIT);

    return 0;
}

int menu(){
  int choice;
  cout << "What would you like to do?\n";
  cout << "1.  Gather resources\n2.  Make something\n3.  Explore\n4.  Quit\n";
  cin >> choice;
  cin.ignore();
  return choice;
}

void makeMenu(string a[], bool b[], string c[], vector<string> &vect, vector<int> &vect2, const int ARRAYSIZE){
    for(int i = 0; i < ARRAYSIZE; i++){
        if (!b[i]){
        string info = a[i] + c [i];
        vect.push_back(info);
        vect2.push_back(i);
        }
    }
}

