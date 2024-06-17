#define AMOUNT_PALABRAS 3
#include <iostream>
#include <vector>
#include "logic.h"

void main(){
	//lArray de las palabras del juego
	std::string palabras[AMOUNT_PALABRAS] = { "SALMON", "PUERTO", "PANTALLA" };
	
	std::vector<std::string> palabrasCorrectas;
	std::string palabra;

	//Inicio del juego
	Gameplay(&palabras[0], palabrasCorrectas, &palabra);

	


}