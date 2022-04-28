#include "Lis.h"

Lis::Lis(Swiat& swiat, Punkt pozycja) : Zwierze(swiat, pozycja, SILA_LISA, INICJATYWA_LISA, ZNAK_LISA, ZWYKLY_ZASIEG_RUCHU, ZWYKLA_SZANSA_NA_RUCH) {

}

bool Lis::TakiSamGatunek(Organizm* inny) {
	return dynamic_cast<Lis*>(inny);
}

Organizm* Lis::KlonujSiebie(Punkt pozycja) {
	return new Lis(swiat, pozycja);
}

std::string Lis::NaString()const {
	return "Lis" + Organizm::NaString();
}

void Lis::Ruch(){
	int czyRuch = rand() % 100;
	if (czyRuch < szansaNaRuch) {
		std::vector<Punkt> pola = swiat.GetSasiedniePola(this->GetPozycja());
		while (pola.size() > 0) {
			int r = rand() % pola.size();
			Organizm* naPolu = swiat.ZnajdzOrganizmNaPolu(pola[r], this);
			if (naPolu != nullptr && naPolu->GetSila() > this->GetSila()) {
				pola.erase(pola.begin() + r);
				swiat.DodajLog(this->NaString() + " wyczul " + naPolu->NaString() + " i nie zaatakowal");
			}
			else {
				this->SetPozycja(pola[r]);
				pola.clear();
			}
		}
	}
}