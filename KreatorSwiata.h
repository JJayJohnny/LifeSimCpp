#pragma once
#include "Swiat.h"
#include "WszystkieOrganizmy.h"
#include <fstream>

class KreatorSwiata {
public:
	Swiat* WygenerujSwiat() {
		srand(time(NULL));
		int x = (rand() % MAX_WORLD_WIDTH) + 1;
		int y = (rand() % MAX_WORLD_HEIGHT) + 1;
		Swiat* nowy = new Swiat(x, y);

		int iloscOrganizmow = (rand() % ((x / 2) * (y / 2))) + 1;

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
};