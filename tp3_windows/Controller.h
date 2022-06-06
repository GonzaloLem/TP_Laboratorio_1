#ifndef CONTROLLER_H_
#define CONTROLLER_H_

//int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, Passenger** list, int len, TypePassenger* type, int lenType, int* id, int* flagLoad);

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
//int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger, Passenger** list, int len, TypePassenger* type, int lenType, int* id);

//int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger, Passenger** list, int len,TypePassenger* type, int lenType);

//int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger, Passenger** list, int len,TypePassenger* type, int lenType);

//int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger, Passenger** list, int len,TypePassenger* type, int lenType);

//int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger, Passenger** list, int len,TypePassenger* type, int lenType);

//int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger, Passenger** list, int len,TypePassenger* type, int lenType, int* id);

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

#endif /* CONTROLLER_H_ */
