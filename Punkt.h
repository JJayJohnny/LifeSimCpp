#pragma once
#include <iostream>

class Punkt {
public:
	int x, y;
	Punkt() {
		x = -1;
		y = -1;
	}
	Punkt(int x, int y) : x(x), y(y){
		
	}
	friend std::ostream& operator<<(std::ostream& os, const Punkt& p) {
		os << p.x <<" " << p.y;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Punkt& p) {
		is >> p.x >> p.y;
		return is;
	}
};