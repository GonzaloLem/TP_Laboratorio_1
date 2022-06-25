#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "Validations.h"

/**
 * @brief menu options
 *
 */
void printMenuOptions()
{
	printf("\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
			"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
			"3. Alta de pasajero\n"
			"4. Modificar datos de pasajero\n"
			"5. Baja de pasajero\n"
			"6. Listar pasajeros\n"
			"7. Ordenar pasajeros\n"
			"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
			"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
			"10. Salir\n");
}

/**
 * @brief  menu options
 *
 */
void printMenuModify()
{
	printf("\n1.Modificar Nombre\n"
			"2.Modificar Apellido\n"
			"3.Modificar Precio\n"
			"4.Modificar Tipo de Pasajero\n"
			"5.Modificar Codigo\n"
			"6.Modificar estado del vuelo\n"
			"7.Regresar\n");
}

/**
 * @brief  asks you to enter an option and validates that it is a valid one
 *
 * @param min int
 * @param max int
 * @return return (-1) [if you do not enter what is requested] - return (option) if ok
 */
int requestOption(int min, int max)
{
	int report = -1;
	int reportOption;

	int option = 0;

	reportOption = getNumberTypeInt(&option, "-Opcion: ", "Error, ingrese lo que se le pide", 1, 11,  1);

			if(reportOption == 0 && option >= min && option <= max)
			{
				report = option;
			}

	return report;
}

/**
 * @brief gives you the option to stay or leave the application
 *
 * @param flagOne int
 * @param flagTwo int
 * @return return (0) [if you do not enter what is requested or do not want to exit] - return (10) [if you want to go out]
 */
int menu_exit(int flagOne, int flagTwo)
{
	int report ;
	int reportOption;

	int opcion;

		if(flagOne == 1 && flagTwo == 1)
		{
			report = 0;

			printf("\nLos datos no se guardaron en ningun archivo.\n");

			reportOption = getNumberTypeInt(&opcion, "¿Esta seguro que desea salir?\n1)Regresar\n2)Salir\n-Opcion: ", "Error. Ingrese una opcion valida\n", 1, 2,  2);

				if(reportOption == 0 && opcion == 2)
				{
					report = 10;
				}

		}

	return report;
}



