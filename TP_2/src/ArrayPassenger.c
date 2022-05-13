#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "Menu.h"
#include "Validation.h"

#define LIMIT_NAME 51
#define LIMIT_LASTNAME 51
#define LIMIT_CODE 10

/**
 * @brief Harcodea the data
 *
 * @param listType eTypePassenger* Pointer to array of passenger
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int forceDataTypePassenger(eTypePassenger* listType)
{
	 int report = -1;

		if(listType != NULL)
		{
			report = 0;

			listType[0].idTypePassenger = 1000;
				strncpy(listType[0].description, "Ni�o", 51);

			listType[1].idTypePassenger = 1010;
				strncpy(listType[1].description, "Adulto", 51);

			listType[2].idTypePassenger = 1020;
				strncpy(listType[2].description, "Anciano", 51);

		}

	return report;
}


/**
 * @brief print list the eTypePassenger
 *
 * @param listType eTypePassenger* Pointer to array of passenger
 * @param len int Array length
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int printTypePassenger(eTypePassenger* listType, int len)
{
	int report = -1;
	int i;

		if(listType != NULL && len > 0)
		{
			report = 0;

				for(i=0;i<len;i++)
				{
					printf("\nID[%d] - %s", listType[i].idTypePassenger, listType[i].description);
				}
		}

	return report;
}

/**
 * @brief Harcodea the data eStatusFlight
 *
 * @param eStatusFlight* Pointer to array of passenger
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int forceDatastatusFlight(eStatusFlight* listStatus)
{
	int report = -1;

		if(listStatus != NULL)
		{
			report = 0;

				listStatus[0].idStatusFlight = 3000;
					strncpy(listStatus[0].description, "Activo", 51);

				listStatus[1].idStatusFlight = 3100;
					strncpy(listStatus[1].description, "Inactivo", 51);

		}

	return report;
}

/**
 * @brief print list type eStatusFlight
 *
 * @param listStatus eStatusFlight* Pointer to array of passenger
 * @param len int Array length
 * @return	int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int printStatusflight(eStatusFlight* listStatus, int len)
{
	int report = -1;
	int i;

		if(listStatus != NULL && len > 0)
		{
			report = 0;

				for(i=0;i<len;i++)
				{
					printf("\nID[%d] - %s", listStatus[i].idStatusFlight, listStatus[i].description);
				}
		}

	return report;
}

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len)
{
	int report = -1;
	int i;

		if(list != NULL && len > 0)
		{
			report = 0;

				for(i=0;i<len;i++)
				{
					list[i].isEmpty = 1;
				}

		}

	return report;
}

/**
 * @brief look for the first free position
 *
 * @param list Passenger* Pointer to array of passenger
 * @param len int Array length
 * @param free int pointer that save position fee
 * @return	int Return (-1) if Error [Invalid length or NULL pointer] - (1) if Error[no free position found] - (0) if Ok
 */
int searchFree(Passenger* list, int len, int* free)
{
	int report = -1;
	int i;

		if(list != NULL && len > 0)
		{
			report = 1;

				for(i=0;i<len;i++)
				{
					if(list[i].isEmpty == 1)
					{
						report = 0;
						(*free) = i;
						break;

					}
				}


		}

	return report;
}

/**
 * @brief change the value of isEmpty
 *
 * @param list Passenger* Pointer to array of passenger
 * @param position int modified place
 * @param valor int assignment
 * @return	int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int modifyIsEmpty(Passenger* list, int position, int valor)
{
	int report = -1;

		if(list != NULL && position >= 0 && valor >= 0 && valor < 2)
		{
			report = 0;

				list[position].isEmpty = valor;

		}

	return report;
}

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{

	int report = -1;
	int reportFree;
	int free;


		if(list != NULL)
		{
			reportFree = searchFree(list, len, &free);

				if(reportFree == 0)
				{
					report = 0;

						list[free].id = id;
						strcpy(list[free].name, name);
						strcpy(list[free].lastName, lastName);
						list[free].price = price;
						list[free].typePassenger = typePassenger;
						strcpy(list[free].flycode, flycode);
						list[free].statusFlight = statusFlight;

						modifyIsEmpty(list, free, 0);

				}

		}

		return report;
}

/**
 * @brief
 *
 * @param list Passenger* Pointer to array of passenger
 * @param len int Array length
 * @param listType etypePassenger* Pointer to array of passenger
 * @param lenType int Array length
 * @param listStatus eStatusflight* Pointer to array of passenger
 * @param lenStatus int Array lenght
 * @param counterId int pointer compute id
 * @return	int Return (-1) if Error [Invalid length or NULL pointer] - (1) if Error[The data was not loaded correctly] - (0) if Ok
 *
 *
 */
int askForInformation(Passenger* list, int len, eTypePassenger* listType, int lenType, eStatusFlight* listStatus, int lenStatus, int* counterId)
{
	int report = -1;
	int id;
	char name[LIMIT_NAME];
	char lastName[LIMIT_LASTNAME];
	float price;
	char code[LIMIT_CODE];
	int typePassenger;
	int statusFlight;

	int reportName;
	int reportLastName;
	int reportPrice;
	int reportCode;
	int reportType;
	int reportStatus;

		if(list != NULL && len > 0)
		{
			report = 1;

			reportName = getNameOrLastName(name, LIMIT_NAME, "Nombre del pasajero: ", "Error. Introdusca bien el nombre\n", 3);
			reportLastName = getNameOrLastName(lastName, LIMIT_LASTNAME, "Apellido del pasajero: ", "Error. Introdusca bien el apellido\n", 3);
			reportPrice = getNumberTypeFloat(&price, "Ingrese precio: ", "Error. Introdusca bien el precio\n", 1, 1000000, 3);
			reportCode = getNumberAlphanumeric(code, LIMIT_CODE, "Ingrese codigo de vuelo: ", "Error. Solo se permiten letras y numeros\n", 3);

			printTypePassenger(listType, lenType);
			reportType = getNumberTypeInt(&typePassenger, "\nIngrese el tipo de pasajero: ", "Error. Ingrese bien el tipo de pasajero\n", 999, 1100, 3);

			printStatusflight(listStatus, lenStatus);
			reportStatus = getNumberTypeInt(&statusFlight, "\nIngrese el estado del vuelo: ", "Error. Ingrese bien el estado del vuelo\n", 2999, 3101, 3);

				if(reportName == 0 && reportLastName == 0 && reportPrice == 0 && reportCode == 0 && reportType == 0 && reportStatus == 0)
				{
					report = 0;
					assignId(&counterId, &id);
					addPassenger(list, len, id, name, lastName, price, typePassenger, code, statusFlight);
				}

		}

	return report;
}
/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger* Pointer to array of passenger
* \param int Array length
* \param id int parameter to compare
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]- if (1) [the id was not found] - if (0) OK
*
*/
int findPassengerById(Passenger* list, int len, int id, int* position)
{
	int report = -1;
	int i;

		if(list != NULL && len > 0 && id >= 0 && position >= 0)
		{
			report = 1;

				for(i=0;i<len;i++)
				{
					if(list[i].id == id)
					{
						report = 0;
						(*position) = i;
						break;
					}
				}

		}


	return report;
}

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id)
{
	int report = -1;
	int i;

		if(list != NULL && len >= 0 && id > 0)
		{
			report = 0;

				for(i=0;i<len;i++)
				{
					if(list[i].id == id)
					{
						modifyIsEmpty(list, i, 1);
					}
				}


		}

	return report;
}

/**
 * @brief search and compare if the parameters are equal
 *
 * @param list Passenger* Pointer to array of passenger
 * @param i int position
 * @param listType etypePassenger* Pointer to array of passenger
 * @param lenType int Array length
 * @param position int position same
 * @return	Return passenger index position or (-1) if [Invalid length or NULL pointer]- if (1) [I did not find a relationship] - if (0) OK
 */
int searchTypePassenger(Passenger* list, int i, eTypePassenger* listType, int lenType, int* position)
{
	int report = -1;
	int j;

		if(list != NULL && i >= 0 && listType != NULL && lenType > 0 && position >= 0)
		{
			report = 1;

					for(j=0;j<lenType;j++)
					{
						if(list[i].typePassenger == listType[j].idTypePassenger)
						{
							report = 0;
							(*position) = j;
							break;
						}
					}

		}

	return report;
}

/**
 * @brief search and compare if the parameters are equal
 *
 * @param list Passenger* Pointer to array of passenger
 * @param i int position
 * @param listType eStatusflight* Pointer to array of passenger
 * @param lentStatus int Array length
 * @param position int position same
 * @return	Return passenger index position or (-1) if [Invalid length or NULL pointer]- if (1) [I did not find a relationship] - if (0) OK
 */
int searchStatusFlight(Passenger* list, int i, eStatusFlight* listStatus, int lenTStatus, int* position)
{
	int report = -1;
	int j;

		if(list != NULL && i >= 0 && listStatus != NULL && lenTStatus > 0 && position >= 0)
		{
			report = 1;

					for(j=0;j<lenTStatus;j++)
					{
						if(list[i].statusFlight == listStatus[j].idStatusFlight)
						{
							report = 0;
							(*position) = j;
							break;
						}
					}

		}

	return report;
}

/**
 * @brief print the content of passengers array
 *
 * @param list	Passenger* Pointer to array of passenger
 * @param len	int Array length
 * @param listType	eTypePassenger* Pointer to array of passenger
 * @param lenType	int Array length
 * @param listStatus eStatusFlight* Pointer to array of passenger
 * @param lenStatus	int Array length
 * @return	Return passenger index position or (-1) if [Invalid length or NULL pointer] - if (0) OK
 */
int printPassenger(Passenger* list, int len, eTypePassenger* listType, int lenType, eStatusFlight* listStatus, int lenStatus)
{
	int report = -1;
	int i;

	int posType;
	int posStatus;

		if(list != NULL && len > 0 && listType != NULL && lenType > 0 && listStatus != NULL && lenStatus > 0)
		{
			report = 0;

				printf("ID     Nombre     Apellido     Precio     Codigo     Tipo     Estado \n");
					for(i=0;i<len;i++)
					{
						if(list[i].isEmpty == 0)
						{
							searchTypePassenger(list, i, listType, lenType, &posType);
							searchStatusFlight(list, i, listStatus, lenStatus, &posStatus);
							printf("[%d]    %s    %s     %.2f    %s       %s   %s\n", list[i].id, list[i].name, list[i].lastName, list[i].price, list[i].flycode, listType[posType].description, listStatus[posStatus].description);

						}
					}

		}

	return report;
}

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order)
{
	Passenger aux;

	int report = -1;
	int i;
	int swap;
	int newLimit;
	int outcome;

		if(list != NULL && len > 0 && order >= 0)
		{
			report = 0;

				newLimit = len - 1;
				do{
					swap = 0;
					for(i=0;i<newLimit;i++)
					{
						outcome = strcmp(list[i].lastName, list[i+1].lastName);

							if(order == 0 && list[i].isEmpty == 0)
							{


								if(outcome > 0)
								{
									swap = 1;
									aux = list[i];
									list[i] = list[i+1];
									list[i+1] = aux;
								}
								else
								{
									if(outcome == 0 && list[i].typePassenger > list[i+1].typePassenger)
									{
										swap = 1;
										aux = list[i];
										list[i] = list[i+1];
										list[i+1] = aux;
									}
								}

							}
							else
							{
								if(order == 1 && list[i].isEmpty == 0)
								{


									if(outcome < 0)
									{
										swap = 1;
										aux = list[i];
										list[i] = list[i+1];
										list[i+1] = aux;
									}
									else
									{
										if(outcome == 0 && list[i].typePassenger < list[i+1].typePassenger)
										{
											swap = 1;
											aux = list[i];
											list[i] = list[i+1];
											list[i+1] = aux;
										}
									}


								}
							}

					}

				}while(swap);


		}

	return report;
}

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* */
int sortPassengersByCode(Passenger* list, int len, int order)
{
	Passenger aux;

	int report = -1;
	int i;
	int swap;
	int newLimit;
	int outcome;

		if(list != NULL && len > 0 && order >= 0)
		{
			report = 0;
			newLimit = len - 1;

				do{
					swap = 0;

					for(i=0;i<newLimit;i++)
					{
						if(order == 0 && list[i].isEmpty == 0)
						{
							outcome = strcmp(list[i].flycode, list[i+1].flycode);

							if(outcome > 0)
							{
								swap = 1;

								aux = list[i];
								list[i] = list[i+1];
								list[i+1] = aux;
							}
							else
							{
								if(outcome == 0 && list[i].statusFlight > list[i+1].statusFlight)
								{
									swap = 1;

									aux = list[i];
									list[i] = list[i+1];
									list[i+1] = aux;
								}
							}
						}
						else
						{
							if(order == 1 && list[i].isEmpty == 0)
							{
								outcome = strcmp(list[i].flycode, list[i+1].flycode);

								if(outcome < 0)
								{
									swap = 1;

									aux = list[i];
									list[i] = list[i+1];
									list[i+1] = aux;
								}
								else
								{
									if(outcome == 0 && list[i].statusFlight < list[i+1].statusFlight)
									{
										swap = 1;

										aux = list[i];
										list[i] = list[i+1];
										list[i+1] = aux;
									}
								}
							}
						}
					}

				}while(swap);

		}

	return report;
}


/**
 * @brief get the total and the average of the prices
 *
 * @param list Passenger* pointer to array of passanger
 * @param len int Arrray lenght
 * @param total int pointer total price
 * @param average int pointer average
 * @return	int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int getTotalAverage(Passenger* list, int len, float* total, float* average)
{
	int report = -1;
	int i;
	float accumulator = 0;
	int counter = 0;

		if(list != NULL && len > 0 && total > 0 && average > 0)
		{
			report = 0;
				for(i=0;i<len;i++)
				{
					if(list[i].isEmpty == 0)
					{
						counter++;
						accumulator += list[i].price;
					}
				}

				(*total) = accumulator;
				(*average) = accumulator / counter;
		}

	return report;
}

/**
 * @brief count how many people are above the average
 *
 * @param list Passenger* pointer to array of passenger
 * @param len	int Array length
 * @param average	int
 * @param counter int counter the passagers
 * @return	int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int getHowManyExceedAverage(Passenger* list, int len, float average, int* counter)
{
	int report = -1;
	int i;
	int cont = 0;

		if(list != NULL && len > 0 && average > 0 && counter > 0)
		{
			report = 0;
			for(i=0;i<len;i++)
			{
				if(list[i].isEmpty == 0)
				{
					if(list[i].price > average)
					{
						cont++;
					}
				}
			}
			(*counter) = cont;
		}

	return report;
}

/**
 * @brief print message the type float
 *
 * @param num float
 * @param message char pointer
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int printTypefloat(float num, char* message)
{
	int report = -1;

		if(num >= 0 && message != NULL)
		{
			report = 0;

			printf("%s%.2f", message, num);
		}

	return report;
}

/**
 * @brief print message the type int
 *
 * @param num int
 * @param message char pointer
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int printTypeInt(int num, char* message)
{
	int report = -1;

		if(num >= 0 && message != NULL)
		{
			report = 0;

			printf("%s%d", message, num);
		}

	return report;
}