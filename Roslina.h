#pragma once
#include "Organizm.h"

#define SZANSA_NA_ROZROST 10
#define ZWYKLA_ILOSC_PROB_ROZROSTU 1
#define INICJATYWA_ROSLIN 0

class Roslina : public Organizm {
protected:
	int szansaNaRozrost;
	int iloscProbRozrostu;
public:
	Roslina(Swiat& swiat, const Punkt& pozycja, const int& sila, const char& znak, const int& szansaNaRozrost, const int& iloscProbRozrostu);
	virtual void Akcja() override;
	virtual void Kolizja(Organizm* inny) override;
	void RozmnozSie() override;
	virtual Organizm* KlonujSiebie(Punkt pozycja) = 0;
};