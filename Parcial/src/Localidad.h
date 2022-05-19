/*
 * Localidad.h
 *
 *  Created on: 18 may. 2022
 *      Author: agosb
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

typedef struct{
	int id;
	char localidad[51];
	int isEmpty;
}Localidad;

int findLocationById(Localidad list[], int len, int id);
int printLocalidades(Localidad listLocations[], int lenLocations);
void printLocalidad(Localidad localidad) ;


#endif /* LOCALIDAD_H_ */
