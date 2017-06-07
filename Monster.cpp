#include <stdafx.h>
#include "ogolnie.h"
#include "Monster.h"
//metody oraz funkcje powi¹zane z klas¹ Monster

Monster::Monster(int h, int a, int d, int agi, int exp, string n) {
	hp = h, attack = a, def = d, agility = agi, exp_give = exp, name = n;
}
void Monster::show() {
	setlocale(LC_ALL, "polish");
	cout << "Pojawia siê " << name << "\nwartoœæ jego punktów ¿ycia to :" << hp<<endl;
	cout << "staty drania: " << agility << " zrêcznoœci, " << attack << " ataku, " << def << " defa!" << endl;
}

void Monster::spown_monster(int h, int a, int d, int agi, int e, string n) {
	setlocale(LC_ALL, "polish");
	hp = h, attack = a, def = d, agility = agi, exp_give = e, name = n;
	system("pause");
	system("cls");
	cout << "Atakuje Ciê: " << name << endl;
	cout << "Posiada on: " << hp << " punktów ¿ycia" << endl;
	cout << "Oraz: " << attack << " ataku i " << def << " obrony" << endl;
	system("pause");
}
// metody pobieraj¹ce ró¿ne statystyki klasy monster 
int Monster::get_hp_monst() {
	return hp;
}
int Monster::get_attack_mons() {
	return attack;
}
int Monster::get_def_mons() {
	return def;
}
int Monster::get_agil_mons() {
	return agility;
}
int Monster::GetExp() {
	return exp_give;
}
int Monster::attack_monster() {
	int dmg_m;
	long los;
	los = (rand() % 100) + 1;
	if (los <= agility) {
		dmg_m = (rand() % attack) + 1;
		return dmg_m;
	} 
	else if (los < (agility - 20)) {
		dmg_m = (rand() % attack) + 1;
		dmg_m = dmg_m * 2;
		return dmg_m;
	}
	else return 0;
}
void Monster::take_dmg_monster(int dmg) {
	hp -= dmg;
}