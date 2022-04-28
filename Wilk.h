#pragma once
#include "Zwierze.h"

#define SILA_WILKA 9
#define INICJATYWA_WILKA 5
#define ZNAK_WILKA 'w'

class Wilk : public Zwierze {
public:
	Wilk(Swiat& swiat, Punkt pozycja);
	bool TakiSamGatunek(Organizm* inny) override;
	Organizm* KlonujSiebie(Punkt pozycja) override;
	std::string NaString() const override;
};