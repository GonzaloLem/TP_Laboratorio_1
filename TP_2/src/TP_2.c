#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "Menu.h"
#include "Validation.h"

#define LIMIT 2000

int main(void) {

	setbuf(stdout, NULL);

	Passenger list[LIMIT];

	int reportAdd;
	int reportModify;
	int reportDelete;

	int option;
	int counterId = 0;

	int flag;
	int flagForced = 0;

		initPassengers(list, LIMIT);

		do{
			flag = searchHousingLoaded(list, LIMIT);

			printMenu();
			saveOption(&option);

				switch(option)
				{
					case 1:
						reportAdd = askForInformation(list, LIMIT, &counterId);

							if(reportAdd == 0)
							{
								printf("Pasajero cargado correctamente\n");
							}
							else
							{
								printf("Error. El pasajero no fue cargado\n");
							}
					break;

					case 2:
						if(flag == 0)
						{
							reportModify = modifiPassenger(list, LIMIT);
								if(reportModify != 0)
								{
									printf("No se encontro el pasjero\n");
								}
						}
						else
						{
							printf("No hay pasajeros para modficar\n");
						}
					break;

					case 3:
						if(flag == 0)
						{
							reportDelete = passenger_removePassenger(list, LIMIT);
								if(reportDelete == 0)
								{
									printf("Pasajero eliminado\n");
								}
								else
								{
									printf("No se encontro el pasajero\n");
								}
						}
						else
						{
							printf("No hay pasajeros para eliminar\n");
						}
					break;

					case 4:
						if(flag == 0)
						{
							passenger_report(list, LIMIT);
						}
						else
						{
							printf("No hay pasajeros para informar\n");
						}
					break;

					case 5:
						if(flagForced == 0)
						{
							forcedLoad(list, LIMIT, "Gonzalo", "Leminia", 20000, "GL11", 2, 1, &counterId); //Pasajeros para cargar forzosamente
							forcedLoad(list, LIMIT, "Martina", "Leminia", 30000, "ML22", 1, 1, &counterId);
							forcedLoad(list, LIMIT, "Valeria", "Vazquez", 18000, "VV21", 3, 2, &counterId);
							forcedLoad(list, LIMIT, "Leonardo", "Gilardi", 32000, "LG66", 2, 1, &counterId);
							forcedLoad(list, LIMIT, "Jesica", "Gonzalez", 45000, "JGD2", 2, 2, &counterId);
							//forcedLoad(list, LIMIT, "Graciela", "Dalto", 16000, "GL11", 3, 2, &counterId);

							flagForced = 1;
						}
						else
						{
							printf("Los datos ya fueron cargados\n");
						}

					break;

				}

		}while(option != 6);

	return EXIT_SUCCESS;
}
