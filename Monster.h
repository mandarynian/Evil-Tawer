#pragma once
#include "stdafx.h"
#include "resource.h"

class Monster {
	int hp, attack, def, agility, exp_give;
	string name;

public:
	Monster(int = 0, int = 0, int = 0, int = 0,int = 0, string = "brak");
	void show();
	void spown_monster(int,int,int,int,int,string);
	int get_hp_monst();
	int get_attack_mons();
	int get_def_mons();
	int get_agil_mons();
	int attack_monster();
	int GetExp(); // zwraca nam ilo�� zdobytego expa 
	void take_dmg_monster(int);
};