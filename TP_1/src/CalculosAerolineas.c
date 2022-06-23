#include <stdio.h>
#include <stdlib.h>
#include "utn_Validaciones.h"
#include "CalculosAerolineas.h"


int calcularDebito(float precio, int descuento, float* total)
{
	int retorno = -1;
	float resultado;

		if(precio > 0 && descuento > 0)
		{
			retorno = 0;

			resultado = precio * descuento;
			resultado = resultado / 100;
			(*total) = precio - resultado;

		}

	return retorno;
}

int calcularCredito(float precio, int descuento, float* total)
{
	int retorno = -1;
	float resultado;

		if(precio > 0 && descuento > 0)
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

			resultado = precio / km;
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


int calcularPrecios(float precio, float kilometros, float* debito, int porcentajeD,float* credito, int  porcentajeC,float* bitcoin, float precio_btc,float* precioUnitario)
{
	int retorno = -1;

		if(precio > 0  && kilometros > 0 && debito != NULL && porcentajeD >= 0 && credito != NULL && porcentajeC >= 0 && bitcoin != NULL && precio_btc >= 0 && precioUnitario != NULL)
		{
			retorno = 0;

			calcularDebito(precio, porcentajeD, debito);
			calcularCredito(precio, porcentajeC, credito);
			calcularBitcoin(precio, precio_btc, bitcoin);
			calcularPrecioPorKm(precio, kilometros, precioUnitario);
		}

	return retorno;
}

int imprimirPrecios(char* mensaje,float precio, float debito, float credito, float bitcoin, float precioUnitario)
{
	int retorno = -1;

		if(precio > 0 && debito > 0 && credito > 0 && bitcoin >= 0 && precioUnitario > 0)
		{
			printf("%s %.2f\n"
					"a)Precio con tarjeta de debito: $%.2f\n"
					"b)Precio con tarjeta de creito: $%.2f\n"
					"c)Precio pagando con Bitcoin: $%f\n"
					"d)Precio unitario: $%2f\n\n",
					mensaje,
					precio,
					debito,
					credito,
					bitcoin,
					precioUnitario);
		}

	return retorno;
}

