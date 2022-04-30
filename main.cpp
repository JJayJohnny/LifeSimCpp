#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
//#include "Swiat.h"
#include "KreatorSwiata.h"
#include <Windows.h>
#include <fstream>
#include <string>
#include "WszystkieOrganizmy.h"




int main() {
	SetConsoleTitleA("PO Projekt 1 | Jan Barczewski(188679)");
	KreatorSwiata kreator;
	Swiat* swiat = nullptr;
	char opcja;
	std::cout << "Wczytac swiat, czy wygenerowac nowy? (n - nowy, w - wczytaj)";
	std::cin >> opcja;
	
	if (opcja == 'w') {
		swiat = kreator.WczytajSwiat();
	}
	else if (opcja == 'n') {
		swiat = kreator.WygenerujSwiat();
	}
	
	if (swiat != nullptr) {
		while (swiat->Symuluje()) {

			swiat->RysujSwiat();
			swiat->WykonajTure();
		}
		swiat->RysujSwiat();
		delete swiat;
	}

	znakiWszystkichOrganizmow.~vector();
	_CrtDumpMemoryLeaks();
	
	return 0;
}