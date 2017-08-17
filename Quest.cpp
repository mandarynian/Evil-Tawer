#include "stdafx.h"
#include "Quest.h"
#include "resource.h"
// metody klassy quest odpowiedzialnej za przechowywanie poszczeg�lnych zada� :-)
Quest::Quest() { 
	QuestList = new string[5];
	Reset();
}
Quest::~Quest() {
	delete[] QuestList;
}
void Quest::AddQuest(string n, int id) {
	QuestList[id] = n;
}
void Quest::LoadQuest() { // wypisiwanie listy quest�w na ekran 
	int IdQ = 1;
	system("cls");
	cout << "Lista Quest�w:" << endl << endl;
	for (int i = 0;i < 5;i++) {
		if (QuestList[i] == "-") {}
		else {
			cout << IdQ << ". " << QuestList[i] << endl;
			IdQ++;
		}
	}
}
void Quest::Reset() {
	for (int i = 0;i < 5;i++) QuestList[i] = "-";
}