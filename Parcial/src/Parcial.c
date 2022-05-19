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

#include "Localidad.h"
#include "Zona.h"
#include "Direccion.h"
#include "FechaNacimiento.h"
#include "Censista.h"

#include "Utn.h"

#define EMPTY 0
#define TAKEN 1
#define Q_CENSISTAS 20
#define Q_LOCALIDADES 10
#define Q_HARDCODE 15
#define Q_ZONAS 10

int main(void) {
	setbuf(stdout, NULL);

	Censista arrayCensistas[Q_CENSISTAS];
//	Localidad arrayLocalidades[Q_LOCALIDADES];
//	Zona arrayZonas[Q_ZONAS];

	Localidad arrayLocalidades[Q_LOCALIDADES] = { { 1, "Caba", TAKEN }, { 2,
			"Avellaneda", TAKEN }, { 3, "Quilmes", TAKEN }, { 4, "Dolores",
	TAKEN }, { 5, "Lincoln", TAKEN }, { 6, "Banfield",
	TAKEN }, { 7, "Lanus", TAKEN }, { 8, "Junin", TAKEN }, { 9,
			"Lomas de Zamora", TAKEN }, { 10, "Tandil", TAKEN } };
	Zona arrayZonas[Q_ZONAS] = { { 10500, 1500, "Cordoba", "Bonpland",
			"Carranza", "Gorriti", 1, "PENDIENTE", 50, 100, 6, TAKEN, }, {
			10501, 1501, "Malabia", "Guemes", "Oro", "Santa Fe", 1,
			"FINALIZADO", 80, 20, 10, TAKEN }, { 10502, 0, "Tucuman", "Colon",
			"Alsina", "La Rioja", 3, "PENDIENTE", 60, 10, 5, TAKEN }, { 10503,
			1503, "Jacob", "Brown", "Paso", "Sivori", 2, "PENDIENTE", 45, 50, 6,
			TAKEN }, { 10504, 1504, "Lamadrid", "9 de Julio", "Cerrito",
			"Moreno", 4, "PENDIENTE", 100, 150, 6, TAKEN }, { 10505, 0, "Pinto",
			"Belgrano", "San Martin", "San Lorenzo", 10, "PENDIENTE", 66, 70, 4,
			TAKEN }, { 10506, 1506, "Belgrano", "Avellaneda", "Bolivar",
			"19 de Julio", 9, "PENDIENTE", 45, 55, 1, TAKEN }, { 10507, 1507,
			"Beruti", "Pueyrredon", "Alberti", "Ferrari", 6, "FINALIZADO", 88,
			50, 3, TAKEN }, { 10508, 1508, "Marconi", "Pelegrini", "Echeverria",
			"Riobamba", 5, "FINALIZADO", 9, 10, 5, TAKEN }, { 10509, 1509,
			"Caseros", "Catulo Castillo", "24 de noviembre", "Almafuerte", 1,
			"PENDIENTE", 99, 80, 5, TAKEN } };

	initCensistas(arrayCensistas, Q_CENSISTAS);

	hardCodeCensistas(arrayCensistas, Q_HARDCODE);
//	hardCodeLocalidad(arrayLocalidades, Q_LOCALIDADES);
//	hardCodeZonas(arrayZonas, Q_ZONAS);
	int option;
	//Censista
	int incrementalId = 999;
	int incrementalIdLocations = 100;
	char name[53];
	char lastName[53];
	int age;
	int day;
	int month;
	int year;
	int streetNumber;
	char streetName[53];
	//Zona
	char streetOne[53];
	char streetTwo[53];
	char streetThree[53];
	char streetFour[53];
	int location;
	char status[10];

	int idToRemove;
	int idToModify;
	int informOption;
	int orderCriteria1;


	int count;

	do {
		utn_showMenu("Sistema de Administracion de Censistas",
				"Cargar censista", "Modificar censista", "Dar de baja censista",
				"Cargar zona", "Asignar zona a censar", "Carga de datos",
				"Mostrar censistas", "Mostrar zonas", "Salir");
		utn_getInt(&option, "\nIngrese una opción: ",
				"\nError! La opcion ingresada no es valida.\n", 10, 1, 2);
		switch (option) {
		case 1:
			if (getCensistaData(arrayCensistas, Q_CENSISTAS, &incrementalId,
					name, lastName, &age, &day, &month, &year, &streetNumber,
					streetName) == 0
					&& addCensista(arrayCensistas, Q_CENSISTAS, incrementalId,
							name, lastName, age, day, month, year, streetNumber,
							streetName) == 0) {
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
			if (getZoneData(arrayLocalidades, Q_LOCALIDADES,
					&incrementalIdLocations, streetOne, streetTwo, streetThree,
					streetFour, &location, status) == 0) {
				printf("\nLa zona se cargo correctamente");
			} else {
				printf("\nError en la carga de la zona");
			}
			;
			break;
		case 5:
			if (assignZone(arrayLocalidades, Q_LOCALIDADES, arrayZonas,
			Q_ZONAS, arrayCensistas, Q_CENSISTAS) == 0) {
				printf("\nCensista asignado con éxito a la zona.");
			} else {
				printf(
						"\nError, no se ha podido asignar un censista a la zona.");
			}
			break;
		case 6:
			if (dataLoad(arrayLocalidades, Q_LOCALIDADES, arrayZonas,
			Q_ZONAS, arrayCensistas, Q_CENSISTAS) == 0) {
				printf("\nLa carga de datos se realizó correctamente.");

			} else {
				printf("\nError en la carga de datos");
			}
			;
			break;
		case 7:
			if (printCensistas(arrayCensistas, Q_CENSISTAS) == 0) {
				printf("\nCensistas mostrados correctamente");
			} else {
				printf(
						"\nNo se pudo mostrar a los censistas. Vuelva a intentarlo");
			}
			break;
		case 8:
			if (printZonas(arrayZonas, Q_ZONAS, arrayLocalidades, Q_LOCALIDADES,
					arrayCensistas, Q_CENSISTAS) == 0) {
				printf("\nZonas mostradas correctamente");
			} else {
				printf("\nNo se mostraron las zonas. Vuelva a intentarlo.");
			}
			;
			break;
		case 9:
			subMenuInform();
			if (utn_getInt(&informOption, "\nIngrese la opcion: ",
					"\nError! Opcion no valida.\n", 3, 1, 2) == 0) {
				switch (informOption) {
				case 1:
					if(printCensistaActivoPendiente(arrayCensistas, Q_CENSISTAS,
							arrayZonas, Q_ZONAS, &count) == 0){
						printf("\nCantidad de Censistas con estado ACTIVO y Zona PENDIENTE: %d", count);

					}else{
						printf("\nError");
					}

					break;
				case 2:
					if (utn_getInt(&orderCriteria1,
							"\nIngrese el criterio de ordenamiento\n1 para ASCENDENTE",
							"\nError! Opcion no valida.\n", 1, 1, 2) == 0) {
						if (sortCensistas(arrayCensistas, Q_CENSISTAS, arrayLocalidades, Q_LOCALIDADES, arrayZonas, Q_ZONAS, orderCriteria1)
								== 0) {
							printf("\nCensistas ordenados con éxito");
						} else {
							printf(
									"\n\nNo se ha podido ordenar a los censistas.");
						}
					}

					break;
				case 3:

				}

			} else {
				printf("\n\nNo se ha podido ordenar a los censistas.");
			}
			;

			break;
		case 10:
			printf("\n\nSistema cerrado con éxito.");
			break;
		}
	} while (option != 10);

	return EXIT_SUCCESS;
}
