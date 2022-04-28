#include "Swiat.h"
#include "Czlowiek.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include "WszystkieOrganizmy.h"

Swiat::Swiat(unsigned int szerokoscPlanszy, unsigned int wysokoscPlanszy) : szerokoscPlanszy(szerokoscPlanszy), wysokoscPlanszy(wysokoscPlanszy), tura(1), symuluj(true){

}

void Swiat::WykonajTure() {
	srand(time(NULL));
	for (int i = 0; i < organizmy.size(); i++)
	{
		if (organizmy[i]->Zywy()) {
			organizmy[i]->Akcja();
			Organizm* przeciwnik = ZnajdzOrganizmNaPolu(organizmy[i]->GetPozycja(), organizmy[i]);
			organizmy[i]->Kolizja(przeciwnik);
		}
	}
	PogrzebZmarlych();
	std::sort(organizmy.begin(), organizmy.end(), [](Organizm* pierwszy, Organizm* drugi) {
		if (pierwszy->GetInicjatywa() != drugi->GetInicjatywa())
			return (pierwszy->GetInicjatywa() > drugi->GetInicjatywa());
		else
			return (pierwszy->GetWiek() > drugi->GetWiek());
		});
	tura++;
}

void Swiat::RysujSwiat() {
	char** plansza = new char* [wysokoscPlanszy];
	for (int i = 0; i < wysokoscPlanszy; i++)
		plansza[i] = new char[szerokoscPlanszy];

	for (int i = 0; i < wysokoscPlanszy; i++)
		for (int j = 0; j < szerokoscPlanszy; j++)
			plansza[i][j] = ' ';
	for (int i = 0; i < organizmy.size(); i++)
	{
		int x = organizmy[i]->GetPozycja().x;
		int y = organizmy[i]->GetPozycja().y;
		plansza[y][x] = organizmy[i]->Rysuj();
	}

	system("cls");
	std::cout << "|Jan Barczewski 188679|" << std::endl;
	std::cout << "Tura: " << tura << std::endl;

	std::cout << "Ilosc organizmow: " << organizmy.size() << std::endl;

	for (int j = 0; j < szerokoscPlanszy; j++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < wysokoscPlanszy; i++) {
		for (int j = 0; j < szerokoscPlanszy; j++) {
			std::cout << plansza[i][j];
		}
		std::cout << "|" << std::endl;
	}
	for (int j = 0; j < szerokoscPlanszy; j++)
		std::cout << "-";
	std::cout << std::endl;

	for (int i = 0; i < wysokoscPlanszy; i++)
		delete[] plansza[i];
	delete[] plansza;

	WypiszLogi();
}

void Swiat::WypiszLogi() {
	for (int i = 0; i < logi.size(); i++)
		std::cout << logi[i] << std::endl;
	logi.clear();
}

void Swiat::DodajOrganizm(Organizm* org) {
	organizmy.push_back(org);
}

Swiat::~Swiat() {
	for (int i = organizmy.size() - 1; i >= 0; i--) {
		delete organizmy[i];
		//organizmy.pop_back();
	}
	std::cout << "Destruktor swiata" << std::endl;
}

Organizm* Swiat::ZnajdzOrganizmNaPolu(Punkt pozycja, Organizm* wylaczony) {
	for (int i = 0; i < organizmy.size(); i++)
		if (organizmy[i]->GetPozycja().x == pozycja.x && organizmy[i]->GetPozycja().y == pozycja.y && organizmy[i] != wylaczony)
			return organizmy[i];
	return nullptr;
}

std::vector<Punkt> Swiat::GetSasiedniePola(Punkt pole) const {
	std::vector<Punkt> pola;
	if (pole.x > 0)
		pola.push_back(Punkt(pole.x - 1, pole.y));
	if (pole.x < szerokoscPlanszy-1)
		pola.push_back(Punkt(pole.x + 1, pole.y));
	if (pole.y > 0)
		pola.push_back(Punkt(pole.x, pole.y - 1));
	if (pole.y < wysokoscPlanszy -1)
		pola.push_back(Punkt(pole.x, pole.y+1));
	return pola;
}

void Swiat::PogrzebZmarlych() {
	for (int i = 0; i < organizmy.size(); i++) {
		if (!organizmy[i]->Zywy()) {
			if (dynamic_cast<Czlowiek*>(organizmy[i]))
				symuluj = false;
			delete organizmy[i];
			organizmy.erase(organizmy.begin() + i);
		}		
	}
}

void Swiat::DodajLog(std::string log) {
	logi.push_back(log);
}

bool Swiat::Symuluje() const{
	return symuluj;
}

std::ostream& operator<<(std::ostream& os, const Swiat& s) {
	os << s.szerokoscPlanszy << " " << s.wysokoscPlanszy << "\n";
	os << s.tura << " " << s.symuluj << "\n";
	for (int i = 0; i < s.organizmy.size(); i++) {
		os << s.organizmy[i];
	}
	return os;
}

std::istream& operator>>(std::istream& is, Swiat& s) {
	is >> s.tura >> s.symuluj;
	char znak;
	Punkt pozycja;

	while (is >> znak) {
		//is >> znak;
		is >> pozycja;
		Organizm* nowy = GetOrganizmFromZnak(znak, s, pozycja);
		is >> *nowy;
		s.DodajOrganizm(nowy);
	}

	return is;
}

void Swiat::Zapisz() {
	std::string nazwaPliku;
	std::cout << "Podaj nazwe pliku do zapisania" << std::endl;
	std::cin >> nazwaPliku;
	std::ofstream ofs(SCIEZKA_DO_ZAPISOW + nazwaPliku);
	ofs << *this;
	ofs.close();
}

