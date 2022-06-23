/**
 * Trabajo Practico 1
 * Nombre: Gonzalo
 * Apellido: Lemiña
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_Validaciones.h"
#include "CalculosAerolineas.h"
#include "Menu.h"

#define BTC 4606954.55

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int bandera = 1;
	int banderaForzada = 1;

	float kilometros = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;

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
	int retornoCalcularA;
	int retornoCalcularL;
	int retornoDiferencia;

		do{

			menu_imprimirMenu();
			opcion = menu_validarOpcion(1, 6);

				switch(opcion)
				{
					case 1:

						printf("Valor actual de los kilometros: %.2f\n", kilometros);
						retornoKilometros = pedirNumero_decimal(&kilometros, "Ingrese los kilometros: ","Error. Ingrese lo que se le pide\n", 1, 1000000, 3);
					break;

					case 2:

						printf("Valor actual del precio de Aerolineas: %.2f\n", precioAerolineas);
						retornoPrecioA = pedirNumero_decimal(&precioAerolineas, "Ingrese el precio de Aerolineas: ","Error. Ingrese lo que se le pide\n", 1, 1000000, 3);

						printf("Valor actual del precio de Latam: %.2f\n", precioLatam);
						retornoPrecioL = pedirNumero_decimal(&precioLatam, "Ingrese el precio de Latam: ","Error. Ingrese lo que se le pide\n", 1, 1000000, 3);

							if(retornoPrecioA != 0 && retornoPrecioL != 0)
							{
								printf("Los datos no se cargaron correctamente\n");
							}

					break;

					case 3:
						if((retornoKilometros == 0 && retornoPrecioA == 0 && retornoPrecioL == 0) || (banderaForzada == 0))
						{

							retornoCalcularA =calcularPrecios(precioAerolineas, kilometros, &debitoA, 10, &creditoA, 25, &bitcoinA, BTC, &unitarioA);
							retornoCalcularL = calcularPrecios(precioLatam, kilometros,&debitoL, 10, &creditoL, 25,&bitcoinL, BTC, &unitarioL);

							retornoDiferencia = diferenciaDePrecio(precioLatam, precioAerolineas, &diferenciaPrecio);

								if(retornoCalcularA == 0 && retornoCalcularL == 0 && retornoDiferencia == 0)
								{
									bandera = 0;
								}
						}
						else
						{
							printf("Tiene que cargar datos para poder usar esta opcion\n");
						}
					break;

					case 4:
						if(bandera == 0)
						{
							imprimirPrecios("Precio Aerolineas: $",precioAerolineas, debitoA, creditoA, bitcoinA, unitarioA);
							imprimirPrecios("Precio Latam: $",precioLatam, debitoL, creditoL, bitcoinL, unitarioL);
							printf("La diferencia de precio es: $%.3f\n", diferenciaPrecio);

							system("PAUSE");
						}
						else
						{
							printf("Primero debe calcular los datos\n");
						}
					break;

					case 5:
						cargaForzada(&kilometros, &precioAerolineas, &precioLatam, 7090, 162965, 159339);
						retornoCalcularA = calcularPrecios(precioAerolineas, kilometros, &debitoA, 10, &creditoA, 25, &bitcoinA, BTC, &unitarioA);
						retornoCalcularL = calcularPrecios(precioLatam, kilometros,&debitoL, 10, &creditoL, 25,&bitcoinL, BTC, &unitarioL);

						retornoDiferencia = diferenciaDePrecio(precioLatam, precioAerolineas, &diferenciaPrecio);

							if(retornoCalcularA == 0 && retornoCalcularL == 0 && retornoDiferencia == 0)
							{
								imprimirPrecios("Precio Aerolineas: $",precioAerolineas, debitoA, creditoA, bitcoinA, unitarioA);
								imprimirPrecios("Precio Latam: $",precioLatam, debitoL, creditoL, bitcoinL, unitarioL);
								printf("La diferencia de precio es: $%.3f\n", diferenciaPrecio);

								bandera = 0;
								banderaForzada = 0;

								system("PAUSE");
							}
							else
							{
								printf("Error. Alguno de los datos no es valido\n");
							}

					break;

					case 6:
						printf("Cerrando programa\n");
					break;
				}

		}while(opcion != 6);


	return EXIT_SUCCESS;
}
