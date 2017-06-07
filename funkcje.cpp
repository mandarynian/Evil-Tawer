#include "stdafx.h"
#include "ogolnie.h"
#include "Hero.h"
#include "Monster.h"
#include "Quest.h"

int cooldown = 0;
int hp_monster;
int visited = 0, visited2 = 0;
//void fight(Hero &hero, Monster &monster);

//funkcje ogólnego urzytku 
void menu() {

	char wybor;
	for (;;) {

		system("cls");
		cout << "MENU GLOWNE" << endl << endl;
		cout << "1 Nowa Gra" << endl;
		cout << "2 Pomoc" << endl;
		cout << "3 Exit" << endl;


		wybor = _getch();

		switch (wybor) {
		case '1':
			system("cls");
			startgame();
			break;
		case '2':
			system("cls");
			pomoc();
			break;
		case '3':
			system("cls");
			cout << "Nastapi zakonczenie programu!" << endl;
			system("pause");
			exit(0);
		default:
			cout << "Niepoprawny wybor!" << endl;
			system("pause");
			system("cls");
			return menu();
		}
	}
}


int pomoc() {
	char wb;
	setlocale(LC_ALL, "polish");
	for (;;) {
		cout << "Pomoc! \n1. Postacie \n2. O grze \n3. Powrót" << endl;

		wb = _getch();
		system("cls");
		switch (wb) {
		case '1':
			cout << "Wojownik. \nSilny odporny na ataki fizyczny posiadajacy duzo pancerza." << endl;
			cout << "Niestety posiada znacznie mniej zrêcznoœci co powoduje, \n¿e wyprowadzane ataki maj¹ mniejszy stopieñ trafienia." << endl;
			cout << "G³ównym atutem wojownika jest drugi jego skill \nPozwala on uderzyæ z czterokrotn¹ si³¹ przeciwnika!" << endl;
			cout<<endl << "Zabojca. \nSzybki, posiadaj¹cy niesamowit¹ zwinnoœæ \nPosiada o wiele mniejsze obra¿enia aczkolwiek jest w stanie wyprowadzaæ je czêœciej" << endl;
			cout << "G³ównym atutem tej postaci jest jego skill zapewniaj¹cy potrujny atak \nNiestety jest on równie¿ obarczony d³ugim czasem regeneracji!" << endl;
			cout << endl << "Paladyn. \nNiestety w obecnym stanie gry postaæ niedokoñczona \nNie polecam nim graæ." << endl;
			cout << "W kolejnym patchu bêdzie rozbudowywana"<<endl;
			system("pause");
			system("cls");
			break;
		case '2':
			cout << "W grze g³ównym zadaniem jest pod¹¿aæ za w¹tkiem fabularnym \nJest to wersja demonstracyjna w przysz³oœci zostan¹ dodane nowe usprawnienia \nTrzy a obecnie dwie postaci, \ndaj¹ mo¿liwoœæ poznania œwiata w którym przyjdzie nam stawiæ czo³a niebespiecznym przygod¹!" << endl;
			system("pause");
			system("cls");
			break;
		case '3':
			system("cls");
			cout << "Nast¹pi powrót do menu..." << endl;
			return main();
		default:
			cout << "Nie poprawny wybor!!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void wprowadzenie() {
	setlocale(LC_ALL, "polish");
	system("pause");
	system("cls");
	cout << "Podró¿ trwa ju¿ kilka miesiecy od k¹d opóœci³em rodzinne wschodnie stepy" << endl;
	cout << "Choroba morska stala sie zaledwie wspomnieniem pocz¹tków tej trudnej podró¿y \nale to jak i sprz¹tanie pok³adu dzien w dzien bylo neiwielk¹ cen¹ jak na tak \ndalek¹ wyprawê." << endl;
	cout << "Dziœ stojê z usmiechem na twarzy obserwójac jak powoli statek cumuje w zatoce. \nCieply klimat i piekna pogoda sprawia ze ta kraina wydaje byc sie rajem." << endl;
	system("pause");
	system("cls");
	cout << "Po przybiciu do brzegu kazano mi udac sie do stra¿nika w celnicy \naby sie zameldowaæ." << endl;
	cout << "Wygl¹d dzielnicy portowej przyozdabia krz¹tanina tragarzy, \nktórzy wij¹ siê swoimi scie¿kami by dostarczyæ na czas \nbezcenne dla ich w³aœcicieli produkty. \nGwar wszystko ogarniaj¹cy sieje zamêt w zmys³ach \nby ju¿ po chwili obserwacji mo¿na by³o dostrzec piekno naturalnego porz¹dku \nNiczym w mrówczym kopcu, ka¿dy ma tu swoje zadanie..." << endl;
	system("pause");
	system("cls");
	cout << "Budynek w którym znajdowa³a siê celnica by³ dwupiêtrowy, mórowany \ndrzwi wielkie wzmacniane metalowymi okuciami"<<endl;
	cout << "W œrodku czeka³ na mnie przy swym stoliku stra¿nik, który coœ skroba³ na kartce" << endl;
	system("pause");
	system("cls");
}

void droga(string n, int charakter) {
	setlocale(LC_ALL, "polish");
	char wb, wb2;
	system("cls");
	cout << "A wiec " << n << " powiedz mi co Ciê sprowadza do tej krainy?" << endl << endl;
	cout << "1. Znudzilo mi sie miejsce w ktorym zylem." << endl;
	cout << "2. Poszukuje przygod i slawy" << endl;
	cout << "3. Mam tu kilka spraw do zalatwienia" << endl;
	cout << "4. Nie zaczyna sie zdania od 'A wiec'!" << endl;

	wb = _getch();

	switch (wb) {
	case '1':
		system("cls");
		cout << "1. Znudzilo mi sie miejsce w ktorym zylem." << endl << endl;
		cout << "Ciekawe... Moze tu uda Ci sie zaspokoic swoja nude" << endl;
		system("pause");
		break;
	case '2':
		system("cls");
		cout << "2. Poszukuje przygod i slawy" << endl << endl;
		cout << "Jak wiekszosc tobie podobnych. Mozesz smialo poszukiwac bylebys nie sprawial klopotow" << endl;
		system("pause");
		break;
	case '3':
		system("cls");
		cout << "3. Mam tu kilka spraw do zalatwienia" << endl << endl;
		cout << "Rozumiem..." << endl;
		system("pause");
		break;
	case '4':
		system("cls");
		cout << "4. Nie zaczyna sie zdania od 'A wiec'!" << endl << endl;
		cout << "Phi!"<< endl;
		cout << "Coz.. Pamietaj by nie sprawiac klopotow!" << endl;
		system("pause");
		break;
	default:break;
	}
	system("cls");
	cout << "Jak d³ugo zamierzasz pozsotaæ tutaj?" << endl<<endl;
	cout << "1. Nie jestem pewien" << endl;
	cout << "2. Jakiœ czas" << endl;
	cout << "3. Dopiero tu przyby³em muszê siê rozej¿eæ, wtedy postanowiê" << endl;

	wb2 = _getch();
	switch (wb2) {
	case '1':
		system("cls");
		cout << "1. Nie jestem pewien" << endl<<endl;
		cout << "Ah. Niezdecydowa³eœ jeszcze" << endl;
		break;
	case '2':
		system("cls");
		cout << "2. Jakiœ czas" << endl<<endl;
		cout << "Yhmy..." << endl;
		break;
	case '3':
		system("cls");
		cout << "3. Dopiero tu przyby³em muszê siê rozej¿eæ, wtedy postanowiê" << endl<<endl;
		cout << "Myœlê ¿e znajd¹ siê tu ciekawe rzeczy do zrobienia" << endl;
		break;
	default:break;
	}

	system("pause");
	system("cls");
	cout << "A w³aœnie..." << endl;
	cout << "Jako ¿e jesteœ nowy w tej krainie muszê daæ Ci jakieœ zadanie sprawdzaj¹ce \nKtóre dowiedzie Twojej przydatnoœci" << endl;
	cout << "Na zachód od miasta jest œcie¿ka, która prowadzi przez las \nNa koñcu tej œcie¿ki znajdziesz sporych rozmiarów wierzê" << endl;
	cout << "Nie sposób jej omin¹æ \n\nChcia³bym abyœ zdoby³ dla nas pewien przedmiot znajduj¹cy siê na szczycie tej wierzy" << endl;
	cout << "Jest to kamienny puchar, skradziony przez szalonego ch³opaka, który ukrywa siê w³aœnie w tej wierzy" << endl;
	cout << "To nie powinno byæ trudne zadanie a Twoje umiejêtnoœci na pewno sprawi¹, ¿e \nszybko rozprawisz siê z rabusiem i dostarczysz skradziony przedmiot do mnie" << endl;
	system("pause");
	system("cls");
	cout << "Oczywiœcie jesli chodzi o wyposa¿enie to mogê daæ Ci orê¿..." << endl<<endl;
	if (charakter == 1) {
		cout << "Zaraz, zaraz coœ tu znajdê dla wojownika..." << endl;
		cout << "O proszê ten miecz na pewno powinien wystarczyæ" << endl;
		system("pause");
		system("cls");
		cout << "Dostajesz du¿y wywa¿ony miecz o szerokim ostrzu i solidnej rêkojeœci"<<endl<<endl;
		system("pause");
		system("cls");
	}
	else if (charakter == 2) {
		cout << "Zaraz, zaraz coœ tu znajdê dla zabojcy..." << endl;
		cout << "O proszê te sztylety na pewno powinny wystarczyæ" << endl;
		system("pause");
		system("cls");
		cout << "Dostajesz standardowe sztylety z ca³kiem wygodnymi rêkojeœciami i ostrej klindze" << endl << endl;
		system("pause");
		system("cls");
	}
	else if (charakter == 3) {
		cout << "Zaraz, zaraz coœ tu znajdê dla palladyna..." << endl;
		cout << "O proszê te miecz powinien wystarczyæ" << endl;
		system("pause");
		system("cls");
		cout << "Dostajesz krótki szeroki miecz legionisty... Przeciez wiara jest tw¹ najwiêksz¹ broni¹" << endl << endl;
		system("pause");
		system("cls");
	}
	
	system("pause");
	system("cls");
	cout << "Nim dotar³em do opisanej przez stra¿nika lokacji zapad³ ju¿ wieczór \nEhh.. Szkoda ¿e nie wzi¹³em ze sob¹ pochodni \nW œrodku mo¿ê byæ ciemno. \nWierza by³a dosyæ wysoka, okoliczne tereny natomiast martwe. \nWszêdzie czuæ by³o zgnielizn¹..." << endl;
	system("pause");
	system("cls");
	cout << "Dziwne... \nCokolwiek tu siê wydarzy³o wygl¹da to jakby wziê³o swój pocz¹tek od tej wierzy \nNo có¿ to nie czas na  zastanawianie siê nad przyczynami tej zarazy. \nPora ruszaæ w drogê!";
	system("pause");
	//sndPlaySound(L"mus.wav", SND_ASYNC);

}

void fight(Hero &hero, Monster &monster) { //funkcja walki z przeciwnikiem
	int ch, hp_hero, attack_hero, deff_hero;
	int attack_monster, deff_monster;
	char wybor;
	cout << endl;
	ch = hero.get_ch();
	hp_hero = hero.get_hp();
	int hp_max = hero.get_max_hp();
	deff_hero = hero.get_def();
	hp_monster = monster.get_hp_monst();
	deff_monster = monster.get_def_mons();
		
	if (ch == 1) {
		while (hp_monster >= 0) {
			if (cooldown == 1) {
				system("cls");
				cout << "MENU WALKI" << endl << endl;
				cout << "Posiadasz " << hp_hero <<"/"<< hp_max << " Punktów ¯ycia!" << endl;
				cout << "Twój przeciwnik posiada jeszcze " << hp_monster << endl << endl;
				cout << "1. Atak podstawowy" << endl;
				cout << "2. Potê¿ny atak! Cooldown 1 ture's" << endl;
				wybor = _getch();
				system("cls");
				switch (wybor) {
				case '1':
					attack_hero = hero.attack1();
					attack_hero -= deff_monster;
					cout << "Wykonujesz cios mieczem" << endl;
					if (attack_hero <= 0) {
						cout << "Nie uda³o zadaæ Ci siê ciosu!" << endl;
						cooldown = 0;
						break;
					}
					else {
						hp_monster -= attack_hero;
						monster.take_dmg_monster(attack_hero);
						cout << "Zadajesz " << attack_hero << " obra¿eñ!" << endl;
						cooldown = 0;
						break;
					}
				default:return fight(hero, monster);
				}
				if (hp_monster <= 0) {
					system("pause");
					system("cls");
					cout << "Wróg pokonany!" << endl;
					system("pause");
					hero.LevelUp(monster.GetExp());
					break;
				}
				
			}
			else {
				system("cls");
				cout << "MENU WALKI" << endl << endl;
				cout << "Posiadasz " << hp_hero <<"/"<< hp_max << " Punktów ¯ycia!" << endl;
				cout << "Twój przeciwnik posiada jeszcze " << hp_monster << endl << endl;
				cout << "1. Atak podstawowy" << endl;
				cout << "2. Potê¿ny atak!" << endl;
				wybor = _getch();
				system("cls");
				switch (wybor) {
				case '1':
					attack_hero = hero.attack1();
					attack_hero -= deff_monster;
					cout << "Wykonujesz cios mieczem" << endl;
					if (attack_hero <= 0) {
						cout << "Nie uda³o zadaæ Ci siê ciosu!" << endl;
						break;
					}
					else {
						hp_monster -= attack_hero;
						monster.take_dmg_monster(attack_hero);
						cout << "Zadajesz " << attack_hero << " obra¿eñ!" << endl;
						break;
					}
				case '2':
					cooldown++;
					attack_hero = hero.attack2();
					attack_hero -= deff_monster;
					cout << "Wykonujesz niezwykle ryzykowny cios z wyskoku!" << endl;
					if (attack_hero <= 0) {
						cout << "Nie uda³o zadaæ Ci siê ciosu!" << endl;
						break;
					}
					else {
						hp_monster -= attack_hero;
						monster.take_dmg_monster(attack_hero);
						cout << "Zadajesz " << attack_hero << " obra¿eñ!" << endl;
						break;
					}
				default:return fight(hero, monster);
				}
				if (hp_monster <= 0) {
					system("pause");
					system("cls");
					cout << "Wróg pokonany!" << endl;
					system("pause");
					hero.LevelUp(monster.GetExp());
					break;
				}
			}			
			cout << endl << "Wróg atakuje" << endl;
			attack_monster = monster.attack_monster();
			hero.take_dmg(attack_monster);
			hp_hero = hero.get_hp();
			system("pause");
		}
	}
	else if (ch == 2) {
		while (hp_hero >= 0 || hp_monster >= 0) {
			if (cooldown > 0) {
				system("cls");
				cout << "MENU WALKI" << endl << endl;
				cout << "Posiadasz " << hp_hero <<"/"<< hp_max << " Punktów ¯ycia!" << endl;
				cout << "Twój przeciwnik posiada jeszcze " << hp_monster << endl << endl;
				cout << "1. Atak podstawowy" << endl;
				cout << "2. Wiruj¹ce sztylety! Cooldown "<< cooldown << " ture's!" << endl;
				wybor = _getch();
				system("cls");
				switch (wybor) {
				case '1':
					cooldown--;
					attack_hero = hero.attack3();
					attack_hero -= deff_monster;
					cout << "Wykonujesz szybki atak sztyletem" << endl;
					if (attack_hero <= 0) {
						cout << "Nie uda³o zadaæ Ci siê ciosu!" << endl;
						break;
					}
					else {
						hp_monster -= attack_hero;
						monster.take_dmg_monster(attack_hero);
						cout << "Zadajesz " << attack_hero << " obra¿eñ!" << endl;
						break;
					}
				default:return fight(hero, monster);

				}
				if (hp_monster <= 0) {
					system("pause");
					system("cls");
					cout << "Wróg pokonany!" << endl;
					system("pause");
					hero.LevelUp(monster.GetExp());
					break;
				}
			}
			else {
				system("cls");
				cout << "MENU WALKI" << endl << endl;
				cout << "Posiadasz " << hp_hero <<"/"<< hp_max << " Punktów ¯ycia!" << endl;
				cout << "Twój przeciwnik posiada jeszcze " << hp_monster << endl << endl;
				cout << "1. Atak podstawowy" << endl;
				cout << "2. Wiruj¹ce sztylety" << endl;
				wybor = _getch();
				system("cls");
				switch (wybor) {
				case '1':
					attack_hero = hero.attack3();
					attack_hero -= deff_monster;
					cout << "Wykonujesz szybki atak sztyletem" << endl;
					if (attack_hero <= 0) {
						cout << "Nie uda³o zadaæ Ci siê ciosu!" << endl;
						break;
					}
					else {
						hp_monster -= attack_hero;
						monster.take_dmg_monster(attack_hero);
						cout << "Zadajesz " << attack_hero << " obra¿eñ!" << endl;
						break;
					}
				case '2':
					system("cls");
					cooldown = 3;
					cout << "Z niesamowit¹ zwinnoœci¹ wyrzucasz szybko trzy sztylety!" << endl;
					for (int i = 0; i < 3; i++) {
						attack_hero = 0;
						attack_hero = hero.attack4();
						attack_hero -= deff_monster;
						if (attack_hero <= 0) {

							cout << "Nó¿ nie trafi³!" << endl;
						}
						else {
							hp_monster -= attack_hero;
							monster.take_dmg_monster(attack_hero);
							cout << "Zadajesz " << attack_hero << " obra¿eñ!" << endl;
						}
					}
					break;
				default:
					cout << "Z³y przycisk!" << endl;
					system("pause");
					return fight(hero, monster);

				}
				if (hp_monster <= 0) {
					system("pause");
					system("cls");
					cout << "Wróg pokonany!" << endl;
					system("pause");
					hero.LevelUp(monster.GetExp());
					break;
				}
			}
			cout << endl << "Wróg atakuje" << endl;
			attack_monster = monster.attack_monster();
			hero.take_dmg(attack_monster);
			hp_hero = hero.get_hp();
			system("pause");
		}
	}
	else if (ch == 3) { // lecimy z palladynem 
		while(hp_hero >= 0 || hp_monster >= 0) { // pêtlelka a¿ jeden padnie 
			if (cooldown > 0) { // jest coodown to lecim
				system("cls");
				cout << "MENU WALKI" << endl << endl;
				cout << "Posiadasz " << hp_hero <<"/"<< hp_max << " Punktów ¯ycia!" << endl;
				cout << "Twój przeciwnik posiada jeszcze " << hp_monster << endl << endl;
				cout << "1. Atak Podstawowy" << endl;
				cout << "2. Wzmocnienie ataku, Cooldown: "<< cooldown << endl;
				wybor = _getch();
				switch (wybor) {
				case '1':
					cooldown--; // powoli schodzimy z cooldowna xD
					attack_hero = hero.attack5();
					attack_hero -= deff_monster;
					
					if (hero.GetBufInfo() == TRUE) cout << "Z uczuciem jakby œwiêty anio³ wykonywa³ z Tob¹ ruch mieczem"<< endl;
					cout << "Wykonujesz precyzyjne ciêcie" << endl;
					if (attack_hero <= 0) {
						cout << "Nie uda³o Ci siê zadaæ obra¿eñ!" << endl;
						hero.buffoff(); // usuwamy buffa gdy¿ jest tylko jednorazowy :) 
						break;
					}
					else {
						hp_monster -= attack_hero;
						monster.take_dmg_monster(attack_hero);
						cout << "Zadajesz " << attack_hero << " obra¿eñ!" << endl;
						hero.buffoff(); // usuwamy buffa gdy¿ jest tylko jednorazowy :) 
						break;
	
					}
				default:return fight(hero,monster);
				}
				if (hp_monster <= 0) {
					system("pause");
					system("cls");
					cout << "Wróg pokonany!" << endl;
					system("pause");
					hero.LevelUp(monster.GetExp());
					break;
				}
			}
			else { // jelsi nie ma cooldown to lecimy z koksem 
				system("cls");
				cout << "MENU WALKI" << endl << endl;
				cout << "Posiadasz " << hp_hero <<"/"<< hp_max << " Punktów ¯ycia!" << endl;
				cout << "Twój przeciwnik posiada jeszcze " << hp_monster << endl << endl;
				cout << "1. Atak Podstawowy" << endl;
				cout << "2. Wzmocnienie ataku" << endl;
				wybor = _getch();
				switch (wybor) {
				case '1':
					attack_hero = hero.attack5();
					attack_hero -= deff_monster;
					cout << "Wykonujesz precyzyjne ciêcie" << endl;
					if (attack_hero <= 0) {
						cout << "Nie uda³o Ci siê zadaæ obra¿eñ!" << endl;
						hero.buffoff(); // usuwamy buffa gdy¿ jest tylko jednorazowy :) 
						break;
					}
					else {
						hp_monster -= attack_hero;
						monster.take_dmg_monster(attack_hero);
						cout << "Zadajesz " << attack_hero << " obra¿eñ!" << endl;
						hero.buffoff(); // usuwamy buffa gdy¿ jest tylko jednorazowy :) 
						break;
					}				
				case '2':
					hero.buffon(); // uruchamia siê buff :D
					cout << "Po chwili modlitwy wzmacniasz czujesz nap³yw niesamowitej energi"<< endl << "Nastepny twój atak bêdzie potê¿niejszy"<< endl;
					cooldown = 2; // ustawiamy cooldown
					break;
				default:return fight(hero, monster);
				}
				if (hp_monster <= 0) {
					system("pause");
					system("cls");
					cout << "Wróg pokonany!" << endl;
					system("pause");
					hero.LevelUp(monster.GetExp());
					break;
				}
			}
			cout << endl << "Wróg atakuje" << endl;
			attack_monster = monster.attack_monster();
			hero.take_dmg(attack_monster);
			hp_hero = hero.get_hp();
			system("pause");	
		}
	}
}	
void tawer_v2(Hero &hero, Monster &monster) {
	system("cls");
	cout << "Pokonuj¹c schody docieram do kolejnego pomieszczenia" << endl;
	cout << "Po przejœciu przez niewielkie drzwi \nz miejsca dobieg³ do mnie przeraŸliwy krzyk!" << endl;
	cout << "Wielki zielony trol dostrzega mnie b³yskawicznie i atakuje!" << endl;
	monster.spown_monster(120, 33, 5, 50, 55, "Trol");
	fight(hero,monster);
	system("cls");
	cout << "Uff uda³o mi siê na szczêœcie pokonaæ zagro¿enie.."<<endl;
	cout << "Sk¹d tu siê bior¹ takie stwory? \nZ t¹ wierz¹ jest coœ totalnie nie tak" << endl;
	cout << endl << "Przygl¹dajac siê pomieszczeniu w którym siê znalaz³em \nDostrzeg³em coœ na kszta³t jadalni." << endl;
	cout << "Wielki stó³ nakryty obfitoœciami, owoce, wyszukane miêsa i wino \nWszystko wygl¹da na œwie¿e." << endl;
	cout << "W dodatku œwiat³o œwiec nadaje piêkny klimat temu miejscu \nSufit to wspania³a kopu³a na której ktoœ umieœcil niemal¿e boski fresk" << endl;
	cout << "I przepiêkne okienne witra¿e z wizerunkami nagich kobiet i mêrzczyzn \npodczas aktów seksualnych." << endl;
	cout << endl << "Coraz bardziej zaczyna mnie zastanawiaæ co to jest za miejsce ?!" << endl;
	system("pause");
	system("cls");
	cout << "W chwili gdy siêga³em ju¿ po jab³uko dostrzeg³em kantem oka ¿e coœ poruszy³o siê w fotelu pod œcianom." << endl;
	cout << endl << "By³a to nie¿no blada postaæ z czerwonymi œlepiami. \nUsta mia³a sine, w³osy ledwo widczne. \nPaznokcie u r¹k d³ugie jak szpile, wygl¹daj¹ jakby bez problemu mog³y przeci¹æ skurzan¹ zbrojê!" << endl;
	cout << "Postaæ wpatrywa³a siê we mnie œwidruj¹cym wzrokiem, \nktóry przeszywa³ mnie niczym jad wê¿a krwioobieg swej ofiary" << endl;
	cout << "By³em totalnie sparari¿owany, ledwo oddycha³em \na postaæ w dziwny nieludzki sposób przesunê³a siê do mnie \nten ruch by³ praktycznie bezszelestn pozbawiony jakichkolwiek emocji." << endl;
	cout << endl << "Patrzy³ mi prosto w oczy! \nZuwa¿y³em jak lekko przesówa siê k¹cik ust ów stwora w suptelny uœmiech" << endl;
	cout << "Po chwili jednak oddali³ siê i znikn¹³ za drzwiami \nJeszcze przez chwilê nie mog³em siê ruszaæ" << endl;
	cout << endl << "W g³owie rodzi³y mi siê pytania... \nPytania bez odpowiedzi!\nW co ja zosta³em wci¹gniêty..." << endl;
	system("pause");
	system("cls");
	cout << "Me serce jeszcze przez d³u¿sz¹ chwilê chcia³o wyrwaæ siê z objêæ klatki piersiowej"<<endl;
	cout << "No nic kilka g³êbszych wdechów powietrza i pora siê otrz¹sn¹æ"<< endl;
	cout << "Nic mi nie da u¿alanie siê nad sob¹ albo co gorsza panikowanie... \nMuszê twardo st¹paæ po ziemi by nie skoñczyæ martwym!"<< endl;
	cout << "Drzwi za mna ju¿ dawno siê zamknê³y i coœ... \nCoœ jakby pcha³o mnie dalej, bym wszed³ g³êbiej."<<endl;
	cout << "A mo¿e drzwi nigdy siê nie zamknê³y tylko to mój umys³ pragnie bym szed³ dalej?"<<endl;
	cout << "Pytanie to pojawi³o siê w mojej g³owie z nik¹d \nBy w mgnieniu oka zmieniæ siê w dobry dowcip"<<endl;
	cout << "Znowu da³em sie namówiæ na jak¹œ dziwn¹ akcjê, która co gorsza mo¿e staæ siê moj¹ ostatni¹!"<<endl;
	system("pause");
	system("cls");
	cout << "Przedemn¹ oblrzymie drzwi prowadz¹ce do jakiegoœ pomieszczenia ";
}
void tawer_start(Hero &hero, Monster &monster, Quest &zadanie) {
	char p1, p2, p3;
	int dmg_h, dmg_m;
	system("cls");

	while (true) {
		if (visited2 > 0) {
			cout << "Znajdujesz siê ponownie w pierwszym pomieszczeniu nic siê tu nie zmieni³o" << endl << endl;
		}
		else {

			cout << "Wchodz¹c do œrodka us³ysza³em zatrzaskuj¹ce siê za mn¹ drzwi \nDostaæ siê do œrodka by³o ³atwo z wydostaniem ju¿ chyba tak nie bêdzie..." << endl;
			system("pause");
			system("cls");
		}

		visited2++;

		cout << "Du¿y pokój wype³niony stêch³ym powietrzem i dwoje drzwi \nCo tu robiæ?" << endl << endl;
		cout << "1. WejdŸ w drzwi po prawej" << endl;
		cout << "2. WejdŸ w drzwi po lewej" << endl;
		cout << "3. Poka¿ statystyki" << endl;
		p1 = _getch();
		switch (p1) {
		case '1':
			cout << endl << "Widzê schody na górê" << endl << endl;
			cout << "1. Wchodzê!" << endl;
			cout << "2. Mam tu jeszcze coœ do zbadania" << endl;
			p2 = _getch();
			switch (p2) {
			case '1':
				tawer_v2(hero,monster);
				break;
			case '2':
				system("cls");
				break;
			}
			break;
		case '2':
			if (visited > 0) {
				cout << endl << "Pokój juz odwiedzony nic poza wspania³¹ piwniczk¹ nie pozosta³o tu do zobaczenia" << endl;
				system("pause");
				break;
			}
			else {
				visited++;
				cout << endl << "W pomieszczeniu panuje ciemnoœæ, na szczêœcie na stoliku jest kaganek \nobok którego znajduje siê krzesiwo" << endl;
				cout << "Po rozpaelniu œwiat³a dostrzedz mo¿na majestat tej sali \njest to swoista piwniczka z nielda ma³ym asortymentem róznych beczuszek i beczek pouk³adanych starannie na rega³ach" << endl;
				system("pause");
				system("cls");
				cout << "Nagle z pomiedzy rega³ów wy³ania siê postaæ \nNie zadu¿a, zgarbiona. Przypominaj¹ca trochê dziecko \nSkierowawszy w jej stronê kaganek okaza³o siê, ¿e to goblin z doœæ pokaŸna ran¹ w g³owie \nRana wygl¹da na star¹ i ju¿ zaczyna powoli gniæ" << endl << endl;
				cout << "Niestety dyplomacja nie ma tu jakiegokolwiek znaczenia \nBiedne stworzenie rusza szar¿¹ wymachuj¹c pa³¹!" << endl;
				system("pause");
				monster.spown_monster(50, 25, 4, 60, 130, "Goblin");
				fight(hero, monster);
				system("cls");
				cout << "Na szczêœcie z ³atwoœci¹ uda³o mi siê pokonaæ tego zawodnika" << endl << endl;
				cout << "Po dok³adniejszym przygl¹dniêciu siê piwnicznce zauwa¿y³em \ndzbany i odkorkowan¹ beczkê. \nKilka g³êbszych na pewno nie zaszkodzi!" << endl;
				hero.heal(50);
				system("pause");
				system("cls");
				break;
			}
			case '3':
				hero.show_stats();
				break;
		default:
			cout << "Niepoprawny wybór!" << endl;
			system("pause");
			return tawer_start(hero,monster,zadanie);
		}
	}	
}

void startgame() {
	Hero postac;
	Monster monster;
	Quest zadanie;
	setlocale(LC_ALL, "polish");
	postac.load();
	wprowadzenie();
	postac.show();
	tawer_start(postac,monster,zadanie);
}