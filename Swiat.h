#pragma once
#include <vector>
#include "Organizm.h"
#include <time.h>
#include <cstdlib>
#include <string>

#define SCIEZKA_DO_ZAPISOW "saves\\"
#define MAX_WORLD_WIDTH 30
#define MAX_WORLD_HEIGHT 30

class Organizm;

class Swiat {
private:
	unsigned int tura;
	bool symuluj;
	std::vector<Organizm*> organizmy;
	std::vector<std::string> logi;
public:
	const unsigned int szerokoscPlanszy;
	const unsigned int wysokoscPlanszy;
	Swiat(unsigned int szerokoscPlanszy, unsigned int wysokoscPlanszy);
	void WykonajTure();
	void RysujSwiat();
	void DodajOrganizm(Organizm* org);
	~Swiat();
	Organizm* ZnajdzOrganizmNaPolu(Punkt pozycja, Organizm* wylaczony);
	std::vector<Punkt> GetSasiedniePola(Punkt pole) const;
	void PogrzebZmarlych();
	void DodajLog(std::string log);
	bool Symuluje() const;
	void Zapisz();
	void WypiszLogi();

	friend std::ostream& operator<<(std::ostream& os, const Swiat& s);
	friend std::istream& operator>>(std::istream& is, Swiat& s);
};