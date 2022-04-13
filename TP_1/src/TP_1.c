/*
Gonzalo Lemiña
TP 1

Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)
 2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
 3. Calcular todos los costos:
 a) Tarjeta de débito (descuento 10%)
 b) Tarjeta de crédito (interés 25%)
 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
 d) Mostrar precio por km (precio unitario)
 e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
 4. Informar Resultados
“Latam:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 Aerolíneas:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int main(void) {

	setbuf(stdout, NULL);

	int opciones;
	int Kilometros = 0;

	float precio_aerolineas;
	float precio_latam;

	float debito_aerolineas; //Variables Aerolineas
	float credito_aerolinas;
	float btc_aerolineas;
	float precio_unitario_aerolineas;

	float debito_latam; //Variables Latam
	float credito_latam;
	float btc_latam;
	float precio_unitario_latam;

	float diferencia_aerolineas_latam;

	int bandera_case_3 = 1;
	int bandera_case_4 = 1;

		do{

			printf("1. Ingresar Kilometros \n"
					"2. Ingresar precio de vuelos \n"
					"3. Calcular todos los costos \n"
					"4. Informar resultados \n"
					"5. Carga forzada de datos \n"
					"6. Salir \n");
				scanf("%d", &opciones);


			switch(opciones)
			{
				case 1:
					//Prototipo real de Ingresar Kilometros
					ingresar_kilometros(&Kilometros);
				break;

				case 2:
					//Prototipo real de Precio de los vuelos Aerolineas y Latam
					precio_vuelos(&precio_aerolineas, &precio_latam);//Prototipo real de los precios
					bandera_case_3 = 0;
				break;

				case 3:
					if(bandera_case_3 == 0)//Fuerzo al usuario a ingresar a la opcion 2
					{
						//prototipos reales de los calculos
						calculos_aerolineas(Kilometros, precio_aerolineas, &debito_aerolineas, &credito_aerolinas, &btc_aerolineas, &precio_unitario_aerolineas);
						calculos_latam(Kilometros, precio_latam, &debito_latam, &credito_latam, &btc_latam, &precio_unitario_latam, precio_aerolineas, &diferencia_aerolineas_latam);

						bandera_case_4 = 0;
					}
					else
					{
						printf("No hay datos que calcular. Use la opcion 2 \n");
					}
				break;

				case 4:
					if(bandera_case_4 == 0)//Fuerzo al usuario a ingresar a la opcion 3
					{
						//prototipo real de los mensajes
						mensajes(Kilometros, precio_aerolineas, debito_aerolineas, credito_aerolinas,btc_aerolineas, precio_unitario_aerolineas, precio_latam, debito_latam, credito_latam, btc_latam, precio_unitario_latam, diferencia_aerolineas_latam);
					}
					else
					{
						printf("No hay datos calculados. Use la opcion 3 \n");
					}
				break;

				case 5:
					//Protipo real de forzar datos y llamo a las funciones de los calculos y del mensaje
					forzar_datos(&Kilometros, &precio_aerolineas, &precio_latam);
					calculos_aerolineas(Kilometros, precio_aerolineas, &debito_aerolineas, &credito_aerolinas, &btc_aerolineas, &precio_unitario_aerolineas);
					calculos_latam(Kilometros, precio_latam, &debito_latam, &credito_latam, &btc_latam, &precio_unitario_latam, precio_aerolineas, &diferencia_aerolineas_latam);
					mensajes(Kilometros, precio_aerolineas, debito_aerolineas, credito_aerolinas,btc_aerolineas, precio_unitario_aerolineas, precio_latam, debito_latam, credito_latam, btc_latam, precio_unitario_latam, diferencia_aerolineas_latam);

					bandera_case_3 = 0;
					bandera_case_4 = 0;
				break;

				case 6:
					printf("¡Programa cerrado! \n");	//Cierro el programa
					system("PAUSE");
				break;

				default:

				break;
			}

		}while(opciones != 6);


	return EXIT_SUCCESS;
}






