#include "Guarana.h"

Guarana::Guarana(Swiat& swiat, Punkt pozycja) : Roslina(swiat, pozycja, SILA_GUARANY, ZNAK_GUARANY, SZANSA_NA_ROZROST, ZWYKLA_ILOSC_PROB_ROZROSTU) {

}

Organizm* Guarana::KlonujSiebie(Punkt pozycja) {
	return new Guarana(swiat, pozycja);
}

std::string Guarana::NaString() const {
	return "Guarana" + Organizm::NaString();
}

void Guarana::Kolizja(Organizm* inny) {
	if (inny != nullptr) {
		swiat.DodajLog(inny->NaString() + " zjada " + this->NaString() + " i jego sila zwieksza sie o " + std::to_string(BONUSOWA_SILA_GUARANY));
		inny->SetSila(inny->GetSila() + BONUSOWA_SILA_GUARANY);
		this->Zgin();
	}
}