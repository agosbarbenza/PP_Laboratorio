/*
 * Zona.c
 *
 *  Created on: 18 may. 2022
 *      Author: agosb
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Zona.h"
#include "Direccion.h"
#include "Localidad.h"
#include "FechaNacimiento.h"
#include "Censista.h"
#include "Utn.h"

#define EMPTY 0
#define TAKEN 1

int initZone(Zona list[], int len) {
	int resultInit = -1;
	int i;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = EMPTY;
		}
		resultInit = 0;
	}
	return resultInit;
}

int findZoneById(Zona list[], int len, int id) {
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

int findZoneEmptyIndex(Zona list[], int len) {
	int index = -1;
	int i;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == EMPTY) {
				index = i;
				break;
			}
		}
	}

	return index;
}

int getZoneData(Localidad locationList[], int locationLen, int *incrementalId,
		char streetOne[], char streetTwo[], char streetThree[],
		char streetFour[], int *location, char status[]) {
	int resultGetData = -1;
	int auxId;
	auxId = utn_getIncrementalId(*incrementalId);
	int resultStreet1 = -1;
	int resultStreet2 = -1;
	int resultStreet3 = -1;
	int resultStreet4 = -1;
	int statusResult = -1;
	int lastResult = -1;
	int maxRetries = 2;

	if (locationList != NULL && locationLen > 0) {
		resultStreet1 = utn_getArrayCharAlphabetic(streetOne,
				"\nIngrese la primera calle: ",
				"\nError! La calle no es valida: ", 2);
		if (resultStreet1 == 0) {
			resultStreet2 = utn_getArrayCharAlphabetic(streetTwo,
					"\nIngrese la segunda calle: ", "\nLa calle no es valida: ",
					2);
			if (resultStreet2 == 0) {
				resultStreet3 = utn_getArrayCharAlphabetic(streetThree,
						"\nIngrese la tercera calle: ",
						"\nLa calle no es valida: ", 2);
				if (resultStreet3 == 0) {
					resultStreet4 = utn_getArrayCharAlphabetic(streetFour,
							"\nIngrese la tercera calle: ",
							"\nLa calle no es valida: ", 2);
					if (resultStreet4 == 0) {
						printLocalidades(locationList, locationLen);
						if (utn_getInt(location, "\nIngrese la localidad: ",
								"\nError! La localidad no es válida: ", 20, 1,
								2) == 0) {
							do {
								if (findLocationById(locationList, locationLen,
										*location) == -1) {
									printf(
											"\nError, la localidad ingresada no existe.");
									printLocalidades(locationList, locationLen);
									utn_getInt(location,
											"\nIngrese la localidad: ",
											"\nError! La localidad no es válida: ",
											20, 1, 2);
								} else {
									statusResult =
											utn_getArrayCharAlphabetic(
													streetOne,
													"\nIngrese el estado:\n-PENDIENTE\n-FINALIZADO",
													"\nError! El estado no es valido: ",
													2);
									if (statusResult == 0) {
										lastResult = 0;
									} else {
										printf("\nError.");
									}
								}
								maxRetries--;
							} while (maxRetries > 0);
						}
					}
				}
			}
		}
	}
	if (!lastResult) {
		printf(
				"\n=======================================================================================================================");
		printf(
				"\nUsted ha ingresado los siguientes datos:\n Calle 1: %s | Calle 2: %s | Calle 3: %s  | Calle 4: %s | Localidad: %d | Estado: %s",
				streetOne, streetTwo, streetThree, streetFour, *location,
				status);
		printf(
				"\n=======================================================================================================================\n");
		*incrementalId = auxId;
		resultGetData = 0;
	} else {
		printf("\nError en la carga de la zona.");
	}

	return resultGetData;
}

int assignZone(Localidad listLocalidad[], int lenLocalidad, Zona listZona[],
		int lenZona, Censista listCensista[], int lenCensista) {
	int resultAssign = -1;
	int resultIdZone = -1;
	int resultIdCensista = -1;
	int indexZoneId;
	int idZone;
	int idCensista;
	int maxRetries = 2;
	int maxRetries2 = 2;



	if(printZonaSinAsignar(listZona, lenZona, listLocalidad, lenLocalidad) == 0){
		resultIdZone = utn_getInt(&idZone,
					"\nIngrese la zona a la cual asignará un censista: ",
					"\nError! El ID de la zona ingresado no es valido.\n", 11000, 9000,
					2);
			do {
				indexZoneId = findZoneById(listZona, lenZona, idZone);
				if (indexZoneId == -1) {
					printf("\nError, el id de la zona ingresado no existe.");
					resultIdZone = utn_getInt(&idZone,
							"\nIngrese la zona a la cual asignará un censista: ",
							"\nError! El ID de la zona ingresado no es valido.\n",
							11000, 9000, 2);
				} else {
					printf("\nZona encontrada");
				}
				maxRetries--;
			} while (maxRetries > 0);
			if (indexZoneId != -1) {
				if (printCensistas(listCensista, lenCensista) == 0) {
					resultIdCensista = utn_getInt(&idCensista,
							"\nIngrese el ID del censista a asignar: ",
							"\nError! El ID del censista ingresado no es valido.\n",
							6000, 1000, 2);
					do {
						if (findCensistaById(listCensista, lenCensista, idCensista)
								== -1) {
							printf("\nError, el id ingresado no existe.");
							printCensistas(listCensista, lenCensista);
							resultIdCensista =
									utn_getInt(&idCensista,
											"\nIngrese el ID del censista a asignar: ",
											"\nError! El ID del censista ingresado no es valido.\n",
											6000, 1000, 1);
						} else {
							printf("\nCensista encontrado.");
							maxRetries2 = 0;
						}
						maxRetries2--;
					} while (maxRetries2 > 0);
				} else {
					printf("\nNo hay censistas para mostrar.");
				}
			} else {
				printf("\nNo se encontró la zona");
			}

			if (resultIdCensista == 0 && resultIdZone == 0) {
				listZona[indexZoneId].idCensista = idCensista;
				resultAssign = 0;
			}
	}else{
		printf("\nError al intentar mostrar las zonas");
	};

		return resultAssign;
}

int addZona(Zona listZona[], int lenZona, int id, char streetOne[],
		char streetTwo[], char streetThree[], char streetFour[], int location,
		char status[]) {
	int resultAdd = -1;
	int indexEmpty;

	if (listZona != NULL && lenZona > 0) {

		indexEmpty = findZoneEmptyIndex(listZona, lenZona);
		if (indexEmpty != -1) {
			if (confirmOperation(
					"\nDesea confirmar la operacion? 1 para si - 2 para no",
					"\nError, opción no válida.") == 0) {
				listZona[indexEmpty].id = id;
				strcpy(listZona[indexEmpty].calleUno, streetOne);
				strcpy(listZona[indexEmpty].calleDos, streetTwo);
				strcpy(listZona[indexEmpty].calleTres, streetThree);
				strcpy(listZona[indexEmpty].calleCuatro, streetFour);
				listZona[indexEmpty].localidad = location;
				strcpy(listZona[indexEmpty].estado, status);
				listZona[indexEmpty].isEmpty = TAKEN;
				resultAdd = 0;
			}
		}
	}
	return resultAdd;
}

int dataLoad(Localidad listLocalidad[], int lenLocalidad, Zona listZona[],
		int lenZona, Censista listCensista[], int lenCensista) {
	int resultDataLoad = -1;
	int resultCantInSitu = -1;
	int resultCantVirtual = -1;
	int resultCantAbsents = -1;
	int cantInSitu = 0;
	int cantVirtual = 0;
	int cantAbsents = 0;
	int idZone = -1;
	int indexZoneId = -1;
	int resultIdZone = -1;
	int maxRetries = 2;
	int i;

	if (listLocalidad != NULL && listZona != NULL && listCensista != NULL
			&& lenLocalidad > 0 && lenZona > 0 && lenCensista > 0) {
		if (printZonaPendiente(listZona, lenZona, listLocalidad, lenLocalidad,
				listCensista, lenCensista) == 0) {

			resultIdZone = utn_getInt(&idZone,
					"\nIngrese la zona a la cual asignará un censista: ",
					"\nError! El ID de la zona ingresado no es valido.\n",
					11000, 9000, 1);
			do {
				indexZoneId = findZoneById(listZona, lenZona, idZone);
				if (indexZoneId == -1) {
					printf("\nError, el id de la zona ingresado no existe.");
					resultIdZone =
							utn_getInt(&idZone,
									"\nIngrese la zona a la cual asignará un censista: ",
									"\nError! El ID de la zona ingresado no es valido.\n",
									11000, 9000, 1);
				} else {
					printf("\nZona encontrada");
					maxRetries = 0;
				}
				maxRetries--;
			} while (maxRetries > 0);
			if (resultIdZone == 0) {
				resultCantInSitu = utn_getInt(&cantInSitu,
						"\nIngrese la cantidad de censados in situ: ",
						"\nError! La cantidad no es válida: ", 500, 1, 2);
				if (resultCantInSitu == 0) {
					resultCantVirtual = utn_getInt(&cantVirtual,
							"\nIngrese la cantidad de censados virtualmente: ",
							"\nError! La cantidad no es válida: ", 500, 1, 2);
					if (resultCantVirtual == 0) {
						resultCantAbsents = utn_getInt(&cantAbsents,
								"\nIngrese la cantidad de ausentes: ",
								"\nError! La cantidad no es válida: ", 500, 1,
								2);
						if (resultCantAbsents == 0) {
							printf(
									"\nData ingresada:\nCantidad censados in situ: %d\nCantidad censados virtual: %d\nCantidad ausentes: %d\n",
									cantInSitu, cantVirtual, cantAbsents);
							if (confirmOperation(
									"\nDesea confirmar la operacion?\n1 para si - 2 para no",
									"\nError. Opcion no valida") == 0) {
								// cargarla a una zona primero tendria que habe relegido la zona, y como elijo la zona? tiene que ser una pendiente.
								strcpy(listZona[indexZoneId].estado,
										"FINALIZADO");
								for (i = 0; i < lenCensista; i++) {
									if (listCensista[i].id
											== listZona[indexZoneId].idCensista) {
										strcpy(listCensista[i].status,
												"LIBERADO");
										listZona[indexZoneId].cantInSitu =
												cantInSitu;
										listZona[indexZoneId].cantAusentes =
												cantAbsents;
										listZona[indexZoneId].cantVirtual =
												cantVirtual;
										break;
									}
								}
								resultDataLoad = 0;

							}
						} else {
							printf("\nError en la carga de ausentes");
						}
					} else {
						printf("\nError en la carga de censados virtualmente");
					}
				} else {
					printf("\nError al cargar los censados in situ");
				}
			} else {
				printf("\nError, en la carga de la zona");
			}

		} else {
			printf("\nNo hay resultados para mostrar");
		}

	}
	return resultDataLoad;
}

int printZonas(Zona listZona[], int lenZona, Localidad listLocalidad[],
		int lenLocalidad, Censista listCensista[], int lenCensistas) {
	int resultPrint = -1;
	int i;
	int qty_Zonas = 0;

	if (listZona != NULL && lenZona > 0) {
		printf(
				"\n=======================================================================================================================================\n                                              Listado de Zonas: \n=======================================================================================================================================");
		printf(
				"\nID           CALLE 1           CALLE 2           CALLE 3           CALLE 4           LOCALIDAD           ESTADO        CENSISTA\n=======================================================================================================================================");
		for (i = 0; i < lenZona; i++) {
			if (listZona[i].isEmpty == TAKEN) {
				printZona(listZona[i], listLocalidad, lenLocalidad,
						listCensista, lenCensistas);
				printf(
						"\n______________________________________________________________________________________________________________________________________\n");
				qty_Zonas++;
			}

		}

		if (qty_Zonas > 0) {
			resultPrint = 0;
		}
	}
	return resultPrint;
}

void printZona(Zona zona, Localidad listLocalidad[], int lenLocalidad,
		Censista listCensista[], int lenCensistas) {
	int i;
	int j;
	for (i = 0; i < lenLocalidad; i++) {
		for (j = 0; j < lenCensistas; j++) {
			if (listLocalidad[i].id == zona.localidad ) {
				if (zona.idCensista == 0) {
					printf(
							"\n%3d %13s %17s %18s %16s %16s %20s       SIN ASIGNAR",
							zona.id, zona.calleUno, zona.calleDos,
							zona.calleTres, zona.calleCuatro,
							listLocalidad[i].localidad, zona.estado);
					break;
				} else if (listCensista[j].id == zona.idCensista) {
					printf("\n%3d %13s %17s %18s %16s %16s %20s %10s %s",
							zona.id, zona.calleUno, zona.calleDos,
							zona.calleTres, zona.calleCuatro,
							listLocalidad[i].localidad, zona.estado,
							listCensista[j].name, listCensista[j].lastName);
				}
			}

		}
	}

}

int printZonaSinAsignar(Zona listZona[], int lenZona,
		Localidad listLocalidad[], int lenLocalidad) {
	int i;
	int k;
	int result = -1;
	if (listLocalidad != NULL && listZona != NULL && lenLocalidad > 0
			&& lenZona > 0) {
		for (i = 0; i < lenLocalidad; i++) {
			for (k = 0; k < lenZona; k++) {
				if (listLocalidad[i].id == listZona[k].localidad
						&& listZona[k].idCensista == 0) {

					printf(
							"\n%3d %13s %17s %18s %16s %16s %20s       SIN ASIGNAR",
							listZona[k].id, listZona[k].calleUno,
							listZona[k].calleDos, listZona[k].calleTres,
							listZona[k].calleCuatro, listLocalidad[i].localidad,
							listZona[k].estado);
				}
			}
		}
		result = 0;
	}
	return result;
}

int printZonaPendiente(Zona listZonas[], int lenZonas,
		Localidad listLocalidad[], int lenLocalidad, Censista listCensista[],
		int lenCensistas) {
	int i;
	int j;
	int k;
	int result = -1;
	if (listLocalidad != NULL && listCensista != NULL && lenLocalidad > 0
			&& lenCensistas > 0) {
		for (i = 0; i < lenLocalidad; i++) {
			for (j = 0; j < lenCensistas; j++) {
				for (k = 0; k < lenZonas; k++) {
					if (listLocalidad[i].id == listZonas[k].localidad) {
						//Tiene un censista asignado y está pendiente
						if (listCensista[j].id == listZonas[k].idCensista
								&& listZonas[k].idCensista != 0
								&& strcmp(listZonas[k].estado, "PENDIENTE")
										== 0) {
							printf(
									"\n%3d %13s %17s %18s %16s %16s %20s %10s %s",
									listZonas[k].id, listZonas[k].calleUno,
									listZonas[k].calleDos,
									listZonas[k].calleTres,
									listZonas[k].calleCuatro,
									listLocalidad[i].localidad,
									listZonas[k].estado, listCensista[j].name,
									listCensista[j].lastName);
						}
					}

				}

			}
		}
		result = 0;
	}
	return result;
}
