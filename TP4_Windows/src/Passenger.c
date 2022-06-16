#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validations.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Passenger.h"
#include "Controller.h"
#include "Menu.h"

Passenger* Passenger_new()
{
	return (Passenger*)malloc(sizeof(Passenger));
}

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

int Passenger_setEstadoDelVuelo(Passenger* this,char* estadoDelVuelo)
{
	int report = -1;

		if(this != NULL && estadoDelVuelo != NULL)
		{
			report  = 0;
			strncpy(this->estadoDelVuelo, estadoDelVuelo, STATUS_FLIGHT);
		}

	return report;
}

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

int Passenger_getNombreDelTipoPasajero(TypePassenger* this,char* nombreTipoPasajero)
{
	int report = -1;

		if(this != NULL && nombreTipoPasajero != NULL)
		{
			report = 0;

			strncpy(nombreTipoPasajero, this->tipoPasajero, LIMIT_TYPE_PASSENGER);
		}

	return report;
}

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

int typePassenger_getType(TypePassenger* this, char* type)
{
	int report = -1;

		if(this != NULL && type != NULL)
		{
			report = 0;
			strncpy(type, this->tipoPasajero, LIMIT_TYPE_PASSENGER);
		}

	return report;
}

int typePassenger_getId(TypePassenger* this,int* id)
{
	int report = -1;

		if(this != NULL && id >= 0)
		{
			report = 0;

			*id = this->idTypePassenger;
		}

	return report;
}

int passenger_assignId(LinkedList* pArrayListPassenger)
{
	Passenger* list;

	int report = -1;
	int i;
	int len;
	int idPassenger;
	int id = 0;

		if(pArrayListPassenger != NULL)
		{
			len = ll_len(pArrayListPassenger);

			if(len > 0)
			{
				for(i=0;i<len;i++)
				{
					list = ll_get(pArrayListPassenger, i);

					Passenger_getId(list, &idPassenger);

					if(idPassenger > id)
					{
						id = idPassenger;
					}
				}
			}
			report = id;
		}

	return report;
}

Passenger* addPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* list = NULL;
	TypePassenger type[TAM_TYPE] = { {20001, "FirstClass"}, {20010, "Executive"}, {20020, "EconomyClass"} };
	Passenger* pPassenger;
	Passenger aux;

	int reportName;
	int reportLastName;
	int reportPrice;
	int reportType;
	int reportCode;
	int reportStatus;

	int optionType;

	int idd;

		if(pArrayListPassenger != NULL)
		{

			reportName = getNameOrLastName(aux.nombre, NAME_LASTNAME,"Nombre del pasajero: ", "Error. Ingrese un nombre valido", 2);
			reportLastName = getNameOrLastName(aux.apellido, NAME_LASTNAME,"Apellido del pasajero: ", "Error. Ingrese un apellido valido", 2);
			reportPrice = getNumberTypeFloat(&aux.precio, "Precio del vuelo: ", "Error. Ingrese un precio valido", 1, 1000000, 2);
			printTypePassenger(type, TAM_TYPE);
			reportType = getNumberTypeInt(&optionType, "Ingres el tipo de pasajero: ", "Error. ingrese una opcion valida", 1, 3, 2);
			assignIdTypePassenger(type, TAM_TYPE, optionType, &aux.tipoPasajero);
			reportCode = getNumberAlphanumeric(aux.codigoVuelo, FLYCODE, "Codigo del Vuelo: ","Error. Ingrese un codigo valido", 2);
			reportStatus = getStatusFlight(aux.estadoDelVuelo, STATUS_FLIGHT, "Ingres el estado del Vuelo: ", "Error. Ingrese un estado valido", 2);

				if(reportName == 0 && reportLastName == 0 && reportPrice == 0 && reportType == 0 && reportCode == 0 && reportStatus == 0)
				{

						pPassenger = Passenger_newParametros(aux.id,aux.nombre, aux.apellido,aux.precio, aux.tipoPasajero, aux.codigoVuelo, aux.estadoDelVuelo);

							if(pPassenger != NULL)
							{
								idd = passenger_assignId(pArrayListPassenger) + 1;
								//idd++;
								aux.id = idd;
								*pPassenger = aux;

								list = pPassenger;
							}

				}
		}

	return list;

}

int passenger_searchId(LinkedList* pArrayListPassenger,int id)
{
	Passenger* list;

	int report = -1;
	int i;
	int len;
	int idPassenger;

		if(id > 0)
		{
			report = -2 ;

			len = ll_len(pArrayListPassenger);

				for(i=0;i<len;i++)
				{
					(list) = ll_get(pArrayListPassenger, i);

					Passenger_getId( list, &idPassenger);

						if(list != NULL && id == idPassenger)
						{
							report = i;
							break;
						}
				}
		}

	return report;
}

int passenger__askId(LinkedList* pArrayListPassenger)
{
	int report = -1;
	int reportId;

	int id;

		if(pArrayListPassenger != NULL)
		{
			report = -2;
			controller_ListPassenger(pArrayListPassenger);
			reportId = getNumberTypeInt(&id, "Ingrese el ID: ", "Error. ingrese un ID valido", 1, 10000, 2);

				if(reportId == 0)
				{
					report = passenger_searchId(pArrayListPassenger, id);
				}

		}

	return report;
}

Passenger* editPassenger(LinkedList* pArrayListPassenger, int index)
{
	Passenger* list = NULL;
	TypePassenger type[TAM_TYPE] = { {20001, "FirstClass"}, {20010, "Executive"}, {20020, "EconomyClass"} };
	Passenger aux;

	int reportName;
	int reportLastName;
	int reportPrice;
	int reportType;
	int reportCode;
	int reportStatus;

	int option;
	int optionType;

		if(pArrayListPassenger != NULL)
		{

			if(index >= 0)
			{

				list =  ll_get(pArrayListPassenger, index);
				do{
					printMenuModify();
					option = requestOption(1, 7);

						switch(option)
						{
							case 1:
								reportName = getNameOrLastName(aux.nombre, NAME_LASTNAME,"Nombre del pasajero: ", "Error. Ingrese un nombre valido", 2);

									if(reportName == 0)
									{
										Passenger_setNombre( list, aux.nombre );
									}
							break;

							case 2:
								reportLastName = getNameOrLastName(aux.apellido, NAME_LASTNAME,"Apellido del pasajero: ", "Error. Ingrese un apellido valido", 2);

									if(reportLastName == 0)
									{
										Passenger_setApellido( list, aux.apellido );
									}
							break;

							case 3:
								reportPrice = getNumberTypeFloat(&aux.precio, "Precio del vuelo: ", "Error. Ingrese un precio valido", 1, 1000000, 2);

									if(reportPrice == 0)
									{
										Passenger_setPrecio( list, aux.precio );
									}
							break;

							case 4:
								printTypePassenger(type, TAM_TYPE);
								reportType = getNumberTypeInt(&optionType, "Ingres el tipo de pasajero: ", "Error. ingrese una opcion valida", 1, 3, 2);
								assignIdTypePassenger(type, TAM_TYPE, optionType, &aux.tipoPasajero);

									if(reportType == 0)
									{
										Passenger_setTipoPasajero( list, aux.tipoPasajero );
									}
							break;

							case 5:
								reportCode = getNumberAlphanumeric(aux.codigoVuelo, FLYCODE, "Codigo del Vuelo: ","Error. Ingrese un codigo valido", 2);

									if(reportCode == 0)
									{
										Passenger_setCodigoVuelo( list, aux.codigoVuelo );
									}
							break;

							case 6:
								reportStatus = getStatusFlight(aux.estadoDelVuelo, STATUS_FLIGHT, "Ingres el estado del Vuelo: ", "Error. Ingrese un estado valido", 2);

									if(reportStatus == 0)
									{
										Passenger_setEstadoDelVuelo( list, aux.estadoDelVuelo );
									}
							break;
						}

				}while(option != 7);
			}



		}
	return list;
}

int passenger_remove(LinkedList* pArrayListPassenger, int index)
{
	int report = -1;

		if(pArrayListPassenger != NULL)
		{
			report = 0;
			ll_remove(pArrayListPassenger ,index);
		}

	return report;
}

int passenger_printList(LinkedList* pArrayListPassenger)
{
	Passenger* list;
	TypePassenger type[TAM_TYPE] = { {20001, "FirstClass"}, {20010, "Executive"}, {20020, "EconomyClass"} };

	int report = -1;
	int i;
	int len;

	int id;
	char name[NAME_LASTNAME];
	char lastName[NAME_LASTNAME];
	float price;
	int passengerType;
	char passengerTypeTxt[LIMIT_TYPE_PASSENGER];
	char codigoDeVuelo[FLYCODE];
	char estadoDelVuelo[STATUS_FLIGHT];

		if(pArrayListPassenger != NULL)
		{
			report = 0;

				len = ll_len(pArrayListPassenger);
				printf("ID   Nombre          Apellido          Precio                     Codigo                 Tipo Pasajero                         Estado del Vuelo\n");
				for(i=0;i<len;i++)
				{
					(list) = ll_get(pArrayListPassenger, i);

						if( list != NULL)
						{
							Passenger_getId( list, &id);
							Passenger_getNombre( list, name);
							Passenger_getApellido( list, lastName);
							Passenger_getPrecio( list, &price);
							Passenger_getTipoPasajero( list, &passengerType);
							searchIdType(type, TAM_TYPE, passengerType, passengerTypeTxt);
							Passenger_getCodigoVuelo( list, codigoDeVuelo );
							Passenger_getEstadoDelVuelo( list, estadoDelVuelo);

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
				}
		}
	return report;
}

int passenger_sortPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* listOne;
	Passenger* listTwo;

	int report = -1;
	int i;
	int swap;
	int len;

		if(pArrayListPassenger != NULL)
		{
			report = 0;

			pFunc* sort;

			sort = passenger_sort;

			len = ll_len(pArrayListPassenger);

				do{
					swap = 0;
					for(i=0;i<len;i++)
					{
						listOne = ll_get(pArrayListPassenger, i);
						listTwo = ll_get(pArrayListPassenger, i+1);

							if(listOne != NULL && listTwo != NULL)
							{
								swap = sort(listOne, listTwo);

									if(swap == 1)
									{
										ll_sort(pArrayListPassenger, sort, 1);
									}
							}

					}
				}while(swap);
		}


	return report;
}

int searchIdType(TypePassenger* type, int len, int idPassenger, char* typeTxt)
{
	int report = -1;
	int i;
	int id;
	char passengerType[LIMIT_TYPE_PASSENGER];

		if(type != NULL && len > 0 && idPassenger > 0 && typeTxt != NULL)
		{
			report = -2;
			for(i=0;i<len;i++)
			{
				typePassenger_getId( (type+i),&id);

				if(idPassenger == id)
				{
					report = 0;
					typePassenger_getType( (type+i), passengerType);
					strcpy(typeTxt, passengerType);
					break;
				}
			}
		}

	return report;
}

int printTypePassenger(TypePassenger* type, int len)
{
	int report = -1;
	int i;
	char passengerType[LIMIT_TYPE_PASSENGER];

		if(type != NULL && len > 0)
		{
			report = 0;
				printf("\nTipos de pasajeros\n");
				for(i=0;i<len;i++)
				{
					typePassenger_getType( (type+i), passengerType );
					printf("%d)%s\n", i+1, passengerType );
				}
		}

	return report;
}

int assignIdTypePassenger(TypePassenger* type, int len, int option, int* id)
{
	int report = -1;
	int i;

		if(type != NULL && len > 0 && option > 0 && id != NULL)
		{
			report = 0;
			option = option -1;
				for(i=0;i<len;i++)
				{
					if(option == i)
					{
						*id = (*(type+i)).idTypePassenger;
					}
				}
		}

	return report;
}

int typePassenger_searchType(TypePassenger* type, int len, char* passengerType, int* idType)
{
	int report = -1;
	int i;
	char nameType[LIMIT_TYPE_PASSENGER];
	int compare;
	int id;

		if( type != NULL && len > 0 && idType != NULL)
		{
			for(i=0;i<len;i++)
			{
				Passenger_getNombreDelTipoPasajero( (type+i), nameType);

				compare = strcmp(passengerType, nameType);

				if( compare == 0)
				{
					typePassenger_getId( (type+i), &id );
					*idType = id;
					break;
				}
			}
		}

	return report;
}

int passenger_sortName(Passenger* listOne, Passenger*listTwo)
{
	Passenger* aux;

	int report = -1;
	int comparison;

		if(listOne != NULL && listTwo != NULL)
		{
			report = 0;
			comparison = strcmp(listOne->nombre, listTwo->nombre);

				if(comparison > 0)
				{
					report = 1;

					aux = listOne;
					listOne = listTwo;
					listTwo = aux;

				}
				else
				{
					if(comparison == 0)
					{
						comparison = strcmp(listOne->apellido, listTwo->apellido);

						if(comparison > 0)
						{
							report = 1;

							aux = listOne;
							listOne = listTwo;
							listTwo = aux;
						}
					}
				}

		}

	return report;
}

int passenger_sort(void* listOne, void* listTwo)
{
	int report = -1;

		if(listOne != NULL && listTwo != NULL)
		{
			report = passenger_sortName(listOne, listTwo);
		}

	return report;
}

int passenger_reasingId(LinkedList* pArrayListPassenger, int id, int option)
{
	Passenger* list;

	int report = -1;
	int i;
	int j;
	int len;
	int idPassenger;

		if(pArrayListPassenger != NULL && id >= 0 && option > 0)
		{
			len = ll_len(pArrayListPassenger);

			if(option == 1)
			{
				for(i=0;i<len;i++)
				{
					list = ll_get(pArrayListPassenger, i);

					Passenger_getId(list, &idPassenger);

					if(id == idPassenger && list != NULL)
					{
						id++;
						for(j=i;j<len;j++)
						{

							Passenger_setId(list, id);
							ll_set(pArrayListPassenger, i, list);
						}
					}
				}
			}
			else
			{
				if(option == 2)
				{
					for(i=0;i<len;i++)
					{
						list = ll_get(pArrayListPassenger, i);
							if(list != NULL)
							{
								id++;

								Passenger_setId(list, id);
								ll_set(pArrayListPassenger, i, list);
							}

					}
				}
			}

		}

	return report;
}




