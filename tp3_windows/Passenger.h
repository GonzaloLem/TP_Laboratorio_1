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

int typePassenger_getId(TypePassenger* this, int* id);
int typePassenger_getType(TypePassenger* this, char* type);

int passenger_initArray(Passenger** list, int len);
int passenger_searchLoad(Passenger** list, int len);
int passenger_searchFree(Passenger** list, int len);
int passenger_searchId(Passenger** list, int len, int id);
int typePassenger_searchType(TypePassenger* type, int len, char* passengerType, int* idType);

int searchIdType(TypePassenger* type, int len, int idPassenger, char* typeTxt);
int passenger_printArray(Passenger** list, int len,TypePassenger* type, int lenType);

int passenger_reasingId(Passenger** list, int len, int* id);
int passenger_loadDate(Passenger** list, int len, TypePassenger* type, int lenType, char* path,int** id);//

int printTypePassenger(TypePassenger* type, int len);
int assignIdTypePassenger(TypePassenger* type, int len, int option, int* id);
int addPassenger(Passenger** list, int len, TypePassenger* type, int lenType, int** id);

int passenger_modifyPassenger(Passenger** list, int len,TypePassenger* type, int lenType);

int passenger_delete(Passenger* this);
int borrarIndexArray(Passenger** list, int index);
int passenger_deletePassenger(Passenger** list, int len, TypePassenger* type, int lenType);

int sortName_lastName(Passenger** list, int len);
int passenger_sortArray(Passenger** list, int len);

int passenger_checkList(Passenger** list, int len, char* path);
int archive_countAmount(char* path, int* id);
int archive_rewrite(Passenger** list, int len, TypePassenger* type, int lenType, char* path);
int passenger_saveDate(Passenger** list, int len, TypePassenger* type, int lenType, char* path, int** id);

#endif /* PASSENGER_H_ */
