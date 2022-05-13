#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "Menu.h"
#include "Validation.h"

#define LIMIT 2000
#define LIMIT_TYPE 3
#define LIMIT_STATUS 2

#define LIMIT_NAME 51
#define LIMIT_LASTNAME 51
#define LIMIT_CODE 10

int main(void) {

	setbuf(stdout, NULL);

	Passenger list[LIMIT];
	Passenger aux;
	eTypePassenger listType[LIMIT_TYPE];
	eStatusFlight listStatus[LIMIT_STATUS];

	int option;
	int optionSecond;
	int optionThird;
	int counterId = 0;
	int id;
	int position;
	int positionLow;
	int flag = 0;
	float total;
	float average;
	int counterAverage;

	int reportinfo;
	int reportId;
	int reportIdLow;
	int reportIdValid;
	int reportName;
	int reportLastName;
	int reportPrice;
	int reportCode;
	int reportType;
	int reportStatus;

		initPassengers(list, LIMIT);
		forceDataTypePassenger(listType);
		forceDatastatusFlight(listStatus);

		do{

			printMenu();
			saveOption(&option);

				switch(option)
				{
					case 1:
						reportinfo = askForInformation(list, LIMIT, listType, LIMIT_TYPE,  listStatus, LIMIT_STATUS, &counterId);

							if(reportinfo == 0)
							{
								flag = 1;
							}
					break;

					case 2:
						if(flag == 1)
						{

							printPassenger(list, LIMIT, listType, LIMIT_TYPE, listStatus, LIMIT_STATUS);
							reportId = getNumberTypeInt(&id, "Ingrese el ID: ", "Error. Solo se pueden ingresar numeros\n", 0, 2001, 3);
								if(reportId == 0)
								{
									reportIdValid = findPassengerById(list, LIMIT, id, &position);

										if(reportIdValid == 0)
										{
											do{
												printMenuSecond();
												saveOption(&optionSecond);

													switch(optionSecond)
													{
														case 1:
															strcpy(aux.name, list[position].name);
															reportName = getNameOrLastName(list[position].name, LIMIT_NAME, "Nombre del pasajero: ", "Error. Introdusca bien el nombre\n", 3);

																if(reportName != 0)
																{
																	strcpy(list[position].name, aux.name);
																}
														break;

														case 2:
															strcpy(aux.lastName, list[position].lastName);
															reportLastName = getNameOrLastName(list[position].lastName, LIMIT_LASTNAME, "Apellido del pasajero: ", "Error. Introdusca bien el apellido\n", 3);

																if(reportLastName != 0)
																{
																	strcpy(list[position].lastName, aux.lastName);
																}

														break;

														case 3:
															aux.price = list[position].price;
															reportPrice = getNumberTypeFloat(&list[position].price, "Ingrese precio: ", "Error. Introdusca bien el precio\n", 1, 1000000, 3);

																if(reportPrice != 0)
																{
																	list[position].price = aux.price;
																}
														break;

														case 4:
															strcpy(aux.flycode, list[position].flycode);
															reportCode = getNumberAlphanumeric(list[position].flycode, LIMIT_CODE, "Ingrese codigo de vuelo: ", "Error. Solo se permiten letras y numeros\n", 3);
																if(reportCode != 0)
																{
																	strcpy(list[position].flycode, aux.flycode);
																}
														break;

														case 5:
															aux.typePassenger = list[position].typePassenger;

															printTypePassenger(listType, LIMIT_TYPE);
															reportType = getNumberTypeInt(&list[position].typePassenger, "\nIngrese el tipo de pasajero: ", "Error. Ingrese bien el tipo de pasajero\n", 999, 1100, 3);
																if(reportType != 0)
																{
																	list[position].typePassenger = aux.typePassenger;
																}
														break;

														case 6:
															aux.statusFlight = list[position].statusFlight;

															printStatusflight(listStatus, LIMIT_STATUS);
															reportStatus = getNumberTypeInt(&list[position].statusFlight, "\nIngrese el estado del vuelo: ", "Error. Ingrese bien el estado del vuelo\n", 2999, 3101, 3);
																if(reportStatus != 0)
																{
																	list[position].statusFlight = aux.statusFlight;
																}
														break;

													}

											}while(optionSecond != 7);
										}

								}
						}
					break;

					case 3:
						if(flag == 1)
						{
							printPassenger(list, LIMIT, listType, LIMIT_TYPE, listStatus, LIMIT_STATUS);
									reportIdLow = getNumberTypeInt(&id, "Ingrese el ID: ", "Error. Solo se pueden ingresar numeros\n", 0, 2001, 3);

										if(reportIdLow == 0)
										{
											reportIdValid = findPassengerById(list, LIMIT, id, &positionLow);

												if(reportIdValid == 0)
												{
													removePassenger(list, LIMIT, id);
												}

										}
						}

					break;

					case 4:
						if(flag == 1)
						{
							do{
								printMenuThird();
								saveOption(&optionThird);

									switch(optionThird)
									{
										case 1:
											sortPassengers(list, LIMIT, 0);
											printPassenger(list, LIMIT, listType, LIMIT_TYPE, listStatus, LIMIT_STATUS);

										break;

										case 2:
											getTotalAverage(list, LIMIT, &total, &average);
											getHowManyExceedAverage(list, LIMIT, average, &counterAverage);

											printTypefloat(total, "\nEl precio total es: ");
											printTypefloat(average, "\nEl promedio de los precios es de: ");
											printTypeInt(counterAverage, "\nLa cantidad de personas que superan el promedio son: ");

										break;

										case 3:
											sortPassengersByCode(list, LIMIT, 0);
											printPassenger(list, LIMIT, listType, LIMIT_TYPE, listStatus, LIMIT_STATUS);
										break;
									}

							}while(optionThird != 4);
						}


					break;

					case 5:
						printf("Cerrando Programa\n");
						system("PAUSE");
					break;
				}

		}while(option != 5);

	return EXIT_SUCCESS;
}