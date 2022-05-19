/*
 * Localidad.c
 *
 *  Created on: 18 may. 2022
 *      Author: agosb
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Localidad.h"
#include "Zona.h"
#include "Direccion.h"
#include "FechaNacimiento.h"
#include "Censista.h"
#include "Utn.h"

#define EMPTY 0
#define TAKEN 1

int findLocationById(Localidad list[], int len, int id) {
	int resultFind = -1;
	int i;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].id == id) {
				resultFind = i;
				break;
			}
		}
	}
	return resultFind;
}

int printLocalidades(Localidad listLocations[], int lenLocations) {
	int resultPrint = -1;
	int i;
	int qty_Locations = 0;

	if (listLocations != NULL && lenLocations > 0) {
		printf(
				"\n=================================================================================================================\n                                              Listado de Localidades: \n=================================================================================================================");
		printf(
				"\nID           LOCALIDAD\n=================================================================================================================");
		for (i = 0; i < lenLocations; i++) {

			if (listLocations[i].isEmpty == TAKEN) {
				printLocalidad(listLocations[i]);
				printf(
						"\n_________________________________________________________________________________________________________________\n");
				qty_Locations++;
			}

		}

		if (qty_Locations > 0) {
			resultPrint = 0;
		}
	}
	return resultPrint;
}

void printLocalidad(Localidad localidad) {

	printf("\n%3d %13s", localidad.id,
			localidad.localidad);
}
