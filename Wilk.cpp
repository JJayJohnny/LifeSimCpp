#include "Wilk.h"

Wilk::Wilk(Swiat& swiat, Punkt pozycja) : Zwierze(swiat, pozycja, SILA_WILKA, INICJATYWA_WILKA, ZNAK_WILKA, ZWYKLY_ZASIEG_RUCHU, ZWYKLA_SZANSA_NA_RUCH) {

}

bool Wilk::TakiSamGatunek(Organizm* inny) {
	return dynamic_cast<Wilk*>(inny);
}

Organizm* Wilk::KlonujSiebie(Punkt pozycja) {
	return new Wilk(swiat, pozycja);
}

std::string Wilk::NaString()const {
	return "Wilk" + Organizm::NaString();
}