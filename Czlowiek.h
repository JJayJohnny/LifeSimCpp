#pragma once
#include "Zwierze.h"
#include <conio.h>

#define SILA_CZLOWIEKA 5
#define INICJATYWA_CZLOWIEKA 4
#define ZNAK_CZLOWIEKA 'C'
#define COOLDOWN_UMIEJETNOSCI_CZLOWIEKA 5
#define CZAS_TRWANIA_UMIEJETNOSCI_CZLOWIEKA 5

#define GORA 72
#define DOL 80
#define LEWO 75
#define PRAWO 77
#define UMIEJETNOSC 'u'
#define ZAPIS 'z'

class Czlowiek : public Zwierze {
private:
	void Ruch() override;
	int cooldownUmiejetnosci;
	int pozostalyCzasTrwaniaUmiejetnosci;
	bool umiejetnoscAktywna;
public:
	Czlowiek(Swiat& swiat, Punkt pozycja);
	std::string NaString() const override;
	//void Akcja() override;
	void Kolizja(Organizm* inny) override;

	bool TakiSamGatunek(Organizm* inny) override;
	Organizm* KlonujSiebie(Punkt pozycja) override;

	friend std::ostream& operator<<(std::ostream& os, const Czlowiek* c) {
		os << c->Rysuj() << " " << c->GetPozycja() << " " << c->GetSila() << " " << c->GetWiek() << " " << c->cooldownUmiejetnosci << " " << c->pozostalyCzasTrwaniaUmiejetnosci << "\n";
		return os;
	}

	void save(std::ostream& os) override {
		os << this->Rysuj() << " " << this->GetPozycja() << " " << this->GetSila() << " " << this->GetWiek() << " " <<this->umiejetnoscAktywna <<" "<< this->cooldownUmiejetnosci << " " << this->pozostalyCzasTrwaniaUmiejetnosci << "\n";
	}

	void load(std::istream& is) override {
		int sila, wiek, cooldownUmiejetnosci, pozostalyCzasTrwaniaUmiejetnosci;
		bool umiejetnoscAktywna;
		is >> sila >> wiek >> umiejetnoscAktywna >>cooldownUmiejetnosci >> pozostalyCzasTrwaniaUmiejetnosci;
		this->SetSila(sila);
		this->SetWiek(wiek);
		this->umiejetnoscAktywna = umiejetnoscAktywna;
		this->cooldownUmiejetnosci = cooldownUmiejetnosci;
		this->pozostalyCzasTrwaniaUmiejetnosci = pozostalyCzasTrwaniaUmiejetnosci;
	}
};