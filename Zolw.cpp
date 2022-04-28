#include "Zolw.h"

Zolw::Zolw (Swiat& swiat, Punkt pozycja) : Zwierze(swiat, pozycja, SILA_ZOLWIA, INICJATYWA_ZOLWIA, ZNAK_ZOLWIA, ZWYKLY_ZASIEG_RUCHU, SZANSA_NA_RUCH_ZOLWIA) {

}

bool Zolw::TakiSamGatunek(Organizm* inny) {
	return dynamic_cast<Zolw*>(inny);
}

Organizm* Zolw::KlonujSiebie(Punkt pozycja) {
	return new Zolw(swiat, pozycja);
}

std::string Zolw::NaString()const {
	return "Zolw" + Organizm::NaString();
}

bool Zolw::CzyOdbilAtak(Organizm* atakujacy) {
	if (atakujacy->GetSila() < SILY_ATAKOW_BLOKOWANE_PRZEZ_ZOLWIA) 
		return true;	
	else
		return false;
}