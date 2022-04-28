#pragma once
#include "Zwierze.h"

#define SILA_LISA 3
#define INICJATYWA_LISA 7
#define ZNAK_LISA 'L'

class Lis : public Zwierze {
public:
	Lis(Swiat& swiat, Punkt pozycja);
	bool TakiSamGatunek(Organizm* inny) override;
	Organizm* KlonujSiebie(Punkt pozycja) override;
	std::string NaString() const override;
	void Ruch() override;
};