#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"

#include "Validation.h"

/**
 * @brief print main menu
 *
 */
void printMenu()
{
	printf("\n1.Altas\n"
			"2.Modificar\n"
			"3.Baja\n"
			"4.Informar\n"
			"5.Salir\n"
			"-Opcion: ");
}

/**
 * @brief print secondary menu
 *
 */
void printMenuSecond()
{
	printf("\n1.Modificar Nombre\n"
			"2.Modificar Apellido\n"
			"3.Modificar Precio\n"
			"4. Modificar Codigo\n"
			"5.Modificar Tipo de Pasajero\n"
			"6. Modificar estado del vuelo\n."
			"7.Regresar\n"
			"-Opcion: ");
}

/**
 * @brief print tertiary menu
 *
 */
void printMenuThird()
{
	printf("\n1.Listado por orden alfabetico y tipo de pasajero\n"
			"2.Total y promedio\n"
			"3.Listado por codigo de vuelo y estados de vuelo Activo\n"
			"4.Regresar\n"
			"-Opcion: ");
}

/**
 * @brief save the entered option
 *
 * @param option int pointer option entered
 * @return Return (-1) if [Invalid length or NULL pointer] - if (0) OK
 */
int saveOption(int* option)
{
	int report = -1;
	int reportOption;
	int reportLenght;
	int length;

	char saveOption[4096];

		if(option > 0)
		{
			fflush(stdin);
			gets(saveOption);

					reportLenght = measureLength(saveOption, &length);
					reportOption = validateNumberInt(saveOption, length);

						if(reportLenght == 0 && reportOption == 0)
						{
							report = 0;

							*option = atoi(saveOption);
						}
						else
						{
							if(reportOption != 0)
							{
								printf("Ingrese numeros\n");
							}
						}
		}

	return report;


}




