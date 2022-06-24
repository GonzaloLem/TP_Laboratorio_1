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
	int typePassenger;
	int statusFlight;

	int isEmpty;

}typedef Passenger;


int initPassengers(Passenger* list, int len);
int searchHousingLoaded(Passenger* list, int len);

int searchFree(Passenger* list, int len, int* free);
int modifyIsEmpty(Passenger* list, int position, int valor);

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);
int askForInformation(Passenger* list, int len,int* counterId);

int requestid(Passenger* list, int len);
int modifiPassenger(Passenger* list, int len);

int findPassengerById(Passenger* list, int len, int id);

int removePassenger(Passenger* list, int len, int id);
int passenger_removePassenger(Passenger* list, int len);

int searchTypePassenger(int typePassenger, char* type);
int searchStatusFlight(int statusFlight, char* status);
int printPassenger(Passenger* list, int len);

int sortPassengers(Passenger* list, int len, int order);
int sortPassengersByCode(Passenger* list, int len, int order);

int getTotalAverage(Passenger* list, int len, float* total, float* average);
int getHowManyExceedAverage(Passenger* list, int len, float average, int* counter);

int passenger_calculateTotalAverage(Passenger* list, int len);

int passenger_report(Passenger* list, int len);

int forcedLoad(Passenger* list, int len, char* name, char* lastName, float price, char* flycode, int typePassenger, int statusFlight, int* counterId);

#endif /* ARRAYPASSENGER_H_ */
