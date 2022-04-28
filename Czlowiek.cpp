#include "Czlowiek.h"

Czlowiek::Czlowiek(Swiat& swiat, Punkt pozycja) : Zwierze(swiat, pozycja, SILA_CZLOWIEKA, INICJATYWA_CZLOWIEKA, ZNAK_CZLOWIEKA, ZWYKLY_ZASIEG_RUCHU, ZWYKLA_SZANSA_NA_RUCH), pozostalyCzasTrwaniaUmiejetnosci(0), cooldownUmiejetnosci(COOLDOWN_UMIEJETNOSCI_CZLOWIEKA), umiejetnoscAktywna(false) {
	this->ZwiekszWiek();
}

std::string Czlowiek::NaString() const {
	return "Czlowiek" + Organizm::NaString();
}

void Czlowiek::Ruch() {
	Punkt nowa = this->GetPozycja();
	char pierwszy = _getch();
	if (pierwszy == UMIEJETNOSC) {
		if (cooldownUmiejetnosci == 0) {
			umiejetnoscAktywna = true;
			cooldownUmiejetnosci = COOLDOWN_UMIEJETNOSCI_CZLOWIEKA + CZAS_TRWANIA_UMIEJETNOSCI_CZLOWIEKA + 1;
			pozostalyCzasTrwaniaUmiejetnosci = CZAS_TRWANIA_UMIEJETNOSCI_CZLOWIEKA + 1;
		}
	}
	else if (pierwszy == ZAPIS) {
		swiat.Zapisz();
	}
	else {
		int klawisz = _getch();
		switch (klawisz) {
		case GORA:
			if (nowa.y > 0)
				nowa.y--;
			break;
		case DOL:
			if (nowa.y < swiat.wysokoscPlanszy - 1)
				nowa.y++;
			break;
		case LEWO:
			if (nowa.x > 0)
				nowa.x--;
			break;
		case PRAWO:
			if (nowa.x < swiat.szerokoscPlanszy - 1)
				nowa.x++;
			break;
		}
	}
	this->SetPozycja(nowa);
}

bool Czlowiek::TakiSamGatunek(Organizm* inny) {
	return dynamic_cast<Czlowiek*>(inny);
}

Organizm* Czlowiek::KlonujSiebie(Punkt pozycja) {
	return new Czlowiek(swiat, pozycja);
}

void Czlowiek::Kolizja(Organizm* inny) {
	//obsluga umiejetnosci specjalnej
	if (umiejetnoscAktywna) {
		std::vector<Punkt> pola = swiat.GetSasiedniePola(this->GetPozycja());
		for (int i = 0; i < pola.size(); i++) {
			Organizm* o = swiat.ZnajdzOrganizmNaPolu(pola[i], this);
			if (o != nullptr) {
				o->Zgin();
				swiat.DodajLog(this->NaString() + " pali umiejetnoscia " + o->NaString());
			}
		}
		pozostalyCzasTrwaniaUmiejetnosci--;
		if (pozostalyCzasTrwaniaUmiejetnosci == 0)
			umiejetnoscAktywna = false;
	}
	if (cooldownUmiejetnosci > 0)
		cooldownUmiejetnosci--;
	swiat.DodajLog("Cooldown umiejetnosci: " + std::to_string(cooldownUmiejetnosci) + " czas trwania: " + std::to_string(pozostalyCzasTrwaniaUmiejetnosci));

	//normalna obsluga kolizji
	Zwierze::Kolizja(inny);
}
