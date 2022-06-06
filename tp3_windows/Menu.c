#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "Validations.h"

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

int requestOption(int min, int max)
{
	int report = -1;
	int option;

		getNumberTypeInt(&option, "-Opcion: ", "Error, ingrese lo que se le pide", 1, 10,  1);

			if(option >= min && option <= max)
			{
				report = option;
			}

	return report;
}
