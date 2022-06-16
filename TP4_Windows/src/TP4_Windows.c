#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"
#include "Passenger.h"
#include "Menu.h"
#include "Validations.h"

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

	int reportController_Sort;
	int reportController_LoadTxt;
	int reportController_LoadBin;
	int reportController_SaveTxt;
	int reportController_SaveBin;

    int option = 0;
    int flagHigh;
    int flagLoad = 0;
    int flagSaveTxt = 0;
    int flagSaveBin = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{

    	flagHigh = ll_len(listaPasajeros );

		printMenuOptions();
		option = requestOption(1, 11);

        switch(option)
        {
            case 1:
            	if(flagLoad == 0)
            	{
            		reportController_LoadTxt = controller_loadFromText("data.csv",listaPasajeros);

            			if(reportController_LoadTxt == 0)
            			{
            				printf("Los datos fueron cargados correctamente\n");
            				flagLoad = 1;
            			}
            	}
            	else
            	{
            		printf("Los datos ya estan cargados en el sistema\n");
            	}

            break;

            case 2:
            	if(flagLoad == 0)
            	{
            		reportController_LoadBin = controller_loadFromBinary("dataBin",listaPasajeros);

            			if(reportController_LoadBin == 0)
            			{
            				printf("Los datos fueron cargados correctamente\n");
            				flagLoad = 1;
            			}
            	}
            	else
            	{
            		printf("Los datos ya estan cargados en el sistema\n");
            	}
            break;

            case 3:
            	controller_addPassenger(listaPasajeros);
            break;

            case 4:
            	if(flagHigh > 0)
            	{
            		controller_editPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("No hay pasajeros para modificar\n");
            	}
            break;

            case 5:
            	if(flagHigh > 0)
            	{
            		controller_removePassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("No hay pasajeros para eliminar\n");
            	}
            break;

            case 6:
            	if(flagHigh > 0)
            	{
            		controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("No hay pasajeros para listar\n");
            	}
            break;

            case 7:
            	if(flagHigh > 0)
            	{
            		reportController_Sort = controller_sortPassenger(listaPasajeros);

            			if(reportController_Sort == 0)
            			{
            				printf("Pasajeros ordenados correctamente\n");
            			}
            	}
            	else
            	{
            		printf("No hay pasajeros para ordenar\n");
            	}
            break;

            case 8:
            	if(flagHigh > 0)
            	{
            		reportController_SaveTxt = controller_saveAsText("data.csv",listaPasajeros);

            			if(reportController_SaveTxt == 0)
            			{
            				flagSaveTxt = 1;
            			}
            	}
            	else
            	{
            		printf("No hay pasajeros para guardar\n");
            	}
            break;

            case 9:
            	if(flagHigh > 0)
            	{
            		reportController_SaveBin = controller_saveAsBinary("dataBin" , listaPasajeros);

            			if(reportController_SaveBin == 0)
            			{
            				flagSaveBin = 1;
            			}
            	}
            	else
            	{
            		printf("No hay pasajeros para guardar\n");
            	}
            break;

            case 10:
            	option = menu_exit(flagSaveTxt, flagSaveBin, 10, "Se guardo en modo texto", "No fue guardado en modo texto", "Se guardo en modo binario", "No se guardo en modo binario");
            break;
        }
    }while(option != 10);

    return 0;
}

