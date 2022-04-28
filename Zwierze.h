#pragma once
#include "Organizm.h"

#define ZWYKLY_ZASIEG_RUCHU 1
#define ZWYKLA_SZANSA_NA_RUCH 100
#define MINIMALNY_WIEK_ROZRODCZY 3
#define COOLDOWN_NA_ROZMNAZANIE 3

class Zwierze : public Organizm {
protected:
	int zasiegRuchu;
	int szansaNaRuch;
	//int cooldownRozmnazania;
	Punkt poprzedniaPozycja;
	virtual void Ruch();
public:
	Zwierze(Swiat& swiat, const Punkt& pozycja, const int& sila, const int& inicjatywa, const char& znak, const int& zasiegRuchu, const int& szansaNaRuch);
	virtual void Akcja() override;
	virtual void Kolizja(Organizm* inny) override;
	virtual bool TakiSamGatunek(Organizm* inny) = 0;
	void RozmnozSie() override;
	virtual Organizm* KlonujSiebie(Punkt pozycja) = 0;
	void CofnijSie();
	
};