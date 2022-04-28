#include "Antylopa.h"

Antylopa::Antylopa(Swiat& swiat, Punkt pozycja) : Zwierze(swiat, pozycja, SILA_ANTYLOPY, INICJATYWA_ANTYLOPY, ZNAK_ANTYLOPY, ZASIEG_RUCHU_ANTYLOPY, ZWYKLA_SZANSA_NA_RUCH) {

}

bool Antylopa::TakiSamGatunek(Organizm* inny) {
	return dynamic_cast<Antylopa*>(inny);
}

Organizm* Antylopa::KlonujSiebie(Punkt pozycja) {
	return new Antylopa(swiat, pozycja);
}

std::string Antylopa::NaString()const {
	return "Antylopa" + Organizm::NaString();
}

bool Antylopa::CzyUciekl(Organizm* atakujacy) {
	int szansaNaUcieczke = rand() % 100;
	if (szansaNaUcieczke < SZANSA_NA_UCIECZKE_ANTYLOPY) {
		std::vector<Punkt> pola = swiat.GetSasiedniePola(this->GetPozycja());
		while (pola.size() > 0) {
			int r = rand() % pola.size();
			if (swiat.ZnajdzOrganizmNaPolu(pola[r], this) == nullptr) {
				this->SetPozycja(pola[r]);
				return true;
			}
			else
				pola.erase(pola.begin() + r);
		}
	}
	return false;
}