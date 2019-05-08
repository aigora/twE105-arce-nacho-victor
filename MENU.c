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
	char ciudadBuscada[15];//a lo mejor hay que quitar esto porque está definida igual tambien en el main
};

struct Tusuario {
	char username[20];
	char password[20];
};
