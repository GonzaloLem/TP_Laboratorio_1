#ifndef MENU_H_
#define MENU_H_

void printMenuOptions();
void printMenuModify();
int requestOption(int min, int max);
int menu_exit(int saveOne, int saveTwo, int exit, char* messageOne, char* errorOne, char* messageTwo, char* errorTwo);

#endif /* MENU_H_ */
