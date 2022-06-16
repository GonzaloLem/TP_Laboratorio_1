#ifndef PASSENGER_H_
#define PASSENGER_H_

#define NAME_LASTNAME 50
#define FLYCODE 16
#define STATUS_FLIGHT 26
#define LIMIT_TYPE_PASSENGER 26
#define LIMIT_BUFFER 4096

typedef struct{

	int idTypePassenger;
	char tipoPasajero[LIMIT_TYPE_PASSENGER];

}TypePassenger;

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

typedef int (pFunc)(void* ,void*);

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
int Passenger_getNombreDelTipoPasajero(TypePassenger* this,char* nombreTipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_setPrecioTxt(Passenger* this,char* precio);
int Passenger_getPrecio(Passenger* this,float* precio);
int Passenger_getPrecioTxt(Passenger* this,char* precio);

int passenger_assignId(LinkedList* pArrayListPassenger);
Passenger* addPassenger(LinkedList* pArrayListPassenger);//389 mirar //527 mirar

int passenger_searchId(LinkedList* pArrayListPassenger,int id);
int passenger__askId(LinkedList* pArrayListPassenger);
Passenger* editPassenger(LinkedList* pArrayListPassenger, int index);
int passenger_remove(LinkedList* pArrayListPassenger, int index);
int passenger_printList(LinkedList* pArrayListPassenger);
int passenger_sortPassenger(LinkedList* pArrayListPassenger);

int searchIdType(TypePassenger* type, int len, int idPassenger, char* typeTxt);
int printTypePassenger(TypePassenger* type, int len);
int assignIdTypePassenger(TypePassenger* type, int len, int option, int* id);
int typePassenger_searchType(TypePassenger* type, int len, char* passengerType, int* idType);

int passenger_sortName(Passenger* listOne, Passenger*listTwo);
int passenger_sort(void*, void*);

int passenger_reasingId(LinkedList* pArrayListPassenger, int id, int option);


#endif /* PASSENGER_H_ */
