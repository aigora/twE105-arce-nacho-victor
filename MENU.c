#define _CRT_SECURE_NO_WARNINGS
#define NUMCASAS 5000
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
	char ciudadBuscada[15];//a lo mejor hay que quitar esto porque esta definida igual tambien en el main
};

struct Tusuario {
	char username[20];
	char password[20];
};
//DECLARACION DE FUNCIONES

int  menu();
int existeUsuario(struct Tusuario usuarioValido, char username[], char password[]);
void mostrarApartamento(struct Tcaracteristica *pisosDisponibles, int indice, char ciudades[NUMCIUDADES][15]);
void SeleccionaTemporada(struct Tfiltros *FitrosDelUsuario);
int SeleccionaTipoDeCasa(struct Tfiltros *FitrosDelUsuario);
int SeleccionaPiscina(struct Tfiltros *FiltrosDelUsuario);
int SeleccionaWifi(struct Tfiltros *FiltrosDelUsuario);
int SeleccionaUbicacion(struct Tfiltros *FiltrosDelUsuario);
int SeleccionaNumeroDeHabitaciones(struct Tfiltros *FiltrosDelUsuario);
int SeleccionaValoracion(struct Tfiltros *FiltrosDelUsuario);
int buscarPisoAdecuado(struct Tfiltros seleccionesDelUsuario, struct Tcaracteristica *pisosDisponibles, char ciudades[NUMCIUDADES][15]);
float calcularPrecioFinalPorDia(struct Tprecios nuestrosPrecios, struct Tcaracteristica pisoSeleccionado, int temporada);



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
	precios.MultiplicadorPorTemporada[1] = 2;	// Verano
	precios.MultiplicadorPorTemporada[2] = 1;	// Otoño
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

			printf("\n\n¿Que ciudad desea visitar? Elija entre opciones como:\n\n");
	                printf("\tBarcelona\tVigo\t\tSantander\n\n\tValencia\tGijon\t\tMalaga\n\n\tAlicante\tMallorca\tCadiz\n\n");
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
				SeleccionaWifi(&casaBuscada);
				SeleccionaUbicacion(&casaBuscada);
				SeleccionaNumeroDeHabitaciones(&casaBuscada);
				SeleccionaValoracion(&casaBuscada);
				casaEncontrada = buscarPisoAdecuado(casaBuscada, casaAAlquilar, ciudad);
			
				if (casaEncontrada >= 0)
				{
					precioFinalPorDia = calcularPrecioFinalPorDia(precios, casaAAlquilar[casaEncontrada], casaBuscada.temporada);

					printf("\n\n¿Cuántos días desea estar?\n\n");
					scanf("%d", &numDias);
					while ((c = getchar()) != '\n' && c != EOF) {}

					precioFinalTotal = precioFinalPorDia * numDias;

					printf("\n\nHemos encontrado un apartamento a su gusto:\n\n");



					mostrarApartamento(casaAAlquilar, casaEncontrada, ciudad);

					

					printf("\n\nEl coste por día es %.2f euros.\nEl coste total es de %.2f euros para su estancia de %d días.", precioFinalPorDia, precioFinalTotal, numDias);
					printf("\nSi desea cancelar la reserva, pulse C.\n\n");
					scanf("%c", &opcion_cancelar);

					if (opcion_cancelar == 'C' || opcion_cancelar == 'c') {

						printf("\n\nHa cancelado su reserva de apartamento.\n\n");
					}
					else
					{
						casaAAlquilar[casaEncontrada].alquilada = 1; // Marcamos la casa como alquilada
						printf("\n\nReserva confirmada.\n\n");

						//-------------------------------------------------------------------

						mostrarApartamentoEnFichero(casaAAlquilar, casaEncontrada, ciudad);

						//-------------------------------------------------------------------
					}
				}
				else
				{
					printf("\n\nNo se ha encontrado ningún apartamento que cumpla sus criterios de búsqueda.\n\n");
				}
				getchar();

			}

			else
			{
				printf("\n\nLo sentimos, no tenemos apartamentos en esa ciudad. Pulse una tecla para volver al menú.\n\n");
				while ((c = getchar()) != '\n' && c != EOF) {}
				getchar();
			}


			break;

		case 'V':
		case 'v':

			system("cls");
			printf("\n\t\tBienvenidos a nuestro portal oficial de alquiler de viviendas\n\n");
			printf("\n\t\t\t    -- Catalogo de apartamentos --\n\n\n");
				for (i = 0; i < NUMCASAS; i++)
			{
				mostrarApartamento(casaAAlquilar, i, ciudad);
				printf("\n-------------------------------------------------\n");
			}
			printf("\n\nPulse una tecla para volver al menu principal.");

			while ((c = getchar()) != '\n' && c != EOF) {}
			getchar();


			break;

		case 'R':
		case 'r':

				for (j = 2; j >= 0; j--) {

				if (existeUsuario(miUsuario, usernameIntroducido, passwordIntroducida) == 1) {

					//-----------------------------

					leerApartamentoDelFichero();

					//-----------------------------

					break;
				}
				else {
					printf("\nEl usuario o la contraseña introducidos no son válidos.\n");
					printf("Tiene %d intentos restantes\n\n", j);
				}
			
			}

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
	printf("\n\t\t\t    -- MENU PRINCIPAL DE RASTRIVAGO --\n\n\n\n");
	printf("\tPara elegir opcion, pulse:\n\n");
	printf("\t  A  -  ALQUILAR.\n\n");
	printf("\t  V  -  VER CATALOGO DE APARTAMENTOS.\n\n");
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
	printf("\nIntroduzca su contraseña: ");
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
	printf("\t\t\tCoste base por dia: %.2f\n", pisosDisponibles[indice].precioBasePorDia);
	printf("\t\t\tWifi: %s\n", (pisosDisponibles[indice].wifi ? "Si" : "No"));
	printf("\t\t\tPiscina: %s\n", (pisosDisponibles[indice].piscina ? "Si" : "No"));
	printf("\t\t\tTipo: %s\n", (pisosDisponibles[indice].tipoDeCasa == 0 ? "Chalet" : "Piso"));
	switch (pisosDisponibles[indice].ubicacion)
	{
	case 0:
		printf("\t\t\tUbicacion: Centrico\n");
		break;
	case 1:
		printf("\t\t\tUbicacion: Costa\n");
		break;
	case 2:
		printf("\t\t\tUbicacion: Alrededores\n");
		break;
	}
	printf("\t\t\tHabitaciones: %d\n", pisosDisponibles[indice].numeroDeHabitaciones);
	printf("\t\t\tValoracion: %d\n", pisosDisponibles[indice].valoracion + 1);
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
			printf("\n\nNo ha seleccionado una opcion valida. Pulse una tecla para volver a escoger.\n\n");
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

			printf("\n\n No ha elegido una opcion disponible. Pulse una tecla para volver a escoger.\n\n");
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

			printf("\n\nNo ha elegido una opcion disponible.\n\n");
		}
		getchar();
	} while (opcionPiscina != 'N' && opcionPiscina != 'n' && opcionPiscina != 'S' && opcionPiscina != 's');

}

int SeleccionaWifi(struct Tfiltros *FiltrosDelUsuario) {

	char opcionWifi, c;

	do {

		system("cls");
		printf("\n\n¿Quiere añadir WiFi? (pulse S para 'si' y N para 'no'):\n\n- SI\n- NO\n\n");
		scanf("%c", &opcionWifi);
		while ((c = getchar()) != '\n' && c != EOF) {}

		if (opcionWifi == 'N' || opcionWifi == 'n') {

			FiltrosDelUsuario->wifi = 0;
			printf("\n\nNo ha reservado apartamento con WiFi.\n\n");
			return FiltrosDelUsuario->wifi;
			break;

		}

		else if (opcionWifi == 'S' || opcionWifi == 's') {

			FiltrosDelUsuario->wifi = 1;
			printf("\n\nHa reservado apartamento con WiFi.\n\n");
			return FiltrosDelUsuario->wifi;
			break;

		}

		else
		{
			printf("\n\nNo ha elegido una opcion disponible. Pulse una tecla para volver a escoger.\n\n");
		}
		getchar();

	} while (opcionWifi != 'N' && opcionWifi != 'n' && opcionWifi != 'S' && opcionWifi != 's');

}


int SeleccionaUbicacion(struct Tfiltros *FiltrosDelUsuario) {

	char opcionUbicacion, c;

	do {

		system("cls");

		printf("¿Que ubicacion prefiere?:\n\n- Centrico (pulse C)\n\n- Costa (pulse O)\n\n- Alrededores (pulse A)\n\n");
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
			printf("\n\nNo ha elegido una opcion disponible. Pulse una tecla para volver a escoger.\n\n");
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
			printf("\n\n Numero de habitaciones no valido. Pulse una tecla para volver a introducirlo.\n\n");
			getchar();
		}
	} while (opcionNumeroDeHabitaciones < 1 || opcionNumeroDeHabitaciones > 7);

	return FiltrosDelUsuario->numeroDeHabitaciones;

}
int SeleccionaValoracion(struct Tfiltros *FiltrosDelUsuario) {

	int estrellas;
	char c;
	do {

		system("cls");

		printf("\n\n¿Que valoracion desea para su apartamento?\n\n- 1 estrella (pulse 1)\n\n- 2 estrellas (pulse 2)\n\n- 3 estrellas (pulse 3)\n\n- 4 estrellas (pulse 4)\n\n- 5 estrellas (pulse 5)\n\n");
		scanf("%d", &estrellas);
		while ((c = getchar()) != '\n' && c != EOF) {}

		if (estrellas >= 1 || estrellas <= 5) {

			FiltrosDelUsuario->valoracion = estrellas;

		}

		else {

			printf("\n\nHa introducido un numero incorrecto. Pulse una tecla para volver a introducirlo.\n\n");
			getchar();

		}

	} while (estrellas < 1 || estrellas > 5);

	return FiltrosDelUsuario->valoracion;

}
int buscarPisoAdecuado(struct Tfiltros seleccionesDelUsuario, struct Tcaracteristica *pisosDisponibles, char ciudades[NUMCIUDADES][15]) {

	int i, j;
	int indiceCiudadBuscada = -1;
	int estaCasaNosVale = 1;

	for (j = 0; j < NUMCIUDADES; j++)
	{
		if (strcmp(seleccionesDelUsuario.ciudadBuscada, ciudades[j]) == 0)
		{
			indiceCiudadBuscada = j;
			break;
		}
	}

	for (i = 0; i < NUMCASAS; i++)
	{
		estaCasaNosVale = 1; // para cada casa del array, comenzamos poniendo el switch a 1. Si al terminar todas las comprobaciones sigue estando a 1, la casa nos vale.

		if (indiceCiudadBuscada != pisosDisponibles[i].indiceCiudad) // Si esta en la ciudad que buscamos
		{
			estaCasaNosVale = 0;
		}

		if (pisosDisponibles[i].alquilada) // Si no esta ya alquilado este piso, lo compruebo
		{
			estaCasaNosVale = 0;
		}

		if (seleccionesDelUsuario.piscina != pisosDisponibles[i].piscina) // Si quiere piscina o no
		{
			estaCasaNosVale = 0;
		}

		if (seleccionesDelUsuario.wifi != pisosDisponibles[i].wifi) // Si tiene wifi o no
		{
			estaCasaNosVale = 0;
		}

		if (seleccionesDelUsuario.numeroDeHabitaciones != pisosDisponibles[i].numeroDeHabitaciones) //Barre el numero de habitaciones
		{
			estaCasaNosVale = 0;
		}

		if (seleccionesDelUsuario.tipoDeCasa != pisosDisponibles[i].tipoDeCasa) //Busca el tipo de casa
		{
			estaCasaNosVale = 0;
		}

		if (seleccionesDelUsuario.ubicacion != pisosDisponibles[i].ubicacion) //Si la ubicacion coincide
		{
			estaCasaNosVale = 0;
		}

		if ((pisosDisponibles[i].valoracion + 1) != seleccionesDelUsuario.valoracion) //En la valoracion hay un +1 porque las estrellas parten desde1, no 0
		{
			estaCasaNosVale = 0;
		}

		if (estaCasaNosVale) //Si vale, nos devuelve un valor i del numero de apartamento
		{
			return i;
		}
	}

	if (indiceCiudadBuscada == -1)
	{
		return -1; // La trabajamos la ciudad seleccionada por el usuario
	}

	return -1; // No hemos encontrado ningun piso valido en todo el array
}
float calcularPrecioFinalPorDia(struct Tprecios nuestrosPrecios, struct Tcaracteristica pisoSeleccionado, int temporada)
{
	float precio = pisoSeleccionado.precioBasePorDia;

	if (pisoSeleccionado.piscina) // Si el piso tiene piscina, lleva un sobrecoste
	{
		precio += nuestrosPrecios.Piscina;
	}

	if (pisoSeleccionado.wifi) // Si el piso tiene Wifi, lleva un sobrecoste
	{
		precio += nuestrosPrecios.Wifi;
	}

	precio += nuestrosPrecios.Ubicacion[pisoSeleccionado.ubicacion]; // este coste siempre se añade
	precio += nuestrosPrecios.TipoCasa[pisoSeleccionado.tipoDeCasa]; // este coste siempre se añade

	precio = precio * nuestrosPrecios.Valoracion[pisoSeleccionado.valoracion]; // Esto es un multiplicador segun lo bien valorada que este la casa

	precio = precio * nuestrosPrecios.MultiplicadorPorTemporada[temporada]; // Esto es un multiplicador segun la temporada escogida

	return precio;
}
