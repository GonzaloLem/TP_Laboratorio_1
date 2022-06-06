#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "Validations.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"

#define NUMBER_PASSENGER 1000
#define TYPE_PASSENGER 3

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

    int option;
    int id = 0;
    int flag;
    int flagLoad = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    TypePassenger types[TYPE_PASSENGER] = { {20001, "FirstClass"}, {20010, "Executive"}, {20020, "EconomyClass"} };
    Passenger* list[NUMBER_PASSENGER];

    	passenger_initArray(list, NUMBER_PASSENGER);

			do{
				flag = passenger_searchLoad(list, NUMBER_PASSENGER);
				printMenuOptions();
				option = requestOption(1, 10);
					switch(option)
					{
						case 1:
							controller_loadFromText("data.csv",listaPasajeros,list, NUMBER_PASSENGER, types, TYPE_PASSENGER, &id, &flagLoad);
						break;

						case 2:

						break;

						case 3:
							controller_addPassenger(listaPasajeros, list, NUMBER_PASSENGER, types, TYPE_PASSENGER, &id);
						break;

						case 4:
							if(flag == 0)
							{
								controller_editPassenger(listaPasajeros, list, NUMBER_PASSENGER,types, TYPE_PASSENGER);
							}
							else
							{
								printf("No hay datos cargados\n");
							}
						break;

						case 5:
							if(flag == 0)
							{
								 controller_removePassenger(listaPasajeros, list, NUMBER_PASSENGER,types, TYPE_PASSENGER);
							}
							else
							{
								printf("No hay datos cargados\n");
							}
						break;

						case 6:
							if(flag == 0)
							{
								controller_ListPassenger(listaPasajeros,list, NUMBER_PASSENGER,types, TYPE_PASSENGER);
							}
							else
							{
								printf("No hay datos cargados\n");
							}
						break;

						case 7:
							if(flag == 0)
							{
								controller_sortPassenger(listaPasajeros,list, NUMBER_PASSENGER,types, TYPE_PASSENGER);
							}
							else
							{
								printf("No hay datos cargados\n");
							}
						break;

						case 8:
							if(flag == 0)
							{
								controller_saveAsText("data.csv" , listaPasajeros, list, NUMBER_PASSENGER,types, TYPE_PASSENGER, &id);
							}
							else
							{
								printf("No hay datos cargados\n");
							}
						break;

						case 9:
							if(flag == 0)
							{

							}
							else
							{
								printf("No hay datos cargados\n");
							}
						break;
					}

			}while(option != 10);

    return 0;
}


/*

 * */
