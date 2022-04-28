#include "Owca.h"

Owca::Owca(Swiat& swiat, Punkt pozycja) : Zwierze(swiat, pozycja, SILA_OWCY, INICJATYWA_OWCY, ZNAK_OWCY, ZWYKLY_ZASIEG_RUCHU, ZWYKLA_SZANSA_NA_RUCH){

}

bool Owca::TakiSamGatunek(Organizm* inny) {
	return dynamic_cast<Owca*>(inny);
}

Organizm* Owca::KlonujSiebie(Punkt pozycja) {
	return new Owca(swiat, pozycja);
}

std::string Owca::NaString() const {
	return "Owca" + Organizm::NaString();
}