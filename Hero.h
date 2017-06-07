#pragma once
#include "stdafx.h"
#include "ogolnie.h"


class Hero {
	int hp, hp_max, attack, def, charakter, agility;
	int exp_go, exp_to;
	int lvl;
	bool buff;
	string name;

public:

	Hero(string = "brak", int = 100, int = 100, int = 50, int = 20, int = 1,int = 10, int = 0, int = 100, int = 1, bool = FALSE);
	~Hero();
	void load();
	void show();
	void show_stats();
	int get_ch();
	int get_agi();
	int get_hp();
	int get_max_hp();
	int get_def();
	int get_attack();
	bool GetBufInfo();
	void heal(int);
	void take_dmg(int);//zadawanie ran bohaterowi
	int attack1(); //atak wojownika standardowy
	int attack2(); //atak wojownika wzmocniony
	int attack3();//atak zabójcy podstawowoy
	int attack4(); //atak zab wzmocniny
	int attack5(); // podstaowy atak paladyna 
	void buffon(); // odpalamy buff palladyna
	void buffoff(); // wy³¹czamy buff palladyna 
	void LevelUp(int);
};