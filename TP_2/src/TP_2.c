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

	int option;
	int counterId = 0;

	int flag;

		initPassengers(list, LIMIT);

/*		forcedLoad(list, LIMIT, "Gonzalo", "Leminia", 10000, "GL11", 2, 1, &counterId); //Pasajeros para cargar forzosamente
		forcedLoad(list, LIMIT, "Martina", "Leminia", 13000, "ML22", 1, 1, &counterId);
		forcedLoad(list, LIMIT, "Valeria", "Vazquez", 20000, "VV21", 3, 2, &counterId);
		forcedLoad(list, LIMIT, "Leonardo", "Gilardi", 6000, "LG66", 2, 1, &counterId);
		forcedLoad(list, LIMIT, "Jesica", "Gonzalez", 9000, "JGD2", 2, 2, &counterId);
		forcedLoad(list, LIMIT, "Graciela", "Dalto", 16000, "GL11", 3, 2, &counterId);*/

		do{
			flag = searchHousingLoaded(list, LIMIT);

			printMenu();
			saveOption(&option);

				switch(option)
				{
					case 1:
						askForInformation(list, LIMIT, &counterId);
					break;

					case 2:
						if(flag == 0)
						{
							modifiPassenger(list, LIMIT);
						}
						else
						{
							printf("No hay pasajeros para modficar\n");
						}
					break;

					case 3:
						if(flag == 0)
						{
							passenger_removePassenger(list, LIMIT);
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

				}

		}while(option != 5);

	return EXIT_SUCCESS;
}
