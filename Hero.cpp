/* metody i powi�zane z klas� Hero funkcjes */
/* */

#include <stdafx.h>
#include "resource.h"
#include "Hero.h"
Hero::Hero(string n, int h, int hp_m, int a, int d, int c,int agi, int eg, int et, int, bool buf) {
	name = n;
	hp = h, hp_max = hp_m, attack = a, def = d, charakter = c, agility = agi, exp_go = eg, exp_to = et;
	lvl = 1;
	buff = buf;
}
Hero::~Hero() {
	cout << "Hahahaha" << endl; //no nie wiem destruktywny �miech 
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

			cout << "Jak Ci na imi�?: "; cin >> name;
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

			cout << "Jak Ci na imi�?: "; cin >> name;
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

			cout << "Jak Ci na imi�?: "; cin >> name;
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
	cout << "Witaj w Czarnej Zatoce przybyszu! \nZ dokument�w wynika, �e przybyles ze wschodnich stepow...\nNazywasz si� " << name << " i jeste� ";
	if (charakter == 1) {
		cout << "wojownikiem! \nWydaje mi si� �e b�dziesz w stanie nam pom�c \nPozw�l jeszcze �e zadam Ci kilka pyta�." << endl;
		cout << "To rutynowe pytania..." << endl;
		system("pause");
		droga(name, charakter);
	}
	else if (charakter == 2) {
		cout << "Zab�jca! \nTwoja profesja mo�e si� nam przyda� \nUwazaj jednak by nie wpasc w klopoty prawne!" << endl;
		system("pause");
		droga(name, charakter);
	}
	else if (charakter == 3) {
		cout << "Paladynem \nOh Twa madro�� i wiara z pewno�ci� b�dzie przydatna w naszej krainie!" << endl;
		system("pause");
		droga(name, charakter);
	}

}
// do zwracania status�w
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
		cout << "Czujesz si� wysmienicie \nTwoje pkt. zdrowia osi�gaj� maximum!"<<endl;
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
		cout << "Otrzymujesz " << dmg << "! Obra�e�" << endl;
		hp = hp - dmg;
		system("pause");
	}
	if (hp <= 0) {
		cout << "Zostajesz pokonany. Tw�j wysi�ek na pewno nie p�jdzie na marne!" << endl;
		system("pause");
		exit(0);
	}
		
}
// metoda pozwalaj�ca nam levelowa� 
void Hero::LevelUp(int exp) { // metoda zapewniaj�ca rozw�j postaci :) 
	int perki = 10;
	char addPerk;
	exp_go += exp;
	cout << "Zdobywasz: " << exp << " punkt�w expa!" << endl;
	if (exp_go >= exp_to) {
		exp_go = 0;
		exp_to += 50;
		lvl++;
		if (charakter == 1) hp,hp_max += 50;
		else if (charakter == 2) hp,hp_max +=20;
		else hp,hp_max += 40;
		cout << "Level Up! Gratulacj� osi�gni�to kolejny level"<<endl;
		system("pause");
		while (perki > 0) {
			system("cls");
			cout << "Masz do rozdania " << perki << " punkt�w, dziel je m�drze :)"<<endl;
			cout<<endl<< "1.Zwi�ksz atak: "<<attack<<endl<< "2.Zwi�ksz defensyw�: "<<def<<endl<<"3.Zwi�ksz zr�czno�� "<<agility<<endl;
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
		cout << "Rozda�e� wszystkie punkty!"<<endl;
		cout<<endl<< "Atak: "<<attack<<endl<< "Defensywa: "<<def<<endl<<"Zr�czno�� "<<agility<<endl;
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

int Hero::attack2() { // pot�ny atak
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
int Hero::attack4() { // wiruj�ce sztylety 
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
	buff = TRUE; // ustawiam buff na true by mo�na by�o aktywowa� moc b�ogos�awie�stwa palladyna :D 
}
void Hero::buffoff() { // odpalamy buffa 
	buff = FALSE;
}
// pokazuje statystyki bohatera
void Hero::show_stats() {
	system("cls");
	cout << "Statystyki: " << endl<<endl;
	cout << "Im�: " << name << endl;
	if (charakter == 1) cout << "Klas: Wojownik"<<endl;
	else if (charakter == 2) cout << "Klas: Zab�jca"<<endl;
	else cout<<"Klasa: Paladyn"<<endl;
	cout<<"Level: "<<lvl<<endl;
	cout << exp_go<<"/"<<exp_to<<" Punkt�w Do�wiadczenia"<<endl;
	cout << hp << "/" << hp_max << " Punkt�w �ycia" << endl;
	cout << attack << " Punkty Ataku"<< endl;
	cout << def << " Punkt�w Obrony" << endl;
	cout << agility << " Punkt�w Zr�czno�ci" << endl;
	system("pause");
	system("cls");
}