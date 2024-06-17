#include <iostream>
#include <vector>

void LimpiarPalabras(std::vector<std::string>& palabrasCorrectas);
void PalabrasCorrectas(std::string* palabras, short ronda, std::vector<std::string>& palabrasCorrectas);
void DesordenarPalabra(std::string* palabras, short ronda, std::vector<std::string>& palabrasCorrectas);
void Gameplay(std::string* palabras, std::vector<std::string>& palabrasCorrectas, std::string *palabra);
void Input(std::string* palabra);
void PalabraCorrecta(std::string* palabra, std::vector<std::string>& palabrasCorrectas);


