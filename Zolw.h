#pragma once
#include "Zwierze.h"

#define SILA_ZOLWIA 2
#define INICJATYWA_ZOLWIA 1
#define ZNAK_ZOLWIA 'z'
#define SZANSA_NA_RUCH_ZOLWIA 25
#define SILY_ATAKOW_BLOKOWANE_PRZEZ_ZOLWIA 5

class Zolw : public Zwierze {
public:
	Zolw(Swiat& swiat, Punkt pozycja);
	bool TakiSamGatunek(Organizm* inny) override;
	Organizm* KlonujSiebie(Punkt pozycja) override;
	std::string NaString() const override;
	bool CzyOdbilAtak(Organizm* atakujacy) override;
};