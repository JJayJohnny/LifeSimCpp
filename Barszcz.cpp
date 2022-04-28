#include "Barszcz.h"

Barszcz::Barszcz(Swiat& swiat, Punkt pozycja) : Roslina(swiat, pozycja, SILA_BARSZCZU, ZNAK_BARSZCZU, SZANSA_NA_ROZROST, ZWYKLA_ILOSC_PROB_ROZROSTU) {

}

Organizm* Barszcz::KlonujSiebie(Punkt pozycja) {
	return new Barszcz(swiat, pozycja);
}

std::string Barszcz::NaString() const {
	return "Barszcz sosnowskiego" + Organizm::NaString();
}

void Barszcz::Kolizja(Organizm* inny) {
	if (inny != nullptr) {
		swiat.DodajLog(inny->NaString() + " zjada " + this->NaString() + " i umiera");
		inny->Zgin();
		this->Zgin();
	}
}

void Barszcz::Akcja() {
	std::vector<Punkt> pola = swiat.GetSasiedniePola(this->GetPozycja());
	for (int i = 0; i < pola.size(); i++) {
		Organizm* inny = swiat.ZnajdzOrganizmNaPolu(pola[i], this);
		if (inny != nullptr && !dynamic_cast<Roslina*>(inny)) {
			inny->Zgin();
			swiat.DodajLog(inny->NaString() + " byl za blisko " + this->NaString() + " i zginal");
		}
	}

	Roslina::Akcja();
}