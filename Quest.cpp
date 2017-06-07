#include "stdafx.h"
#include "Quest.h"
#include "ogolnie.h"
// metody klassy quest odpowiedzialnej za przechowywanie poszczególnych zadañ :-)
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
void Quest::LoadQuest() { // wypisiwanie listy questów na ekran 
	int IdQ = 1;
	system("cls");
	cout << "Lista Questów:" << endl << endl;
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