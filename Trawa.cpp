#include "Trawa.h"

Trawa::Trawa(Swiat& swiat, Punkt pozycja) : Roslina(swiat, pozycja, SILA_TRAWY, ZNAK_TRAWY, SZANSA_NA_ROZROST, ZWYKLA_ILOSC_PROB_ROZROSTU) {

}

Organizm* Trawa::KlonujSiebie(Punkt pozycja) {
	return new Trawa(swiat, pozycja);
}

std::string Trawa::NaString() const {
	return "Trawa" + Organizm::NaString();
}