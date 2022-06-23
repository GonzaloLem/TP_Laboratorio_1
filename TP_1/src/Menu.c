#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_Validaciones.h"
#include "Menu.h"


void menu_imprimirMenu()
{
	printf("\n1.Ingresar Kilometros\n"
			"2.Ingresar precio de los vuelos\n"
			"3.Calcular todos los costos\n"
			"4.Informar Resultados\n"
			"5.Carga forzada de datos\n"
			"6.Salir\n");
}


int menu_validarOpcion(int min, int max)
{
	int retorno = -1;
	int retornoOpcion;

	int opcion;

		if(min >= 0 && max <= 20)
		{

			retorno = -2;

			retornoOpcion = pedirNumeroEntero(&opcion, "-opcion: ", "Error. Ingrese una opcion valida\n", min, max,  0);

				if(retornoOpcion == 0)
				{
					retorno = opcion;
				}
		}

	return retorno;
}


