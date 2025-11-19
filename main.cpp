#include <cstdlib>
#include <ctype.h> // Para tolower()
#include "QuestionsLibrary.h"

#define notaParaAprobar 20

void main() {
	short nota;
	char respuesta;

	std::cout << "Bienvenido a el juego de las 10 preguntas, pulsa una tecla para continuar." << std::endl;
	system("pause"); //Pausa el programa hasta que se pulse una letra.

	nota = pregunta();

	if (nota < notaParaAprobar) {
		std::cout << "Te haremos una pregunta escrita, si aciertas apruebas" << std::endl;
		std::cout << "¿Por que letra empieza la inicial del personaje más conocido de Nintendo?";
		std::cin >> respuesta;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Descartamas todo lo restante que no sea el primer char.

		if (tolower(respuesta) == 'm') {
			std::cout << "¡Aprobado, enhorabuena!" << std::endl;
		}

		else {
			std::cout << "Suspendido." << std::endl;
		}
	}

	else {
		std::cout << "¡Aprobado, enhorabuena!" << std::endl;
	}
}
