#pragma once
#include "Roslina.h"

#define SILA_GUARANY 0
#define ZNAK_GUARANY 'g'
#define BONUSOWA_SILA_GUARANY 3

class Guarana : public Roslina {
public:
	Guarana(Swiat& swiat, Punkt pozycja);
	Organizm* KlonujSiebie(Punkt pozycja) override;
	std::string NaString() const override;
	void Kolizja(Organizm* inny) override;
};