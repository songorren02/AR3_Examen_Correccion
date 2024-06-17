#define AMOUNT_PALABRAS 3
#include <iostream>
#include <vector>

void PalabrasCorrectas(std::string* palabras, short ronda, std::vector<std::string>& palabrasCorrectas) {
	//Defino las palabras correctas para cada palabra

	switch (ronda) {
		//Primera ronda SALMON
	case 0:
		palabrasCorrectas.push_back("SAL");
		palabrasCorrectas.push_back("SALON");
		palabrasCorrectas.push_back("SOLA");
		break;
		//Segunda ronda PUERTO
	case 1:
		palabrasCorrectas.push_back("PUTO");
		palabrasCorrectas.push_back("PERO");
		palabrasCorrectas.push_back("PETO");
		break;
		//Tercera ronda PANTALLA
	case 2:
		palabrasCorrectas.push_back("PAN");
		palabrasCorrectas.push_back("TALLA");
		palabrasCorrectas.push_back("LLANTA");
		palabrasCorrectas.push_back("LATA");
		break;
	}
}

void DesordenarPalabra(std::string* palabras, short ronda, std::vector<std::string>& palabrasCorrectas) {
	short desorden;
	char tmp;

	//Inicializar rand
	srand(time(NULL));

	//Inicializar las palabras correctas
	PalabrasCorrectas(palabras, ronda, palabrasCorrectas);
}


void Gameplay(std::string *palabras, std::vector<std::string> &palabrasCorrectas) {
	//Inicio de la ronda (serán 3)
	for (short i = 0; i < AMOUNT_PALABRAS; i++) {
		//Desordenar palabra
		DesordenarPalabra(&palabras[0], i, palabrasCorrectas);
	}
}