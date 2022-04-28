#pragma once
#include "Roslina.h"

#define SILA_WILCZYCHJAGOD 99
#define ZNAK_WILCZYCHJAGOD 'j'

class WilczeJagody : public Roslina {
public:
	WilczeJagody(Swiat& swiat, Punkt pozycja);
	Organizm* KlonujSiebie(Punkt pozycja) override;
	std::string NaString() const override;
	void Kolizja(Organizm* inny) override;
};