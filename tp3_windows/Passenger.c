#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validations.h"
#include "LinkedList.h"
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

			if( validateOnlyLetters(nombre, lenght) == 0)
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

			if( validateOnlyLetters(apellido, lenght) == 0)
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
			strncpy(apellido, this->apellido, NAME_LASTNAME);
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

int passenger_initArray(Passenger** list, int len)
{
	int report = -1;
	int i;

		if(list != NULL && len > 0)
		{
			for(i=0;i<len;i++)
			{
				*(list+i) = NULL;
			}
		}

	return report;
}

int passenger_searchLoad(Passenger** list, int len)
{
	int report = -1;
	int i;

		if(list != NULL && len > 0)
		{
			report = -2;
			for(i=0;i<len;i++)
			{
				if(*(list+i) != NULL)
				{
					report = 0;
					break;
				}
			}
		}

	return report;
}

int passenger_searchFree(Passenger** list, int len)
{
	int report = -1;
	int i;

		if(list != NULL && len > 0)
		{
			for(i=0;i<len;i++)
			{
				if(*(list+i) == NULL)
				{
					report = i;
					break;
				}
			}
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

int passenger_printArray(Passenger** list, int len,TypePassenger* type, int lenType)
{
	int report = -1;
	int i;

	int id;
	char name[NAME_LASTNAME];
	char lastName[NAME_LASTNAME];
	float price;
	int passengerType;
	char passengerTypeTxt[LIMIT_TYPE_PASSENGER];
	char codigoDeVuelo[FLYCODE];
	char estadoDelVuelo[STATUS_FLIGHT];

		if(list != NULL && len > 0 && type != NULL&& lenType > 0)
		{
			report = -2;
				printf("ID Nombre Apellido Precio     Tipo Pasajero Codigo Estado del Vuelo\n");
				for(i=0;i<len;i++)
				{
					if( *(list+i) != NULL)
					{

						Passenger_getId( *(list+i), &id);
						Passenger_getNombre( *(list+i), name);
						Passenger_getApellido( *(list+i), lastName);
						Passenger_getPrecio( *(list+i), &price);
						Passenger_getTipoPasajero( *(list+i), &passengerType);
						searchIdType(type, lenType, passengerType, passengerTypeTxt);
						Passenger_getCodigoVuelo( *(list+i), codigoDeVuelo );
						Passenger_getEstadoDelVuelo( *(list+i), estadoDelVuelo);

						printf("[%d] "
								"%s "
								"%s "
								"%.2f  "
								"%s "
								"%s "
								"   %s\n",
								id,
								name,
								lastName,
								price,
								passengerTypeTxt,
								codigoDeVuelo,
								estadoDelVuelo);
					}
				}
		}

	return report;
}

int passenger_reasingId(Passenger** list, int len, int* id)
{
	int report = -1;
	int i;
	int j;
	int idI;
	int idJ;

		if(list != NULL && len > 0)
		{
			report = 0;

				for(i=0;i<len;i++)
				{
					for(j=i+1;j<len;j++)
					{
						if( *(list+i) != NULL && *(list+j) != NULL )
						{
							Passenger_getId( *(list+i), &idI );
							Passenger_getId( *(list+j), &idJ );
							if( idI == idJ )
							{
								(*id)++;
								idI = *id;
								Passenger_setId( *(list+i), idI );
							}
						}

					}
				}

		}

	return report;
}

int passenger_loadDate(Passenger** list, int len, TypePassenger* type, int lenType, char* path,int** id)
{
	FILE* pFile;
	Passenger* pAux;

	int report = -1;
	int reportLoad;

	int count = 0;
	int index;

	char idTxt[LIMIT_BUFFER];
	char name[LIMIT_BUFFER];
	char lastName[LIMIT_BUFFER];
	char priceTxt[LIMIT_BUFFER];
	char typePassengerTxt[LIMIT_BUFFER];
	char flyCode[LIMIT_BUFFER];
	char statusFlight[LIMIT_BUFFER];

	int idType;

		if(list != NULL && len > 0 && type != NULL && lenType > 0)
		{
			report = -2;
				reportLoad = passenger_searchLoad(list, len);
				pFile = fopen(path, "r");
					if(pFile != NULL)
					{
						report = 0;
							do{
								if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idTxt, name, lastName, priceTxt, typePassengerTxt, flyCode, statusFlight) == 7)
								{
									//printf("%s - %s - %s - %s - %s - %s - %s\n", idTxt, name, lastName, priceTxt, typePassengerTxt, flyCode, statusFlight);
									index = passenger_searchFree(list, len);
										if(index >= 0)
										{
											typePassenger_searchType(type, lenType, typePassengerTxt, &idType);
											sprintf(typePassengerTxt, "%d", idType);
											pAux = Passenger_newParametrosTxt(idTxt, name, lastName, priceTxt, typePassengerTxt, flyCode, statusFlight);
												if(pAux != NULL)
												{
													count++;
													*(list+index) = pAux;
												}
										}


								}

							}while( !feof(pFile) );
							fclose(pFile);

							if(count == 0)
							{
								report = -3;
							}
							if(reportLoad == 0)
							{
								passenger_reasingId(list, len, &count);
							}

							(**id) = count;
					}
					else
					{
						printf("No se pudo abrir el archivo\n");
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

int addPassenger(Passenger** list, int len, TypePassenger* type, int lenType, int** id)
{
	Passenger aux;
	Passenger* pPassenger;

	int report = -1;
	int reportName;
	int reportLastName;
	int reportPrice;
	int reportType;
	int reportCode;
	int reportStatus;

	int optionType;
	int index;

		if(list != NULL && len > 0)
		{
			report = -2;

			reportName = getNameOrLastName(aux.nombre, NAME_LASTNAME,"Nombre del pasajero: ", "Error. Ingrese un nombre valido", 2);
			reportLastName = getNameOrLastName(aux.apellido, NAME_LASTNAME,"Apellido del pasajero: ", "Error. Ingrese un apellido valido", 2);
			reportPrice = getNumberTypeFloat(&aux.precio, "Precio del vuelo: ", "Error. Ingrese un precio valido", 1, 1000000, 2);
			printTypePassenger(type, lenType);
			reportType = getNumberTypeInt(&optionType, "Ingres el tipo de pasajero: ", "Error. ingrese una opcion valida", 1, 3, 2);
			assignIdTypePassenger(type, lenType, optionType, &aux.tipoPasajero);
			reportCode = getNumberAlphanumeric(aux.codigoVuelo, FLYCODE, "Codigo del Vuelo: ","Error. Ingrese un codigo valido", 2);
			reportStatus = getStatusFlight(aux.estadoDelVuelo, STATUS_FLIGHT, "Ingres el estado del Vuelo: ", "Error. Ingrese un estado valido", 2);

				if(reportName == 0 && reportLastName == 0 && reportPrice == 0 && reportType == 0 && reportCode == 0 && reportStatus == 0)
				{
					index = passenger_searchFree(list, len);

						if(index >= 0)
						{
							(**id)++;
							aux.id = **id;
							pPassenger = Passenger_newParametros(aux.id,aux.nombre, aux.apellido,aux.precio, aux.tipoPasajero, aux.codigoVuelo, aux.estadoDelVuelo);

								if(pPassenger != NULL)
								{
									report = 0;
									*pPassenger = aux;
									*(list+index) = pPassenger;
								}
								else
								{
									(**id)--;
								}
						}

				}
		}

	return report;
}

int passenger_searchId(Passenger** list, int len, int id)
{
	int report = -1;
	int i;
	int idPassenger;

		if(list != NULL && len > 0)
		{
			report = -2;
			for(i=0;i<len;i++)
			{
				Passenger_getId( *(list+i), &idPassenger);

				if(id == idPassenger && *(list+i) != NULL )
				{
					report = i;
					break;
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

int passenger_modifyPassenger(Passenger** list, int len,TypePassenger* type, int lenType)
{

	Passenger aux;

	int report = -1;
	int reportId;
	int reportName;
	int reportLastName;
	int reportPrice;
	int reportType;
	int reportCode;
	int reportStatus;

	int option;
	int id;
	int index;
	int optionType;

		if(list != NULL && len > 0 && type != NULL && lenType > 0)
		{
			report = -2;

			passenger_printArray(list, len, type, lenType);
			reportId = getNumberTypeInt(&id, "Ingrese el ID: ", "Error. ingrese un ID valido", 1, 10000, 2);

				if(reportId == 0)
				{
					index = passenger_searchId(list, len, id);

						if(index >= 0)
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
													Passenger_setNombre( *(list+index), aux.nombre );
												}
										break;

										case 2:
											reportLastName = getNameOrLastName(aux.apellido, NAME_LASTNAME,"Apellido del pasajero: ", "Error. Ingrese un apellido valido", 2);

												if(reportLastName == 0)
												{
													Passenger_setApellido( *(list+index), aux.apellido );
												}
										break;

										case 3:
											reportPrice = getNumberTypeFloat(&aux.precio, "Precio del vuelo: ", "Error. Ingrese un precio valido", 1, 1000000, 2);

												if(reportPrice == 0)
												{
													Passenger_setPrecio( *(list+index), aux.precio );
												}
										break;

										case 4:
											printTypePassenger(type, lenType);
											reportType = getNumberTypeInt(&optionType, "Ingres el tipo de pasajero: ", "Error. ingrese una opcion valida", 1, 3, 2);
											assignIdTypePassenger(type, lenType, optionType, &aux.tipoPasajero);

												if(reportType == 0)
												{
													Passenger_setTipoPasajero( *(list+index), aux.tipoPasajero );
												}
										break;

										case 5:
											reportCode = getNumberAlphanumeric(aux.codigoVuelo, FLYCODE, "Codigo del Vuelo: ","Error. Ingrese un codigo valido", 2);

												if(reportCode == 0)
												{
													Passenger_setCodigoVuelo( *(list+index), aux.codigoVuelo );
												}
										break;

										case 6:
											reportStatus = getStatusFlight(aux.estadoDelVuelo, STATUS_FLIGHT, "Ingres el estado del Vuelo: ", "Error. Ingrese un estado valido", 2);

												if(reportStatus == 0)
												{
													Passenger_setEstadoDelVuelo( *(list+index), aux.estadoDelVuelo );
												}
										break;
									}


							}while(option != 7);
						}
				}
		}

	return report;
}

int passenger_delete(Passenger* this)
{
	int report = -1;

		if(this != NULL)
		{
			free(this);
		}

	return report;
}

int borrarIndexArray(Passenger** list, int index)
{
	int report = -1;

		if(list != NULL && index >= 0 && *(list+index) != NULL)
		{
			passenger_delete( *(list+index) );
			*(list+index) = NULL;
		}

	return report;
}

int passenger_deletePassenger(Passenger** list, int len, TypePassenger* type, int lenType)
{
	int report = -1;
	int reportId;

	int id;
	int index;

		if(list != NULL && len > 0)
		{
			passenger_printArray(list, len, type, lenType);
			reportId = getNumberTypeInt(&id, "Ingrese el ID: ", "Error. ingrese un ID valido", 1, 10000, 2);

				if(reportId == 0)
				{
					index = passenger_searchId(list, len, id);

						if(index >= 0)
						{
							report = 0;

							borrarIndexArray(list, index);
						}
				}
		}

	return report;
}

int sortName_lastName(Passenger** list, int len)
{
	Passenger aux;

	int report = -1;
	int i;
	int swap;
	int compare;
	int compareLastName;
	int newLen;

	char nameOne[NAME_LASTNAME];
	char nameTwo[NAME_LASTNAME];

	char lastNameOne[NAME_LASTNAME];
	char lastNameTwo[NAME_LASTNAME];

		if(list != NULL && len > 0)
		{
			report = 0;
			newLen = len -1;
				do{
					swap = 0;
						for(i=0;i<newLen;i++)
						{

						Passenger_getNombre( *(list+i), nameOne );
						Passenger_getNombre( *(list+i+1), nameTwo );

						compare = strcmp( nameOne, nameTwo );
							if( *(list+i) != NULL )
							{
								if(compare > 0)
								{
			 	 					swap = 1;

			 	 					aux = (**(list+i));
			 	 					(**(list+i)) = (**(list+i+1));
			 	 					(**(list+i+1)) = aux;

								}
								else
								{
									if(compare == 0)
									{
										Passenger_getApellido( *(list+i), lastNameOne );
										Passenger_getApellido( *(list+i+1), lastNameTwo );

										compareLastName = strcmp(lastNameOne, lastNameTwo);

										if(compareLastName > 0)
										{

											swap = 1;

					 	 					aux = **(list+i);
					 	 					**(list+i) = **(list+i+1);
					 	 					**(list+i+1) = aux;
										}
									}
								}
								printf("SWAP: %d\n", swap);
							}
						}
				}while(swap);
		}

	return report;
}

int passenger_sortArray(Passenger** list, int len)
{
	int report = -1;

		if(list != NULL && len > 0)
		{
			sortName_lastName(list, len);
		}

	return report;
}


int passenger_checkList(Passenger** list, int len, char* path)
{
	FILE* pFile;

	int report = -1;

	int i;
	int id;
	char idTxt[LIMIT_BUFFER];
	char buffer[LIMIT_BUFFER];

		if(list != NULL && len > 0 && path != NULL)
		{
			report = -2;
			pFile = fopen(path, "r");
				if(pFile != NULL)
				{
					report = 1;
					do{
						if(fscanf(pFile,"%[^,],%[^\n]\n", idTxt, buffer) == 2)
						{
							for(i=0;i<len;i++)
							{
								if( *(list+i) != NULL )
								{
									Passenger_getId( *(list+i), &id);

									if( id == atoi(idTxt) )
									{
										report = 0;
										break;
									}
								}

								if(report == 0)
								{
									break;
								}
							}
						}
					}while(!feof(pFile));
					fclose(pFile);
				}
		}

	return report;
}

int archive_save(Passenger** list, int len, TypePassenger* type, int lenType, char* path)
{
	FILE* pFile;
	int report = -1;

	int i;
	int id;
	char name[NAME_LASTNAME];
	char lastName[NAME_LASTNAME];
	float price;
	int passengerType;
	char flyCode[FLYCODE];
	char statusFligh[STATUS_FLIGHT];
	char typeTxt[LIMIT_TYPE_PASSENGER];

		if(list != NULL && len > 0 && type != NULL && lenType > 0 && path != NULL)
		{
			pFile = fopen(path, "w");

				if(pFile != NULL)
				{
					for(i=0;i<len;i++)
					{
						if( *(list+i) != NULL )
						{
							Passenger_getId( *(list+i), &id  );
							Passenger_getNombre( *(list+i), name );
							Passenger_getApellido( *(list+i), lastName);
							Passenger_getPrecio( *(list+i), &price);
							Passenger_getTipoPasajero( *(list+i), &passengerType);
							searchIdType(type, lenType, passengerType, typeTxt);

							Passenger_getCodigoVuelo( *(list+i), flyCode);
							Passenger_getEstadoDelVuelo( *(list+i), statusFligh);

							fprintf(pFile, "%d,%s,%s,%.2f,%s,%s,%s\n", id, name, lastName, price, typeTxt, flyCode, statusFligh);

						}

					}
					fclose(pFile);
				}
		}

	return report;
}

int archive_countAmount(char* path, int* id)
{
	int report = -1;
	FILE* pFile;

	char buffer[LIMIT_BUFFER];
	int count = 0;

		if(path != NULL)
		{
			report = -2;

				pFile = fopen(path, "r");

					if(pFile != NULL)
					{
						do{
							if(fscanf(pFile,"%[^\n]\n", buffer) == 1)
							{
								count++;
							}
						}while( !feof(pFile) );
						fclose(pFile);

						(*id) = count;
					}

		}
	return report;

}

int archive_rewrite(Passenger** list, int len, TypePassenger* type, int lenType, char* path)
{
	FILE* pFile;

	int report = -1;

	int i;
	int id;
	char name[NAME_LASTNAME];
	char lastName[NAME_LASTNAME];
	float price;
	int passengerType;
	char flyCode[FLYCODE];
	char statusFligh[STATUS_FLIGHT];
	char typeTxt[LIMIT_TYPE_PASSENGER];

		if(list != NULL && len > 0 && type != NULL && lenType > 0 && path != NULL)
		{
			pFile = fopen(path, "a");
				if(pFile != NULL)
				{
					for(i=0;i<len;i++)
					{
						if( *(list+i) != NULL )
						{
							Passenger_getId( *(list+i), &id  );
							Passenger_getNombre( *(list+i), name );
							Passenger_getApellido( *(list+i), lastName);
							Passenger_getPrecio( *(list+i), &price);
							Passenger_getTipoPasajero( *(list+i), &passengerType);
							searchIdType(type, lenType, passengerType, typeTxt);

							Passenger_getCodigoVuelo( *(list+i), flyCode);
							Passenger_getEstadoDelVuelo( *(list+i), statusFligh);

							fprintf(pFile, "%d,%s,%s,%.2f,%s,%s,%s\n", id, name, lastName, price, typeTxt, flyCode, statusFligh);

						}

					}
					fclose(pFile);
				}
		}

	return report;
}

int passenger_saveDate(Passenger** list, int len, TypePassenger* type, int lenType, char* path, int** id)
{
	int report = -1;
	int reportCheck;
	int count;

		if(list != NULL && len > 0 && type != NULL && lenType > 0 && path != NULL)
		{
			report = -2;


					reportCheck = passenger_checkList(list, len, path);

						if(reportCheck == 0)
						{
							archive_save(list, len, type, lenType, path);
						}
						else
						{
							if(reportCheck == 1)
							{
								archive_countAmount(path, &count);
								passenger_reasingId(list, len, &count);
								(**id) = count;
								archive_rewrite(list, len, type, lenType, path);
							}
						}


		}

	return report;
}

