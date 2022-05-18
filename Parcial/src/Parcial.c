/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Direccion.h"
#include "FechaNacimiento.h"
#include "Censista.h"
#include "Utn.h"

#define EMPTY 0
#define TAKEN 1
#define Q_CENSISTAS 15
#define Q_HARDCODE 15

int main(void) {
	setbuf(stdout, NULL);

	Censista arrayCensistas[Q_CENSISTAS];
//	Flight arrayFlights[Q_FLIGHTS] = {
//			{ 1, "Cordoba", "COR4782K", "DEMORADO", 0 }, { 2, "Bariloche",
//					"BRC9807I", "ATERRIZADO", 0 }, { 3, "Calafate", "FTE9905A",
//					"ACTIVO", 0 }, { 4, "Rosario", "ROS1455P", "DEMORADO", 0 },
//			{ 5, "Mendoza", "MZA8865O", "ATERRIZADO", 0 }, { 6, "Mendoza",
//					"USH8111O", "ACTIVO", 0 } };
	initCensistas(arrayCensistas, Q_CENSISTAS);
	hardCodeCensistas(arrayCensistas, Q_HARDCODE);
	int option;
	int incrementalId = 999;
	char name[52];
	char lastName[52];
	int age;
	FechaNacimiento date;
	Direccion address;
	int idToRemove;
	int idToModify;
//	int informOption;
//	int orderCriteria1;
//	int orderCriteria2;

	do {
		utn_showMenu("Sistema de Administracion de Censistas", "ALTAS",
				"MODIFICAR", "BAJAS", "INFORMAR", "SALIR");
		utn_getInt(&option, "\nIngrese una opción: ",
				"\nError! La opcion ingresada no es valida.\n", 6, 1, 2);
		switch (option) {
		case 1:
			if (getCensistaData(arrayCensistas, Q_CENSISTAS, &incrementalId, name, lastName, &age, date,
					address) == 0
					&& addCensista(arrayCensistas, Q_CENSISTAS,
							incrementalId, name, lastName, age, date,
							address) == 0) {


				printf("\nCensista cargado correctamente.");
			} else {
				printf(
						"\nEl censista no ha sido cargado. Vuelva a intentarlo.");
			}
			break;
		case 2:
			if (printCensistas(arrayCensistas, Q_CENSISTAS) == 0) {
				utn_getInt(&idToModify,
						"\nIngrese el ID del censista a modificar: ",
						"\nError! El ID ingresado no es valido.\n", 3000, 1000,
						2);
				if (modifyCensista(arrayCensistas, Q_CENSISTAS, idToModify)
						== 0) {
					printf("\nCensista modificado con éxito.");
				} else {
					printf("\nError, no se modificó el censista.");
				};
			} else {
				printf("\nNo hay censistas disponibles para modificar");
			}
			break;
		case 3:
			if (printCensistas(arrayCensistas, Q_CENSISTAS) == 0) {
				utn_getInt(&idToRemove,
						"\nIngrese el ID del censista a remover: ",
						"\nError! El ID ingresado no es valido.\n", 3000, 1000,
						2);
				if (removeCensista(arrayCensistas, Q_CENSISTAS, idToRemove)
						== 0) {
					printf(
							"\nCensista removido de la base de datos correctamente.");
				} else {
					printf(
							"\nEl censista no ha sido removido de la base de datos. Vuelva a intentarlo.");
				};
			} else {
				printf(
						"\n\nError. No hay censistas disponibles para remover de la base de datos.");
			}
			;

			break;
		case 4:
			printCensistas(arrayCensistas, Q_CENSISTAS);
//			if (checkAtLeastOneRegister(arrayCensistas, Q_CENSISTAS) == 0) {
//				subMenuInform();
//				if (utn_getInt(&informOption, "\nIngrese la opcion: ",
//						"\nError! Opcion no valida.\n", 3, 1, 2) == 0) {
//					switch (informOption) {
//					case 1:
//						if (utn_getInt(&orderCriteria1,
//								"\nIngrese el criterio de ordenamiento\n1 para ASCENDENTE\n2 para DESCENDENTE",
//								"\nError! Opcion no valida.\n", 2, 1, 2) == 0) {
//							if (sortPassengers(arrayCensistas,
//							Q_CENSISTAS, arrayFlights, Q_FLIGHTS,
//									orderCriteria1, 0) == 0) {
//								printf("\nPasajeros ordenados con éxito");
//							} else {
//								printf(
//										"\n\nNo se ha podido ordenar a los pasajeros.");
//							}
//						}
//
//						break;
//					case 2:
//						if (calculateAveragePrice(arrayCensistas,
//						Q_CENSISTAS) == 0) {
//							printf("\nDatos mostrados con éxito");
//						} else {
//							printf(
//									"\nHa ocurrido un error y no se pueden mostrar los datos solicitados.");
//						}
//						break;
//					case 3:
//						if (utn_getInt(&orderCriteria2,
//								"\nIngrese el criterio de ordenamiento\n1 para DESCENDENTE\n2 para ASCENDENTE ",
//								"\nError! Opcion no valida.\n", 2, 1, 2) == 0) {
//							printf("\nOrderCriteria2 Despues %d",
//									orderCriteria2);
//							if (sortPassengers(arrayCensistas,
//							Q_CENSISTAS, arrayFlights, Q_FLIGHTS,
//									orderCriteria2, 1) == 0) {
//								printf("\nPasajeros ordenados con éxito");
//							} else {
//								printf(
//										"\n\nNo se ha podido ordenar a los pasajeros.");
//							}
//						}
//						break;
//
//					}
//
//				} else {
//					printf("\n\nNo se ha podido ordenar a los pasajeros.");
//				};
//
//			}
			break;
		case 5:
			printf("\n\nSistema cerrado con éxito.");
			break;
		}
	} while (option != 5);

	return EXIT_SUCCESS;
}
