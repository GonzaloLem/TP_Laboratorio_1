#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validations.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Menu.h"
#include "Passenger.h"
#include "Controller.h"

/**
 * @brief ask for dynamic memory
 *
 * @return Passenger pointer* Passenger
 */
Passenger* Passenger_new()
{
	return (Passenger*)malloc(sizeof(Passenger));
}

/**
 * @brief  add a passenger with the parameters passed to it
 *
 * @param id int
 * @param nombre char*
 * @param apellido char*
 * @param precio float
 * @param tipoPasajero int
 * @param codigoVuelo char*
 * @param estadoDelVuelo char*
 * @return return (NULL) [if any of the pointers arrived in null or the minimums are not respected] - return (Passenger*) if ok
 */
Passenger* Passenger_newParametros(int id,char* nombre, char* apellido,float precio,int tipoPasajero, char* codigoVuelo, char* estadoDelVuelo)
{
	Passenger* PassengerAux = NULL;

		PassengerAux = Passenger_new();

			if(PassengerAux != NULL && id >= 0 && nombre != NULL && apellido != NULL && precio > 0 && tipoPasajero > 0 && codigoVuelo != NULL)
			{
				Passenger_setId(PassengerAux, id);
				Passenger_setNombre(PassengerAux, nombre);
				Passenger_setApellido(PassengerAux, apellido);
				Passenger_setCodigoVuelo(PassengerAux, codigoVuelo);
				Passenger_setTipoPasajero(PassengerAux, tipoPasajero);
				Passenger_setPrecio(PassengerAux, precio);
				Passenger_setEstadoDelVuelo(PassengerAux,estadoDelVuelo);
			}

	return PassengerAux;
}

/**
 * @brief  Add a passenger with the parameters in txt
 *
 * @param id int
 * @param nombre char*
 * @param apellido char*
 * @param precio float
 * @param tipoPasajero int
 * @param codigoVuelo char*
 * @param estadoDelVuelo char*
 * @return return (NULL) [if any of the pointers arrived in null] - return (Passenger*) if ok
 */
Passenger* Passenger_newParametrosTxt(char* idTxt,char* nombreTxt, char* apellidoTxt,char* precioTxt,char* tipoPasajeroTxt, char* codigoVueloTxt,  char* estadoDelVuelo)
{
	Passenger* PassengerAux = NULL;

		PassengerAux = Passenger_new();

			if(PassengerAux != NULL && idTxt != NULL && nombreTxt != NULL && apellidoTxt != NULL && precioTxt != NULL && tipoPasajeroTxt != NULL && codigoVueloTxt != NULL)
			{
				Passenger_setIdTxt(PassengerAux, idTxt);
				Passenger_setNombre(PassengerAux, nombreTxt);
				Passenger_setApellido(PassengerAux, apellidoTxt);
				Passenger_setCodigoVuelo(PassengerAux, codigoVueloTxt);
				Passenger_setTipoPasajeroTxt(PassengerAux, tipoPasajeroTxt);
				Passenger_setPrecioTxt(PassengerAux, precioTxt);
				Passenger_setEstadoDelVuelo(PassengerAux, estadoDelVuelo);
			}

	return PassengerAux;
}

/**
 * @brief set an id
 *
 * @param this Passenger* pointer
 * @param id int
 * @return return (-1) [if the pointer arrived in NULL or the id is less than 0] - return (0) if Ok
 */
int Passenger_setId(Passenger* this,int id)
{
	int report = -1;

		if(this != NULL && id >= 0)
		{
			report = 0;

			this->id = id;
		}

	return report;
}

/**
 * @brief set an id by passing it a txt id
 *
 * @param this Passenger* pointer
 * @param id int
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if Ok
 */
int Passenger_setIdTxt(Passenger* this, char* id)
{
	int report = -1;
	int lenght;

		if(this != NULL && id != NULL)
		{
			measureLength(id, &lenght);

			if( validateNumberInt(id, lenght) == 0)
			{
				report  = 0;
				this->id = atoi(id);
			}
		}

	return report;
}

/**
 * @brief get an id
 *
 * @param this Pointer Passenger
 * @param id int*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_getId(Passenger* this,int* id)
{
	int report = -1;

		if(this != NULL && id >= 0)
		{
			report = 0;

			*id = this->id;
		}

	return report;
}

/**
 * @brief get an id txt
 *
 * @param this Pointer Passenger
 * @param id char*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_getIdTxt(Passenger* this, char* id)
{
	int report = -1;

		if(this != NULL && id != NULL)
		{
			report = 0;
			sprintf(id, "%d", this->id);
		}

	return report;
}

/**
 * @brief set a name
 *
 * @param this pointer Passenger
 * @param nombre char*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int report = -1;
	int lenght;

		if(this != NULL && nombre != NULL)
		{
			measureLength(nombre, &lenght);

			if( validateOnlyLettersAndSpace(nombre, lenght) == 0)
			{
				report  = 0;
				strncpy(this->nombre, nombre, NAME_LASTNAME);
			}
		}

	return report;
}

/**
 * @brief get a name
 *
 * @param this pointer Passenger
 * @param nombre char*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int report = -1;

		if(this != NULL && nombre != NULL)
		{
			report = 0;
			strncpy(nombre, this->nombre, NAME_LASTNAME);
		}

	return report;
}


/**
 * @brief set a LastName
 *
 * @param this pointer Passenger
 * @param apellido char*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int report = -1;
	int lenght;

		if(this != NULL && apellido != NULL)
		{
			measureLength(apellido, &lenght);

			if( validateOnlyLettersAndSpace(apellido, lenght) == 0)
			{
				report  = 0;
				strncpy(this->apellido, apellido, NAME_LASTNAME);
			}
		}

	return report;
}

/**
 * @brief get a LastName
 *
 * @param this pointer Passenger
 * @param apellido char*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int report = -1;

		if(this != NULL && apellido != NULL)
		{
			report = 0;
			strncpy(apellido, this->apellido, 50);
		}

	return report;
}

/**
 * @brief set a Code
 *
 * @param this pointer Passenger
 * @param codigoVuelo char*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int report = -1;
	int lenght;

		if(this != NULL && codigoVuelo != NULL)
		{
			measureLength(codigoVuelo, &lenght);

			if( validateOnlyLettersAndNumbers(codigoVuelo, lenght) == 0)
			{
				report  = 0;
				strncpy(this->codigoVuelo, codigoVuelo, FLYCODE);
			}
		}

	return report;
}

/**
 * @brief get a Code
 *
 * @param this pointer Passenger
 * @param codigoVuelo char*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int report = -1;

		if(this != NULL && codigoVuelo != NULL)
		{
			report  = 0;
			strncpy(codigoVuelo,this->codigoVuelo, FLYCODE);
		}

	return report;
}

/**
 * @brief set a statusFligh
 *
 * @param this pointer Passenger
 * @param estadoDelVuelo char*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_setEstadoDelVuelo(Passenger* this,char* estadoDelVuelo)
{
	int report = -1;

		if(this != NULL && estadoDelVuelo != NULL)
		{
			report  = 0;
			strncpy(this->estadoDelVuelo , estadoDelVuelo, STATUS_FLIGHT);
		}

	return report;
}

/**
 * @brief get a statusFligh
 *
 * @param this pointer Passenger
 * @param estadoDelVuelo char*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_getEstadoDelVuelo(Passenger* this,char* estadoDelVuelo)
{
	int report = -1;

		if(this != NULL && estadoDelVuelo != NULL)
		{
			report  = 0;
			strncpy(estadoDelVuelo,this->estadoDelVuelo, STATUS_FLIGHT);
		}

	return report;
}

/**
 * @brief set a typePassenger
 *
 * @param this pointer Passenger
 * @param tipoPasajero int
 * @return return (-1) [if the pointer is NULL or the type is less than 1]  - return (0) if ok
 */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int report = -1;

		if(this != NULL && tipoPasajero > 0)
		{
			report = 0;

			this->tipoPasajero = tipoPasajero;
		}

	return report;
}

/**
 * @brief set a typePassenger txt
 *
 * @param this pointer Passenger
 * @param tipoPasajero char*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_setTipoPasajeroTxt(Passenger* this,char* tipoPasajero)
{
	int report = -1;

		if(this != NULL && tipoPasajero != NULL)
		{
			report = 0;

			this->tipoPasajero = atoi(tipoPasajero);
		}

	return report;
}

/**
 * @brief get a typePassenger
 *
 * @param this pointer Passenger
 * @param tipoPasajero int*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int report = -1;

		if(this != NULL && tipoPasajero > 0)
		{
			report = 0;

			*tipoPasajero = this->tipoPasajero;
		}

	return report;
}

/**
 * @brief get a typePassenger txt
 *
 * @param this pointer Passenger
 * @param tipoPasajero char*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_getTipoPasajeroTxt(Passenger* this,char* tipoPasajero)
{
	int report = -1;

		if(this != NULL && tipoPasajero != NULL)
		{
			report = 0;

			sprintf(tipoPasajero,"%d",this->tipoPasajero);
		}

	return report;
}

/**
 * @brief set a price
 *
 * @param this pointer Passenger
 * @param precio float
 * @return return (-1) [if the pointer is NULL or the type is less than one or price is less than one]  - return (0) if ok
 */
int Passenger_setPrecio(Passenger* this,float precio)
{
	int report = -1;

		if(this != NULL && precio > 0)
		{
			report = 0;
			this->precio = precio;
		}

	return report;
}

/**
 * @brief set a price txt
 *
 * @param this pointer Passenger
 * @param precio float
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_setPrecioTxt(Passenger* this,char* precio)
{
	int report = -1;

		if(this != NULL && precio != NULL)
		{
			report = 0;
			this->precio = atof(precio);
		}

	return report;
}

/**
 * @brief get a price
 *
 * @param this pointer Passenger
 * @param precio float*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int report = -1;

		if(this != NULL && precio > 0)
		{
			report = 0;
			*precio = this->precio;
		}

	return report;
}

/**
 * @brief get a price txt
 *
 * @param this pointer Passenger
 * @param precio char*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int Passenger_getPrecioTxt(Passenger* this,char* precio)
{
	int report = -1;

		if(this != NULL && precio != NULL)
		{
			report = 0;
			sprintf(precio, "%f", this->precio);
		}

	return report;
}

/**
 * @brief a type of passenger is passed and it returns the number of the type
 *
 * @param typePassenger char*
 * @param type int*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int passenger_getTypeTxt(char* typePassenger, int* type)
{
	int report = -1;

	int compareFirtsClass;
	int compareExecutive;
	int compareEconomyClass;

		if(typePassenger != NULL && type != NULL)
		{
			report = 0;

			compareFirtsClass = strcmp(typePassenger, "FirstClass");
			compareExecutive = strcmp(typePassenger, "Executive");
			compareEconomyClass = strcmp(typePassenger, "EconomyClass");

				if(compareFirtsClass == 0)
				{
					(*type) = 1;
				}

				if(compareExecutive == 0)
				{
					(*type) = 2;
				}

				if(compareEconomyClass == 0)
				{
					(*type) = 3;
				}

		}

	return report;
}

/**
 * @brief a type of passenger is passed and it returns the number of the type
 *
 * @param typePassenger char*
 * @param type char*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int passenger_getType(int typePassenger, char* type)
{
	int report = -1;

		if(typePassenger > 0 && type != NULL)
		{
			report = 0;

				switch(typePassenger)
				{
					case 1:
						strcpy(type, "FirstClass");
					break;

					case 2:
						strcpy(type, "Executive");
					break;

					case 3:
						strcpy(type, "EconomyClass");
					break;
				}

		}

	return report;
}

/**
 * @brief a type of passenger is passed to it and it returns the number of the type in text
 *
 * @param typePassenger char*
 * @param type char*
 * @return return (-1) [if any of the pointers arrived in null]  - return (0) if ok
 */
int passenger_setType(char* type, char* typePassenger)
{
	int report = -1;

	int compareFirtsClass;
	int compareExecutive;
	int compareEconomyClass;

		if(type != NULL && typePassenger > 0)
		{
			report = 0;

			compareFirtsClass = strcmp(type, "FirstClass");
			compareExecutive = strcmp(type, "Executive");
			compareEconomyClass = strcmp(type, "EconomyClass");

				if(compareFirtsClass == 0)
				{
					strcpy(typePassenger, "1");
				}

				if(compareExecutive == 0)
				{
					strcpy(typePassenger, "2");
				}

				if(compareEconomyClass == 0)
				{
					strcpy(typePassenger, "3");
				}

		}

	return report;
}

/**
 * @brief Assigns an id to the created Passenger
 *
 * @param pArrayListPassenger LinkedList*
 * @return Return (-1) if [Invalid length or NULL pointer] - if (0) OK
 */
int passenger_searchIdMax(LinkedList* pArrayListPassenger)
{
	Passenger* ePassenger;
	int report = -1;

	int i;
	int id;
	int idMax = 0;

		if(pArrayListPassenger != NULL)
		{
			for(i=0;i<ll_len(pArrayListPassenger);i++)
			{
				ePassenger = ll_get(pArrayListPassenger, i);
				Passenger_getId(ePassenger, &id);

					if(id >= idMax)
					{
						idMax = id;
					}
			}

			report = idMax;
			//printf("ID %d\n", id);

		}

	return report;
}

/**
 * @brief reassign the id's in the list
 *
 * @param pArrayListPassenger LinkedList*
 * @param idMax int
 * @return return (-1) [if the pointer arrived in null or the id is less than one] return (0) if ok
 */
int passenger_reasingId(LinkedList* pArrayListPassenger, int idMax)
{
	Passenger* ePassenger;

	int report = -1;

	int i;
	int id;

		if(pArrayListPassenger != NULL && idMax > 0)
		{
			report = 0;

			for(i=0;i<ll_len(pArrayListPassenger);i++)
			{
				ePassenger = ll_get(pArrayListPassenger, i);

				Passenger_getId(ePassenger, &id);

				idMax++;
				id = idMax;

				Passenger_setId(ePassenger, id);
				ll_set(pArrayListPassenger, i, ePassenger);

			}

		}

	return report;
}

/**
 * @brief request the data and add a passenger
 *
 * @return return (NULL) [if you do not enter what is requested] - return (Passenger*) if ok
 */
Passenger* addPassenger()
{
	Passenger* ePassenger = NULL;

	Passenger* pPassenger;
	Passenger aux;

	int reportName;
	int reportLastName;
	int reportPrice;
	int reportType;
	int reportCode;
	int reportStatus;

			reportName = getNameOrLastName(aux.nombre, NAME_LASTNAME,"Nombre del pasajero: ", "Error. Ingrese un nombre valido", 2);
			reportLastName = getNameOrLastName(aux.apellido, NAME_LASTNAME,"Apellido del pasajero: ", "Error. Ingrese un apellido valido", 2);
			reportPrice = getNumberTypeFloat(&aux.precio, "Precio del vuelo: ", "Error. Ingrese un precio valido", 1, 1000000, 2);
			reportType = getNumberTypeInt(&aux.tipoPasajero, "Ingrese el tipo de pasajero\n1)FirstClass\n2)Executive\n3)EconomyClass\n-Opcion: ", "Error. ingrese una opcion valida", 1, 3, 2);
			reportCode = getNumberAlphanumeric(aux.codigoVuelo, FLYCODE, "Codigo del Vuelo: ","Error. Ingrese un codigo valido", 2);
			reportStatus = getStatusFlight(aux.estadoDelVuelo, STATUS_FLIGHT, "Ingres el estado del Vuelo: ", "Error. Ingrese un estado valido", 2);

				if(reportName == 0 && reportLastName == 0 && reportPrice == 0 && reportType == 0 && reportCode == 0 && reportStatus == 0)
				{

						pPassenger = Passenger_newParametros(aux.id,aux.nombre, aux.apellido,aux.precio, aux.tipoPasajero, aux.codigoVuelo, aux.estadoDelVuelo);

							if(pPassenger != NULL)
							{
								ePassenger = pPassenger;
							}

				}


	return ePassenger;

}

/**
 * @brief search for the id that is passed by parameter
 *
 * @param pArrayListPassenger LinkedList*
 * @param id int
 * @return return (-1) [Invalid length or NULL pointer] - return (index Passenger) if ok
 */
int passenger_searchId(LinkedList* pArrayListPassenger,int id)
{
	Passenger* ePassenger;

	int report = -1;
	int i;
	int len;
	int idPassenger;

		if(id > 0)
		{

			len = ll_len(pArrayListPassenger);

				for(i=0;i<len;i++)
				{
					ePassenger = ll_get(pArrayListPassenger, i);

					Passenger_getId( ePassenger, &idPassenger);

						if(ePassenger != NULL && id == idPassenger)
						{
							report = i;
							break;
						}
				}
		}

	return report;
}

/**
 * @brief ask for an id and call the function (passenger_searchId) to look it up
 *
 * @param pArrayListPassenger
 * @return return (-1) [Invalid length or NULL pointer] - return (-2) [if you do not enter what is requested] - return (index Passenger) if ok
 */
int passenger__askId(LinkedList* pArrayListPassenger)
{
	int report = -1;
	int reportId;

	int id;

		if(pArrayListPassenger != NULL)
		{
			report = -2;
			//controller_ListPassenger(pArrayListPassenger);
			reportId = getNumberTypeInt(&id, "Ingrese el ID: ", "Error. ingrese un ID valido", 1, 10000, 2);

				if(reportId == 0)
				{
					report = passenger_searchId(pArrayListPassenger, id);
				}

		}

	return report;
}

/**
 * @brief edit the passenger that was passed by parameter
 *
 * @param ePassenger  pointer Passenger*
 * @return return (Passenger* ePassenger) if ok
 */
Passenger* editPassenger(Passenger* ePassenger)
{
	Passenger aux;

	int reportName;
	int reportLastName;
	int reportPrice;
	int reportType;
	int reportCode;
	int reportStatus;

	int option;

		if(ePassenger != NULL)
		{
				do{
					printMenuModify();
					option = requestOption(1, 7);

						switch(option)
						{
							case 1:
								reportName = getNameOrLastName(aux.nombre, NAME_LASTNAME,"Nombre del pasajero: ", "Error. Ingrese un nombre valido", 2);

									if(reportName == 0)
									{
										Passenger_setNombre( ePassenger, aux.nombre );
									}
							break;

							case 2:
								reportLastName = getNameOrLastName(aux.apellido, NAME_LASTNAME,"Apellido del pasajero: ", "Error. Ingrese un apellido valido", 2);

									if(reportLastName == 0)
									{
										Passenger_setApellido( ePassenger, aux.apellido );
									}
							break;

							case 3:
								reportPrice = getNumberTypeFloat(&aux.precio, "Precio del vuelo: ", "Error. Ingrese un precio valido", 1, 1000000, 2);

									if(reportPrice == 0)
									{
										Passenger_setPrecio( ePassenger, aux.precio );
									}
							break;

							case 4:
								reportType = getNumberTypeInt(&aux.tipoPasajero, "Ingrese el tipo de pasajero\n1)FirstClass\n2)Executive\n3)EconomyClass\n-Opcion: ", "Error. ingrese una opcion valida", 1, 3, 2);

									if(reportType == 0)
									{
										Passenger_setTipoPasajero( ePassenger, aux.tipoPasajero );
									}
							break;

							case 5:
								reportCode = getNumberAlphanumeric(aux.codigoVuelo, FLYCODE, "Codigo del Vuelo: ","Error. Ingrese un codigo valido", 2);

									if(reportCode == 0)
									{
										Passenger_setCodigoVuelo( ePassenger, aux.codigoVuelo );
									}
							break;

							case 6:
								reportStatus = getStatusFlight(aux.estadoDelVuelo, STATUS_FLIGHT, "Ingres el estado del Vuelo: ", "Error. Ingrese un estado valido", 2);

									if(reportStatus == 0)
									{
										Passenger_setEstadoDelVuelo( ePassenger, aux.estadoDelVuelo );
									}
							break;
						}

				}while(option != 7);




		}
	return ePassenger;
}

/**
 * @brief print the passenger that was passed by parameter
 *
 * @param ePassenger Passenger* ePassenger
 * @return return (-1) [if the pointer arrived in NULL] - return (0) if ok
 */
int passenger_printPassenger(Passenger* ePassenger)
{
	int report = -1;

	int id;
	char name[NAME_LASTNAME];
	char lastName[NAME_LASTNAME];
	float price;
	int passengerType;
	char passengerTypeTxt[LIMIT_TYPE_PASSENGER];
	char codigoDeVuelo[FLYCODE];
	char estadoDelVuelo[STATUS_FLIGHT];

		if(ePassenger != NULL)
		{
			report = 0;

				Passenger_getId( ePassenger, &id);
				Passenger_getNombre( ePassenger, name);
				Passenger_getApellido( ePassenger, lastName);
				Passenger_getPrecio( ePassenger, &price);
				Passenger_getTipoPasajero( ePassenger, &passengerType);
				passenger_getType(passengerType, passengerTypeTxt);

				Passenger_getCodigoVuelo( ePassenger, codigoDeVuelo );
				Passenger_getEstadoDelVuelo( ePassenger, estadoDelVuelo);

				printf("[%d]  "
						"%s         "
						"%s           "
						"%.2f                  "
						"%s                          "
						"%s                             "
						"%s     \n",
						id,
						name,
						lastName,
						price,
						codigoDeVuelo,
						passengerTypeTxt,
						estadoDelVuelo);


		}

	return report;
}

/**
 * @brief compare two lastnames
 *
 * @param elementOne void*
 * @param elementTwo void*
 * @return return (-2) [if any of the pointers arrived in NULL] - return (-1) [if the lastName two is not less]
 * 																		  (2) [if lastName two is higher]
 */
int passenger_orderPassengerByLastName(void* elementOne, void* elementTwo)
{
	int report = -2;

	char lastNameOne[60];
	char lastNameTwo[60];

	int compareLastName;

		if(elementOne != NULL && elementTwo !=  NULL)
		{

			Passenger_getApellido(elementOne, lastNameOne);
			Passenger_getApellido(elementTwo, lastNameTwo);

			compareLastName = strcmp(lastNameOne, lastNameTwo);

				report = -1;
				if(compareLastName > 0 )
				{
					report = 1;
				}

		}

	return report;
}

