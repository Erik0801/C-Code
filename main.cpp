#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include "Items.h"
using namespace std;


void abort(void);


int main() {
  char start_game;

  items long_sword, really_long_sword, ultra_long_sword; 
  long_sword.damage = 1;
  really_long_sword.damage = 2;
  ultra_long_sword.damage = 3;

  cout << "Would you like to start the game? (Y/N) ";
  cin >> start_game;
  if(start_game == 'Y' || start_game == 'y'){
    intro();
    cout << string( 100, '\n' );
    lv2(5,1,1,long_sword.damage);
    cout << string( 100, '\n' );
    lv2(10,2,1,long_sword.damage);
    cout << string( 100, '\n' );
    cout << "Before you leave you find a Really Long Sword - increasing your damage." << endl;
    lv2(15,3,1,really_long_sword.damage);
    cout << string( 100, '\n' );
    cout << "Before you leave you find an Ultra Long Sword - increasing your damage." << endl;
    lvboss(25,5,5,ultra_long_sword.damage);
    
    leaderboards();
  
    abort();
  }
  else{
    cout << "You decided to not start the game." << endl;
    abort();
  }

  return 0;
}