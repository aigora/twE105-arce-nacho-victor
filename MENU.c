#define _CRT_SECURE_NO_WARNINGS
#define NUMCASAS 10000
#define NUMCIUDADES 9

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//NO HAY VARIABLES GLOBALES


//ESTRUCTURAS
struct Tprecios {

	float Wifi;
	float Piscina;
	float TipoCasa[2];
	float Ubicacion[3];
	float MultiplicadorPorTemporada[4];
	float Valoracion[5];
};

struct Tcaracteristica {

	int tipoDeCasa;
	int piscina;
	int ubicacion;
	int wifi;
	int numeroDeHabitaciones;
	int valoracion;
	float precioBasePorDia;
	int indiceCiudad;
	int alquilada; // 0 = No, 1 = Si
};

struct Tfiltros {
	int temporada;
	int tipoDeCasa;
	int piscina;
	int ubicacion;
	int wifi;
	int numeroDeHabitaciones;
	int valoracion;
	char ciudadBuscada[15];//a lo mejor hay que quitar esto porque estÃ¡ definida igual tambien en el main
};

struct Tusuario {
	char username[20];
	char password[20];
};
//DECLARACIÓN DE FUNCIONES



int  menu();


void main() {

	//PREMISAS
	system("color 3F");
	system("@chcp 1252 > nul");


	//ESTRUCTURAS
	struct Tprecios precios;
	struct Tcaracteristica casaAAlquilar[NUMCASAS];
	struct Tfiltros casaBuscada;
	struct Tusuario miUsuario = { "admin", "1234" };


	//VARIABLES
	char usernameIntroducido[20], passwordIntroducida[20];
	int i, j, ciudadEncontrada = 0, numDias;
	float precioFinalPorDia, precioFinalTotal;
	char opcion, opcion_cancelar, ciudadBuscada[15], c;
	int casaEncontrada; // Variable para guardar el indice de la casa que cumpla las necesidades del usuario
	char ciudad[NUMCIUDADES][15] = { "BARCELONA", "VALENCIA", "CADIZ","SANTANDER", "MALAGA", "VIGO", "ALICANTE", "MALLORCA", "GIJON" };



	//DAMOS VALORES A LAS VARIABLES PRECIOS
	precios.Piscina = 10;
	precios.Wifi = 1.5;
	precios.TipoCasa[0] = 20;
	precios.TipoCasa[1] = 10;
	precios.Ubicacion[0] = 15;
	precios.Ubicacion[1] = 10;
	precios.Ubicacion[2] = 5;
	precios.Valoracion[0] = 0.5;
	precios.Valoracion[1] = 0.75;
	precios.Valoracion[2] = 1;
	precios.Valoracion[3] = 1.25;
	precios.Valoracion[4] = 1.5;
	precios.MultiplicadorPorTemporada[0] = 1.25;	// Primavera
	precios.MultiplicadorPorTemporada[1] = 2;		// Verano
	precios.MultiplicadorPorTemporada[2] = 1;		// Otoño
	precios.MultiplicadorPorTemporada[3] = 0.75;	// Invierno
	
	do {

		opcion = menu();

		switch (opcion) {

		case 'A':
		case 'a':

			printf("\n\n¿Qué ciudad desea visitar? Elija entre opciones como:\n\n");
			printf("\tBarcelona\tVigo\t\tSantander\n\n\tValencia\tGijón\t\tMálaga\n\n\tAlicante\tMallorca\tCádiz\n\n");
			scanf("%s", ciudadBuscada);
			

			break;

		case 'V':
		case 'v':

			system("cls");
			printf("\n\t\tBienvenidos a nuestro portal oficial de alquiler de viviendas\n\n");
			printf("\n\t\t\t    -- Catálogo de apartamentos --\n\n\n");
		
			

			break;

		case 'R':
		case 'r':

			

			break;

		default:

			break;
		}

	} while (opcion != 'S' && opcion != 's');

	getchar();
}



//DESARROLLO DE LAS FUNCIONES

int  menu() {

	char op;

	system("cls");
	printf("\n\n\n\t\tBienvenidos a nuestro portal oficial de alquiler de viviendas\n\n\n");
	printf("\n\t\t\t    -- MENÚ PRINCIPAL DE TRIVATEATOR --\n\n\n\n");
	printf("\tPara elegir opción, pulse:\n\n");
	printf("\t  A  -  ALQUILAR.\n\n");
	printf("\t  V  -  VER CATÁLOGO DE APARTAMENTOS.\n\n");
	printf("\t  R  -  VER RESERVAS REALIZADAS DE APARTAMENTOS.\n\n");
	printf("\t  S  -  SALIR.\n");
	scanf("%c", &op);
	getchar();

	return op;
}
