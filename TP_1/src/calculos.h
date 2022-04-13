/*
 * calculos.h
 *
 *  Created on: 7 abr. 2022
 *      Author: Gonzalo Lemiña
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

//Prototipo formal de ingresar Kilometros
int ingresar_kilometros(int* km);
//Prototipo formal de ingresar Kilometros
int precio_vuelos(float* precio_aerolineas, float* precio_latam);
//Prototipo formal de calculos de Aerolineas
int calculos_aerolineas(int x, float y, float* guardar_debito, float* guardar_credito, float* guardar_btc, float* guardar_unitario);
//Prototipo formal de calculos de Latam
int calculos_latam(int x, float z, float* guardar_debito, float* guardar_credito, float* guardar_btc, float* guardar_unitario, float y, float* diferencia_z_y);
//Prototipo formal de mensajes
void mensajes(int x, float y, float debito_aerolineas, float credito_aerolineas, float btc_aerolineas, float precio_unitario_aerolineas, float z, float debito_latam, float credito_latam, float btc_latam, float unitario_latam, float diferencia_z_y);
//Prototipo formal de la carga forzada de datos
int forzar_datos(int* x, float* y, float* z);

#endif /* CALCULOS_H_ */
