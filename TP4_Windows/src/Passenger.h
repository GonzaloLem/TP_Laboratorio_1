#ifndef PASSENGER_H_
#define PASSENGER_H_

#define NAME_LASTNAME 50
#define FLYCODE 16
#define STATUS_FLIGHT 26
#define LIMIT_TYPE_PASSENGER 26
#define LIMIT_BUFFER 4096

typedef struct
{
	int id;
	char nombre[NAME_LASTNAME];
	char apellido[NAME_LASTNAME];
	float precio;
	int tipoPasajero;
	char codigoVuelo[FLYCODE];
	char estadoDelVuelo[STATUS_FLIGHT];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(int id,char* nombre, char* apellido,float precio,int tipoPasajero, char* codigoVuelo, char* estadoDelVuelo);
Passenger* Passenger_newParametrosTxt(char* idTxt,char* nombreTxt, char* apellidoTxt,char* precioTxt,char* tipoPasajeroTxt, char* codigoVueloTxt,  char* estadoDelVuelo);

void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_setIdTxt(Passenger* this, char* id);
int Passenger_getId(Passenger* this,int* id);
int Passenger_getIdTxt(Passenger* this, char* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setEstadoDelVuelo(Passenger* this,char* estadoDelVuelo);
int Passenger_getEstadoDelVuelo(Passenger* this,char* estadoDelVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_setTipoPasajeroTxt(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);
int Passenger_getTipoPasajeroTxt(Passenger* this,char* tipoPasajero);


int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_setPrecioTxt(Passenger* this,char* precio);
int Passenger_getPrecio(Passenger* this,float* precio);
int Passenger_getPrecioTxt(Passenger* this,char* precio);

int passenger_getTypeTxt(char* typePassenger, int* type);
int passenger_getType(int typePassenger, char* type);
int passenger_setType(char* type, char* typePassenger);

int passenger_addId(LinkedList* pArrayListPassenger, int* id);
int passenger_searchIdMax(LinkedList* pArrayListPassenger);
int passenger_reasingId(LinkedList* pArrayListPassenger, int idMax);

Passenger* addPassenger();

int passenger_searchId(LinkedList* pArrayListPassenger,int id);
int passenger__askId(LinkedList* pArrayListPassenger);
Passenger* editPassenger(Passenger* ePassenger);

int passenger_printPassenger(Passenger* ePassenger);

int passenger_orderPassengerByLastName(void* elementOne, void* elementTwo);

#endif /* PASSENGER_H_ */
