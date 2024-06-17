#define AMOUNT_PALABRAS 3
#include <iostream>
#include <vector>

void LimpiarPalabras(std::vector<std::string>& palabrasCorrectas) {
	for (short j = 0; j < palabrasCorrectas.size(); j++) {
		//palabrasCorrectas.erase(palabrasCorrectas.begin() + j);
		palabrasCorrectas.clear();
	}
}

void PalabrasCorrectas(std::string* palabras, short ronda, std::vector<std::string>& palabrasCorrectas) {
	//Defino las palabras correctas para cada palabra

	switch (ronda) {
		//Primera ronda SALMON
	case 0:
		palabrasCorrectas.push_back("sal");
		palabrasCorrectas.push_back("salon");
		palabrasCorrectas.push_back("sola");
		break;
		//Segunda ronda PUERTO
	case 1:
		palabrasCorrectas.push_back("puto");
		palabrasCorrectas.push_back("pero");
		palabrasCorrectas.push_back("peto");
		break;
		//Tercera ronda PANTALLA
	case 2:
		palabrasCorrectas.push_back("pan");
		palabrasCorrectas.push_back("talla");
		palabrasCorrectas.push_back("llanta");
		palabrasCorrectas.push_back("lata");
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

	//Desordeno la palabra de la ronda
	for (short j = 0; j < palabras[ronda].size(); j++) {
		desorden = rand() % palabras[ronda].size();

		//Guardo en tmp la letra de la palabra
		tmp = palabras[ronda][j];

		//Substituyo
		palabras[ronda][j] = palabras[ronda][desorden];
		palabras[ronda][desorden] = tmp;
	}

	//Muestro las letras entre comas
	std::cout << "Las letras elegidas son: ";
	for (short j = 0; j < palabras[ronda].size(); j++) {
		std::cout << palabras[ronda][j] << ", ";
	}

	std::cout << "puedes formar " << palabrasCorrectas.size() << " palabras con ellas." << std::endl;
}

void Input(std::string* palabra) {
	std::cout << "Introduce una palabra: " << std::endl;
	std::cin >> *palabra;


}

void PalabraCorrecta(std::string* palabra, std::vector<std::string>& palabrasCorrectas) {
	short intentos = 5;
	short tmpPalabrasCorrectas = palabrasCorrectas.size();
	bool existe = false;
	bool dicha = false;
	std::vector<std::string> palabrasAcertadas;
	
	while (intentos >= 0) {
		for (short j = 0; j < palabrasCorrectas.size(); j++) {
			if (*palabra == palabrasCorrectas[j]) {
				//Coincide
				existe = true;

				//Comprovar si se ha dicho previamente
				for (short k = 0; k < palabrasAcertadas.size(); k++) {
					if (*palabra == palabrasAcertadas[k]) {
						//Se ha dicho
						std::cout << "La palabra ya se ha dicho previamente" << std::endl;
						dicha = true;

						Input(palabra);
					}
				}

				if (!dicha) {
					tmpPalabrasCorrectas--;

					//Ha ganado la ronda
					if (tmpPalabrasCorrectas == 0) {
						intentos = -1;

						//Suma 1 punto
						std::cout << "Has ganado la ronda" << std::endl;
					}
					else {

						//Añadir a las palabras dichas
						palabrasAcertadas.push_back(*palabra);

						std::cout << "Palabra correcta, quedan " << tmpPalabrasCorrectas << " palabras para acertar y " << intentos << " intentos, " << std::endl;
						Input(palabra);
					}
				}
			}
		}

		if (!existe) {
			intentos--;

			//Si es el ultimo intento
			if (intentos == -1) {
				std::cout << "Has perdido la ronda" << std::endl;
			}
			else {
				std::cout << "Palabra incorrecta, quedan " << tmpPalabrasCorrectas << " palabras para acertar y " << intentos << " intentos, " << std::endl;

				Input(palabra);
			}
		}

		existe = false;
	}
}


void Gameplay(std::string *palabras, std::vector<std::string> &palabrasCorrectas, std::string* palabra) {
	//Inicio de la ronda (serán 3)
	for (short i = 0; i < AMOUNT_PALABRAS; i++) {
		//Desordenar palabra
		DesordenarPalabra(&palabras[0], i, palabrasCorrectas);

		//Input
		Input(palabra);

		//Verificacion ronda
		PalabraCorrecta(palabra, palabrasCorrectas);

		//Limpiar las palabras correctas
		LimpiarPalabras(palabrasCorrectas);
		
	}
}