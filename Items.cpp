#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include "Items.h"
using namespace std;


double coins = 1;
char next_room;
int health = 10;
int num_heal_pots = 5;
char player_input;
int item;
string leader_name;


int heal(){
  if(num_heal_pots > 0){
    health = health + 5 * coins;
    num_heal_pots = num_heal_pots - 1;
    cout << "Your health is now " << health << endl;
  }
  else{
  cout << "You are unable to heal. You have no healing pots left to use." << endl;
  }
  return 0;
}


int attack(int enemy_health, int enemy_dmg, int item_dmg){
  int total_dmg = item_dmg * coins;
  enemy_health = enemy_health - item_dmg * coins;
  health = health - enemy_dmg;
  cout << "You have attacked the monster for " << total_dmg << "!!! It is now at " << enemy_health << " health."<< endl;
  cout << "The monster counter-attacked for " << enemy_dmg << " which brought you down to " << health << "!" << endl << endl;
  if(health < 1){
    cout << "The monster has torn you to shreds. You were never heard from again." << endl;
    abort();
  }
  return enemy_health;
}


int leaderboards(){
  ifstream file ("leaderboard.txt");
  if (file.is_open()){
      std::cout << file.rdbuf() << endl;
  }
  ofstream sfile ("leaderboard.txt", ios::app);
  cout << "Congratulations on beating the game! Please enter your name to join the leaderboards:";
  cin >> leader_name;
  sfile << leader_name << endl;
}


int intro(){
  health = health * coins;
  cout << string( 100, '\n' );
  cout << "Welcome to the dungeon, you have " << coins << " coins." << endl;
  cout << "You head deeper into the dungeon with a long sword." << endl;
  cout << "_________________    ___________________" << endl;
  cout << "|               /                      |" << endl;
  cout << "|              /                       |" << endl;
  cout << "|                                      |" << endl;
  cout << "|                                      |" << endl;
  cout << "|                                      |" << endl;
  cout << "|                                      |" << endl;
  cout << "|                 0/  Coins: " << coins <<"         |" << endl;
  cout << "|                /|   Health pots: "<< num_heal_pots<<"   |" << endl;
  cout << "|                /|   Health: "<<health<<"       |" << endl;
  cout << "|______________________________________|" << endl;
  cout << "Would you like to continue to the next room? (Y/N) ";
  cin >> next_room;
  if(next_room == 'Y' || next_room == 'y'){
  }
  else{
    cout << "You have chosen to stay in the same room indefinetly. You last 1 week before you die of dyhydration. You were never heard from again" << endl;
    abort();
  }
    
  return 0;
}


int lv2(int enemy_health, int enemy_dmg, double room_coins, int item_damage){
  cout << "Welcome to the next room. You currently have " << coins << " coins." << endl;
  cout << "You encounter an enemy. It is known as the terrible monster." << endl;
  cout << "_________________    ___________________" << endl;
  cout << "|               /                      |" << endl;
  cout << "|              /                       |" << endl;
  cout << "|                                      |" << endl;
  cout << "|                >O<                   |" << endl;
  cout << "|                /|                    |" << endl;
  cout << "|                                      |" << endl;
  cout << "|                 0/  Coins: " << coins <<"         |" << endl;
  cout << "|                /|   Health pots: "<< num_heal_pots<<"   |" << endl;
  cout << "|                /|   Health: "<<health<<"       |" << endl;
  cout << "|________________     _________________|" << endl;
  next_room = 'n';
  while (enemy_health > 0){
    cout << "Would you like to attack(a) or heal(h)." << endl;
    cin >> player_input;
    if(player_input == 'a' || player_input == 'A'){
      attack(enemy_health, enemy_dmg, item_damage);
      enemy_health = enemy_health - (item_damage * coins);
    }
    else if (player_input == 'h' || player_input == 'H'){
      heal();
    }
  }
  cout << "Congradulations. You have defeated the terrible monster" << endl;
  coins = coins + room_coins;
  cout << "Would you like to continue to the next room? (Y/N) ";
  cin >> next_room;
  if(next_room == 'Y' || next_room == 'y'){
  }
  else{
    cout << "You have chosen to stay in the same room indefinetly. You last 1 week before you die of dyhydration. You were never heard from again" << endl;
    abort();
  }
  return 0;
}


int lvboss(int enemy_health, int enemy_dmg, double room_coins, int item_damage){
  cout << "Welcome to the final boss room. You currently have " << coins << " coins." << endl;
  cout << "You encounter an enemy. It is known as the horrific monster." << endl;
  cout << "_________________    ___________________" << endl;
  cout << "|               /                      |" << endl;
  cout << "|              /                       |" << endl;
  cout << "|                (=)                   |" << endl;
  cout << "|                 |                    |" << endl;
  cout << "|                /|                    |" << endl;
  cout << "|                                      |" << endl;
  cout << "|                 0/  Coins: " << coins <<"         |" << endl;
  cout << "|                /|   Health pots: "<< num_heal_pots<<"   |" << endl;
  cout << "|                /|   Health: "<<health<<"       |" << endl;
  cout << "|________________     _________________|" << endl;
  next_room = 'n';
  while (enemy_health > 0){
    cout << "Would you like to attack(a) or heal(h)." << endl;
    cin >> player_input;
    if(player_input == 'a' || player_input == 'A'){
      attack(enemy_health, enemy_dmg, item_damage);
      enemy_health = enemy_health - (item_damage * coins);
    }
    else if (player_input == 'h' || player_input == 'H'){
      heal();
    }
  }
  cout << "Congradulations! You have suceeded in your tasks of defeating the horrific monster. You have completed your final objective." << endl << endl;
  return 0;
}