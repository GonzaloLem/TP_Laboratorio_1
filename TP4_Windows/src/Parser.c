#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (0) todoOk
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* ePassenger;
	Passenger* aux;

	int report = -1;

	char buffer[7][50];

	char idTxt[100];
	char name[100];
	char lastName[100];
	char priceTxt[100];
	char typePassengerTxt[100];
	char typePassengerNumTxt[20];
	char flyCode[100];
	char statusFlight[100];

		if(pFile != NULL && pArrayListPassenger != NULL)
		{
			report = 0;

			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", *(buffer+0), *(buffer+1), *(buffer+2), *(buffer+3), *(buffer+4), *(buffer+5), *(buffer+6));

				do{
					if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idTxt, name, lastName, priceTxt, flyCode, typePassengerTxt,statusFlight) == 7)
					{
						passenger_setType(typePassengerTxt, typePassengerNumTxt);
						aux = Passenger_newParametrosTxt(idTxt, name, lastName, priceTxt, typePassengerNumTxt, flyCode,  statusFlight);

							if(aux != NULL)
							{
								ePassenger = aux;
								ll_add(pArrayListPassenger, ePassenger);
							}
					}

				}while( !feof(pFile) );

		}

    return report;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (0) todoOk
 *
 */
int parser_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{
	Passenger ePassengerAux;
	Passenger* aux;
	Passenger* ePassenger;

	int report = -1;

		if(pFile != NULL && pArrayListPassenger != NULL)
		{
			report = 0;

			do{

				if(fread(&ePassengerAux, sizeof(Passenger), 1, pFile) == 1 )
				{

					aux = Passenger_newParametros(ePassengerAux.id, ePassengerAux.nombre, ePassengerAux.apellido, ePassengerAux.precio, ePassengerAux.tipoPasajero, ePassengerAux.codigoVuelo, ePassengerAux.estadoDelVuelo);

						if(aux != NULL)
						{
							ePassenger = aux;
							ll_add(pArrayListPassenger, ePassenger);
						}
				}

			}while( !feof(pFile));
		}

	return report;
}

/**
 * @brief Guarda los datos en un archivo de texto
 *
 * @param pFile FILE*
 * @param pArrayListPassenger LinkedList*
 * @return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (0) todoOk
 */
int parser_PassengerSaveText(FILE* pFile, LinkedList* pArrayListPassenger)
{
	Passenger* ePassenger;
	int report = -1;

	int i;

	int id;
	int passengerType;
	char name[50];
	char lastName[50];
	float price;
	char flyCodee[16];
	char typePassengerTxt[26];
	char statusFlightt[26];


		if(pFile != NULL && pArrayListPassenger != NULL)
		{
			report = 0;

				fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
				for(i=0;i<ll_len(pArrayListPassenger);i++)
				{
					ePassenger = ll_get(pArrayListPassenger, i);

						if(ePassenger != NULL)
						{
								Passenger_getId( ePassenger, &id);
								Passenger_getNombre( ePassenger, name);
								Passenger_getApellido( ePassenger, lastName);
								Passenger_getPrecio( ePassenger, &price);
								Passenger_getTipoPasajero( ePassenger, &passengerType);
								passenger_getType(passengerType, typePassengerTxt);
								Passenger_getCodigoVuelo( ePassenger, flyCodee );
								Passenger_getEstadoDelVuelo( ePassenger, statusFlightt);

								//printf(" %d - %s - %s - %.2f - %s - %s - %s\n", id, name, lastName, price, flyCodee, typePassengerTxt, statusFlightt);

								fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n", id, name, lastName, price, flyCodee, typePassengerTxt, statusFlightt);
						}


				}

		}

    return report;
}

/**
 * @brief  guarda los datos en un archivo binario
 *
 * @param pFile FILE*
 * @param pArrayListPassenger LinkedList*
 * @return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (0) todoOk
 */
int parser_PassengerSaveBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{
	Passenger* ePassenger;
	Passenger ePassengerAux;

	int report = -1;

	int i;

		if(pFile != NULL && pArrayListPassenger != NULL)
		{
			report = 0;

			for(i=0;i<ll_len(pArrayListPassenger);i++)
			{
				ePassenger = ll_get(pArrayListPassenger, i);

					if(ePassenger != NULL)
					{
						ePassengerAux = *ePassenger;
						fwrite(&ePassengerAux, sizeof(Passenger), 1, pFile);
					}


			}
		}

	return report;
}

