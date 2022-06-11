#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validations.h"

/**
 * @brief measure the length of a chain
 *
 * @param string char
 * @param length int pointer
 * @return	Return (-1) if [Invalid length or NULL pointer] - if (0) OK
 */
int measureLength(char* string, int* length)
{
	int report = -1;

		if(string != NULL && length > 0)
		{
			report = 0;

			(*length) = strlen(string);

		}

	return report;
}

/**
 * @brief check that it does not exceed the length limit
 *
 * @param chains char pointer
 * @param len int limit
 * @return Return (-1) if [Invalid length or NULL pointer] - if (1)[exceeds the maximum length] - if (0) OK
 */
int validateLength(char* chains, int len, int min)
{
	int report = -1;
	int length;

		if(chains != NULL && len > 0)
		{
			report = 0;

			length = strlen(chains);

				if(length < len && length >= min)
				{
					report = 0;
				}
				else
				{
					report = 1;
				}

		}

	return report;
}

/**
 * @brief Validate that it is only an integer
 *
 * @param buffer char pointer
 * @param lenght int limit
 * @return	Return (-1) if [Invalid length or NULL pointer] - if (1)[found an invalid character] - if (0) OK
 */
int validateNumberInt(char* buffer, int lenght)
{
	int report = -1;
	int i;

		if(buffer != NULL && lenght > 0)
		{
			report = 0;

			for(i=0;i<lenght;i++)
			{
				if(buffer[i] < 48 || buffer[i] > 57)
				{
					report = 1;
					break;
				}
			}

		}

	return report;
}

/**
 * @brief asks for an integer data type
 *
 * @param number int pointer
 * @param message	char pointer message coming out
 * @param messageError char message of error
 * @param min int num minimum
 * @param max int maximum
 * @param Attempts int number of attempts
 * @return	Return (-1) if [Invalid length or NULL pointer] - if (1)[data was not loaded] - if (0) OK
 */
int getNumberTypeInt(int* number, char* message, char* messageError, int min, int max,  int Attempts)
{
	int report = -1;
	char buffer[4096];
	int lenght;
	int reportNumber;
	int NumConverted;

		if(min >= 0 && max <= 1000000 && message != NULL && messageError != NULL && Attempts > 0)
		{
				while(Attempts >= 0)
				{
					report = 1;

					Attempts--;

					printf("%s", message);
					fflush(stdin);
					gets(buffer);

					measureLength(buffer, &lenght);

					reportNumber = validateNumberInt(buffer, lenght);

					NumConverted = atoi(buffer);

						if(reportNumber == 0 && NumConverted >= min && NumConverted <= max)
						{
							report = 0;
							*number = NumConverted;
							break;
						}
						else
						{
							printf("%s\n", messageError);
						}
				}

		}

	return report;
}

/**
 * @brief validate that they are only letters
 *
 * @param chains char pointer
 * @param len int limit
 * @return	Return (-1) if [Invalid length or NULL pointer] - if (1)[found an invalid character] - if (0) OK
 */
int validateOnlyLetters(char* chains, int len)
{
	int report = -1;
	int i;

		if(chains != NULL && len > 0)
		{
			report = 0;
			for(i=0;i<len;i++)
			{
				if((chains[i] < 65 || chains[i] > 90) && (chains[i] < 97 || chains[i] > 122))
				{
					report = 1;
					break;
				}
			}
		}

	return report;
}

/**
 * @brief asks for the first or last name and validates it
 *
 * @param pResult char pointer save name or latName
 * @param len	int limit
 * @param message	char pointer message coming out
 * @param messageError char message of error
 * @param Attempts int number of attempts
 * @return Return (-1) if [Invalid length or NULL pointer] - if (1)[data was not loaded] - if (0) OK
 */
int getNameOrLastName(char* pResult, int len, char* message, char* messageError, int Attempts)
{
	int report = -1;
	int reportLetters;
	int reportLength;
	char buffer[4096];

	int lenght;

		if(pResult != NULL && len > 0 && message != NULL && messageError != NULL && Attempts > 0)
		{
			while(Attempts >= 0)
			{
				report = 1;

				Attempts--;

					printf("%s", message);
						fflush(stdin);
						gets(buffer);

						measureLength(buffer, &lenght);

						reportLength = validateLength(buffer, len, 3);
						reportLetters = validateOnlyLettersAndSpace(buffer, lenght);

						if(reportLetters == 0 && reportLength == 0)
						{
							report = 0;
							strncpy(pResult, buffer, len);
							break;
						}
						else
						{
							printf("%s\n", messageError);
						}
			}

		}

	return report;
}

/**
 * @brief validates that only a floating number is entered
 *
 * @param buffer char pointer
 * @param len int limit
 * @return	Return (-1) if [Invalid length or NULL pointer] - if (1)[found an invalid character] - if (0) OK
 */
int validateNumberFloat(char* buffer, int len)
{
	int report = -1;
	int i;
	int bandera=0;

		if(buffer != NULL && len > 0)
		{
			report = 0;
			for(i=0;i<len;i++)
			{
				if((buffer[i] != 46) && (buffer[i] < 48 || buffer[i] > 57))
				{
					report = 1;
					break;
				}
				if(bandera == 0 && buffer[i] == 46)
				{
					bandera=1;
				}
				else
				{
					if(buffer[i] == 46 && bandera == 1)
					{
						report = 1;
						break;
					}

				}

			}

		}

	return report;
}


/**
 * @brief ask for a float type number
 *
 * @param number float pointer
 * @param message	char pointer message coming out
 * @param messageError char message of error
 * @param min float num minimum
 * @param max float maximum
 * @param Attempts int number of attempts
 * @return Return (-1) if [Invalid length or NULL pointer] - if (1)[data was not loaded] - if (0) OK
 */
int getNumberTypeFloat(float* number, char* message, char*messageError, float min, float max, int Attempts)
{
	int report = -1;
	char numberFloat[4096];
	int reportFloat;
	int lenght;
	float NumConverted;

		if(min >= 0.01 && max <= 10000000 && message != NULL && messageError != NULL && Attempts > 0)
		{
			report = 1;

				while(Attempts>=0)
				{
					Attempts--;

					printf("%s", message);
						fflush(stdin);
						gets(numberFloat);

					measureLength(numberFloat, &lenght);

					reportFloat = validateNumberFloat(numberFloat, lenght);

					NumConverted = atof(numberFloat);

						if(reportFloat == 0 && NumConverted >= min && NumConverted <= max)
						{
							report = 0;
							*number = NumConverted;
							break;
						}

					printf("%s\n",messageError);

				}
		}

	return report;
}


/**
 * @brief Validate that they are only alphanumeric characters
 *
 * @param chains char pointer
 * @param len int limit
 * @return	Return (-1) if [Invalid length or NULL pointer] - if (1)[found an invalid character] - if (0) OK
 */
int validateOnlyLettersAndNumbers(char* chains, int len)
{
	int report = -1;
	int i;

		if(chains != NULL && len > 0)
		{
			report = 0;
			for(i=0;i<len;i++)
			{
				if(((chains[i] < 48 || chains[i] > 57) && (chains[i] < 65 || chains[i] > 90)) && ( chains[i] < 97 || chains[i] > 122))
				{
					report = 1;
					break;
				}
			}
		}

	return report;
}

/**
 * @brief	provides alphanumeric data
 *
 *
 * @param alphaNumeic char pointer
 * @param len int limit
 * @param message	char pointer message coming out
 * @param message Error char message of error
 * @param attempts int number of attempts
 * @return	Return (-1) if [Invalid length or NULL pointer] - if (1)[data was not loaded] - if (0) OK
 */
int getNumberAlphanumeric(char* alphaNumeic, int len, char* message, char*messageError, int attempts)
{
	int report = -1;
	char buffer[4096];
	int reportLength;
	int reportLetterNumbers;
	int lenght;

		if(alphaNumeic != NULL && len > 0 && message != NULL && attempts > 0)
		{
			report = 1;

				while(attempts >= 0)
				{
					attempts--;

					printf("%s", message);
						fflush(stdin);
						gets(buffer);

					measureLength(buffer, &lenght);

					reportLength = validateLength(buffer, len, 3);
					reportLetterNumbers = validateOnlyLettersAndNumbers(buffer, lenght);

						if(reportLength == 0 && reportLetterNumbers == 0 )
						{
							strcpy(alphaNumeic, buffer);
							report = 0;
							break;
						}
					printf("%s\n", messageError);
				}


		}

	return report;
}

/**
 * @brief validate that they are letters and space
 *
 * @param chains char pointer
 * @param len int limit
 * @return	Return (-1) if [Invalid length or NULL pointer] - if (1)[found an invalid character] - if (0) OK
 */
int validateOnlyLettersAndSpace(char* chains, int len)
{
	int report = -1;
	int i;

		if(chains != NULL && len > 0)
		{
			report = 0;
			for(i=0;i<len;i++)
			{
				if( *(chains+i) != 32 && *(chains+i) != 45 && ( *(chains+i) < 65 || *(chains+i) > 90) && ( *(chains+i) < 97 || *(chains+i) > 122))
				{
					report = 1;
					break;
				}
			}
		}

	return report;
}

/**
 * @brief asks you to enter a flight status
 *
 * @param pResult char pointer save name or latName
 * @param len	int limit
 * @param message	char pointer message coming out
 * @param messageError char message of error
 * @param Attempts int number of attempts
 * @return Return (-1) if [Invalid length or NULL pointer] - if (1)[data was not loaded] - if (0) OK
 */
int getStatusFlight(char* pResult, int len, char* message, char* messageError, int Attempts)
{
	int report = -1;
	int reportLetters;
	int reportLength;
	char buffer[4096];

	int lenght;

		if(pResult != NULL && len > 0 && message != NULL && messageError != NULL && Attempts > 0)
		{
			while(Attempts >= 0)
			{
				report = 1;

				Attempts--;

					printf("%s", message);
						fflush(stdin);
						gets(buffer);

						measureLength(buffer, &lenght);

						reportLength = validateLength(buffer, len, 3);
						reportLetters = validateOnlyLettersAndSpace(buffer, lenght);

						if(reportLetters == 0 && reportLength == 0)
						{
							report = 0;
							strncpy(pResult, buffer, len);
							break;
						}
						else
						{
							printf("%s\n", messageError);
						}
			}

		}

	return report;
}
