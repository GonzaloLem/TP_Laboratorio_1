/*
 * calculos.c
 *
 *  Created on: 7 abr. 2022
 *      Author: Gonzalo Lemiñas
 */

#include <stdio.h>
#include <stdlib.h>

/**
  * @brief Esta funcion le pide al usuario que ingrese los kilometros que se van a hacer, tambien valida de que los kilometros ingresados sean mayor a 0
 * @param km Guarda los Kilometros ingresados por el usuario
 * @return regresa un valor indicando si hubo o no un error(-1 hubo error y 1 no hubo error)
 */
int ingresar_kilometros(int* km)
{
	int retorno = -1;
	int x;

		if(km != NULL)
		{
			retorno = 1;

			printf("Ingresar Kilometros: ");
				scanf("%d", &x);

				while(x < 1)
				{
					printf("Error. Ingresar Kilometros: ");
						scanf("%d", &x);
				}

			*km = x;
		}

	return retorno;
}

/**
 * @brief Esta funcion le pide al usuario que ingrese un precio para Aerolinas y otro para latam, tambien valida de que el precio sea mayor a 0
 * @param precio_aerolineas	Guarda el precio que le asigne el usuario(Aerolineas)
 * @param precio_latam		Guarda el precio que le asigne el usuario(Latam)
 * @return regresa un valor indicando si hubo o no un error(-1 hubo error y 1 no hubo error)
 */

int precio_vuelos(float* precio_aerolineas, float* precio_latam)
{
	int retorno = -1;
	float y;
	float z;

		if(precio_aerolineas != NULL && precio_latam != NULL)
		{
			retorno = 1;

			printf("Precio vuelo Aerolineas: ");
				scanf("%f", &y);

					while(y < 1)
					{
						printf("Error. Precio vuelo Aerolineas: ");
							scanf("%f", &y);
					}

			*precio_aerolineas = y;

			printf("Precio vuelo Latam: ");
				scanf("%f", &z);

					while(z < 1)
					{
						printf("Error. Precio vuelo Latam: ");
							scanf("%f", &z);
					}

			*precio_latam = z;
		}

	return retorno;
}
/**
 *@brief   Esta funcion calcula los costos de la empresa Aerolineas. Para poder usar esta opcion es necesario usar la opcion 2 si o si
 * @param x 				Kilometros
 * @param y 				Precio aerolineas
 * @param guardar_debito 	Costo con debito
 * @param guardar_credito 	Costo con credito
 * @param guardar_btc 		Costo si paga en bitCoins
 * @param guardar_unitario 	Precio unitario de Aerolineas
 * @return regresa un valor indicando si hubo o no un error(-1 hubo error y 1 no hubo error)
 */

int calculos_aerolineas(int x, float y, float* guardar_debito, float* guardar_credito, float* guardar_btc, float* guardar_unitario)
{

	int retorno = -1;
	float debito;
	float credito;
	float btc;
	float btc_precio = 4606954.55;
	float precio_unitario;

	if(guardar_debito != NULL && guardar_credito != NULL && guardar_btc != NULL && guardar_unitario != NULL)
	{
		retorno = 1;
			debito = y * 10;
			debito = debito  / 100;
			debito = y - debito;
			(*guardar_debito) = debito;

			credito = y * 25;
			credito = credito / 100;
			credito = y + credito;
			(*guardar_credito) = credito;

			btc = y / btc_precio;
			(*guardar_btc) = btc;

			precio_unitario = y / x;
			(*guardar_unitario) = precio_unitario;

	}

	return retorno;
}

/**
 *@brief	Esta funcion lo que hace es calcular los costos de la empresa Latam. Para poder usar esta opcion es necesario usar si o si la opcion 2
 * @param x					Kilometros
 * @param z					Precio Latam
 * @param guardar_debito	Precio con debito
 * @param guardar_credito	Precio	con credito
 * @param guardar_btc		Precio con BitCoin
 * @param guardar_unitario	Precio unitario de Latam
 * @return regresa un valor indicando si hubo o no un error(-1 hubo error y 1 no hubo error)
 */

int calculos_latam(int x, float z, float* guardar_debito, float* guardar_credito, float* guardar_btc, float* guardar_unitario, float y, float* diferencia_z_y)
{

	int retorno = -1;
	float debito;
	float credito;
	float btc;
	float btc_precio = 4606954.55;
	float unitario;

	float sacar_diferencia;

		if(guardar_debito != NULL && guardar_debito != NULL && guardar_btc != NULL && guardar_unitario != NULL && diferencia_z_y != NULL)
		{
			retorno = 1;

				debito = z * 10;
				debito = debito / 100;
				debito = z - debito;
				(*guardar_debito) = debito;

				credito = z * 25;
				credito = credito / 100;
				credito = z + credito;
				(*guardar_credito) = credito;

				btc = z / btc_precio;
				(*guardar_btc) = btc;

				unitario = z / x;                         //precio / kilometro
				(*guardar_unitario) = unitario;

				sacar_diferencia = z - y;
				(*diferencia_z_y) = sacar_diferencia;
		}

		return retorno;
}

/**
 *@brief Esta funcion muestra todos los datos ya calculados de Aerolineas y latam, tambien adentro de esta funicon saca la diferencia entre Laram y Aerolineas
 * @param x								Kilometros
 * @param y								Precio Aerolineas	Aerolinas
 * @param debito_aerolineas				Precio con debito	Aerolinas
 * @param credito_aerolineas			Precio con credito	Aerolinas
 * @param btc_aerolineas				Precio con Bitcoins Aerolinas
 * @param precio_unitario_aerolineas	Precio unitario de Aerolinas
 * @param z								Precio Latam
 * @param debito_latam					Precio con debito Latam
 * @param credito_latam					Precio con credito Latam
 * @param btc_latam						Precio con Bitcoin Latam
 * @param unitario_latam				Precio unitario de Latam
 */
void mensajes(int x, float y, float debito_aerolineas, float credito_aerolineas, float btc_aerolineas, float precio_unitario_aerolineas, float z, float debito_latam, float credito_latam, float btc_latam, float unitario_latam, float diferencia_z_y)
{

		printf("Kilometos ingresados: %d \n\n", x);

		printf("Precio Aerolineas: $%.2f \n", y);
			printf("\t a)Precio con tarjeta de Debito: $%.2f \n", debito_aerolineas);
			printf("\t b)Precio con tarjeta de Credito: $%.2f \n", credito_aerolineas);
			printf("\t c)Precio pagando con BitCoin: $%.2f \n", btc_aerolineas);
			printf("\t d)Precio Unitario: $%.2f \n\n", precio_unitario_aerolineas);

		printf("Precio Latam: %.2f \n", z);
			printf("\t a)Precio con tarjeta de Debito: $%.2f \n", debito_latam);
			printf("\t b)Precio con tarjeta de Credito: $%.2f \n", credito_latam);
			printf("\t c)Precio pagando con BitCoin: $%.2f \n", btc_latam);
			printf("\t d)Precio Unitario: $%.2f \n\n", unitario_latam);

		printf("La diferencia de precio entre Aerolineas y Latam es de $%.2f\n\n", diferencia_z_y);

		system("PAUSE"); //Este system es para que se puedan leer mas comodos los datos


}


/**
 *@brief	Esta funcion le da valores a x, y, z para forzar la carga de datos, tambien llama a la funcion calculos(Aerolineas y Latam) y mensaje(en el main)
 * @param x	Kilometros
 * @param y	Precio de Aerolineas
 * @param z	Precio de latam
 * @return regresa un valor indicando si hubo o no un error(-1 hubo error y 1 no hubo error)
 */
int forzar_datos(int* x, float* y, float* z)
{
	int retorno = -1;

	if(x != NULL && y != NULL && z != NULL)
	{
		retorno = 1;
			(*x) = 7090;
			(*y) = 162965;
			(*z) = 159339;
	}
	return retorno;

}

