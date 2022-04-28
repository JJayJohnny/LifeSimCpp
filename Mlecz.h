#pragma once
#include "Roslina.h"

#define SILA_MLECZA 0
#define ZNAK_MLECZA 'M'
#define ILOSC_PROB_ROZROSTU_MLECZA 3

class Mlecz : public Roslina {
public:
	Mlecz(Swiat& swiat, Punkt pozycja);
	Organizm* KlonujSiebie(Punkt pozycja) override;
	std::string NaString() const override;
};