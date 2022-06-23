#ifndef CALCULOSAEROLINEAS_H_
#define CALCULOSAEROLINEAS_H_

int calcularDebito(float precio, int descuento, float* total);
int calcularCredito(float precio, int descuento, float* total);
int calcularBitcoin(float precio, float btc, float* total);
int calcularPrecioPorKm(float precio, float km, float* total);
int diferenciaDePrecio(float precioUno, float precioDos, float* total);

int calcularPrecios(float precio, float kilometros,float* debito, int porcentajeD,float* credito, int  porcentajeC,float* bitcoin, float precio_btc,float* precioUnitario);
int imprimirPrecios(char* mensaje,float precio, float debito, float credito, float bitcoin, float precioUnitario);

int cargaForzada(float* kilometros,float* precioAerolineas, float* precioLatam, float km, float precioA, float precioL);

#endif /* CALCULOSAEROLINEAS_H_ */
