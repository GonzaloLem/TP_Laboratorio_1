#ifndef UTN_VALIDACIONES_H_
#define UTN_VALIDACIONES_H_

int validarNumeroFlotante(float* numero, int min, int max, int intentos);

int calcularDebito(float precio, int descuento, float* total);
int calcularCredito(float precio, int descuento, float* total);
int calcularBitcoin(float precio, float btc, float* total);
int calcularPrecioPorKm(float precio, float km, float* total);
int diferenciaDePrecio(float precioUno, float precioDos, float* total);

int informarResultados(float debito,float credito,float bitcoin, float unitario);

int cargaForzada(float* kilometros,float* precioAerolineas, float* precioLatam, float km, float precioA, float precioL);

#endif /* UTN_VALIDACIONES_H_ */
