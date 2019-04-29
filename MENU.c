#define NUMCASAS 5000  
#define NUMCIUDADES 9

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//ESTRUCTURAS
struct precios {

	float Wifi;
	float Piscina;
	float TipoCasa[2];
	float Ubicacion[3];
	float MultiplicadorPorTemporada[4];
	float Valoracion[5];
	};
	struct caracteristica {

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

struct filtros {
	int temporada;
	int tipoDeCasa;
	int piscina;
	int ubicacion;
	int wifi;
	int numeroDeHabitaciones;
	int valoracion;
	char ciudadBuscada[15];//a lo mejor hay que quitar esto porque está definida igual tambien en el main
};
struct usuario {
	char username[20];
	char password[20]; //estructura usuario para la futura reserva
};

//Declaracion de funciones
int SeleccionaUbicacion(struct filtros *FiltrosDelUsuario);
int existeUsuario(struct usuario usuarioValido, char username[], char password[]);
	
	
	
	
	
int main() {

	//ESTRUCTURAS 
	struct precios NuestrosPreciosPorDia;
	struct caracteristica casaAAlquilar[NUMCASAS];
	struct filtros casaBuscada;
	struct usuario miUsuario = { "admin", "1234" };


	//VARIABLES

	
	char opcion, ciudadBuscada[15], ubicacion;
	char usernameIntroducido[20], passwordIntroducida[20];
        int i, j, ciudadEncontrada = 0;



	
	

	do { //bucle do-while inicial

			
			printf("\t\tBIENVENIDOS A NUESTRO PORTAL DE VIVIENDAS\n");
			printf("\n\t\t\t    -- MENÚ PRINCIPAL DE RASTRIVAGO --\n\n\n\n");
			printf("\tPara elegir opción, pulse:\n\n");
			printf("\t  1  -  ALQUILAR.\n\n");
			printf("\t  2  -  VER CATÁLOGO DE APARTAMENTOS.\n\n");
			printf("\t  3  -  REGISTRARSE.\n");
			scanf("%c", &opcion);

			switch (opcion) { //switch para  el menu principal
			case '1':
			

				
				do{
				
				
				printf("Indique que desea: zona cantábrica (C),zona mediterránea (M), zona atlantica(A)\n ");
				scanf("%c",&ubicacion);
				
				
				switch (ubicacion){ //switch para el menu ubicacion
					case 'C':
					case'c':
							
							printf("\n\n¿Qué ciudad desea visitar? Elija entre opciones como:\n\n");
							printf("\tVigo\t\tSantander\n\tGijón\n");
							scanf(" %s", ciudadBuscada);
						
						        ciudadEncontrada = 0;
			                                for (i = 0; i < NUMCIUDADES; i++) {
				                        if (strcmp(ciudadBuscada, ciudad[i]) == 0) {
					                ciudadEncontrada = 1;
					                break;
				                         }
			                                }
							if (ciudadEncontrada == 1) {
	
		
				                        SeleccionaUbicacion(&casaBuscada);
				
						        break;
								
					case 'M':
						case 'm':
							printf("\n\n¿Qué ciudad desea visitar? Elija entre opciones como:\n\n");
							printf("\tBarcelona\t\n\tValencia\tMálaga\tAlicante\tMallorca\n");
							scanf(" %s", ciudadBuscada);
				
						        ciudadEncontrada = 0;
			                                for (i = 0; i < NUMCIUDADES; i++) {
				                        if (strcmp(ciudadBuscada, ciudad[i]) == 0) {
					                ciudadEncontrada = 1;
					                break;
				                         }
			                                }
							
							break;
							
					case 'A':
						case 'a':
							
							printf("\n\n¿Qué ciudad desea visitar? Elija entre opciones como:\n\n");
							printf("\tCádiz\tHuelva\n\n");
							scanf(" %s", ciudadBuscada);
						
						        ciudadEncontrada = 0;
			                                for (i = 0; i < NUMCIUDADES; i++) {
				                        if (strcmp(ciudadBuscada, ciudad[i]) == 0) {
					                ciudadEncontrada = 1;
					                break;
				                         }
			                                }
							
							break;
							
				default: printf("La letra pulsada no corresponde a ningun destino\n");
							
							
				}
				
				
				}
				
				while(ubicacion!= 'A'||ubicacion!= 'a'||ubicacion!= 'M'||ubicacion!= 'm'||ubicacion!= 'c'||ubicacion!= 'C' );
				
				break;				
				
				 
				
				
				
				
			case '2':
		
			
				
				printf("\n\t\tBienvenidos a nuestro portal oficial de alquiler de viviendas\n\n");
				printf("\n\t\t\t    -- Catálogo de apartamentos --\n\n\n");
				break;
					
			case '3':

			for (j = 2; j >= 0; j--) {

				if (existeUsuario(miUsuario, usernameIntroducido, passwordIntroducida) == 1) {

				
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
			
			} while (opcion != '3' && opcion != '3');	
			
			
			
				}
//Exposicion de las funciones 

int existeUsuario(struct usuario usuarioValido, char username[], char password[]) {

	printf("\nIntroduzca su usuario: ");
	scanf("%s", username);
	printf("\nIntroduzca su contraseña: ");
	scanf("%s", password);

	if ((strcmp(password, usuarioValido.password) == 0) && (strcmp(username, usuarioValido.username) == 0)) {

		return 1;
	}
	else {

		return 0;
	}
}


int SeleccionaUbicacion(struct filtros *FiltrosDelUsuario) {

	char opcionUbicacion, c;

	do {

		printf("¿Qué ubicación prefiere?:\n\n- Centrico (pulse C)\n\n- Costa (pulse O)\n\n- Alrededores (pulse A)\n\n");
		scanf("%c", &opcionUbicacion);
		
}
