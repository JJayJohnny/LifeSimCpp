#pragma once
#include "Punkt.h"
#include "Swiat.h"
#include <string>
#include <iostream>

class Swiat;

class Organizm {
	int sila, inicjatywa;
	Punkt pozycja;
	char znak;
	bool zyje;
	int wiek;
protected:
	Swiat& swiat;
public:
	Organizm(Swiat& swiat, const Punkt pozycja, const int sila, const int inicjatywa, const char znak);
	virtual void Akcja() = 0;
	virtual void Kolizja(Organizm* inny) = 0;
	char Rysuj() const;
	int GetSila() const;
	void SetSila(int sila);
	int GetInicjatywa() const;
	void SetInicjatywa(int inicjatywa);
	Punkt GetPozycja() const;
	void SetPozycja(Punkt pozycja);
	bool Zywy() const;
	virtual void RozmnozSie() = 0;
	int GetWiek() const;
	void SetWiek(int wiek);
	void ZwiekszWiek();
	virtual bool CzyOdbilAtak(Organizm* atakujacy);
	virtual bool CzyUciekl(Organizm* atakujacy);
	virtual void Zgin();
	virtual std::string NaString() const;

	friend std::ostream& operator<<(std::ostream& os, Organizm* o) {
		o->save(os);
		return os;
	}
	virtual void save(std::ostream& os) {
		if (this->Zywy())
			os << this->Rysuj() << " " << this->GetPozycja() << " " << this->GetSila() << " " << this->GetWiek() << "\n";
	}

	friend std::istream& operator>>(std::istream& is, Organizm& o) {
		o.load(is);
		return is;
	}
	virtual void load(std::istream& is) {
		is >> this->sila >> this->wiek;
	}
};