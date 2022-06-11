#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Parser.h"
#include "Validations.h"
#include "Menu.h"
#include "Controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;

	int report = -1;

		if(path != NULL && pArrayListPassenger != NULL)
		{
			pFile = fopen(path, "r");
				if(pFile != NULL)
				{
					report = 0;
					parser_PassengerFromText(pFile ,pArrayListPassenger);
				}
			fclose(pFile);

		}

    return report;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int report = -1;


		if(path != NULL && pArrayListPassenger != NULL)
		{
			report = -2;

				pFile = fopen(path, "rb");

					if(pFile != NULL)
					{
						report = 0;
						 parser_PassengerFromBinary(pFile ,pArrayListPassenger);
						fclose(pFile);
					}

		}

    return report;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{

	Passenger* list = NULL;

	int report = -1;			//FORMA CORRECTA DE HACER EL CONTROLLER


		if(pArrayListPassenger != NULL)
		{
			report = -2;

			list = addPassenger(pArrayListPassenger);
				if(list != NULL)
				{
					report = 0;
					ll_add(pArrayListPassenger , list );
				}


		}

    return report;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* list;

	int report = -1;
	int index;

		if(pArrayListPassenger != NULL)
		{

			index = passenger__askId(pArrayListPassenger);
				if(index >= 0)
				{
					list = editPassenger(pArrayListPassenger, index);

						if(list != NULL)
						{
							ll_set(pArrayListPassenger, index, list);
						}
				}

		}

    return report;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int report = -1;
	int index;

		if(pArrayListPassenger != NULL)
		{
			report = -2;

			index = passenger__askId(pArrayListPassenger);

				if(index >= 0)
				{
					report = 0;
					passenger_remove(pArrayListPassenger, index);
				}

		}

    return report;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int report = -1;

		if(pArrayListPassenger != NULL)
		{
			report = 0;
			passenger_printList(pArrayListPassenger);
		}

    return report;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int report = -1;

		if(pArrayListPassenger != NULL)
		{
			report = 0;

			passenger_sortPassenger(pArrayListPassenger);
		}

    return report;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int report = -1;
	int opening;
	int id;

		if(path != NULL && pArrayListPassenger != NULL)
		{
			report = -2;

			opening = file_serachPassenger(path, pArrayListPassenger);
			//printf("OPENING: %d\n", opening);
				if(opening == 0)
				{
					report = 0;
					file_toRewriteFile(path, pArrayListPassenger);

				}
				else
				{
					report = 0;
					id = parser_searchIdMax(path, pArrayListPassenger);
					passenger_reasingId(pArrayListPassenger, id, 2);
					file_writeBelow(path, pArrayListPassenger);

				}
		}

    return report;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{

	int report = -1;


		if(path != NULL && pArrayListPassenger != NULL)
		{
			report = 0;
			//Reformar la funcion que en la mima funcion buscque y compares los passenjers
			file_writeBelowBin(path, pArrayListPassenger);


		}

    return report;
}

