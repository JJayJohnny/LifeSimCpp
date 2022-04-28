#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "Swiat.h"
#include <Windows.h>
#include <fstream>
#include <string>
#include "WszystkieOrganizmy.h"

Swiat* WygenerujSwiat() {
	srand(time(NULL));
	int x = (rand() % MAX_WORLD_WIDTH) + 1;
	int y = (rand() % MAX_WORLD_HEIGHT) + 1;
	Swiat* nowy = new Swiat(x, y);

	int iloscOrganizmow = (rand() % ((x/2) * (y/2)))+1;

	Organizm* czlowiek = new Czlowiek(*nowy, Punkt(rand() % x, rand() % y));
	nowy->DodajOrganizm(czlowiek);

	for (int i = 0; i < iloscOrganizmow; i++) {
		int orgX = rand() % x;
		int orgY = rand() % y;
		if (nowy->ZnajdzOrganizmNaPolu(Punkt(orgX, orgY), nullptr) == nullptr) {
			char znak = znakiWszystkichOrganizmow[rand() % znakiWszystkichOrganizmow.size()];
			Organizm* organizm = GetOrganizmFromZnak(znak, *nowy, Punkt(orgX, orgY));
			nowy->DodajOrganizm(organizm);
		}
		else
			i--;
	}
	
	return nowy;
}

Swiat* WczytajSwiat() {
	std::cout << "Podaj nazwe pliku do wczytania" << std::endl;
	std::string nazwaPliku;
	std::cin >> nazwaPliku;
	if (nazwaPliku != "") {
		int x, y;
		std::ifstream ifs(SCIEZKA_DO_ZAPISOW + nazwaPliku);
		if (ifs.good()) {
			std::cout << "PLIK OK" << std::endl;
			ifs >> x >> y;
			Swiat* swiat = new Swiat(x, y);
			ifs >> *swiat;
			ifs.close();
			return swiat;
		}
		else
		{
			return nullptr;
		}
	}
}


int main() {
	SetConsoleTitleA("PO Projekt 1 | Jan Barczewski(188679)");
	Swiat* swiat = nullptr;
	char opcja;
	std::cout << "Wczytac swiat, czy wygenerowac nowy? (n - nowy, w - wczytaj)";
	std::cin >> opcja;
	
	if (opcja == 'w') {
		swiat = WczytajSwiat();
	}
	else if (opcja == 'n') {
		swiat = WygenerujSwiat();
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