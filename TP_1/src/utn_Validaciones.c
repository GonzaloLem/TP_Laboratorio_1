#include <stdio.h>
#include <stdlib.h>
#include "utn_Validaciones.h"

/**
 * @brief  Valida que el numero ingresado respete los minimos y maximos
 *
 * @param numero Puntero* int
 * @param min int
 * @param max int
 * @return retorna (-1) [Si el puntero llego en NULL] - retorna (1) [Si no respeta lo que se le pide] - retorna (0) si todoOk
 */
int validarNumeroFlotante(float* numero, int min, int max, int intentos)
{
	int retorno = -1;
	float auxiliar;

		if(min >= 0 && max < 10000000 && intentos > 0)
		{
				while(intentos > 0)
				{
					retorno = 1;

					intentos--;

					scanf("%f", &auxiliar);

						if(auxiliar >= min && auxiliar <= max)
						{
							retorno = 0;
							*(numero) = auxiliar;
							break;
						}
					   else
						{
							printf("Error. respete los valores minimos y maximos\n");
						}
				}
		}

	return retorno;
}

int calcularDebito(float precio, int descuento, float* total)
{
	int retorno = -1;
	float resultado;

		if(precio > 0 && descuento > 0 && total != NULL)
		{
			retorno = 0;

			resultado = precio * descuento;
			resultado = resultado / 100;
			*(total) = precio - resultado;

		}

	return retorno;
}

int calcularCredito(float precio, int descuento, float* total)
{
	int retorno = -1;
	float resultado;

		if(precio > 0 && descuento > 0 && total != NULL)
		{
			retorno = 0;

			resultado = precio * descuento;
			resultado = resultado / 100;
			*(total) = precio + resultado;

		}

	return retorno;
}

int calcularBitcoin(float precio, float btc, float* total)
{
	int retorno = -1;
	float resultado;

		if(precio > 0 && btc > 0 && total != NULL)
		{
			retorno = 0;

			resultado = precio / btc;
			*(total) = resultado;

		}

	return retorno;
}

int calcularPrecioPorKm(float precio, float km, float* total)
{
	int retorno = -1;
	float resultado;

		if(precio > 0 && km > 0 && total != NULL)
		{
			retorno = 0;

			resultado = precio * km;
			*(total) = resultado;

		}

	return retorno;
}

int diferenciaDePrecio(float precioUno, float precioDos, float* total)
{
	int retorno = -1;
	float resultado;

		if(precioUno > 0 && precioDos > 0 && total != NULL)
		{
			retorno = 0;

			resultado = precioUno - precioDos;
			*(total) = resultado;

		}

	return retorno;
}

int informarResultados(float debito,float credito,float bitcoin, float unitario)
{
	int retorno = -1;

		if(debito > 0 && credito > 0 && bitcoin > -1 && unitario > 0)
		{
			retorno = 0;


					printf("a)Precio con tarjeta de debito: $%.2f\n"
							"b)Precio con tarjeta de creito: $%.2f\n"
							"c)Precio pagando con Bitcoin: $%.2f\n"
							"d)Precio unitario: $%.2f\n\n",
							debito,
							credito,
							bitcoin,
							unitario);
		}

	return retorno;
}

int cargaForzada(float* kilometros,float* precioAerolineas, float* precioLatam, float km, float precioA, float precioL)
{
	int retorno = -1;

		if(kilometros != NULL && precioAerolineas != NULL && precioLatam != NULL && km > 0 && precioA > 0 && precioL > 0)
		{
			retorno = 0;

			*(kilometros) = km;
			*(precioAerolineas) = precioA;
			*(precioLatam) = precioL;

		}

	return retorno;
}

