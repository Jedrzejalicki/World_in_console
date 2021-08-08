#include "Commentator.h"


string Commentator::lookToString(char x) {
	switch (x) {
	case 'H':
		return "Human";
		break;
	case 'W':
		return "Wolf";
		break;
	case 'T':
		return "Turtle";
		break;
	case 'A':
		return "Antelope";
		break;
	case 'S':
		return "Sheep";
		break;
	case 'F':
		return "Fox";
		break;
	case '+':
		return "Grass";
		break;
	case '/':
		return "Sow thistle";
		break;
	case '@':
		return "Guarana";
		break;
	case '#':
		return "Belladonna";
		break;
	case '$':
		return "Sosnowsky hogweed";
		break;
	}
}




void Commentator::addToText(string x) {
	text.push_back(x);
}


void Commentator::commentRound() {
	for (int i = 0; i < text.size(); i++) {
		cout << text[i] << endl;
	}

	text.clear();
}