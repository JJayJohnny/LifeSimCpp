#include "Mlecz.h"

Mlecz::Mlecz(Swiat& swiat, Punkt pozycja) : Roslina(swiat, pozycja, SILA_MLECZA, ZNAK_MLECZA, SZANSA_NA_ROZROST, ILOSC_PROB_ROZROSTU_MLECZA) {

}

Organizm* Mlecz::KlonujSiebie(Punkt pozycja) {
	return new Mlecz(swiat, pozycja);
}

std::string Mlecz::NaString() const {
	return "Mlecz" + Organizm::NaString();
}