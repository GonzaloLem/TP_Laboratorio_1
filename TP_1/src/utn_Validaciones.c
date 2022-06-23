#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_Validaciones.h"

/**
 * @brief mide la longitud de la cadena que se le pasa y la retorna
 *
 * @param cadena Puntero* char
 * @return Retorna (-1) [Si el puntero llego en NULL] - Retorna (La longitud de la cadena) si todoOk
 */
int medirLongitud(char* cadena)
{
	int retorno = -1;

		if(cadena != NULL)
		{
			retorno = strlen(cadena);
		}

	return retorno;
}

/**
 * @brief valida que cadena no pase el limte de caracters
 *
 * @param cadena char*
 * @param limite int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si la cadena supera el limete] -retorna (0) si todoOk
 */
int validarLongitud(char* cadena, int limite, int minimo)
{
	int retorno = -1;
	int longitud;

		if(cadena != NULL && limite > 0)
		{

				longitud = strlen(cadena);

				if(longitud < limite && longitud >= minimo)
				{
					retorno = 0;
				}
				else
				{
					retorno = 1;
				}

		}

	return retorno;
}

/**
 * @brief  valida que la cadena que se le pase sean numeros decimales
 *
 * @param buffer char*
 * @param longitud int
 * @return retorna (-1) [Si los punteros llegaron en NULL - la longitud es 0 o menor] - retorna (0) si todoOk
 */
int validarNumeroDecimal(char* buffer, int longitud)
{
	int retorno = -1;
	int i;
	int contador = 0;

		if(buffer != NULL && longitud > 0)
		{
			retorno = 0;

				for(i=0;i<longitud;i++)
				{
					if((*(buffer+i)) == 46)
					{
						contador++;
					}

					if( (contador > 1) || (( (*(buffer+i)) != 46 ) && ( (*(buffer+i)) < 48 || (*(buffer+i)) > 57)) )
					{
						retorno = 1;
						break;
					}



				}

		}

	return retorno;
}

/**
 * @brief  valida que la cadena que se le pase sean numeros enteros
 *
 * @param buffer char*
 * @param longitud int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (0) si todoOk
 */
int validar_numerosEnteros(char* buffer, int longitud)
{
	int retorno = -1;
	int i;

		if(buffer != NULL && longitud > 0)
		{
			retorno = 0;

				for(i=0;i<longitud;i++)
				{
					if((*(buffer+i)) < 48 || (*(buffer+i)) > 57)
					{
						retorno = 1;
						break;
					}
				}

		}

	return retorno;
}

int pedirNumero_decimal(float* numero, char* mensaje, char* mensajeError, int min, int max, int intentos)
{
	int retorno = -1;
	int retornoDecimal;

	char buffer[4096];

		if(mensaje != NULL && mensajeError != NULL && min >= 0 && max <= 1000000 && intentos > 0)
		{
			retorno = -2;

				while(intentos >= 0)
				{
					intentos--;

					printf("%s",mensaje);
					fflush(stdin);
					gets(buffer);

						retornoDecimal = validarNumeroDecimal(buffer, medirLongitud(buffer));
							if(retornoDecimal == 0)
							{
								retorno = 0;

								(*numero) = atof(buffer);
								break;
							}
							else
							{
								printf("%s", mensajeError);
							}
				}
		}

	return retorno;
}

/**
 * @brief  Valida que el numero ingresado respete los minimos y maximos
 *
 * @param numero Puntero* int
 * @param min int
 * @param max int
 * @return retorna (-1) [Si el puntero llego en NULL] - retorna (1) [Si no respeta lo que se le pide] - retorna (0) si todoOk
 */
int validarNumeroFlotante(float* numero, int min, int max, int intentos)///////////////////////////////?
{
	int retorno = -1;
	float auxiliar;

		if(min >= 0 && max < 100000000 && intentos > 0)
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

/**
 * @brief  pide un numero que sea entero, tiene un minimo y un maximo valor a ingresar y le da x intentos de ingresarla bien
 *
 * @param numero Puntero* int
 * @param mensaje char*
 * @param mensajeError char*
 * @param min int
 * @param max int
 * @param intentos int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si no respeta lo que se le pide] - retorna (0) si todoOk
 */
int pedirNumeroEntero(int* numero, char* mensaje, char* mensajeError, int min, int max,  int intentos)
{
	int retorno = -1;
	char buffer[4096];
	int retornoNumero;
	int numeroConvertido;

		if(numero != NULL && min >= 0 && max < 1000000 && mensaje != NULL && mensajeError != NULL && intentos >= 0)
		{
				while(intentos >= 0)
				{
					retorno = -2;

					intentos--;

					printf("%s", mensaje);
					fflush(stdin);
					gets(buffer);

					retornoNumero = validar_numerosEnteros(buffer, medirLongitud(buffer));

					numeroConvertido = atoi(buffer);

						if(retornoNumero == 0 && numeroConvertido >= min && numeroConvertido <= max)
						{
							retorno = 0;
							*numero = numeroConvertido;
							break;
						}
						else
						{
							printf("%s", mensajeError);
						}
				}

		}

	return retorno;
}



