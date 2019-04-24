#include <stdio.h>
#include <string.h>
#define NUMCASAS 5000

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
	char ciudadBuscada[15];//a lo mejor hay que quitar esto porque est� definida igual tambien en el main
};
	
	
	
	
	
int main() {

	//ESTRUCTURAS 
	struct precios NuestrosPreciosPorDia;
	struct caracteristica casaAAlquilar[NUMCASAS];
	struct filtros casaBuscada;


	//VARIABLES

	
	char opcion, ciudadBuscada[15], ubicacion;




	
	

	do {

			
			printf("\t\tBIENVENIDOS A NUESTRO PORTAL DE VIVIENDAS\n");
			printf("\n\t\t\t    -- MEN� PRINCIPAL DE RASTRIVAGO --\n\n\n\n");
			printf("\tPara elegir opci�n, pulse:\n\n");
			printf("\t  1  -  ALQUILAR.\n\n");
			printf("\t  2  -  VER CAT�LOGO DE APARTAMENTOS.\n\n");
			printf("\t  3  -  SALIR.\n");
			scanf("%c", &opcion);

			switch (opcion) {
			case '1':
			

				
				do{
				
				
				printf("Indique que desea: zona cant�brica (C),zona mediterr�nea (M), zona atlantica(A)\n ");
				scanf("%c",&ubicacion);
				
				
				switch (ubicacion){
					case 'C':
					case'c':
							
							printf("\n\n�Qu� ciudad desea visitar? Elija entre opciones como:\n\n");
							printf("\tVigo\t\tSantander\n\tGij�n\n");
								scanf(" %s", ciudadBuscada);
								
								break;
								
					case 'M':
						case 'm':
							printf("\n\n�Qu� ciudad desea visitar? Elija entre opciones como:\n\n");
							printf("\tBarcelona\t\n\tValencia\tM�laga\tAlicante\tMallorca\n");
							scanf(" %s", ciudadBuscada);
							
							break;
							
					case 'A':
						case 'a':
							
							printf("\n\n�Qu� ciudad desea visitar? Elija entre opciones como:\n\n");
							printf("\tC�diz\tHuelva\n\n");
							scanf(" %s", ciudadBuscada);
							
							break;
							
				default: printf("La letra pulsada no corresponde a ningun destino\n");
							
							
				}
				
				
				}
				
				while(ubicacion!= 'A'||ubicacion!= 'a'||ubicacion!= 'M'||ubicacion!= 'm'||ubicacion!= 'c'||ubicacion!= 'C' );
				
				break;				
				
				 
				
				
				
				
			case '2':
		
			
				
				printf("\n\t\tBienvenidos a nuestro portal oficial de alquiler de viviendas\n\n");
				printf("\n\t\t\t    -- Cat�logo de apartamentos --\n\n\n");
			

			default:
				break;
			}	
			
			} while (opcion != '3' && opcion != '3');	
			
			
			
				}	
