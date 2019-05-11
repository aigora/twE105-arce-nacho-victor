#define _CRT_SECURE_NO_WARNINGS
#define NUMCASAS 1000
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
	char ciudadBuscada[15];//a lo mejor hay que quitar esto porque estÃƒÂ¡ definida igual tambien en el main
};

struct Tusuario {
	char username[20];
	char password[20];
};
//DECLARACIÃ“N DE FUNCIONES

int  menu();
int existeUsuario(struct Tusuario usuarioValido, char username[], char password[]);
void mostrarApartamento(struct Tcaracteristica *pisosDisponibles, int indice, char ciudades[NUMCIUDADES][15]);
void SeleccionaTemporada(struct Tfiltros *FitrosDelUsuario);
int SeleccionaTipoDeCasa(struct Tfiltros *FitrosDelUsuario);
int SeleccionaPiscina(struct Tfiltros *FiltrosDelUsuario);
int SeleccionaUbicacion(struct Tfiltros *FiltrosDelUsuario);
int SeleccionaNumeroDeHabitaciones(struct Tfiltros *FiltrosDelUsuario);


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
	precios.MultiplicadorPorTemporada[2] = 1;		// OtoÃ±o
	precios.MultiplicadorPorTemporada[3] = 0.75;	// Invierno
	
	
	
	
														// Definimos las casas a aquilar: sus caracteristicas y precio
	for (i = 0; i < NUMCASAS; i++) {
		casaAAlquilar[i].tipoDeCasa = rand() % 2;
		casaAAlquilar[i].piscina = rand() % 2;
		casaAAlquilar[i].wifi = rand() % 2;
		casaAAlquilar[i].ubicacion = rand() % 3;
		casaAAlquilar[i].numeroDeHabitaciones = (rand() % 7) + 1;
		casaAAlquilar[i].indiceCiudad = rand() % NUMCIUDADES;
		casaAAlquilar[i].precioBasePorDia = (rand() % 21) + 20;
		casaAAlquilar[i].alquilada = 0;
		casaAAlquilar[i].valoracion = (rand() % 5); // De 0 a 4, para coincidir con los indices de los precios
	}
	
	
	//DESARROLLO DEL PROGRAMA
	
	
	do {

		opcion = menu();

		switch (opcion) {

		case 'A':
		case 'a':

			printf("\n\nÂ¿QuÃ© ciudad desea visitar? Elija entre opciones como:\n\n");
			printf("\tBarcelona\tVigo\t\tSantander\n\n\tValencia\tGijÃ³n\t\tMÃ¡laga\n\n\tAlicante\tMallorca\tCÃ¡diz\n\n");
			scanf("%s", ciudadBuscada);
			
			while ((c = getchar()) != '\n' && c != EOF) {}
			_strupr(ciudadBuscada);


			ciudadEncontrada = 0;
			for (i = 0; i < NUMCIUDADES; i++) {
				if (strcmp(ciudadBuscada, ciudad[i]) == 0) {
					ciudadEncontrada = 1;
					break;
				}
			}

			if (ciudadEncontrada == 1) {

				strcpy(casaBuscada.ciudadBuscada, ciudadBuscada);
				SeleccionaTemporada(&casaBuscada);
				SeleccionaTipoDeCasa(&casaBuscada);
				SeleccionaPiscina(&casaBuscada);
			}
			

			break;

		case 'V':
		case 'v':

			system("cls");
			printf("\n\t\tBienvenidos a nuestro portal oficial de alquiler de viviendas\n\n");
			printf("\n\t\t\t    -- CatÃ¡logo de apartamentos --\n\n\n");
				for (i = 0; i < NUMCASAS; i++)
			{
				mostrarApartamento(casaAAlquilar, i, ciudad);
				printf("\n-------------------------------------------------\n");
			}
			printf("\n\nPulse una tecla para volver al menú principal.");

			while ((c = getchar()) != '\n' && c != EOF) {}
			getchar();


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
	printf("\n\t\t\t    -- MENÃš PRINCIPAL DE TRIVATEATOR --\n\n\n\n");
	printf("\tPara elegir opciÃ³n, pulse:\n\n");
	printf("\t  A  -  ALQUILAR.\n\n");
	printf("\t  V  -  VER CATÃLOGO DE APARTAMENTOS.\n\n");
	printf("\t  R  -  VER RESERVAS REALIZADAS DE APARTAMENTOS.\n\n");
	printf("\t  S  -  SALIR.\n");
	scanf("%c", &op);
	getchar();

	return op;
}

int existeUsuario(struct Tusuario usuarioValido, char username[], char password[]) {

	printf("\nIntroduzca su usuario: ");
	scanf("%s", username);
	fflush(stdin);
	printf("\nIntroduzca su contraseÃ±a: ");
	scanf("%s", password);
	fflush(stdin);
	getchar();

	if ((strcmp(password, usuarioValido.password) == 0) && (strcmp(username, usuarioValido.username) == 0)) {

		return 1;
	}
	else {

		return 0;
	}
}

void mostrarApartamento(struct Tcaracteristica *pisosDisponibles, int indice, char ciudades[NUMCIUDADES][15])
{
	printf("\n\t\tApartamento #%d:\n", indice + 1);
	printf("\t\t\tEstado: %s\n", (pisosDisponibles[indice].alquilada ? "ALQUILADO" : "LIBRE"));

	printf("\t\t\tCiudad: %s\n", ciudades[pisosDisponibles[indice].indiceCiudad]);
	printf("\t\t\tCoste base por día: %.2f\n", pisosDisponibles[indice].precioBasePorDia);
	printf("\t\t\tWifi: %s\n", (pisosDisponibles[indice].wifi ? "Si" : "No"));
	printf("\t\t\tPiscina: %s\n", (pisosDisponibles[indice].piscina ? "Si" : "No"));
	printf("\t\t\tTipo: %s\n", (pisosDisponibles[indice].tipoDeCasa == 0 ? "Chalet" : "Piso"));
	switch (pisosDisponibles[indice].ubicacion)
	{
	case 0:
		printf("\t\t\tUbicación: Céntrico\n");
		break;
	case 1:
		printf("\t\t\tUbicación: Costa\n");
		break;
	case 2:
		printf("\t\t\tUbicación: Alrededores\n");
		break;
	}
	printf("\t\t\tHabitaciones: %d\n", pisosDisponibles[indice].numeroDeHabitaciones);
	printf("\t\t\tValoración: %d\n", pisosDisponibles[indice].valoracion + 1);
}


void SeleccionaTemporada(struct Tfiltros *FiltrosDelUsuario) {

	char opcion;
	int opcionValida = 0;
	char c;

	do {

		system("cls");

		printf("\n\nElija la temporada en la que desea alquilar un apartamento: \n\n");
		printf("P - Primavera\n\n");
		printf("V - Verano\n\n");
		printf("O - Otoño\n\n");
		printf("I - Invierno\n\n");
		scanf("%c", &opcion);
		while ((c = getchar()) != '\n' && c != EOF) {}

		switch (opcion)
		{
		case 'P':
		case 'p':
			opcionValida = 1;
			FiltrosDelUsuario->temporada = 0;
			break;
		case 'V':
		case 'v':
			opcionValida = 1;
			FiltrosDelUsuario->temporada = 1;
			break;
		case 'O':
		case 'o':
			opcionValida = 1;
			FiltrosDelUsuario->temporada = 2;
			break;
		case 'I':
		case 'i':
			opcionValida = 1;
			FiltrosDelUsuario->temporada = 3;
			break;

		default:
			printf("\n\nNo ha seleccionado una opción válida. Pulse una tecla para volver a escoger.\n\n");
			opcionValida = 0;
			getchar();
			break;
		}

	} while (!opcionValida);

}

int SeleccionaTipoDeCasa(struct Tfiltros *FiltrosDelUsuario) {

	char opcionTipoDeCasa, c;

	do {

		system("cls");

		printf("\n\nElija si quiere alquilar un chalet (pulsando C) o un piso (pulsando P): ");
		scanf("%c", &opcionTipoDeCasa);
		while ((c = getchar()) != '\n' && c != EOF) {}

		if (opcionTipoDeCasa == 'C' || opcionTipoDeCasa == 'c') {

			FiltrosDelUsuario->tipoDeCasa = 0;
			printf("\n\nHa reservado un chalet.\n\n");
			return FiltrosDelUsuario->tipoDeCasa;
			break;
		}

		else if (opcionTipoDeCasa == 'P' || opcionTipoDeCasa == 'p') {

			FiltrosDelUsuario->tipoDeCasa = 1;
			printf("\n\nHa reservado un piso.\n\n");
			return FiltrosDelUsuario->tipoDeCasa;
			break;
		}

		else {

			printf("\n\n No ha elegido una opción disponible. Pulse una tecla para volver a escoger.\n\n");
		}
		getchar();
		
	} while (opcionTipoDeCasa != 'C' && opcionTipoDeCasa != 'c' && opcionTipoDeCasa != 'P' && opcionTipoDeCasa != 'p');

}

int SeleccionaPiscina(struct Tfiltros *FiltrosDelUsuario) {

	char opcionPiscina, c;

	do {

		system("cls");

		printf("\n\n¿Quiere añadir piscina? (pulse S para 'si' y N para 'no'):\n\n- SI\n- NO\n\n");
		scanf("%c", &opcionPiscina);
		while ((c = getchar()) != '\n' && c != EOF) {}

		if (opcionPiscina == 'N' || opcionPiscina == 'n') {

			FiltrosDelUsuario->piscina = 0;
			return FiltrosDelUsuario->piscina;
			printf("\n\nNo ha reservado apartamento con piscina.\n\n");
			break;

		}

		else if (opcionPiscina == 'S' || opcionPiscina == 's') {

			FiltrosDelUsuario->piscina = 1;
			printf("\n\nHa reservado apartamento con piscina.\n\n");
			return FiltrosDelUsuario->piscina;
			break;

		}

		else {

			printf("\n\nNo ha elegido una opción disponible.\n\n");
		}
		getchar();
	} while (opcionPiscina != 'N' && opcionPiscina != 'n' && opcionPiscina != 'S' && opcionPiscina != 's');

}
int SeleccionaUbicacion(struct Tfiltros *FiltrosDelUsuario) {

	char opcionUbicacion, c;

	do {

		system("cls");

		printf("¿Qué ubicación prefiere?:\n\n- Centrico (pulse C)\n\n- Costa (pulse O)\n\n- Alrededores (pulse A)\n\n");
		scanf("%c", &opcionUbicacion);
		while ((c = getchar()) != '\n' && c != EOF) {}

		if (opcionUbicacion == 'C' || opcionUbicacion == 'c') {

			FiltrosDelUsuario->ubicacion = 0;
			printf("\n\nHa reservado un apartamento en el centro.\n\n");
			return FiltrosDelUsuario->ubicacion;
			break;

		}

		else if (opcionUbicacion == 'O' || opcionUbicacion == 'o') {

			FiltrosDelUsuario->ubicacion = 1;
			printf("\n\nHa reservado un apartamento en la costa.\n\n");
			return FiltrosDelUsuario->ubicacion;
			break;


		}

		else if (opcionUbicacion == 'A' || opcionUbicacion == 'a') {

			FiltrosDelUsuario->ubicacion = 2;
			printf("\n\nHa reservado un apartamento en los alrededores.\n\n");
			return FiltrosDelUsuario->ubicacion;
			break;

		}

		else
		{
			printf("\n\nNo ha elegido una opción disponible. Pulse una tecla para volver a escoger.\n\n");
		}
		getchar();

	} while (opcionUbicacion == 'C' || opcionUbicacion == 'c' || opcionUbicacion == 'O' || opcionUbicacion == 'o' || opcionUbicacion == 'A' || opcionUbicacion == 'a');

}
int SeleccionaNumeroDeHabitaciones(struct Tfiltros *FiltrosDelUsuario) {

	char c;
	int opcionNumeroDeHabitaciones;
	do {

		system("cls");


		printf("\n\n¿Cuantas habitaciones desea reservar?\n\n");
		scanf("%d", &opcionNumeroDeHabitaciones);
		while ((c = getchar()) != '\n' && c != EOF) {}

		if (opcionNumeroDeHabitaciones >= 1 && opcionNumeroDeHabitaciones <= 7) {

			FiltrosDelUsuario->numeroDeHabitaciones = opcionNumeroDeHabitaciones;
			break;
		}

		else
		{
			printf("\n\n Número de habitaciones no válido. Pulse una tecla para volver a introducirlo.\n\n");
			getchar();
		}
	} while (opcionNumeroDeHabitaciones < 1 || opcionNumeroDeHabitaciones > 7);

	return FiltrosDelUsuario->numeroDeHabitaciones;

}
