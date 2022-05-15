#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define LIMIT_NAME 51
#define LIMIT_LASTNAME 51
#define LIMIT_CODE 10

struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int isEmpty;

	int typePassenger;
	int statusFlight;


}typedef Passenger;

struct{

	int idTypePassenger;
	char description[51];

}typedef eTypePassenger;

struct{

	int idStatusFlight;
	char description[51];

}typedef eStatusFlight;


int forceDataTypePassenger(eTypePassenger* listType);
int printTypePassenger(eTypePassenger* listType, int len);

int forceDatastatusFlight(eStatusFlight* listStatus);
int printStatusflight(eStatusFlight* listStatus, int len);

int initPassengers(Passenger* list, int len);
int searchFree(Passenger* list, int len, int* free);
int modifyIsEmpty(Passenger* list, int position, int valor);
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);

//int askForInformation(Passenger* list, int len);
int askForInformation(Passenger* list, int len, eTypePassenger* listType, int lenType, eStatusFlight* listStatus, int lenStatus, int* counterId);

int findPassengerById(Passenger* list, int len, int id, int* position);
int removePassenger(Passenger* list, int len, int id);

int searchTypePassenger(Passenger* list, int len, eTypePassenger* listType, int lenType, int* position);
int searchStatusFlight(Passenger* list, int len, eStatusFlight* listStatus, int lenTStatus, int* position);
int printPassenger(Passenger* list, int len, eTypePassenger* listType, int lenType, eStatusFlight* listStatus, int lenStatus);

int sortPassengers(Passenger* list, int len, int order);
int sortPassengersByCode(Passenger* list, int len, int order);

int getTotalAverage(Passenger* list, int len, float* total, float* average);
int getHowManyExceedAverage(Passenger* list, int len, float average, int* counter);

int printTypefloat(float num, char* message);
int printTypeInt(int num, char* message);

int forcedLoad(Passenger* list, int len, int* counterId);

#endif /* ARRAYPASSENGER_H_ */
