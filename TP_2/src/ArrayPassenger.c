#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Menu.h"
#include "Validation.h"
#include "ArrayPassenger.h"

#define LIMIT_NAME 51
#define LIMIT_LASTNAME 51
#define LIMIT_CODE 10

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
 * @brief It is in charge of knowing if there is housing data loaded
 *
 * @param list Passenger* Pointer to array of passenger
 * @param len int
 * @return report (-1) [If the structure Passenger arrived in NULL] - report (-2) [If there is no passenger loaded] -  report (0) if OK
 */
int searchHousingLoaded(Passenger* list, int len)
{
	int report = -1;
	int i;

		if(list != NULL && len > 0)
		{
			report = -2;

			for(i=0;i<len;i++)
			{
				if( list[i].isEmpty == 0 )
				{
					report = 0;
					break;
				}
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


		if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL && price >= 0 && typePassenger > 0 && flycode != NULL && statusFlight > 0)
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
int askForInformation(Passenger* list, int len, int* counterId)
{
	int report = -1;
	int reportAddPassenger;
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

			reportType = getNumberTypeInt(&typePassenger, "Ingrese el tipo de pasajero\n1)Ninio\n2)Adulto\n3)Anciano\n-Opcion: ", "Error. Ingrese bien el tipo de pasajero\n", 1, 3, 3);

			reportStatus = getNumberTypeInt(&statusFlight, "Ingrese el estado del vuelo\n1)Activo\n2)Inactivo\n-Opcion: ", "Error. Ingrese bien el estado del vuelo\n", 1, 2, 3);

				if(reportName == 0 && reportLastName == 0 && reportPrice == 0 && reportCode == 0 && reportType == 0 && reportStatus == 0)
				{
					report = 0;
					//assignId(&counterId, &id);
					(*counterId)++;
					reportAddPassenger = addPassenger(list, len, (*counterId), name, lastName, price, typePassenger, code, statusFlight);

						if(reportAddPassenger != 0)
						{
							(*counterId)--;
						}
				}

		}

	return report;
}

/**
 * @brief it asks the user for the id and if it finds it, it enters an options menu to modify the passenger
 *
 * @param list Passenger* Pointer to array of passenger
 * @param len int
 * @return return (-1) [Invalid length or NULL pointer]] - return (0) allOk
 */
int modifiPassenger(Passenger* list, int len)
{
	Passenger aux;

	int report = -1;
	int index;

	int optionMenu;

	int reportName;
	int reportLastName;
	int reportPrice;
	int reportCode;
	int reportType;
	int reportStatus;

		if(list != NULL && len > 0)
		{
			printPassenger(list, len);
			index = requestid(list, len);

			if(index >= 0)
			{
				report = 0;
				do{
					printMenuSecond();
					saveOption(&optionMenu);

						switch(optionMenu)
						{
							case 1:
								reportName = getNameOrLastName(aux.name, LIMIT_NAME, "Nombre del pasajero: ", "Error. Introdusca bien el nombre\n", 3);

									if(reportName == 0)
									{
										strcpy(list[index].name, aux.name);
									}
							break;

							case 2:
								reportLastName = getNameOrLastName(aux.lastName, LIMIT_LASTNAME, "Apellido del pasajero: ", "Error. Introdusca bien el apellido\n", 3);

									if(reportLastName == 0)
									{
										strcpy(list[index].lastName, aux.lastName);
									}
							break;

							case 3:
								reportPrice = getNumberTypeFloat(&aux.price, "Ingrese precio: ", "Error. Introdusca bien el precio\n", 1, 1000000, 3);

									if(reportPrice == 0)
									{
										list[index].price = aux.price;
									}
							break;

							case 4:
								reportCode = getNumberAlphanumeric(aux.flycode, LIMIT_CODE, "Ingrese codigo de vuelo: ", "Error. Solo se permiten letras y numeros\n", 3);
									if(reportCode == 0)
									{
										strcpy(list[index].flycode, aux.flycode);
									}
							break;

							case 5:
								reportType = getNumberTypeInt(&aux.typePassenger, "Ingrese el tipo de pasajero\n1)Ninio\n2)Adulto\n3)Anciano\n-Opcion: ", "Error. Ingrese bien el tipo de pasajero\n", 1, 3, 3);
									if(reportType == 0)
									{
										list[index].typePassenger = aux.typePassenger;
									}
							break;

							case 6:
								reportStatus = getNumberTypeInt(&aux.statusFlight, "Ingrese el estado del vuelo\n1)Activo\n2)Inactivo\n-Opcion: ", "Error. Ingrese bien el estado del vuelo\n", 1, 2, 3);
									if(reportStatus == 0)
									{
										list[index].statusFlight = aux.statusFlight;
									}
							break;

						}

				}while(optionMenu != 7);
			}

		}

	return report;
}

/**
 * @brief asks for the passenger id to delete
 *
 * @param list Passenger* Pointer to array of passenger
 * @param len int len
 * @return return (-1) [Invalid length or NULL pointer] - return (1) [you do not enter what is requested] - return (0) allOk
 */
int passenger_removePassenger(Passenger* list, int len)
{
	int report = -1;
	int reportAskId;

	int id;

		if(list != NULL && len > 0)
		{
			report = 1;

			printPassenger(list, len);
			reportAskId = getNumberTypeInt(&id, "Ingrese el ID del pasajero: ", "Error. Ingrese una ID valida\n", 1, 10000,  2);

				if(reportAskId == 0)
				{
					report = 0;
					removePassenger(list, len, id);
				}
		}

	return report;
}


/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger* Pointer to array of passenger
* \param int Array length
* \param id int parameter to compare
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]- if (-2) [the id was not found] - if (return the position) OK
*
*/
int findPassengerById(Passenger* list, int len, int id)
{
	int report = -1;
	int i;

		if(list != NULL && len > 0 && id >= 0)
		{
			report = -2;

				for(i=0;i<len;i++)
				{
					if(list[i].id == id)
					{
						report = i;
						break;
					}
				}

		}


	return report;
}

/**
 * @brief It asks for the id and looks for it to see if it exists and returns the ID
 *
 * @param list Passenger* Pointer to array of passenger
 * @param len int
 * @param listType eTypePassenger* Pointer to array of passenger
 * @param lenType int
 * @param listStatus eStatusFligh* Pointer to array of passenger
 * @param lenStatus int
 * @return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]- if (-2) [the id was not found] - if (return the position) OK
 *
 */
int requestid(Passenger* list, int len)
{
	int report = -1;
	int id;
	int reportValidateId;

		if(list != NULL && len > 0)
		{
			report = -2;

			//reportId = printPassenger(list, len, listType, lenType, listStatus, lenStatus);
			reportValidateId  = getNumberTypeInt(&id, "Ingrese el ID: ", "Error. Solo se pueden ingresar numeros\n", 0, 2001, 3);

				if(reportValidateId == 0)
				{
					report = findPassengerById(list, len, id);
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

		if(list != NULL && len > 0 && id > 0)
		{
			for(i=0;i<len;i++)
			{
				if( list[i].id == id )
				{
					report = 0;
					list[i].isEmpty = 1;
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
 * @param listType etypePassenger* Pointer to array of passenger
 * @param lenType int Array length
 * @param position int position same
 * @return	Return passenger index position or (-1) if [Invalid length or NULL pointer]- if (1) [I did not find a relationship] - if (0) OK
 */
int searchTypePassenger(int typePassenger, char* type)
{
	int report = -1;

		if(typePassenger > 0 && type != NULL)
		{
			report = 0;

				switch(typePassenger)
				{
					case 1:
						strcpy(type, "Ninio");
					break;

					case 2:
						strcpy(type, "Adulto");
					break;

					case 3:
						strcpy(type, "Anciano");
					break;
				}

		}

	return report;
}

/**
 * @brief happens to the guy who has the passenger

 * @param statusFlight int
 * @param status char*
 * @return	Return passenger index position or (-1) if [Invalid length or NULL pointer]- if (0) OK
 */
int searchStatusFlight(int statusFlight, char* status)
{
	int report = -1;

		if(statusFlight > 0 && status != NULL)
		{
			report = 0;

				switch(statusFlight)
				{
					case 1:
						strcpy(status, "Activo");
					break;

					case 2:
						strcpy(status, "Inactivo");
					break;
				}

		}

	return report;
}

/**
 * @brief print the content of passengers array
 *
 * @param list	Passenger* Pointer to array of passenger
 * @param len	int Array length
 * @return	Return passenger index position or (-1) if [Invalid length or NULL pointer] - if (0) OK
 */
int printPassenger(Passenger* list, int len)
{
	int report = -1;
	int i;

	char type[26];
	char status[26];

		if(list != NULL && len > 0)
		{
			report = 0;

				printf("ID     Nombre     Apellido     Precio     Codigo     Tipo     Estado \n");
					for(i=0;i<len;i++)
					{
						if(list[i].isEmpty == 0)
						{
							searchTypePassenger(list[i].typePassenger, type);
							searchStatusFlight(list[i].statusFlight, status);
							printf("[%d]    %s    %s     %.2f    %s       %s   %s\n", list[i].id, list[i].name, list[i].lastName, list[i].price, list[i].flycode, type, status);

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

							if(list[i].isEmpty == 0 && ((order == 0 && outcome > 0) || (order == 1 && outcome < 0)))
							{

								swap = 1;
								aux = list[i];
								list[i] = list[i+1];
								list[i+1] = aux;

							}
							else
							{
								if(list[i].isEmpty == 0 && outcome == 0 && ((order == 0 && list[i].typePassenger > list[i+1].typePassenger) || (order == 1 && list[i].typePassenger < list[i+1].typePassenger)) )
								{
									swap = 1;
									aux = list[i];
									list[i] = list[i+1];
									list[i+1] = aux;
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

int passenger_calculateTotalAverage(Passenger* list, int len)
{
	int report = -1;

	float total;
	float average;
	int counter;

		if(list != NULL && len > 0 )
		{
			getTotalAverage(list, len, &total, &average);
			getHowManyExceedAverage(list, len, average, &counter);

			printf("El precio total es: %.3f\n", total);
			printf("El promedio de los precios es de: %.2f\n", average);
			printf("La cantidad de personas que superan el promedio son: %d\n", counter);
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
						outcome = strcmp(list[i].flycode, list[i+1].flycode);

						if(list[i].isEmpty == 0 && ((order == 0 && outcome > 0) || (order == 1 && outcome < 0)))
						{
								swap = 1;
								aux = list[i];
								list[i] = list[i+1];
								list[i+1] = aux;
						}
						else
						{
							if(list[i].isEmpty == 0  && outcome == 0 && ((order == 0 && list[i].statusFlight > list[i+1].statusFlight) || ( order == 1 && list[i].statusFlight < list[i+1].statusFlight)) )
							{
								swap = 1;
								aux = list[i];
								list[i] = list[i+1];
								list[i+1] = aux;
							}
						}
					}

				}while(swap);

		}

	return report;
}

/**
 * @brief sub menu where it informs the passenger data
 *
 * @param list Passenger* pointer to array of passenger
 * @param len int
 * @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int passenger_report(Passenger* list, int len)
{
	int report = -1;

	int option;

		if(list != NULL && len > 0)
		{
			do{
				printMenuThird();
				saveOption(&option);

					switch(option)
					{
						case 1:
							sortPassengers(list, len, 0);
							printPassenger(list, len);
						break;

						case 2:
							passenger_calculateTotalAverage(list, len);
						break;

						case 3:
							sortPassengersByCode(list, len, 0);
							printPassenger(list, len);
						break;
					}

				}while(option != 4);
		}

	return report;
}

/**
 * @brief forcefully loads passengers into the system
 *
 * @param list Passenger* pointer to array of passenger
 * @param len	int Array lenght
 * @param counterId int pointer
 * @return	Return passenger index position or (-1) if [Invalid length or NULL pointer]- if (1) [if the data was not loaded correctly] - if (0) OK
 */
int forcedLoad(Passenger* list, int len, char* name, char* lastName, float price, char* flycode, int typePassenger, int statusFlight, int* counterId)
{
	int report=-1;
	int reportSearch;

	int index;

		if(list != NULL && name != NULL && lastName != NULL && price >= 0 && flycode != NULL && typePassenger > 0 && statusFlight > 0 && counterId != NULL)
		{
			report = 1;

			reportSearch = searchFree(list,  len, &index);

				if(reportSearch == 0)
				{
					(*counterId)++;
					list[index].id = (*counterId);
					strcpy(list[index].name, name);
					strcpy(list[index].lastName, lastName);
					list[index].price = price;
					strcpy(list[index].flycode, flycode);
					list[index].typePassenger = typePassenger;
					list[index].statusFlight = statusFlight;

					modifyIsEmpty(list, index, 0);
				}
		}

	return report;
}

