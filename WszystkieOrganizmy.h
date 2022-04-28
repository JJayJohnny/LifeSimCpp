#pragma once
#include <vector>
#include "Owca.h"
#include "Wilk.h"
#include "Trawa.h"
#include "Czlowiek.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "Barszcz.h"

__declspec(selectany) std::vector<char> znakiWszystkichOrganizmow = { ZNAK_ANTYLOPY, ZNAK_BARSZCZU, ZNAK_GUARANY, ZNAK_LISA, ZNAK_MLECZA, ZNAK_OWCY, ZNAK_TRAWY, ZNAK_WILCZYCHJAGOD, ZNAK_WILKA, ZNAK_ZOLWIA };

inline Organizm* GetOrganizmFromZnak(char znak, Swiat& s, Punkt pozycja) {
	switch (znak) {
	case ZNAK_ANTYLOPY:
		return new Antylopa(s, pozycja);
	case ZNAK_BARSZCZU:
		return new Barszcz(s, pozycja);
	case ZNAK_CZLOWIEKA:
		return new Czlowiek(s, pozycja);
	case ZNAK_GUARANY:
		return new Guarana(s, pozycja);
	case ZNAK_LISA:
		return new Lis(s, pozycja);
	case ZNAK_MLECZA:
		return new Mlecz(s, pozycja);
	case ZNAK_OWCY:
		return new Owca(s, pozycja);
	case ZNAK_TRAWY:
		return new Trawa(s, pozycja);
	case ZNAK_WILCZYCHJAGOD:
		return new WilczeJagody(s, pozycja);
	case ZNAK_WILKA:
		return new Wilk(s, pozycja);
	case ZNAK_ZOLWIA:
		return new Zolw(s, pozycja);
	default:
		return nullptr;
	}
}