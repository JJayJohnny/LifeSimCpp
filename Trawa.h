#pragma once
#include "Roslina.h"

#define SILA_TRAWY 0
#define ZNAK_TRAWY 'T'

class Trawa : public Roslina {
public:
	Trawa(Swiat& swiat, Punkt pozycja);
	Organizm* KlonujSiebie(Punkt pozycja) override;
	std::string NaString() const override;
};