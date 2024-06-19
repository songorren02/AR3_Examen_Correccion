#include <iostream>
#include <vector>

void LimpiarPalabras(std::vector<std::string>& palabrasCorrectas);
void PalabrasCorrectas(std::string* palabras, short ronda, std::vector<std::string>& palabrasCorrectas);
void DesordenarPalabra(std::string* palabras, short ronda, std::vector<std::string>& palabrasCorrectas);
void Gameplay(std::string* palabras, std::vector<std::string>& palabrasCorrectas, std::string *palabra, short* puntuacion);
void Input(std::string* palabra);
void PalabraCorrecta(std::string* palabra, std::vector<std::string>& palabrasCorrectas, short* puntuacion);
void Victoria(short rondas, short puntuacion);


