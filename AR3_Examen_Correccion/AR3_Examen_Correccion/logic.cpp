#define AMOUNT_PALABRAS 3
#include <iostream>
#include <vector>



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