#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	LinkedList* listClone = ll_newLinkedList();
	Passenger* list;
	TypePassenger type[TAM_TYPE] = { {20001, "FirstClass"}, {20010, "Executive"}, {20020, "EconomyClass"} };
	Passenger* aux;

	int report = -1;

	char buffer[7][30];
	int i;

	int id = 0;
	int idType;
	char idTxt[LIMIT_BUFFER];
	char name[LIMIT_BUFFER];
	char lastName[LIMIT_BUFFER];
	char priceTxt[LIMIT_BUFFER];
	char typePassengerTxt[LIMIT_BUFFER];
	char flyCode[LIMIT_BUFFER];
	char statusFlight[LIMIT_BUFFER];

		if(listClone != NULL && pFile != NULL && pArrayListPassenger != NULL)
		{
			report = 0;

			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
			do{
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idTxt, name, lastName, priceTxt, flyCode, typePassengerTxt, statusFlight) == 7)
				{
					typePassenger_searchType(type, TAM_TYPE, typePassengerTxt, &idType);
					sprintf(typePassengerTxt, "%d", idType);

					aux = Passenger_newParametrosTxt(idTxt, name, lastName, priceTxt, typePassengerTxt, flyCode, statusFlight);

						if(aux != NULL)
						{
							report = 0;
							list = aux;
							ll_add(listClone, list);

								if(atoi(idTxt) > id)
								{
									id = atoi(idTxt);
								}
						}
				}

			}while( !feof(pFile) );

			passenger_reasingId(pArrayListPassenger, id, 2);

				for(i=0;i<ll_len(listClone);i++)
				{
					list = ll_get(listClone, i);

						if(list != NULL)
						{
							ll_add(pArrayListPassenger, list);
						}
				}

		}

    return report;
}


int parser_searchIdMax(char* path,LinkedList* pArrayListPassenger)
{
	FILE* pFile;

	int report = -1;

	int id = 0;

	char bufferUno[7][30];
	char idTxt[4096];
	char buffer[4096];

		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferUno[0], bufferUno[1], bufferUno[2], bufferUno[3], bufferUno[4], bufferUno[5], bufferUno[6]);
			do{
				if(fscanf(pFile,"%[^,],%[^\n]\n", idTxt, buffer))
				{
					if(atoi(idTxt) >= id)
					{
						id = atoi(idTxt);
					}
				}
			}while( !feof(pFile) );

			report = id;
			fclose(pFile);
		}


	return report;
}

int file_serachPassenger(char* path, LinkedList* pArrayListPassenger)
{
	LinkedList* listClone = ll_newLinkedList();
	FILE* pFile;
	Passenger* listOne;
	Passenger* listTwo;
	Passenger* aux;

	int report = -1;

	int i;
	int j;
	int len;
	char lecFant[7][50];

	char idTxt[100];
	char name[100];
	char lastName[100];
	char priceTxt[100];
	char typePassengerTxt[100];
	char flyCode[100];
	char statusFlight[100];

		if(listClone != NULL && path != NULL && pArrayListPassenger != NULL)
		{
			report = 1;
			pFile = fopen(path, "r");
				if(pFile != NULL)
				{
					len = ll_len(pArrayListPassenger);
					fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", lecFant[0], lecFant[1], lecFant[2], lecFant[3], lecFant[4], lecFant[5], lecFant[6]);
					do{
						if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idTxt, name, lastName, priceTxt, flyCode, typePassengerTxt,statusFlight) == 7)
						{

							aux = Passenger_newParametrosTxt(idTxt, name, lastName, priceTxt, typePassengerTxt, flyCode, statusFlight);

								if(aux != NULL)
								{
									report = 0;
									listOne = aux;
									ll_add(listClone, listOne);

								}
						}

					}while( !feof(pFile) );
					fclose(pFile);

					for(i=0;i<len;i++)
					{
						listOne = ll_get(pArrayListPassenger, i);

						for(j=0;j<ll_len(listClone);j++)
						{
							listTwo = ll_get(listClone, j);


						/*	Passenger_getCodigoVuelo(listTwo, code);
							Passenger_getNombre(listTwo, nam);
							Passenger_getApellido(listTwo, last);

							compCode = strcmp(flyCode, code);
							compName = strcmp(name, nam);
							compLastName = strcmp(lastName, last);*/

							/*	if(compCode == 0 && compName == 0 && compLastName == 0)
								{
									flag = 1;
									break;
								}*/

							if(listOne == listTwo)
							{
								printf("Entro\n");
								break;
							}

						}

					}

				}
		}

	return report;
}

int file_toRewriteFile(char* path, LinkedList* pArrayListPassenger)
{
	FILE* pFile;

	Passenger* list;
	TypePassenger type[TAM_TYPE] = { {20001, "FirstClass"}, {20010, "Executive"}, {20020, "EconomyClass"} };

	int report = -1;
	int i;
	int len;

	int id;
	int passengerType;
	char name[50];
	char lastName[50];
	float price;
	char flyCodee[16];
	char typePassengerTxt[26];
	char statusFlightt[26];


		if(pArrayListPassenger != NULL && path != NULL)
		{

			pFile = fopen(path, "w+");
				if(pFile != NULL)
				{
					report = 0;
					len = ll_len(pArrayListPassenger);

					fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
					for(i=0;i<len;i++)
					{
						list = ll_get(pArrayListPassenger, i);

							if(list != NULL)
							{
									Passenger_getId( list, &id);
									Passenger_getNombre( list, name);
									Passenger_getApellido( list, lastName);
									Passenger_getPrecio( list, &price);
									Passenger_getTipoPasajero( list, &passengerType);
									searchIdType(type, TAM_TYPE, passengerType, typePassengerTxt);
									Passenger_getCodigoVuelo( list, flyCodee );
									Passenger_getEstadoDelVuelo( list, statusFlightt);

									//printf(" %d - %s - %s - %.2f - %s - %s - %s\n", id, name, lastName, price, flyCodee, typePassengerTxt, statusFlightt);

									fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n", id, name, lastName, price, flyCodee, typePassengerTxt, statusFlightt);
							}

					}
					fclose(pFile);
				}

		}

	return report;
}

int file_writeBelow(char* path, LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* list;
	TypePassenger type[TAM_TYPE] = { {20001, "FirstClass"}, {20010, "Executive"}, {20020, "EconomyClass"} };

	int report = -1;
	int i;
	int len;

	int id;
	int passengerType;
	char name[50];
	char lastName[50];
	float price;
	char flyCodee[16];
	char typePassengerTxt[26];
	char statusFlightt[26];

		if(path != NULL && pArrayListPassenger != NULL)
		{
			pFile = fopen(path, "a");

				if(pFile != NULL)
				{
					len = ll_len(pArrayListPassenger);
					//fprintf(pFile,"\n");
					for(i=0;i<len;i++)
					{
						list = ll_get(pArrayListPassenger, i);
							if(list != NULL)
							{
								Passenger_getId( list, &id);
								Passenger_getNombre( list, name);
								Passenger_getApellido( list, lastName);
								Passenger_getPrecio( list, &price);
								Passenger_getTipoPasajero( list, &passengerType);
								searchIdType(type, TAM_TYPE, passengerType, typePassengerTxt);
								Passenger_getCodigoVuelo( list, flyCodee );
								Passenger_getEstadoDelVuelo( list, statusFlightt);

								//printf(" %d - %s - %s - %.2f - %s - %s - %s\n", id, name, lastName, price, flyCodee, typePassengerTxt, statusFlightt);

								fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n", id, name, lastName, price, flyCodee, typePassengerTxt, statusFlightt);
							}
					}
					fclose(pFile);
				}
		}

	return report;
}


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* list;
	Passenger* pPassenger;
	Passenger aux;
	TypePassenger type[TAM_TYPE] = { {20001, "FirstClass"}, {20010, "Executive"}, {20020, "EconomyClass"} };

	int report = -1;

	char typePassengerTxt[LIMIT_BUFFER];

		if(pFile != NULL && pArrayListPassenger != NULL)
		{
			report = 0;
				do{
					if(fread(&aux,sizeof(Passenger),1,pFile))
					{
						searchIdType(type, TAM_TYPE, aux.tipoPasajero, typePassengerTxt);
						//printf("%d - %s - %s - %f - %s - %s - %s\n", aux.id, aux.nombre, aux.apellido, aux.precio, aux.codigoVuelo, typePassengerTxt,aux.estadoDelVuelo);

						pPassenger = Passenger_newParametros(aux.id, aux.nombre, aux.apellido,aux.precio,aux.tipoPasajero, aux.codigoVuelo, aux.estadoDelVuelo);

							if(pPassenger != NULL)
							{

								*pPassenger = aux;
								list = pPassenger;
								passenger_reasingId(pArrayListPassenger, aux.id, 1);//Ver si esta bien la opcion
								ll_add(pArrayListPassenger, list);

							}
					}
				}while( !feof(pFile) );

		}


    return report;
}

int parser_searchIdMaxBin(char* path,LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger aux;

	int report = -1;

	int id = 0;

		pFile = fopen(path, "rb");
		if(pFile != NULL)
		{

			do{
				if(fread(&aux,sizeof(Passenger),1,pFile))
				{
					if(aux.id >= id)
					{
						id = aux.id;
					}
				}
			}while( !feof(pFile) );

			report = id;
			fclose(pFile);
		}


	return report;
}

int parser_searchPassengerBin(char* path,  LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* list;
	Passenger aux;

	int report = -1;
	int i;
	int len;


		if(path != NULL && pArrayListPassenger != NULL)
		{
			pFile = fopen(path, "wb");
				if(pFile != NULL)
				{
					len = ll_len(pArrayListPassenger);
					for(i=0;i<len;i++)
					{
						list = ll_get(pArrayListPassenger, i);
						aux = *list;
						fwrite(&aux, sizeof(Passenger), 1, pFile);
					}
					fclose(pFile);
				}
		}

	return report;
}

int file_serachPassengerBin(char* path, LinkedList* pArrayListPassenger)
{
	LinkedList* listPassengerClone = ll_newLinkedList();;
	FILE* pFile;
	Passenger* list;
	Passenger* listClone;
	TypePassenger type[TAM_TYPE] = { {20001, "FirstClass"}, {20010, "Executive"}, {20020, "EconomyClass"} };
	Passenger* pPassenger;
	Passenger aux;

	int report = -1;

	char typePassengerTxt[26];
	int i;
	int j;

	char code[100];
	char nam[100];
	char last[100];

	char c[100];
	char n[100];
	char l[100];


	int compName;
	int compLastName;
	int compCode;

		if(path != NULL && pArrayListPassenger != NULL)
		{

			pFile = fopen(path, "rb");
				if(pFile != NULL)
				{
					report = 1;
					do{
						if(fread(&aux,sizeof(Passenger),1,pFile))
						{

							searchIdType(type, TAM_TYPE, aux.tipoPasajero, typePassengerTxt);
							//printf("%d - %s - %s - %f - %s - %s - %s\n", aux.id, aux.nombre, aux.apellido, aux.precio, aux.codigoVuelo, typePassengerTxt,aux.estadoDelVuelo);

							pPassenger = Passenger_newParametros(aux.id, aux.nombre, aux.apellido,aux.precio,aux.tipoPasajero, aux.codigoVuelo, aux.estadoDelVuelo);

								if(pPassenger != NULL)
								{
									*pPassenger = aux;
									listClone = pPassenger;
									ll_add(listPassengerClone, listClone);
								}
						}

					}while( !feof(pFile));
					fclose(pFile);


					for(i=0;i<ll_len(pArrayListPassenger);i++)
					{
						list = ll_get(pArrayListPassenger, i);

						Passenger_getCodigoVuelo(list, code);
						Passenger_getNombre(list, nam);
						Passenger_getApellido(list, last);

						//printf("LIST: %d - %s - %s - %.2f - %d - %s - %s \n", list->id,list->nombre, list->apellido,list->precio, list->tipoPasajero, list->codigoVuelo, list->estadoDelVuelo);


						for(j=0;j<ll_len(listPassengerClone);j++)
						{

							listClone = ll_get(listPassengerClone, i);

							//printf("CLON: %d - %s - %s - %.2f - %d - %s - %s \n", listClone->id,listClone->nombre, listClone->apellido,listClone->precio, listClone->tipoPasajero, listClone->codigoVuelo, listClone->estadoDelVuelo);

							Passenger_getCodigoVuelo(listClone, c);
							Passenger_getNombre(listClone, n);
							Passenger_getApellido(listClone, l);

							compCode = strcmp(c, code);
							compName = strcmp(n, nam);
							compLastName = strcmp(l, last);

								if(compCode == 0 && compName == 0 && compLastName == 0)
								{
									report = 0;
									break;
								}

						}
					}


				}
		}

	return report;
}

int file_reasingId(char* path, LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* list;
	Passenger aux;

	int report = -1;

	int i;
	int len;
	int id;
	int idMax;
	int flag = 0;
	int get;

	char code[100];
	char nam[100];
	char last[100];

	int compName;
	int compLastName;
	int compCode;

		if(path != NULL && pArrayListPassenger != NULL)
		{
			pFile = fopen(path, "rb");

				if(pFile != NULL)
				{
					len = ll_len(pArrayListPassenger);


					idMax = parser_searchIdMaxBin(path, pArrayListPassenger);


					do{
						if(fread(&aux,sizeof(Passenger),1,pFile))
						{
							for(i=0;i<len;i++)
							{
								list = ll_get(pArrayListPassenger, i);

								Passenger_getId(list, &id);

									if(aux.id == id)
									{
										Passenger_getCodigoVuelo(list, code);
										Passenger_getNombre(list, nam);
										Passenger_getApellido(list, last);

										compCode = strcmp(aux.codigoVuelo, code);
										compName = strcmp(aux.nombre, nam);
										compLastName = strcmp(aux.apellido, last);

											if(compCode != 0 && compName != 0 && compLastName != 0)
											{
												passenger_reasingId(pArrayListPassenger,  idMax, 2);
												flag = 1;
												break;
											}
									}
							}
						}

						if(flag == 1)
						{
							get = 1;
							break;
						}
					}while( !feof(pFile));
					fclose(pFile);

					report = get;
				}
		}

	return report;
}

int file_carryPassengerBin(char* path, LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* list;
	TypePassenger type[TAM_TYPE] = { {20001, "FirstClass"}, {20010, "Executive"}, {20020, "EconomyClass"} };
	Passenger* pPassenger;
	Passenger aux;

	int report = -1;

	char typePassengerTxt[26];

		if(path != NULL && pArrayListPassenger != NULL)
		{

			pFile = fopen(path, "rb");
				if(pFile != NULL)
				{
					report = 0;
					do{
						if(fread(&aux,sizeof(Passenger),1,pFile))
						{
							searchIdType(type, TAM_TYPE, aux.tipoPasajero, typePassengerTxt);
							//printf("%d - %s - %s - %f - %s - %s - %s\n", aux.id, aux.nombre, aux.apellido, aux.precio, aux.codigoVuelo, typePassengerTxt,aux.estadoDelVuelo);

							pPassenger = Passenger_newParametros(aux.id, aux.nombre, aux.apellido,aux.precio,aux.tipoPasajero, aux.codigoVuelo, aux.estadoDelVuelo);

								if(pPassenger != NULL)
								{

									*pPassenger = aux;
									list = pPassenger;
									//printf("NOMBRE 1: %s\n", list->nombre);
									ll_add(pArrayListPassenger, list);

								}
						}
					}while( !feof(pFile));
					fclose(pFile);
				}
		}

	return report;
}

int file_writeBelowBinBis(char* path, LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* list;
	Passenger aux;

	int report = -1;
	int i;
	int len;

		if(path != NULL && pArrayListPassenger != NULL)
		{
			pFile = fopen(path, "wb");
				if(pFile != NULL)
				{
					len = ll_len(pArrayListPassenger);
					for(i=0;i<len;i++)
					{
						list = ll_get(pArrayListPassenger, i);
							if(list != NULL)
							{
								//printf("NOMBRE 2 %s\n", list->nombre);
								aux = *list;
								fwrite(&aux,sizeof(Passenger),1,pFile);
							}
					}
					fflush(pFile);
					fclose(pFile);
				}
		}

	return report;
}

int file_idMaxBin(char* path, LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger aux;

	int report = -1;
	int id = 0;

		if(path != NULL && pArrayListPassenger != NULL)
		{
			pFile = fopen(path, "rb");
				if(pFile != NULL)
				{

					do{

						if(fread(&aux,sizeof(Passenger),1,pFile))
						{
							if(aux.id > id)
							{
								id = aux.id;
							}
						}

					}while( !feof(pFile) );
					fclose(pFile);

					report = id;
				}
		}

	return report;
}

int file_writeBelowBin(char* path, LinkedList* pArrayListPassenger)
{
	LinkedList* listClone = ll_newLinkedList();;
	FILE* pFile;
	Passenger* list;
	Passenger* clone;
	Passenger aux;

	int report = -1;

	int i;
	int len;
	int id;

		if(path != NULL && pArrayListPassenger != NULL)
		{
			file_carryPassengerBin(path, listClone);

				for(i=0;i<ll_len(pArrayListPassenger);i++)
				{
					list = ll_get(pArrayListPassenger, i);

						if(list != NULL)
						{
							ll_add(listClone, list);
						}

				}

				id = file_idMaxBin(path, pArrayListPassenger);
				passenger_reasingId(pArrayListPassenger, id, 2);

			pFile = fopen(path, "wb");
				if(pFile != NULL)
				{
					len = ll_len(listClone);

						for(i=0;i<len;i++)
						{
							clone = ll_get(listClone, i);
								if(list != NULL)
								{
									//printf("NOMBRE 2 %s\n", list->nombre);
									aux = *clone;
									fwrite(&aux,sizeof(Passenger),1,pFile);
								}
						}


					fclose(pFile);
				}
		}

	return report;
}


