#pragma once
// deklaracje wszelkich bibliotek cpp oraz w³asnych
#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#include <fstream>

using namespace std;
/*
typedef enum {
	TRUE = 1,
	FALSE = 0
}bool; */

void menu();
int pomoc();
int main();
void startgame();
void wprowadzenie();
void droga(string n, int charakter);