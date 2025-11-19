#include <iostream>
#include <locale.h>
#include <ctype.h> // Para tolower()
#include <queue>

#define numeroPreguntas 10
#define numRespuestas 4
#define indiceInicializacion 0
#define valorParaRacha 2

char entradaCorrecta(char &entrada) { //El & devuelve la dirección de memoria de la variable de entrada, en este caso, de opcion.
	bool aceptado = false;
	entrada = tolower(entrada); //Transformo la opcion en minúsculas.

	while (!aceptado) { //Mientras el input del usuario no sea aceptado.
		aceptado = false;
		if (entrada != 'a' && entrada != 'b' && entrada != 'c' && entrada != 'd') {
			aceptado = false;
			std::cout << "Entrada incorrecta, introducela de nuevo: " << std::endl;
			std::cin >> entrada;
		}

		else {
			aceptado = true;
		}
	}

	return entrada;
}

short puntuacionYRacha(bool &aciertoOFallo, short &racha) {
	short puntuacionActual = 0;

	if (aciertoOFallo == true) {
		if (racha >= valorParaRacha) {
			puntuacionActual += racha; //La racha va augmentando cada cuantas más aciertes.
		}

		else {
			puntuacionActual++;
		}
	}

	else {
		puntuacionActual--;
	}

	return puntuacionActual;
}

short pregunta() {
	short numPregunta = 1;
	short puntuacion = 0;
	char opcion;
	bool acierto;
	short aciertosSeguidos = 0;

	setlocale(LC_ALL, ""); // Configura la configuración regional del sistema

	std::string preguntas[numeroPreguntas] = {
		"1. ¿Cuál es el nombre del protagonista principal en la saga 'The Legend of Zelda'?",
		"2. ¿En qué año se lanzó el primer juego de la saga 'Super Mario Bros'?",
		"3. ¿Cuál de estos juegos fue desarrollado por Rockstar Games?",
		"4. ¿Qué criatura debes atrapar en el juego 'Pokémon'?",
		"5. ¿Cuál es el nombre del planeta donde ocurre 'Mass Effect'?",
		"6. ¿Qué arma es característica del juego 'Halo'?",
		"7. ¿Qué personaje es conocido por decir 'It's-a me, Mario!'?",
		"8. ¿Cuál de estos juegos es un battle royale?",
		"9. ¿Qué empresa desarrolló 'The Witcher 3: Wild Hunt'?",
		"10. ¿En qué consola debutó 'Sonic the Hedgehog'?"
	};

	std::string respuestas[numeroPreguntas][numRespuestas] = {
		{"Zelda", "Epona", "Link", "Ganon"},
		{"1987", "1983", "1990", "1985"},
		{"Grand Theft Auto V", "Call of Duty", "Overwatch", "Fortnite"},
		{"Zombies", "Aliens", "Pokémon", "Digimon"},
		{"Terra", "Citadel", "No hay un solo planeta principal", "Andrómeda"},
		{"Lanza de plasma", "Espada láser", "Energy Sword", "BFG 9000"},
		{"Toad", "Luigi", "Wario", "Mario"},
		{"FIFA", "Fortnite", "The Sims", "Minecraft"},
		{"EA Games", "Ubisoft", "CD Projekt Red", "Bethesda"},
		{"PlayStation", "Sega Genesis", "Super Nintendo", "Game Boy"}
	};

	//Las soluciones de cada pregunta. Recuerda que una array empieza a contar por 0.
	char solucion[numeroPreguntas] = { 'c', 'd', 'a', 'c', 'c', 'c', 'd', 'b', 'c', 'b'}; 

	std::queue <std::string> respuestasCorrectasYIncorrectas; //Almacenaremos las respuestas correctas y incorrectas.

	for (short i = indiceInicializacion; i < numeroPreguntas; i++) {
		std::cout << preguntas[i] << std::endl; //Imprimo en pantalla la pregunta actual.
		std::cout << "Seleccione la respuesta: " << std::endl;

		for (short j = indiceInicializacion; j < numRespuestas; j++) { //Le muestro al usuario las respuestas disponibles.
			std::cout << (char)('A' + j) << ". " << respuestas[i][j] << std::endl;
		}

		std::cout << "Respuesta: ";
		std::cin >> opcion;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Descartamas todo lo restante que no sea el primer char.

		entradaCorrecta(opcion); //Verifico si la entrada es un parámetro aceptado o si no pido hasta que lo sea.

		if (opcion == solucion[i]) {
			std::cout << "¿Solución correcta!" << std::endl;
			acierto = true;
			aciertosSeguidos++;
			puntuacion += puntuacionYRacha(acierto, aciertosSeguidos); //Le asignamos la nueva puntuación.
			std::cout << "Puntuación actual: " << puntuacion << std::endl;
			respuestasCorrectasYIncorrectas.push(" correcta");
		}

		else {
			std::cout << "¡Solución incorrecta!" << std::endl;
			acierto = false;
			aciertosSeguidos = 0;
			puntuacion += puntuacionYRacha(acierto, aciertosSeguidos); //Le asignamos la nueva puntuación.
			std::cout << "Puntuación actual: " << puntuacion << std::endl;
			respuestasCorrectasYIncorrectas.push(" incorrecta");
		}
	}

	std::cout << "Tus respuestas han sido: " << std::endl;

	while (!respuestasCorrectasYIncorrectas.empty()) { //Recorremos cada elemento de la queue.
		std::cout << respuestasCorrectasYIncorrectas.front() << std::endl; //Imprimimos el primer elemento.
		respuestasCorrectasYIncorrectas.pop(); //Eliminamos el primer elemento.
	}

	return puntuacion;
}