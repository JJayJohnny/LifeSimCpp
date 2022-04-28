#include "Roslina.h"

Roslina::Roslina(Swiat& swiat, const Punkt& pozycja, const int& sila, const char& znak, const int& szansaNaRozrost, const int& iloscProbRozrostu) : Organizm(swiat, pozycja, sila, INICJATYWA_ROSLIN, znak), szansaNaRozrost(szansaNaRozrost), iloscProbRozrostu(iloscProbRozrostu) {

}

void Roslina::Akcja() {
	if (this->GetWiek() > 0) {
		for (int i = 0; i < iloscProbRozrostu; i++) {
			int szansa = rand() % 100;
			if (szansa < szansaNaRozrost)
				this->RozmnozSie();
		}
	}
	this->ZwiekszWiek();
}

void Roslina::Kolizja(Organizm* inny) {
	if (inny != nullptr) {
		swiat.DodajLog(inny->NaString() + " zjada " + this->NaString());
		this->Zgin();
	}
}

void Roslina::RozmnozSie() {
	std::vector<Punkt> pola = swiat.GetSasiedniePola(this->GetPozycja());
	while (pola.size()>0) {
		int i = rand() % pola.size();
		if (swiat.ZnajdzOrganizmNaPolu(pola[i], this) == nullptr)
		{
			Organizm* dziecko = this->KlonujSiebie(pola[i]);
			swiat.DodajOrganizm(dziecko);
			swiat.DodajLog("Rozrosl sie: " + dziecko->NaString());
			break;
		}
		else
			pola.erase(pola.begin() + i);
	}
}