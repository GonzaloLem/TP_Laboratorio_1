#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (0) todoOk
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	LinkedList* listPassengerAux = ll_newLinkedList();
	FILE* pFile;

	int report = -1;

	int idMax = 0;

		if(path != NULL && pArrayListPassenger != NULL && listPassengerAux != NULL)
		{

			if( !ll_isEmpty(pArrayListPassenger) )
			{
				pFile = fopen(path, "r");
					if(pFile != NULL)
					{
						parser_PassengerFromText(pFile ,listPassengerAux);
						idMax = passenger_searchIdMax(listPassengerAux);
						passenger_reasingId(pArrayListPassenger, idMax);

						fclose(pFile);
					}
			}

			pFile = fopen(path, "r");
				if(pFile != NULL)
				{
					report = 0;
					parser_PassengerFromText(pFile ,pArrayListPassenger);
					fclose(pFile);
				}
		}

    return report;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (0) todoOk
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	LinkedList* listPassengerAux = ll_newLinkedList();

	FILE* pFile;

	int report = -1;

	int idMax;

		if(path != NULL && pArrayListPassenger != NULL)
		{

			if( !ll_isEmpty(pArrayListPassenger) )
			{
				pFile = fopen(path, "rb");
					if(pFile != NULL)
					{
						parser_PassengerFromBinary(pFile ,listPassengerAux);
						idMax = passenger_searchIdMax(listPassengerAux);
						passenger_reasingId(pArrayListPassenger, idMax);

						fclose(pFile);
					}
			}

			pFile = fopen(path, "rb");
				if(pFile != NULL)
				{
					report = 0;

					parser_PassengerFromBinary(pFile, pArrayListPassenger);
					fclose(pFile);
				}

		}

    return report;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return retorna (-1) [Si el puntero llego en NULL] - retorna (0) todoOk
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* ePassenger;

	int report = -1;

	int id;

		if(pArrayListPassenger != NULL)
		{
			ePassenger = addPassenger();

				if(ePassenger != NULL)
				{
					report = 0;
					id = passenger_searchIdMax(pArrayListPassenger)+1;
					Passenger_setId(ePassenger, id);
					ll_add(pArrayListPassenger, ePassenger);
				}
		}

    return report;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return retorna (-1) [Si el puntero llego en NULL] - retorna (0) todoOk
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* ePassenger;

	int report = -1;

	int index;

		if(pArrayListPassenger != NULL)
		{

			controller_ListPassenger(pArrayListPassenger);
			index = passenger__askId(pArrayListPassenger);

				if(index >= 0)
				{
					ePassenger = editPassenger(ll_get(pArrayListPassenger, index));
						if(ePassenger != NULL)
						{
							report = 0;
							ll_set(pArrayListPassenger, index, ePassenger);
						}
				}
		}

    return report;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return retorna (-1) [Si el puntero llego en NULL] - retorna (0) todoOk
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int report = -1;

	int index;

		if(pArrayListPassenger != NULL)
		{
			controller_ListPassenger(pArrayListPassenger);
			index = passenger__askId(pArrayListPassenger);
			//printf("INDEX: %d\n", index);
				if(index >= 0)
				{
					report = 0;
					ll_remove(pArrayListPassenger, index);
				}
		}

    return report;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return retorna (-1) [Si el puntero llego en NULL] - retorna (0) todoOk
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int report = -1;

	int i;

		if(pArrayListPassenger != NULL)
		{
			report = 0;

			printf("ID   Nombre          Apellido          Precio                     Codigo                 Tipo Pasajero                         Estado del Vuelo\n");
			for(i=0;i<ll_len(pArrayListPassenger);i++)
			{
				passenger_printPassenger(ll_get(pArrayListPassenger, i));
			}
		}

    return report;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return retorna (-1) [Si el puntero llego en NULL] - retorna (0) todoOk
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int (*pFunc)(void* ,void*);

	int report = -1;

		if(pArrayListPassenger != NULL)
		{
			report = 0;

			pFunc = passenger_orderPassengerByLastName;

			ll_sort(pArrayListPassenger, pFunc, 1);

		}

    return report;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (0) todoOk
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int report = -1;

		if(path != NULL && pArrayListPassenger != NULL)
		{

			pFile = fopen(path, "w");
				if(pFile != NULL)
				{
					report = 0;
					parser_PassengerSaveText(pFile, pArrayListPassenger);
					fclose(pFile);
				}

		}

    return report;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (0) todoOk
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;

	int report = -1;

		if(path != NULL && pArrayListPassenger != NULL)
		{
				pFile = fopen(path, "wb");
					if(pFile != NULL)
					{
						report = 0;
						parser_PassengerSaveBinary(pFile, pArrayListPassenger);
						fclose(pFile);
					}
		}

    return report;
}

