#ifndef VALIDATION_H_
#define VALIDATION_H_

int measureLength(char string[], int* lenght);
int validateNumberInt(char* buffer, int lenght);

int validateOnlyLetters(char* chains, int len);
int validateLength(char* chains, int len);
int getNameOrLastName(char* pResult, int len, char* message, char* messageError, int Attempts);

int validateNumberFloat(char* buffer, int len);
int getNumberTypeFloat(float* number, char* message, char*messageError, float min, float max, int Attempts);

int validateOnlyLettersAndNumbers(char* chains, int len);
int getNumberAlphanumeric(char* alphaNumeic, int len, char* message, char*messageError, int attempts);

int getNumberTypeInt(int* number, char* message, char* messageError, int min, int max,  int Attempts);

int assignId(int** counterId, int* id);

#endif /* VALIDATION_H_ */
