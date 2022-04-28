#include "Organizm.h"

Organizm::Organizm(Swiat& swiat, const Punkt pozycja, const int sila, const int inicjatywa, const char znak) : swiat(swiat), pozycja(pozycja), sila(sila), inicjatywa(inicjatywa), znak(znak), zyje(true) , wiek(0){

}

char Organizm::Rysuj() const {
	if (zyje)
		return znak;
	else
		return ' ';
}

int Organizm::GetSila() const {
	return sila;
}

void Organizm::SetSila(int sila) {
	this->sila = sila;
}

int Organizm::GetInicjatywa() const {
	return inicjatywa;
}

void Organizm::SetInicjatywa(int inicjatywa) {
	this->inicjatywa = inicjatywa;
}

Punkt Organizm::GetPozycja() const {
	return pozycja;
}

void Organizm::SetPozycja(Punkt pozycja) {
	this->pozycja = pozycja;
}

bool Organizm::Zywy()const {
	return zyje;
}

int Organizm::GetWiek()const {
	return wiek;
}

void Organizm::SetWiek(int wiek) {
	this->wiek = wiek;
}

void Organizm::ZwiekszWiek() {
	wiek++;
}

bool Organizm::CzyOdbilAtak(Organizm* atakujacy) {
	return false;
}

bool Organizm::CzyUciekl(Organizm* atakujacy) {
	return false;
}

void Organizm::Zgin() {
	zyje = false;
}

std::string Organizm::NaString() const {
	return "(wiek: " + std::to_string(GetWiek()) + " x: " + std::to_string(this->GetPozycja().x) + " y: " + std::to_string(this->GetPozycja().y) +" sila: "+std::to_string(this->GetSila()) + ")";
}