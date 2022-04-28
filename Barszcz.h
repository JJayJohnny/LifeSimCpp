#pragma once
#include "Roslina.h"

#define SILA_BARSZCZU 10
#define ZNAK_BARSZCZU 'B'

class Barszcz : public Roslina {
public:
	Barszcz(Swiat& swiat, Punkt pozycja);
	Organizm* KlonujSiebie(Punkt pozycja) override;
	std::string NaString() const override;
	void Kolizja(Organizm* inny) override;
	void Akcja() override;
};