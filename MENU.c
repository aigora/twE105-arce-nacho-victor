#include <stdio.h>
#include <string.h>


int main() {

	

	//VARIABLES

	
	char opcion, ciudadBuscada[15], ubicacion;




	
	

	do {

			
			printf("\t\tBIENVENIDOS A NUESTRO PORTAL DE VIVIENDAS\n");
			printf("\n\t\t\t    -- MENÚ PRINCIPAL DE RASTRIVAGO --\n\n\n\n");
			printf("\tPara elegir opción, pulse:\n\n");
			printf("\t  1  -  ALQUILAR.\n\n");
			printf("\t  2  -  VER CATÁLOGO DE APARTAMENTOS.\n\n");
			printf("\t  3  -  SALIR.\n");
			scanf("%c", &opcion);

			switch (opcion) {
			case '1':
			

				
				do{
				
				
				printf("Indique que desea: zona cantábrica (C),zona mediterránea (M), zona atlantica(A)\n ");
				scanf("%c",&ubicacion);
				
				
				switch (ubicacion){
					case 'C':
					case'c':
							
							printf("\n\n¿Qué ciudad desea visitar? Elija entre opciones como:\n\n");
							printf("\tVigo\t\tSantander\n\tGijón\n");
								scanf("%s", ciudadBuscada);
								
								break;
								
					case 'M':
						case 'm':
							printf("\n\n¿Qué ciudad desea visitar? Elija entre opciones como:\n\n");
							printf("\tBarcelona\t\n\tValencia\tMálaga\ntAlicante\tMallorca\n");
							scanf("%s", ciudadBuscada);
							
							break;
							
					case 'A':
						case 'a':
							
							printf("\n\n¿Qué ciudad desea visitar? Elija entre opciones como:\n\n");
							printf("\tCádiz\tHuelva\n\n");
							scanf("%s", ciudadBuscada);
							
							break;
							
				default: printf("La letra pulsada no corresponde a ningun destino\n");
							
							
				}
				
				
				}
				
				while(ubicacion!= 'A'||ubicacion!= 'a'||ubicacion!= 'M'||ubicacion!= 'm'||ubicacion!= 'c'||ubicacion!= 'C' );
				
				break;				
				
				 
				
				
				
				
			case '2':
		
			
				
				printf("\n\t\tBienvenidos a nuestro portal oficial de alquiler de viviendas\n\n");
				printf("\n\t\t\t    -- Catálogo de apartamentos --\n\n\n");
			

			default:
				break;
			}	
			
			} while (opcion != '3' && opcion != '3');	
			
			
			
				}	
