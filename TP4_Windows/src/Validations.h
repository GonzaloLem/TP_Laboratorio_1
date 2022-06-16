#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

int measureLength(char* string, int* length);
int validateLength(char* chains, int len, int min);

int validateNumberInt(char* buffer, int lenght);
int getNumberTypeInt(int* number, char* message, char* messageError, int min, int max,  int Attempts);

int validateOnlyLetters(char* chains, int len);
int getNameOrLastName(char* pResult, int len, char* message, char* messageError, int Attempts);

int validateNumberFloat(char* buffer, int len);
int getNumberTypeFloat(float* number, char* message, char*messageError, float min, float max, int Attempts);

int validateOnlyLettersAndNumbers(char* chains, int len);
int getNumberAlphanumeric(char* alphaNumeic, int len, char* message, char*messageError, int attempts);

int validateOnlyLettersAndSpace(char* chains, int len);
int getStatusFlight(char* pResult, int len, char* message, char* messageError, int Attempts);

#endif /* VALIDATIONS_H_ */
