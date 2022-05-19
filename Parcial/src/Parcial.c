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

//typedef struct{
//	int id;
//	int idCensista;
//	char calleUno[51];
//	char calleDos[51];
//	char calleTres[51];
//	char calleCuatro[51];
//	int localidad;
//	char estado[10];
//	int isEmpty;
//}Zona;

int main(void) {
	setbuf(stdout, NULL);

	Censista arrayCensistas[Q_CENSISTAS];
	Localidad arrayLocalidades[Q_LOCALIDADES] = { { 1, "Caba", TAKEN }, { 2,
			"Campana", TAKEN }, { 3, "Quilmes", TAKEN },
			{ 4, "Dolores", TAKEN }, { 5, "Lincoln", TAKEN }, { 6, "Brandsen",
					TAKEN }, { 7, "Escobar", TAKEN }, { 8, "Junin", TAKEN }, {
					9, "Zarate", TAKEN }, { 10, "Tandil", TAKEN } };
	Zona arrayZonas[Q_ZONAS]={
			{10500, 0, "Cordoba", "Bonpland", "Carranza", "Gorriti", 1, "PENDIENTE", TAKEN},
			{10501, 0, "Malabia", "Guemes", "Oro", "Santa Fe", 1, "FINALIZADO", TAKEN},
			{10502, 0, "Tucuman", "Colon", "Alsina", "La Rioja", 3, "FINALIZADO", TAKEN },
			{10503, 0, "Jacob", "Brown", "Paso", "Sivori", 2, "PENDIENTE"},
			{10504, 0, "Lamadrid", "9 de Julio", "Cerrito", "Moreno", 4, "PENDIENTE", TAKEN},
			{10505, 0, "Pinto", "Belgrano", "San Martin", "San Lorenzo", 10, "FINALIZAOD", TAKEN},
			{10506, 0, "Belgrano", "Avellaneda", "Bolivar", "19 de Julio", 9, "PENDIENTE", TAKEN},
			{10507, 0, "Beruti", "Pueyrredon", "Alberti", "Ferrari", 6, "FINALIZADO", TAKEN},
			{10508, 0, "Marconi", "Pelegrini", "Echeverria", "Riobamba", 5, "FINALIZADO", TAKEN},
			{10509, 0, "Caseros", "Catulo Castillo", "24 de noviembre", "Almafuerte", 1, "PENDIENTE", TAKEN}
	};

	initCensistas(arrayCensistas, Q_CENSISTAS);
	hardCodeCensistas(arrayCensistas, Q_HARDCODE);
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

//	FechaNacimiento date;
//	Direccion address;
	int idToRemove;
	int idToModify;
//	int informOption;
//	int orderCriteria1;
//	int orderCriteria2;

	do {
		utn_showMenu("Sistema de Administracion de Censistas",
				"Cargar censista", "Modificar censista", "Dar de baja censista",
				"Cargar zona", "Asignar zona a censar", "Carga de datos",
				"Mostrar censistas", "Mostrar zonas", "Salir");
		utn_getInt(&option, "\nIngrese una opci�n: ",
				"\nError! La opcion ingresada no es valida.\n", 6, 1, 2);
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
					printf("\nCensista modificado con �xito.");
				} else {
					printf("\nError, no se modific� el censista.");
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
			if (assignZone(arrayLocalidades, Q_LOCALIDADES,arrayZonas,
					Q_ZONAS, arrayCensistas, Q_CENSISTAS) == 0){
				printf("\nCensista asignado con �xito a la zona.");
			}else{
				printf("\nError, no se ha podido asignar un censista a la zona.");
			}
			break;
		case 6:
			break;
		case 7:
			if(printCensistas(arrayCensistas, Q_CENSISTAS) == 0) {
							printf("\nCensistas mostrados correctamente");
						}else{
							printf("\nNo se pudo mostrar a los censistas. Vuelva a intentarlo");
						}
			break;
		case 8:
			if(printZonas(arrayZonas, Q_ZONAS, arrayLocalidades, Q_LOCALIDADES, arrayCensistas, Q_CENSISTAS) == 0){
				printf("\nZonas mostradas correctamente");
			}else{
				printf("\nNo se mostraron las zonas. Vuelva a intentarlo.");
			};
			break;
		case 9:
			printf("\n\nSistema cerrado con �xito.");
			break;
		}
	} while (option != 9);

	return EXIT_SUCCESS;
}
