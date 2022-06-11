#define TAM_TYPE 3

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

int file_serachPassenger(char* path, LinkedList* pArrayListPassenger);
int file_toRewriteFile(char* path, LinkedList* pArrayListPassenger);

int parser_searchIdMax(char* path,LinkedList* pArrayListPassenger);
int file_writeBelow(char* path, LinkedList* pArrayListPassenger);


int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

int file_reasingId(char* path, LinkedList* pArrayListPassenger);
int file_carryPassengerBin(char* path, LinkedList* pArrayListPassenger);

int parser_searchIdMaxBin(char* path,LinkedList* pArrayListPassenger);
int parser_searchPassengerBin(char* path,  LinkedList* pArrayListPassenger);
int file_serachPassengerBin(char* path, LinkedList* pArrayListPassenger, void* listAux);
int file_writeBelowBin(char* path, LinkedList* pArrayListPassenger);
