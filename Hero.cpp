/* metody i powi¹zane z klas¹ Hero funkcjes */
/* */

#include <stdafx.h>
#include "ogolnie.h"
#include "Hero.h"
Hero::Hero(string n, int h, int hp_m, int a, int d, int c,int agi, int eg, int et, int, bool buf) {
	name = n;
	hp = h, hp_max = hp_m, attack = a, def = d, charakter = c, agility = agi, exp_go = eg, exp_to = et;
	lvl = 1;
	buff = buf;
}
Hero::~Hero() {
	cout << "Hahahaha" << endl; //no nie wiem destruktywny œmiech 
}
void Hero::load() {
	for (;;) {
		char wybor;
		cout << "Wybierz postac. \n1. Wojownik \n2. Zaboijca \n3. Paladyn" << endl;
		wybor = _getch();
		switch (wybor) {
		case '1':
			hp = 170;
			hp_max = 170;
			attack = 35;
			def = 20;
			charakter = 1;
			agility = 45;
			exp_go = 0;
			exp_to = 100;

			cout << "Jak Ci na imiê?: "; cin >> name;
			break;
		case '2':
			hp = 120;
			hp_max = 120;
			attack = 4;
			def = 6;
			charakter = 2;
			agility = 70;
			exp_go = 0;
			exp_to = 100;

			cout << "Jak Ci na imiê?: "; cin >> name;
			break;
		case '3':
			hp = 140;
			hp_max = 140;
			attack = 20;
			def = 15;
			charakter = 3;
			agility = 60;
			exp_go = 0;
			exp_to = 100;

			cout << "Jak Ci na imiê?: "; cin >> name;
			break;
		default:
			cout << "Niepoprawny wybor!" << endl;
			system("pause");
			system("cls");
			return load();
		}
		break;

	}
}
void Hero::show() {
	setlocale(LC_ALL, "polish");
	cout << "Witaj w Czarnej Zatoce przybyszu! \nZ dokumentów wynika, ¿e przybyles ze wschodnich stepow...\nNazywasz siê " << name << " i jesteœ ";
	if (charakter == 1) {
		cout << "wojownikiem! \nWydaje mi siê ¿e bêdziesz w stanie nam pomóc \nPozwól jeszcze ¿e zadam Ci kilka pytañ." << endl;
		cout << "To rutynowe pytania..." << endl;
		system("pause");
		droga(name, charakter);
	}
	else if (charakter == 2) {
		cout << "Zabójca! \nTwoja profesja mo¿e siê nam przydaæ \nUwazaj jednak by nie wpasc w klopoty prawne!" << endl;
		system("pause");
		droga(name, charakter);
	}
	else if (charakter == 3) {
		cout << "Paladynem \nOh Twa madroœæ i wiara z pewnoœci¹ bêdzie przydatna w naszej krainie!" << endl;
		system("pause");
		droga(name, charakter);
	}

}
// do zwracania statusów
int Hero::get_ch() {
	return charakter;
}
int Hero::get_agi() {
	return agility;
}
int Hero::get_hp() {
	return hp;
}
int Hero::get_max_hp() {
	return hp_max;
}
int Hero::get_def() {
	return def;
}
int Hero::get_attack() {
	return attack;
}
bool Hero::GetBufInfo() {
	return buff;
}
// do zabierania i dawania zdrowia
void Hero::heal(int h) { 
	if ((hp + h) > hp_max) {
		hp = hp_max;
		cout << "Czujesz siê wysmienicie \nTwoje pkt. zdrowia osi¹gaj¹ maximum!"<<endl;
		system("pause");
	}
	else {
		hp += h;
		cout << "Przywrucono "<< h << " pkt. zdrowia!";
		system("pause");
	} 	
}
void Hero::take_dmg(int dmg) {
	dmg -= def;
	if (dmg <= 0) {
		cout << "Parry full!" << endl;
		system("pause");
	}
	else if (dmg > 0) {
		cout << "Otrzymujesz " << dmg << "! Obra¿eñ" << endl;
		hp = hp - dmg;
		system("pause");
	}
	if (hp <= 0) {
		cout << "Zostajesz pokonany. Twój wysi³ek na pewno nie pójdzie na marne!" << endl;
		system("pause");
		exit(0);
	}
		
}
// metoda pozwalaj¹ca nam levelowaæ 
void Hero::LevelUp(int exp) { // metoda zapewniaj¹ca rozwój postaci :) 
	int perki = 10;
	char addPerk;
	exp_go += exp;
	cout << "Zdobywasz: " << exp << " punktów expa!" << endl;
	if (exp_go >= exp_to) {
		exp_go = 0;
		exp_to += 50;
		lvl++;
		if (charakter == 1) hp,hp_max += 50;
		else if (charakter == 2) hp,hp_max +=20;
		else hp,hp_max += 40;
		cout << "Level Up! Gratulacjê osi¹gniêto kolejny level"<<endl;
		system("pause");
		while (perki > 0) {
			system("cls");
			cout << "Masz do rozdania " << perki << " punktów, dziel je m¹drze :)"<<endl;
			cout<<endl<< "1.Zwiêksz atak: "<<attack<<endl<< "2.Zwiêksz defensywê: "<<def<<endl<<"3.Zwiêksz zrêcznoœæ "<<agility<<endl;
			addPerk = _getch();
			switch (addPerk) {
				case '1':
					attack++;
					perki--;
					break;
				case '2':
					def++;
					perki--;
					break;
				case '3':
					agility++;
					perki--;
					break;
				default:break;
			}
		}
		system("cls");
		cout << "Rozda³eœ wszystkie punkty!"<<endl;
		cout<<endl<< "Atak: "<<attack<<endl<< "Defensywa: "<<def<<endl<<"Zrêcznoœæ "<<agility<<endl;
		system("pause");
		system("cls");
	}
	cout << "Aktualnie posiadasz "<<exp_go<<"/"<<exp_to<<endl;
	system("pause");
	system("cls");
}
// metody operacji ataku bohatera
int Hero::attack1() { // atak podstawowy wojownika
	srand(time(NULL));
	int dmg_h;
	long los;
	los = rand() % 100 + 1;

	if (los < agility) {
		dmg_h = rand() % attack + 10;
		return dmg_h;
	} else return 0;
}

int Hero::attack2() { // potê¿ny atak
	srand(time(NULL));
	int dmg_h;
	long los;
	los = rand() % 100 + 1;
	if (los < (agility - 10)) {
		dmg_h = rand() % attack + 10;
		dmg_h = dmg_h * 3;
		return dmg_h;
	} else return 0;
}
int Hero::attack3() { // atak sztyletem
	srand(time(NULL));
	int dmg_h;
	long los;
	los = rand() % 100 + 1;
	if (los <= (agility - 20)) {
		dmg_h = rand() % attack + 1;
		dmg_h = (dmg_h + 6)*3;
		return dmg_h;
	}
	else if (los <= (agility - 10)) {
		dmg_h = rand() % attack + 1;
		dmg_h = (dmg_h + 6)*2;
		return dmg_h;
	}
	else if (los <= agility) {
		dmg_h = rand() % attack + 1;
		dmg_h = dmg_h + 6;
		return dmg_h;
	}
	else return 0;
}
int Hero::attack4() { // wiruj¹ce sztylety 
	srand(time(NULL));
	int dmg_h;
	long los;
	los = rand() % 100 + 1;
	if (los <= (agility - 20)) {
		dmg_h = (rand() % attack) + 1;
		dmg_h = (dmg_h + 6) * 3;
		return dmg_h;
	}
	else if (los <= (agility - 10)) {
		dmg_h = rand() % attack + 1;
		dmg_h = (dmg_h + 6)*2;
		return dmg_h;
	}
	else if (los <= agility) {
		dmg_h = rand() % attack + 1;
		dmg_h = dmg_h + 6;
		return dmg_h;
	}
	else return 0;
}
int Hero::attack5() { // podstawowy atak paladyna
	srand(time(NULL));
	int dmg_h;
	int los = rand() % 100 + 1;	
	if (buff) { // sprawdzamy czy buff jest aktywny 
		if (los < (agility - 30)) {
			dmg_h = rand() % attack + 5;
			dmg_h = (dmg_h + 12) * 3;
			return dmg_h;
		}
		else if (los < (agility - 20)) {
			dmg_h = rand() % attack + 5;
			dmg_h = (dmg_h + 12) * 2;
			return dmg_h;
		}
		else if (los < (agility - 10)) {
			dmg_h = rand() % attack + 5;
			dmg_h = dmg_h + 12;
			return dmg_h;
		}
		else return 0;
	} else { // opcja bez aktywnego buffa 
		if (los < agility) {
			dmg_h = rand() % attack + 5;
			dmg_h = (dmg_h + 2) * 1.2;
			return dmg_h;
		}
		else return 0;		
	}	
}
void Hero::buffon() {
	buff = TRUE; // ustawiam buff na true by mo¿na by³o aktywowaæ moc b³ogos³awieñstwa palladyna :D 
}
void Hero::buffoff() { // odpalamy buffa 
	buff = FALSE;
}
// pokazuje statystyki bohatera
void Hero::show_stats() {
	system("cls");
	cout << "Statystyki: " << endl<<endl;
	cout << "Imê: " << name << endl;
	if (charakter == 1) cout << "Klas: Wojownik"<<endl;
	else if (charakter == 2) cout << "Klas: Zabójca"<<endl;
	else cout<<"Klasa: Paladyn"<<endl;
	cout<<"Level: "<<lvl<<endl;
	cout << exp_go<<"/"<<exp_to<<" Punktów Doœwiadczenia"<<endl;
	cout << hp << "/" << hp_max << " Punktów ¯ycia" << endl;
	cout << attack << " Punkty Ataku"<< endl;
	cout << def << " Punktów Obrony" << endl;
	cout << agility << " Punktów Zrêcznoœci" << endl;
	system("pause");
	system("cls");
}