#ifndef UTN_VALIDACIONES_H_
#define UTN_VALIDACIONES_H_

int medirLongitud(char* cadena);
int validarLongitud(char* cadena, int limite, int minimo);

int validarNumeroFlotante(float* numero, int min, int max, int intentos);
int pedirNumero_decimal(float* numero, char* mensaje, char* mensajeError, int min, int max, int intentos);

int validar_numerosEnteros(char* buffer, int longitud);
int pedirNumeroEntero(int* numero, char* mensaje, char* mensajeError, int min, int max,  int intentos);



#endif /* UTN_VALIDACIONES_H_ */
