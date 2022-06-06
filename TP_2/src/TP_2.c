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
	eTypePassenger listType[LIMIT_TYPE] = { {1000, "Niño"}, {1010, "Adulto"}, {1020, "Anciano"} };
	eStatusFlight listStatus[LIMIT_STATUS] = { {3000, "Activo"}, {3100, "Inactivo"} };

	int option;
	int optionSecond;
	int optionThird;
	int counterId = 0;
	int id;
	int position;
	int positionLow;

	int flag;
	float total;
	float average;
	int counterAverage;

		initPassengers(list, LIMIT);

		do{
			flag = searchHousingLoaded(list, LIMIT);

			printMenu();
			saveOption(&option);

				switch(option)
				{
					case 1:
						askForInformation(list, LIMIT, listType, LIMIT_TYPE,  listStatus, LIMIT_STATUS, &counterId);
					break;

					case 2:
						if(flag == 0)
						{
							position = requestid(list, LIMIT, listType, LIMIT_TYPE,  listStatus, LIMIT_STATUS);

								if(position != -1 && position != -2)
								{
											do{
												printMenuSecond();
												saveOption(&optionSecond);

													switch(optionSecond)
													{
														case 1:
															modifyPassengerData(list, position, listType, LIMIT_TYPE, listStatus, LIMIT_STATUS, 1);
														break;

														case 2:
															modifyPassengerData(list, position, listType, LIMIT_TYPE, listStatus, LIMIT_STATUS, 2);
														break;

														case 3:
															modifyPassengerData(list, position, listType, LIMIT_TYPE, listStatus, LIMIT_STATUS, 3);
														break;

														case 4:
															modifyPassengerData(list, position, listType, LIMIT_TYPE, listStatus, LIMIT_STATUS, 4);
														break;

														case 5:
															modifyPassengerData(list, position, listType, LIMIT_TYPE, listStatus, LIMIT_STATUS, 5);
														break;

														case 6:
															modifyPassengerData(list, position, listType, LIMIT_TYPE, listStatus, LIMIT_STATUS, 6);
														break;

													}

											}while(optionSecond != 7);
								}
						}
					break;

					case 3:
						if(flag == 0)
						{

							positionLow = requestid(list, LIMIT, listType, LIMIT_TYPE,  listStatus, LIMIT_STATUS);
										if(positionLow != -1 && positionLow != -2)
										{
											id = returnId(list, positionLow);
											removePassenger(list, LIMIT, id);
										}
						}

					break;

					case 4:
						if(flag == 0)
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
						//reportForced = forcedLoad(list, LIMIT, &counterId);
					break;

					case 6:
						printf("Cerrando Programa\n");
						system("PAUSE");
					break;
				}

		}while(option != 6);

	return EXIT_SUCCESS;
}
