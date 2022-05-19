/*
 * Zona.h
 *
 *  Created on: 18 may. 2022
 *      Author: agosb
 */

#ifndef ZONA_H_
#define ZONA_H_

#include "Localidad.h"
#include "Zona.h"
#include "Censista.h"

typedef struct{
	int id;
	int idCensista;
	char calleUno[51];
	char calleDos[51];
	char calleTres[51];
	char calleCuatro[51];
	int localidad;
	char estado[10];
	int cantInSitu;
	int cantVirtual;
	int cantAusentes;
	int isEmpty;
}Zona;

int initZone(Zona list[], int len);
int findZoneById(Zona list[], int len, int id);
int findZoneEmptyIndex(Zona list[], int len);
int addZona(Zona listZona[], int lenZona, int id, char streetOne[],
		char streetTwo[], char streetThree[], char streetFour[], int location, char status[]);
int assignZone(Localidad listLocalidad[], int lenLocalidad, Zona listZona[], int lenZona, Censista listCensista[], int lenCensista);
int getZoneData(Localidad locationList[], int locationLen, int *incrementalId,
		char streetOne[], char streetTwo[], char streetThree[],
		char streetFour[], int *location, char status[]);
void printZona(Zona zona, Localidad listLocalidad[], int lenLocalidad, Censista listCensista[], int lenCensistas);
int printZonas(Zona listZona[], int lenZona, Localidad listLocalidad[], int lenLocalidad, Censista listCensista[], int lenCensistas);
int printZonaPendiente(Zona listZonas[], int lenZonas,
		Localidad listLocalidad[], int lenLocalidad, Censista listCensista[],
		int lenCensistas);
int printZonaSinAsignar(Zona listZona[], int lenZona,
		Localidad listLocalidad[], int lenLocalidad);
int dataLoad(Localidad listLocalidad[], int lenLocalidad, Zona listZona[],
		int lenZona, Censista listCensista[], int lenCensista);
#endif /* ZONA_H_ */
