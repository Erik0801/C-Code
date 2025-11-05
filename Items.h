#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>


#ifndef Items
#define Items


class items{
private:
public:
  int damage;
};


int heal();

int attack(int enemy_health, int enemy_dmg, int item_dmg);

int leaderboards();

int intro();

int lv2(int enemy_health, int enemy_dmg, double room_coins, int item_damage);

int lvboss(int enemy_health, int enemy_dmg, double room_coins, int item_damage);


#endif