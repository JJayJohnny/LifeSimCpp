#pragma once
#include "Zwierze.h"

#define SILA_ANTYLOPY 4
#define INICJATYWA_ANTYLOPY 4
#define ZNAK_ANTYLOPY 'a'
#define ZASIEG_RUCHU_ANTYLOPY 2
#define SZANSA_NA_UCIECZKE_ANTYLOPY 50

class Antylopa : public Zwierze {
public:
	Antylopa(Swiat& swiat, Punkt pozycja);
	bool TakiSamGatunek(Organizm* inny) override;
	Organizm* KlonujSiebie(Punkt pozycja) override;
	std::string NaString() const override;
	bool CzyUciekl(Organizm* atakujacy) override;
};