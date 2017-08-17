#include "stdafx.h"
#include "resource.h"
#include "Hero.h"

class Hero;
class Monster;
// klasa zapewniaj�ca mo��iwo�� zbierania quest�w od napotkanych npc 
class Quest : public Hero {
public:
		string* QuestList; // nazwa questa
		int QuestId; // ID questa
		bool QuestStatus; // status czy aktywny czy nie aktywny

		Quest();
		~Quest();
		void AddQuest(string,int); // dodajemy questa
		void LoadQuest();
		void Reset();
};