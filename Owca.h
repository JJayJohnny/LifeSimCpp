#pragma once
#include "Zwierze.h"

#define SILA_OWCY 4
#define INICJATYWA_OWCY 4
#define ZNAK_OWCY 'o'

class Owca : public Zwierze {
public:
	Owca(Swiat& swiat, Punkt pozycja);
	bool TakiSamGatunek(Organizm* inny) override;
	Organizm* KlonujSiebie(Punkt pozycja) override;
	std::string NaString() const override;
};