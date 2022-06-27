#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"
#include "Validations.h"
#include "Menu.h"

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

    LinkedList* listaPasajeros = ll_newLinkedList();
    LinkedList* listaPasajerosAuxilear = ll_newLinkedList();

    int option = 0;
    int id = 0;

    int reportAdd;
    int reportLoad;
    int reportLoadBin;

    int flagLoad = 0;

    int flagSaveTxt = 1;
    int flagSaveBin = 1;


    	if(listaPasajeros != NULL && listaPasajerosAuxilear != NULL)
    	{
			do{

				printMenuOptions();
				option = requestOption(1, 11);

				switch(option)
				{
					case 1:
						if(flagLoad == 0)
						{
							reportLoad = controller_loadFromText("data.csv",listaPasajeros);
								if(reportLoad == 0)
								{
									flagLoad = 1;
									id = passenger_searchIdMax(listaPasajeros);
								}
						}
						else
						{
							printf("Los pasajeros ya fueron cargados\n");
						}
					break;

					case 2:
						if(flagLoad == 0)
						{
							reportLoadBin = controller_loadFromBinary("dataBinario", listaPasajeros);
								if(reportLoadBin == 0)
								{
									flagLoad = 1;
									id = passenger_searchIdMax(listaPasajeros);
								}
						}
						else
						{
							printf("Los pasajeros ya fueron cargados\n");
						}
					break;

					case 3:
						reportAdd = controller_addPassenger(listaPasajeros);
							if(reportAdd == 0)
							{
								passenger_addId(listaPasajeros, &id);
							}
					break;

					case 4:
						if( !ll_isEmpty(listaPasajeros) )
						{
							controller_editPassenger(listaPasajeros);
						}
						else
						{
							printf("No hay pasajeros para modificar\n");
						}

					break;

					case 5:
						if( !ll_isEmpty(listaPasajeros) )
						{
							controller_removePassenger(listaPasajeros);
						}
						else
						{
							printf("No hay pasajeros para dar de baja\n");
						}
					break;

					case 6:
						if( !ll_isEmpty(listaPasajeros) )
						{
							controller_ListPassenger(listaPasajeros);
						}
						else
						{
							printf("No hay pasajeros para listar\n");
						}

					break;

					case 7:
						if( !ll_isEmpty(listaPasajeros) )
						{
							controller_sortPassenger(listaPasajeros);
						}
						else
						{
							printf("No hay pasajeros para ordenar\n");
						}
					break;

					case 8:
						if( !ll_isEmpty(listaPasajeros) )
						{
							listaPasajerosAuxilear = ll_clone(listaPasajeros);
							if(flagLoad == 0)
							{
								controller_loadFromText("data.csv",listaPasajerosAuxilear);
							}
							flagSaveTxt = controller_saveAsText("data.csv", listaPasajerosAuxilear);
						}
						else
						{
							printf("No hay pasajeros para guardar\n");
						}
					break;

					case 9:
						if( !ll_isEmpty(listaPasajeros) )
						{
							listaPasajerosAuxilear = ll_clone(listaPasajeros);
							if(flagLoad == 0)
							{
								controller_loadFromBinary("dataBinario", listaPasajerosAuxilear);
							}
							flagSaveBin = controller_saveAsBinary("dataBinario", listaPasajerosAuxilear);
						}
						else
						{
							printf("No hay pasajeros para guardarr\n");
						}
					break;

					case 10:
						if(!ll_isEmpty(listaPasajeros))
						{
							option = menu_exit(flagSaveBin, flagSaveTxt);
						}
					break;
				}
			}while(option != 10);
    	}

    return 0;
}

