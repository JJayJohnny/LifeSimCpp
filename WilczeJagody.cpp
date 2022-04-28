#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Swiat& swiat, Punkt pozycja) : Roslina(swiat, pozycja, SILA_WILCZYCHJAGOD, ZNAK_WILCZYCHJAGOD, SZANSA_NA_ROZROST, ZWYKLA_ILOSC_PROB_ROZROSTU) {

}

Organizm* WilczeJagody::KlonujSiebie(Punkt pozycja) {
	return new WilczeJagody(swiat, pozycja);
}

std::string WilczeJagody::NaString() const {
	return "Wilcze jagody" + Organizm::NaString();
}

void WilczeJagody::Kolizja(Organizm* inny) {
	if (inny != nullptr) {
		swiat.DodajLog(inny->NaString() + " zjada " + this->NaString() + " i umiera");
		inny->Zgin();
		this->Zgin();
	}
}