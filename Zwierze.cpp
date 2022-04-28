#include "Zwierze.h"

Zwierze::Zwierze(Swiat& swiat, const Punkt& pozycja, const int& sila, const int& inicjatywa, const char& znak, const int& zasiegRuchu, const int& szansaNaRuch) : Organizm(swiat, pozycja, sila, inicjatywa, znak), zasiegRuchu(zasiegRuchu), szansaNaRuch(szansaNaRuch), poprzedniaPozycja(pozycja) {
}

void Zwierze::Akcja() {
	if (this->GetWiek() > 0) {
		poprzedniaPozycja = this->GetPozycja();
		for (int i = 0; i < zasiegRuchu; i++)
			this->Ruch();
	}
	this->ZwiekszWiek();
}

void Zwierze::Kolizja(Organizm* inny) {
	if (inny != nullptr) {
		if (this->TakiSamGatunek(inny)) {
			if (inny->GetWiek() >= MINIMALNY_WIEK_ROZRODCZY && this->GetWiek() >= MINIMALNY_WIEK_ROZRODCZY) {
				this->CofnijSie();
				this->RozmnozSie();
			}
			else {
				this->CofnijSie();
			}
		}
		else if (dynamic_cast<Zwierze*>(inny)) {
			if (inny->CzyOdbilAtak(this)) {
				this->CofnijSie();
				swiat.DodajLog(inny->NaString() + " zablokowal atak " + this->NaString());
			}
			else if (inny->CzyUciekl(this)) {
				swiat.DodajLog(inny->NaString() + " ucieka przed atakiem " + this->NaString());
			}
			else if (this->GetSila() >= inny->GetSila()) {
				inny->Zgin();
				swiat.DodajLog(this->NaString() + " atakuje i zabija " + inny->NaString());
			}
			else {
				this->Zgin();
				swiat.DodajLog(this->NaString() + " atakuje " + inny->NaString() + ", ale przegrywa");
			}
		}
		else {
			inny->Kolizja(this);
		}
	}
}

void Zwierze::Ruch() {
	int czyRuch = rand() % 100;
	if (czyRuch < szansaNaRuch) {
		std::vector<Punkt> pola = swiat.GetSasiedniePola(this->GetPozycja());
		if (pola.size() > 0) {
			int r = rand() % pola.size();
			this->SetPozycja(pola[r]);
		}
	}
}

void Zwierze::RozmnozSie() {
	std::vector<Punkt> pola = swiat.GetSasiedniePola(this->GetPozycja());
	while (pola.size() > 0) {
		int i = rand() % pola.size();
		if (swiat.ZnajdzOrganizmNaPolu(pola[i], this) == nullptr)
		{
			Organizm* dziecko = this->KlonujSiebie(pola[i]);
			swiat.DodajOrganizm(dziecko);
			swiat.DodajLog("Urodzil sie: " + dziecko->NaString());
			break;
		}
		else
			pola.erase(pola.begin() + i);
	}
}

void Zwierze::CofnijSie() {
	this->SetPozycja(poprzedniaPozycja);
}