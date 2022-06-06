#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "Menu.h"
#include "Validations.h"
#include "LinkedList.h"
#include "Controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
//int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, Passenger** list, int len, TypePassenger* type, int lenType, int* id, int* flagLoad)
{
	int report = -1;
	int reportLoadDate;

		if(path != NULL &&  pArrayListPassenger != NULL && list != NULL && len > 0 && type != NULL && lenType > 0 && id != NULL)
		{
			report = -2;

				if(*flagLoad == 0)
				{
					reportLoadDate = passenger_loadDate(list, len, type, lenType, path, &id);

						if(reportLoadDate == 0)
						{
							report = 0;
							printf("Los datos se cargaron correctamente\n");
							*flagLoad = 1;
						}
						else
						{
							if(reportLoadDate == -3)
							{
								printf("No hay datos para cargar en el sistema\n");
							}
						}
				}
				else
				{
					printf("Los datos ya fueron cargados\n");
				}


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
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
//(Passenger** list, int len, TypePassenger* type, int lenType, int* id
//int controller_addPassenger(LinkedList* pArrayListPassenger)
int controller_addPassenger(LinkedList* pArrayListPassenger, Passenger** list, int len, TypePassenger* type, int lenType, int* id)
{
	int report = -1;

		if(pArrayListPassenger != NULL && list != NULL && len > 0 && type != NULL && lenType > 0 && id != NULL)
		{
			report = -2;

			addPassenger(list, len, type,lenType, &id);
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
//int controller_editPassenger(LinkedList* pArrayListPassenger)
int controller_editPassenger(LinkedList* pArrayListPassenger, Passenger** list, int len,TypePassenger* type, int lenType)
{
	int report = -1;

		if(pArrayListPassenger != NULL && list != NULL && len > 0 && type != NULL && lenType > 0)
		{
			report = -2;

			passenger_modifyPassenger(list, len, type, lenType);
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
//int controller_removePassenger(LinkedList* pArrayListPassenger)
int controller_removePassenger(LinkedList* pArrayListPassenger, Passenger** list, int len,TypePassenger* type, int lenType)
{
	int report = -1;

	if(pArrayListPassenger != NULL && list != NULL && len > 0 && type != NULL && lenType > 0)
	{
		report = -2;

		passenger_deletePassenger(list, len, type, lenType);
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
//int controller_ListPassenger(LinkedList* pArrayListPassenger)
int controller_ListPassenger(LinkedList* pArrayListPassenger, Passenger** list, int len,TypePassenger* type, int lenType)
{
	int report = -1;

		if(pArrayListPassenger != NULL && list != NULL && len > 0 && type != NULL && lenType > 0)
		{
			report = -2;

				passenger_printArray(list, len, type, lenType);
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
//int controller_sortPassenger(LinkedList* pArrayListPassenger)
int controller_sortPassenger(LinkedList* pArrayListPassenger, Passenger** list, int len,TypePassenger* type, int lenType)
{
	int report = -1;

		if(pArrayListPassenger != NULL && list != NULL && len > 0 && type != NULL && lenType > 0)
		{
			report = -2;

				passenger_sortArray(list, len);
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
//int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger, Passenger** list, int len,TypePassenger* type, int lenType, int* id)
{
	int report = -1;
		if(path != NULL && pArrayListPassenger != NULL && list != NULL && len > 0 && type != NULL && lenType > 0)
		{
			report = -2;

			passenger_saveDate(list, len, type, lenType, path, &id);

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
    return 1;
}

