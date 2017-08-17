#include "stdafx.h"
#include "resource.h"
#include "Hero.h"
#include "Monster.h"
#include "Quest.h"

int cooldown = 0;
int hp_monster;
int visited = 0, visited2 = 0;
//void fight(Hero &hero, Monster &monster);

//funkcje og�lnego urzytku 
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
		cout << "Pomoc! \n1. Postacie \n2. O grze \n3. Powr�t" << endl;

		wb = _getch();
		system("cls");
		switch (wb) {
		case '1':
			cout << "Wojownik. \nSilny odporny na ataki fizyczny posiadajacy duzo pancerza." << endl;
			cout << "Niestety posiada znacznie mniej zr�czno�ci co powoduje, \n�e wyprowadzane ataki maj� mniejszy stopie� trafienia." << endl;
			cout << "G��wnym atutem wojownika jest drugi jego skill \nPozwala on uderzy� z czterokrotn� si�� przeciwnika!" << endl;
			cout<<endl << "Zabojca. \nSzybki, posiadaj�cy niesamowit� zwinno�� \nPosiada o wiele mniejsze obra�enia aczkolwiek jest w stanie wyprowadza� je cz�ciej" << endl;
			cout << "G��wnym atutem tej postaci jest jego skill zapewniaj�cy potrujny atak \nNiestety jest on r�wnie� obarczony d�ugim czasem regeneracji!" << endl;
			cout << endl << "Paladyn. \nNiestety w obecnym stanie gry posta� niedoko�czona \nNie polecam nim gra�." << endl;
			cout << "W kolejnym patchu b�dzie rozbudowywana"<<endl;
			system("pause");
			system("cls");
			break;
		case '2':
			cout << "W grze g��wnym zadaniem jest pod��a� za w�tkiem fabularnym \nJest to wersja demonstracyjna w przysz�o�ci zostan� dodane nowe usprawnienia \nTrzy a obecnie dwie postaci, \ndaj� mo�liwo�� poznania �wiata w kt�rym przyjdzie nam stawi� czo�a niebespiecznym przygod�!" << endl;
			system("pause");
			system("cls");
			break;
		case '3':
			system("cls");
			cout << "Nast�pi powr�t do menu..." << endl;
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
	cout << "Podr� trwa ju� kilka miesiecy od k�d op�ci�em rodzinne wschodnie stepy" << endl;
	cout << "Choroba morska stala sie zaledwie wspomnieniem pocz�tk�w tej trudnej podr�y \nale to jak i sprz�tanie pok�adu dzien w dzien bylo neiwielk� cen� jak na tak \ndalek� wypraw�." << endl;
	cout << "Dzi� stoj� z usmiechem na twarzy obserw�jac jak powoli statek cumuje w zatoce. \nCieply klimat i piekna pogoda sprawia ze ta kraina wydaje byc sie rajem." << endl;
	system("pause");
	system("cls");
	cout << "Po przybiciu do brzegu kazano mi udac sie do stra�nika w celnicy \naby sie zameldowa�." << endl;
	cout << "Wygl�d dzielnicy portowej przyozdabia krz�tanina tragarzy, \nkt�rzy wij� si� swoimi scie�kami by dostarczy� na czas \nbezcenne dla ich w�a�cicieli produkty. \nGwar wszystko ogarniaj�cy sieje zam�t w zmys�ach \nby ju� po chwili obserwacji mo�na by�o dostrzec piekno naturalnego porz�dku \nNiczym w mr�wczym kopcu, ka�dy ma tu swoje zadanie..." << endl;
	system("pause");
	system("cls");
	cout << "Budynek w kt�rym znajdowa�a si� celnica by� dwupi�trowy, m�rowany \ndrzwi wielkie wzmacniane metalowymi okuciami"<<endl;
	cout << "W �rodku czeka� na mnie przy swym stoliku stra�nik, kt�ry co� skroba� na kartce" << endl;
	system("pause");
	system("cls");
}

void droga(string n, int charakter) {
	setlocale(LC_ALL, "polish");
	char wb, wb2;
	system("cls");
	cout << "A wiec " << n << " powiedz mi co Ci� sprowadza do tej krainy?" << endl << endl;
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
	cout << "Jak d�ugo zamierzasz pozsota� tutaj?" << endl<<endl;
	cout << "1. Nie jestem pewien" << endl;
	cout << "2. Jaki� czas" << endl;
	cout << "3. Dopiero tu przyby�em musz� si� rozej�e�, wtedy postanowi�" << endl;

	wb2 = _getch();
	switch (wb2) {
	case '1':
		system("cls");
		cout << "1. Nie jestem pewien" << endl<<endl;
		cout << "Ah. Niezdecydowa�e� jeszcze" << endl;
		break;
	case '2':
		system("cls");
		cout << "2. Jaki� czas" << endl<<endl;
		cout << "Yhmy..." << endl;
		break;
	case '3':
		system("cls");
		cout << "3. Dopiero tu przyby�em musz� si� rozej�e�, wtedy postanowi�" << endl<<endl;
		cout << "My�l� �e znajd� si� tu ciekawe rzeczy do zrobienia" << endl;
		break;
	default:break;
	}

	system("pause");
	system("cls");
	cout << "A w�a�nie..." << endl;
	cout << "Jako �e jeste� nowy w tej krainie musz� da� Ci jakie� zadanie sprawdzaj�ce \nKt�re dowiedzie Twojej przydatno�ci" << endl;
	cout << "Na zach�d od miasta jest �cie�ka, kt�ra prowadzi przez las \nNa ko�cu tej �cie�ki znajdziesz sporych rozmiar�w wierz�" << endl;
	cout << "Nie spos�b jej omin�� \n\nChcia�bym aby� zdoby� dla nas pewien przedmiot znajduj�cy si� na szczycie tej wierzy" << endl;
	cout << "Jest to kamienny puchar, skradziony przez szalonego ch�opaka, kt�ry ukrywa si� w�a�nie w tej wierzy" << endl;
	cout << "To nie powinno by� trudne zadanie a Twoje umiej�tno�ci na pewno sprawi�, �e \nszybko rozprawisz si� z rabusiem i dostarczysz skradziony przedmiot do mnie" << endl;
	system("pause");
	system("cls");
	cout << "Oczywi�cie jesli chodzi o wyposa�enie to mog� da� Ci or�..." << endl<<endl;
	if (charakter == 1) {
		cout << "Zaraz, zaraz co� tu znajd� dla wojownika..." << endl;
		cout << "O prosz� ten miecz na pewno powinien wystarczy�" << endl;
		system("pause");
		system("cls");
		cout << "Dostajesz du�y wywa�ony miecz o szerokim ostrzu i solidnej r�koje�ci"<<endl<<endl;
		system("pause");
		system("cls");
	}
	else if (charakter == 2) {
		cout << "Zaraz, zaraz co� tu znajd� dla zabojcy..." << endl;
		cout << "O prosz� te sztylety na pewno powinny wystarczy�" << endl;
		system("pause");
		system("cls");
		cout << "Dostajesz standardowe sztylety z ca�kiem wygodnymi r�koje�ciami i ostrej klindze" << endl << endl;
		system("pause");
		system("cls");
	}
	else if (charakter == 3) {
		cout << "Zaraz, zaraz co� tu znajd� dla palladyna..." << endl;
		cout << "O prosz� te miecz powinien wystarczy�" << endl;
		system("pause");
		system("cls");
		cout << "Dostajesz kr�tki szeroki miecz legionisty... Przeciez wiara jest tw� najwi�ksz� broni�" << endl << endl;
		system("pause");
		system("cls");
	}
	
	system("pause");
	system("cls");
	cout << "Nim dotar�em do opisanej przez stra�nika lokacji zapad� ju� wiecz�r \nEhh.. Szkoda �e nie wzi��em ze sob� pochodni \nW �rodku mo�� by� ciemno. \nWierza by�a dosy� wysoka, okoliczne tereny natomiast martwe. \nWsz�dzie czu� by�o zgnielizn�..." << endl;
	system("pause");
	system("cls");
	cout << "Dziwne... \nCokolwiek tu si� wydarzy�o wygl�da to jakby wzi�o sw�j pocz�tek od tej wierzy \nNo c� to nie czas na  zastanawianie si� nad przyczynami tej zarazy. \nPora rusza� w drog�!";
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
				cout << "Posiadasz " << hp_hero <<"/"<< hp_max << " Punkt�w �ycia!" << endl;
				cout << "Tw�j przeciwnik posiada jeszcze " << hp_monster << endl << endl;
				cout << "1. Atak podstawowy" << endl;
				cout << "2. Pot�ny atak! Cooldown 1 ture's" << endl;
				wybor = _getch();
				system("cls");
				switch (wybor) {
				case '1':
					attack_hero = hero.attack1();
					attack_hero -= deff_monster;
					cout << "Wykonujesz cios mieczem" << endl;
					if (attack_hero <= 0) {
						cout << "Nie uda�o zada� Ci si� ciosu!" << endl;
						cooldown = 0;
						break;
					}
					else {
						hp_monster -= attack_hero;
						monster.take_dmg_monster(attack_hero);
						cout << "Zadajesz " << attack_hero << " obra�e�!" << endl;
						cooldown = 0;
						break;
					}
				default:return fight(hero, monster);
				}
				if (hp_monster <= 0) {
					system("pause");
					system("cls");
					cout << "Wr�g pokonany!" << endl;
					system("pause");
					hero.LevelUp(monster.GetExp());
					break;
				}
				
			}
			else {
				system("cls");
				cout << "MENU WALKI" << endl << endl;
				cout << "Posiadasz " << hp_hero <<"/"<< hp_max << " Punkt�w �ycia!" << endl;
				cout << "Tw�j przeciwnik posiada jeszcze " << hp_monster << endl << endl;
				cout << "1. Atak podstawowy" << endl;
				cout << "2. Pot�ny atak!" << endl;
				wybor = _getch();
				system("cls");
				switch (wybor) {
				case '1':
					attack_hero = hero.attack1();
					attack_hero -= deff_monster;
					cout << "Wykonujesz cios mieczem" << endl;
					if (attack_hero <= 0) {
						cout << "Nie uda�o zada� Ci si� ciosu!" << endl;
						break;
					}
					else {
						hp_monster -= attack_hero;
						monster.take_dmg_monster(attack_hero);
						cout << "Zadajesz " << attack_hero << " obra�e�!" << endl;
						break;
					}
				case '2':
					cooldown++;
					attack_hero = hero.attack2();
					attack_hero -= deff_monster;
					cout << "Wykonujesz niezwykle ryzykowny cios z wyskoku!" << endl;
					if (attack_hero <= 0) {
						cout << "Nie uda�o zada� Ci si� ciosu!" << endl;
						break;
					}
					else {
						hp_monster -= attack_hero;
						monster.take_dmg_monster(attack_hero);
						cout << "Zadajesz " << attack_hero << " obra�e�!" << endl;
						break;
					}
				default:return fight(hero, monster);
				}
				if (hp_monster <= 0) {
					system("pause");
					system("cls");
					cout << "Wr�g pokonany!" << endl;
					system("pause");
					hero.LevelUp(monster.GetExp());
					break;
				}
			}			
			cout << endl << "Wr�g atakuje" << endl;
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
				cout << "Posiadasz " << hp_hero <<"/"<< hp_max << " Punkt�w �ycia!" << endl;
				cout << "Tw�j przeciwnik posiada jeszcze " << hp_monster << endl << endl;
				cout << "1. Atak podstawowy" << endl;
				cout << "2. Wiruj�ce sztylety! Cooldown "<< cooldown << " ture's!" << endl;
				wybor = _getch();
				system("cls");
				switch (wybor) {
				case '1':
					cooldown--;
					attack_hero = hero.attack3();
					attack_hero -= deff_monster;
					cout << "Wykonujesz szybki atak sztyletem" << endl;
					if (attack_hero <= 0) {
						cout << "Nie uda�o zada� Ci si� ciosu!" << endl;
						break;
					}
					else {
						hp_monster -= attack_hero;
						monster.take_dmg_monster(attack_hero);
						cout << "Zadajesz " << attack_hero << " obra�e�!" << endl;
						break;
					}
				default:return fight(hero, monster);

				}
				if (hp_monster <= 0) {
					system("pause");
					system("cls");
					cout << "Wr�g pokonany!" << endl;
					system("pause");
					hero.LevelUp(monster.GetExp());
					break;
				}
			}
			else {
				system("cls");
				cout << "MENU WALKI" << endl << endl;
				cout << "Posiadasz " << hp_hero <<"/"<< hp_max << " Punkt�w �ycia!" << endl;
				cout << "Tw�j przeciwnik posiada jeszcze " << hp_monster << endl << endl;
				cout << "1. Atak podstawowy" << endl;
				cout << "2. Wiruj�ce sztylety" << endl;
				wybor = _getch();
				system("cls");
				switch (wybor) {
				case '1':
					attack_hero = hero.attack3();
					attack_hero -= deff_monster;
					cout << "Wykonujesz szybki atak sztyletem" << endl;
					if (attack_hero <= 0) {
						cout << "Nie uda�o zada� Ci si� ciosu!" << endl;
						break;
					}
					else {
						hp_monster -= attack_hero;
						monster.take_dmg_monster(attack_hero);
						cout << "Zadajesz " << attack_hero << " obra�e�!" << endl;
						break;
					}
				case '2':
					system("cls");
					cooldown = 3;
					cout << "Z niesamowit� zwinno�ci� wyrzucasz szybko trzy sztylety!" << endl;
					for (int i = 0; i < 3; i++) {
						attack_hero = 0;
						attack_hero = hero.attack4();
						attack_hero -= deff_monster;
						if (attack_hero <= 0) {

							cout << "N� nie trafi�!" << endl;
						}
						else {
							hp_monster -= attack_hero;
							monster.take_dmg_monster(attack_hero);
							cout << "Zadajesz " << attack_hero << " obra�e�!" << endl;
						}
					}
					break;
				default:
					cout << "Z�y przycisk!" << endl;
					system("pause");
					return fight(hero, monster);

				}
				if (hp_monster <= 0) {
					system("pause");
					system("cls");
					cout << "Wr�g pokonany!" << endl;
					system("pause");
					hero.LevelUp(monster.GetExp());
					break;
				}
			}
			cout << endl << "Wr�g atakuje" << endl;
			attack_monster = monster.attack_monster();
			hero.take_dmg(attack_monster);
			hp_hero = hero.get_hp();
			system("pause");
		}
	}
	else if (ch == 3) { // lecimy z palladynem 
		while(hp_hero >= 0 || hp_monster >= 0) { // p�tlelka a� jeden padnie 
			if (cooldown > 0) { // jest coodown to lecim
				system("cls");
				cout << "MENU WALKI" << endl << endl;
				cout << "Posiadasz " << hp_hero <<"/"<< hp_max << " Punkt�w �ycia!" << endl;
				cout << "Tw�j przeciwnik posiada jeszcze " << hp_monster << endl << endl;
				cout << "1. Atak Podstawowy" << endl;
				cout << "2. Wzmocnienie ataku, Cooldown: "<< cooldown << endl;
				wybor = _getch();
				switch (wybor) {
				case '1':
					cooldown--; // powoli schodzimy z cooldowna xD
					attack_hero = hero.attack5();
					attack_hero -= deff_monster;
					
					if (hero.GetBufInfo() == TRUE) cout << "Z uczuciem jakby �wi�ty anio� wykonywa� z Tob� ruch mieczem"<< endl;
					cout << "Wykonujesz precyzyjne ci�cie" << endl;
					if (attack_hero <= 0) {
						cout << "Nie uda�o Ci si� zada� obra�e�!" << endl;
						hero.buffoff(); // usuwamy buffa gdy� jest tylko jednorazowy :) 
						break;
					}
					else {
						hp_monster -= attack_hero;
						monster.take_dmg_monster(attack_hero);
						cout << "Zadajesz " << attack_hero << " obra�e�!" << endl;
						hero.buffoff(); // usuwamy buffa gdy� jest tylko jednorazowy :) 
						break;
	
					}
				default:return fight(hero,monster);
				}
				if (hp_monster <= 0) {
					system("pause");
					system("cls");
					cout << "Wr�g pokonany!" << endl;
					system("pause");
					hero.LevelUp(monster.GetExp());
					break;
				}
			}
			else { // jelsi nie ma cooldown to lecimy z koksem 
				system("cls");
				cout << "MENU WALKI" << endl << endl;
				cout << "Posiadasz " << hp_hero <<"/"<< hp_max << " Punkt�w �ycia!" << endl;
				cout << "Tw�j przeciwnik posiada jeszcze " << hp_monster << endl << endl;
				cout << "1. Atak Podstawowy" << endl;
				cout << "2. Wzmocnienie ataku" << endl;
				wybor = _getch();
				switch (wybor) {
				case '1':
					attack_hero = hero.attack5();
					attack_hero -= deff_monster;
					cout << "Wykonujesz precyzyjne ci�cie" << endl;
					if (attack_hero <= 0) {
						cout << "Nie uda�o Ci si� zada� obra�e�!" << endl;
						hero.buffoff(); // usuwamy buffa gdy� jest tylko jednorazowy :) 
						break;
					}
					else {
						hp_monster -= attack_hero;
						monster.take_dmg_monster(attack_hero);
						cout << "Zadajesz " << attack_hero << " obra�e�!" << endl;
						hero.buffoff(); // usuwamy buffa gdy� jest tylko jednorazowy :) 
						break;
					}				
				case '2':
					hero.buffon(); // uruchamia si� buff :D
					cout << "Po chwili modlitwy wzmacniasz czujesz nap�yw niesamowitej energi"<< endl << "Nastepny tw�j atak b�dzie pot�niejszy"<< endl;
					cooldown = 2; // ustawiamy cooldown
					break;
				default:return fight(hero, monster);
				}
				if (hp_monster <= 0) {
					system("pause");
					system("cls");
					cout << "Wr�g pokonany!" << endl;
					system("pause");
					hero.LevelUp(monster.GetExp());
					break;
				}
			}
			cout << endl << "Wr�g atakuje" << endl;
			attack_monster = monster.attack_monster();
			hero.take_dmg(attack_monster);
			hp_hero = hero.get_hp();
			system("pause");	
		}
	}
}	
void tawer_v2(Hero &hero, Monster &monster) {
	system("cls");
	cout << "Pokonuj�c schody docieram do kolejnego pomieszczenia" << endl;
	cout << "Po przej�ciu przez niewielkie drzwi \nz miejsca dobieg� do mnie przera�liwy krzyk!" << endl;
	cout << "Wielki zielony trol dostrzega mnie b�yskawicznie i atakuje!" << endl;
	monster.spown_monster(120, 33, 5, 50, 55, "Trol");
	fight(hero,monster);
	system("cls");
	cout << "Uff uda�o mi si� na szcz�cie pokona� zagro�enie.."<<endl;
	cout << "Sk�d tu si� bior� takie stwory? \nZ t� wierz� jest co� totalnie nie tak" << endl;
	cout << endl << "Przygl�dajac si� pomieszczeniu w kt�rym si� znalaz�em \nDostrzeg�em co� na kszta�t jadalni." << endl;
	cout << "Wielki st� nakryty obfito�ciami, owoce, wyszukane mi�sa i wino \nWszystko wygl�da na �wie�e." << endl;
	cout << "W dodatku �wiat�o �wiec nadaje pi�kny klimat temu miejscu \nSufit to wspania�a kopu�a na kt�rej kto� umie�cil niemal�e boski fresk" << endl;
	cout << "I przepi�kne okienne witra�e z wizerunkami nagich kobiet i m�rzczyzn \npodczas akt�w seksualnych." << endl;
	cout << endl << "Coraz bardziej zaczyna mnie zastanawia� co to jest za miejsce ?!" << endl;
	system("pause");
	system("cls");
	cout << "W chwili gdy si�ga�em ju� po jab�uko dostrzeg�em kantem oka �e co� poruszy�o si� w fotelu pod �cianom." << endl;
	cout << endl << "By�a to nie�no blada posta� z czerwonymi �lepiami. \nUsta mia�a sine, w�osy ledwo widczne. \nPaznokcie u r�k d�ugie jak szpile, wygl�daj� jakby bez problemu mog�y przeci�� skurzan� zbroj�!" << endl;
	cout << "Posta� wpatrywa�a si� we mnie �widruj�cym wzrokiem, \nkt�ry przeszywa� mnie niczym jad w�a krwioobieg swej ofiary" << endl;
	cout << "By�em totalnie sparari�owany, ledwo oddycha�em \na posta� w dziwny nieludzki spos�b przesun�a si� do mnie \nten ruch by� praktycznie bezszelestn pozbawiony jakichkolwiek emocji." << endl;
	cout << endl << "Patrzy� mi prosto w oczy! \nZuwa�y�em jak lekko przes�wa si� k�cik ust �w stwora w suptelny u�miech" << endl;
	cout << "Po chwili jednak oddali� si� i znikn�� za drzwiami \nJeszcze przez chwil� nie mog�em si� rusza�" << endl;
	cout << endl << "W g�owie rodzi�y mi si� pytania... \nPytania bez odpowiedzi!\nW co ja zosta�em wci�gni�ty..." << endl;
	system("pause");
	system("cls");
	cout << "Me serce jeszcze przez d�u�sz� chwil� chcia�o wyrwa� si� z obj�� klatki piersiowej"<<endl;
	cout << "No nic kilka g��bszych wdech�w powietrza i pora si� otrz�sn��"<< endl;
	cout << "Nic mi nie da u�alanie si� nad sob� albo co gorsza panikowanie... \nMusz� twardo st�pa� po ziemi by nie sko�czy� martwym!"<< endl;
	cout << "Drzwi za mna ju� dawno si� zamkn�y i co�... \nCo� jakby pcha�o mnie dalej, bym wszed� g��biej."<<endl;
	cout << "A mo�e drzwi nigdy si� nie zamkn�y tylko to m�j umys� pragnie bym szed� dalej?"<<endl;
	cout << "Pytanie to pojawi�o si� w mojej g�owie z nik�d \nBy w mgnieniu oka zmieni� si� w dobry dowcip"<<endl;
	cout << "Znowu da�em sie nam�wi� na jak�� dziwn� akcj�, kt�ra co gorsza mo�e sta� si� moj� ostatni�!"<<endl;
	system("pause");
	system("cls");
	cout << "Przedemn� oblrzymie drzwi prowadz�ce do jakiego� pomieszczenia ";
}
void tawer_start(Hero &hero, Monster &monster, Quest &zadanie) {
	char p1, p2, p3;
	int dmg_h, dmg_m;
	system("cls");

	while (true) {
		if (visited2 > 0) {
			cout << "Znajdujesz si� ponownie w pierwszym pomieszczeniu nic si� tu nie zmieni�o" << endl << endl;
		}
		else {

			cout << "Wchodz�c do �rodka us�ysza�em zatrzaskuj�ce si� za mn� drzwi \nDosta� si� do �rodka by�o �atwo z wydostaniem ju� chyba tak nie b�dzie..." << endl;
			system("pause");
			system("cls");
		}

		visited2++;

		cout << "Du�y pok�j wype�niony st�ch�ym powietrzem i dwoje drzwi \nCo tu robi�?" << endl << endl;
		cout << "1. Wejd� w drzwi po prawej" << endl;
		cout << "2. Wejd� w drzwi po lewej" << endl;
		cout << "3. Poka� statystyki" << endl;
		p1 = _getch();
		switch (p1) {
		case '1':
			cout << endl << "Widz� schody na g�r�" << endl << endl;
			cout << "1. Wchodz�!" << endl;
			cout << "2. Mam tu jeszcze co� do zbadania" << endl;
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
				cout << endl << "Pok�j juz odwiedzony nic poza wspania�� piwniczk� nie pozosta�o tu do zobaczenia" << endl;
				system("pause");
				break;
			}
			else {
				visited++;
				cout << endl << "W pomieszczeniu panuje ciemno��, na szcz�cie na stoliku jest kaganek \nobok kt�rego znajduje si� krzesiwo" << endl;
				cout << "Po rozpaelniu �wiat�a dostrzedz mo�na majestat tej sali \njest to swoista piwniczka z nielda ma�ym asortymentem r�znych beczuszek i beczek pouk�adanych starannie na rega�ach" << endl;
				system("pause");
				system("cls");
				cout << "Nagle z pomiedzy rega��w wy�ania si� posta� \nNie zadu�a, zgarbiona. Przypominaj�ca troch� dziecko \nSkierowawszy w jej stron� kaganek okaza�o si�, �e to goblin z do�� poka�na ran� w g�owie \nRana wygl�da na star� i ju� zaczyna powoli gni�" << endl << endl;
				cout << "Niestety dyplomacja nie ma tu jakiegokolwiek znaczenia \nBiedne stworzenie rusza szar�� wymachuj�c pa��!" << endl;
				system("pause");
				monster.spown_monster(50, 25, 4, 60, 130, "Goblin");
				fight(hero, monster);
				system("cls");
				cout << "Na szcz�cie z �atwo�ci� uda�o mi si� pokona� tego zawodnika" << endl << endl;
				cout << "Po dok�adniejszym przygl�dni�ciu si� piwnicznce zauwa�y�em \ndzbany i odkorkowan� beczk�. \nKilka g��bszych na pewno nie zaszkodzi!" << endl;
				hero.heal(50);
				system("pause");
				system("cls");
				break;
			}
			case '3':
				hero.show_stats();
				break;
		default:
			cout << "Niepoprawny wyb�r!" << endl;
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