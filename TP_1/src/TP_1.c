/**
 * Trabajo Practico 1
 * Nombre: Gonzalo
 * Apellido: Lemiña
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_Validaciones.h"

#define BTC 4606954.55

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int banderaCasoUno = 1;
	int banderaCasoDos = 1;
	int bandera = 1;
	float kilometros;
	float precioAerolineas;
	float precioLatam;

	float debitoA;
	float creditoA;
	float bitcoinA;
	float unitarioA;

	float debitoL;
	float creditoL;
	float bitcoinL;
	float unitarioL;

	float diferenciaPrecio;

	int retornoKilometros;
	int retornoPrecioA;
	int retornoPrecioL;

		do{

			printf("\n1.Ingresar Kilometros\n"
					"2.Ingresar precio de los vuelos\n"
					"3.Calcular todos los costos\n"
					"4.Informar Resultados\n"
					"5.Carga forzada de datos\n"
					"6.Salir\n"
					"-Opcion: ");
			scanf("%d", &opcion);

				switch(opcion)
				{
					case 1:

						if(banderaCasoUno == 1)
						{
							kilometros = 0;
						}

						printf("Ingrese los kilometros (KM=%.2f): ", kilometros);
						retornoKilometros = validarNumeroFlotante(&kilometros, 1, 50000, 2);

						banderaCasoUno = 0;
					break;

					case 2:

						if(banderaCasoDos == 1)
						{
							precioAerolineas = 0;
							precioLatam = 0;
						}

						printf("Ingrese el precio de Aerolineas (Precio Aerolinas %.2f): ", precioAerolineas);
						retornoPrecioA = validarNumeroFlotante(&precioAerolineas, 1000, 1000000, 1);

						printf("Ingrese el precio de Latam (Precio Latam %.2f): ", precioLatam);
						retornoPrecioL = validarNumeroFlotante(&precioLatam, 1000, 1000000, 1);

							if(retornoPrecioA != 0 && retornoPrecioL != 0)
							{
								printf("Los datos no se cargaron correctamente\n");
							}
							else
							{
								banderaCasoDos = 0;
							}
					break;

					case 3:
						if(retornoKilometros == 0 && retornoPrecioA == 0 && retornoPrecioL == 0)
						{
							calcularDebito(precioAerolineas, 10, &debitoA);
							calcularCredito(precioAerolineas, 25, &creditoA);
							calcularBitcoin(precioAerolineas, BTC, &bitcoinA);
							calcularPrecioPorKm(precioAerolineas, kilometros, &unitarioA);

							calcularDebito(precioLatam, 10, &debitoL);
							calcularCredito(precioLatam, 25, &creditoL);
							calcularBitcoin(precioLatam, BTC, &bitcoinL);
							calcularPrecioPorKm(precioLatam, kilometros, &unitarioL);

							diferenciaDePrecio(precioLatam, precioAerolineas, &diferenciaPrecio);

							bandera = 0;

						}
						else
						{
							printf("Tiene que cargar datos en la opcion dos\n");
						}
					break;

					case 4:
						if(bandera == 0)
						{
							printf("KMs Ingresados %.2f km\n", kilometros);

							printf("\nPrecio Aerolinas: %.2f\n", precioAerolineas);
							informarResultados(debitoA, creditoA, bitcoinA, unitarioA);

							printf("\nPrecio Latam: %.2f\n", precioLatam);
							informarResultados(debitoL, creditoL, bitcoinL, unitarioL);

							printf("La deferencia de precio es de: %.2f\n", diferenciaPrecio);

							system("PAUSE");
						}
						else
						{
							printf("Primero debe pasar por la opcion 3\n");
						}
					break;

					case 5:
						cargaForzada(&kilometros, &precioAerolineas, &precioLatam, 7090, 162965, 159339);

						calcularDebito(precioAerolineas, 10, &debitoA);
						calcularCredito(precioAerolineas, 25, &creditoA);
						calcularBitcoin(precioAerolineas, BTC, &bitcoinA);
						calcularPrecioPorKm(precioAerolineas, kilometros, &unitarioA);

						calcularDebito(precioLatam, 10, &debitoL);
						calcularCredito(precioLatam, 25, &creditoL);
						calcularBitcoin(precioLatam, BTC, &bitcoinL);
						calcularPrecioPorKm(precioLatam, kilometros, &unitarioL);

						diferenciaDePrecio(precioLatam, precioAerolineas, &diferenciaPrecio);

						printf("KMs Ingresados %.2f km\n", kilometros);

						printf("\nPrecio Aerolinas: $%.2f\n", precioAerolineas);
						informarResultados(debitoA, creditoA, bitcoinA, unitarioA);

						printf("\nPrecio Latam: $%.2f\n", precioLatam);
						informarResultados(debitoL, creditoL, bitcoinL, unitarioL);

						printf("La deferencia de precio es de: $%.2f\n", diferenciaPrecio);

						system("PAUSE");


						bandera = 0;
						banderaCasoUno = 0;
						banderaCasoDos = 0;

						retornoKilometros = 0;
						retornoPrecioA = 0;
						retornoPrecioL = 0;

					break;

					case 6:
						printf("Cerrando programa\n");
						system("PAUSE");
					break;
				}

		}while(opcion != 6);


	return EXIT_SUCCESS;
}
