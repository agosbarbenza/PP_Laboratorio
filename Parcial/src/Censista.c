/*
 * Censista.c
 *
 *  Created on: 17 may. 2022
 *      Author: agosb
 */

#ifndef CENSISTA_C_
#define CENSISTA_C_

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

void showFlyCodes(void) {
	printf(
			"\nListado de vuelos:\nCordoba: COR4782K\nBariloche: BRC9807I\nCalafate: FTE9905A\nRosario: ROS1455P\nMendoza: MZA8865O\n");
}

void subMenuModify(void) {
	printf(
			"\nDatos disponibles para modificar: \n1)Nombre \n2)Apellido \n3)Edad \n4)Direccion\n5)Fecha de Nacimiento\n");
}
void subMenuInform(void) {
	printf(
			"\nInformar: \n1)Listado de pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero\n2)Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio\n3)Listado de pasajeros por código de vuelo y estados de vuelo 'ACTIVO'");
}

void subMenuOrderCriteria(void) {
	printf(
			"\nIngrese el criterio de ordenamiento: \n0 para Menor a Mayor \n1 para Mayor a Menor \n");
}

int initCensistas(Censista list[], int len) {
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

int addCensista(Censista listCensista[], int lenCensista, int id, char name[],
		char lastName[], int age, FechaNacimiento date, Direccion address) {
	int resultAdd = -1;
	int indexEmpty;

	if (listCensista != NULL && lenCensista > 0) {

		indexEmpty = findEmptyIndex(listCensista, lenCensista);
		if (indexEmpty != -1) {
			if (confirmOperation(
					"\nDesea confirmar la operacion? 1 para si - 2 para no",
					"\nError, opción no válida.") == 0) {
				listCensista[indexEmpty].id = id;
				strcpy(listCensista[indexEmpty].name, name);
				strcpy(listCensista[indexEmpty].lastName, lastName);
				listCensista[indexEmpty].age = age;
				listCensista[indexEmpty].dateOfBirth = date;
				listCensista[indexEmpty].address = address;
				listCensista[indexEmpty].isEmpty = TAKEN;
				resultAdd = 0;
			}
		}
	}

	return resultAdd;
}

int getCensistaData(Censista CensistaList[], int CensistaLen,
		int *incrementalId, char name[], char lastName[], int *age,
		FechaNacimiento date, Direccion address) {
	int resultGetData = -1;
	int auxId;
	auxId = utn_getIncrementalId(*incrementalId);
	int resultName = 0;
	int resultLastName = 0;
	int resultAge = 0;
	int resultDate = 0;
	int resultAddress;
	int lastResult = -1;
//	int maxRetries = 2;
//	int flagFlyCode = -1;
//	char auxStreet[51];
//	int auxStreetNumber;
//	FechaNacimiento auxBirthDate;
//	Direccion auxAddress;

	if (CensistaList != NULL && CensistaLen > 0) {
		resultName = utn_getArrayCharAlphabetic(name, "\nIngrese nombre: ",
				"\nError! El nombre no es válido: ", 2);
		if (resultName == 0) {
			resultLastName = utn_getArrayCharAlphabetic(lastName,
					"\nIngrese apellido: ",
					"\nError! El apellido no es válido. ", 2);
			if (resultLastName == 0) {
				resultAge =
						utn_getInt(age, "\nIngrese la edad: ",
								"\nError! la edad no es válida, debe ser entre 18 y 100 años ",
								100, 18, 2);
				if (resultAge == 0) {

					if (utn_getInt(&date.day, "\nIngrese el día de nacimiento: ",
							"\nError! el día no es válido, debe ser entre 1 y 31 ",
							31, 1, 2) == 0
							&& utn_getInt(&date.month,
									"\nIngrese el mes de nacimiento: ",
									"\nError! el mes no es válido, debe ser entre 1 y 12 ",
									12, 1, 2) == 0
							&& utn_getInt(&date.year,
									"\nIngrese el año de nacimiento: ",
									"\nError! el año no es válido, debe ser entre 1922 y 2004 ",
									2004, 1922, 2) == 0) {
						resultDate = 0;
						if (!resultDate) {
							if (utn_getArrayCharAlphabetic(address.calle,
									"\nIngrese el nombre de la calle: ",
									"\nError! El nombre no es válido: ", 2) == 0
									&& utn_getInt(&address.numero,
											"\nIngrese el número de la calle: ",
											"\nError! el mes no es válido, debe ser entre 1 y 10900 ",
											10900, 1, 2) == 0) {
								resultAddress = 0;
							}
						} else {
							printf("\nError en la carga de la dirección.");
						}
						if (!resultAddress) {
							lastResult = 0;
						}
					}
				}
			}
		}
		if(!lastResult){
		printf(
				"\n=======================================================================================================================");
		printf(
				"\nUsted ha ingresado los siguientes datos:\n\nNombre: %s | Apellido: %s | Edad: %d  | Fecha de Nacimiento: %d/%d/%d | Direccion: %s %d",
				name, lastName, *age, date.day, date.month, date.year,
				address.calle, address.numero);
		printf(
				"\n=======================================================================================================================\n");
		*incrementalId = auxId;
		resultGetData = 0;
	} else {
		printf("\nError en la carga de censista.");
	}

}
	return resultGetData;
}

int findCensistaById(Censista list[], int len, int id) {
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

int findEmptyIndex(Censista list[], int len) {
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

int removeCensista(Censista list[], int len, int id) {
	int resultRemove = -1;
	int index;
	int atLeastOneRegister = -1;

	if (list != NULL && len > 0) {
		atLeastOneRegister = checkAtLeastOneRegister(list, len);

		if (atLeastOneRegister == 0) {
			index = findCensistaById(list, len, id);
		}
		if (index != -1) {
			printf(
					"\nEstá a punto de remover al censista de ID N° %d, cuyo nombre es %s %s",
					list[index].id, list[index].name, list[index].lastName);
			if (confirmOperation(
					"\nDesea confirmar la operacion?\n1 para si - 2 para no",
					"Error. Opcion no valida") == 0) {
				list[index].isEmpty = EMPTY;
				resultRemove = 0;
			}
		}
	}

	return resultRemove;
}

int printCensistas(Censista listCensista[], int lenCensista) {
	int resultPrint = -1;
	int i;
	int qty_Censistas = 0;

	if (listCensista != NULL && lenCensista > 0) {
		printf(
				"\n=================================================================================================================\n                                              Listado de Pasajeros: \n=================================================================================================================");
		printf(
				"\nID           NOMBRE           APELLIDO           EDAD           FECHA DE NACIMIENTO           DIRECCION\n=================================================================================================================");
		for (i = 0; i < lenCensista; i++) {

			if (listCensista[i].isEmpty == TAKEN) {
				printCensista(listCensista[i]);
			}
			printf(
					"\n_________________________________________________________________________________________________________________\n");
			qty_Censistas++;
		}

		if (qty_Censistas > 0) {
			resultPrint = 0;
		}
	}
	return resultPrint;
}

void printCensista(Censista Censista) {

	printf("\n%3d %13s %17s %20d %22d/%d/%d %27s %d", Censista.id,
			Censista.name, Censista.lastName, Censista.age,
			Censista.dateOfBirth.day, Censista.dateOfBirth.month,
			Censista.dateOfBirth.year, Censista.address.calle,
			Censista.address.numero);
}

void hardCodeCensistas(Censista list[], int len) {
	int idCensista[] = { 1500, 1501, 1502, 1503, 1504, 1505, 1506, 1507, 1508,
			1509, 1510, 1511, 1512, 1513, 1514 };
	char nameCensista[][51] = { "Taylor", "Richie", "James", "Britney", "Tarja",
			"Tuomas", "Steve", "Tommy", "Vince", "Dave", "Amy", "Gustavo",
			"Adrian", "Ozzy", "Matt" };
	char lastNameCensista[][51] = { "Swift", "Sambora", "Hetfield", "Spears",
			"Turunen", "Holopainen", "Harris", "Lee", "Neil", "Grohl", "Lee",
			"Cerati", "Dargelos", "Osbourne", "Heafy" };
	int age[] = { 25, 30, 50, 55, 36, 29, 55, 60, 45, 41, 22, 42, 37, 23, 36 };
	FechaNacimiento dates[] = {

	{ 15, 4, 1996 }, { 20, 3, 1992 }, { 31, 3, 1972 }, { 1, 1, 1967 }, { 4, 5,
			1988 }, { 6, 6, 1951 }, { 10, 8, 1968 }, { 11, 12, 1999 }, { 30, 5,
			1982 }, { 18, 8, 1993 }, { 2, 3, 1980 }, { 6, 4, 1971 }, { 25, 5,
			1988 }, { 14, 1, 1960 }, { 15, 2, 1998 } };

	Direccion address[] = {

	{ 1555, "Nicaragua" },
	{ 2023, "Santa Fe" },
	{ 5456, "Fitz Roy" },
	{ 5556, "Anchorena" },
			{ 1001, "Honduras" },
			{ 3232, "Aguero" },
			{ 1145, "Carranza" },
			{ 6312, "Bonpland" },
			{ 1136, "Santos Dumont" },
			{
			114, "Cabildo" },
			{ 3301, "Donado" },
			{ 1147, "Holmberg" },
			{ 555,
			"Charlone" },
			{ 2680, "Conesa" },

			{ 444, "Libertador" } };
	int i;

	for (i = 0; i < len; i++) {
		list[i].id = idCensista[i];
		strcpy(list[i].name, nameCensista[i]);
		strcpy(list[i].lastName, lastNameCensista[i]);
		list[i].age = age[i];
		list[i].dateOfBirth = dates[i];
		list[i].address = address[i];
		list[i].isEmpty = TAKEN;
	}

}

int modifyCensista(Censista list[], int len, int id) {
	int resultModify = -1;
	int atLeastOneRegister = -1;
	int optionToModify;
	int index;
	char auxName[51];
	char auxLastName[51];

	if (list != NULL && len > 0) {
		atLeastOneRegister = checkAtLeastOneRegister(list, len);

		if (atLeastOneRegister == 0) {
			index = findCensistaById(list, len, id);
		}
		if (index != -1) {
			subMenuModify();
			utn_getInt(&optionToModify, "\nIngrese la opcion a modificar: ",
					"\nError! La opcion ingresada no es correcta.\n", 5, 1, 2);
			switch (optionToModify) {
			case 1:
				utn_getArrayCharAlphabetic(auxName,
						"\nIngrese el nombre del censista: ",
						"\nError! El nombre no es válido: ", 2);
				strcpy(list[index].name, auxName);
				break;
			case 2:
				utn_getArrayCharAlphabetic(auxLastName,
						"\nIngrese el apellido del censista: ",
						"\nError! El apellido no es válido: ", 2);
				strcpy(list[index].lastName, auxLastName);
				break;
			case 3:
				utn_getInt(&list[index].age, "\nIngrese la edad: ",
						"\nError! La edad no es válida, debe ser entre 18 y 100 años. ",
						100, 18, 2);
				break;
			case 4:
				utn_getArrayCharAlphabetic(list[index].address.calle,
						"\nIngrese el nombre de la calle: ",
						"\nError! El nombre no es válido: ", 2);
				utn_getInt(&list[index].address.numero,
						"\nIngrese el número de la calle: ",
						"\nError! el mes no es válido, debe ser entre 1 y 10900 ",
						10900, 1, 2);
				break;
			case 5:
				utn_getInt(&list[index].dateOfBirth.day,
						"\nIngrese el día de nacimiento: ",
						"\nError! el día no es válido, debe ser entre 1 y 31 ",
						31, 1, 2);
				utn_getInt(&list[index].dateOfBirth.month,
						"\nIngrese el mes de nacimiento: ",
						"\nError! el mes no es válido, debe ser entre 1 y 12 ",
						12, 1, 2);
				utn_getInt(&list[index].dateOfBirth.year,
						"\nIngrese el año de nacimiento: ",
						"\nError! el año no es válido, debe ser entre 1922 y 2004 ",
						2004, 1922, 2);
			}
			resultModify = 0;
		}

	}

	return resultModify;
}

//int sortCensistas(Censista listCensista[], int lenCensista, Flight listFlight[],
//		int lenFlight, int order, int flagByCodeActive) {
//	int resultSort = -1;
//	if (listCensista != NULL && lenCensista > 0 && listFlight != NULL
//			&& lenFlight > 0 && order >= 0) {
//		switch (order) {
//		case 1:
//			sortLowerToHigher(listCensista, lenCensista, listFlight, lenFlight,
//					flagByCodeActive);
//			break;
//		case 2:
//			sortHigherToLower(listCensista, lenCensista, listFlight, lenFlight,
//					flagByCodeActive);
//			break;
//		}
//		printCensistas(listCensista, lenCensista, listFlight, lenFlight,
//				flagByCodeActive);
//		resultSort = 0;
//	}
//	return resultSort;
//}
//
//void sortLowerToHigher(Censista listCensista[], int lenCensista,
//		Flight listFlight[], int lenFlight, int flagByCodeActive) {
//	Censista auxCensista;
//	int resultOrder;
//	int i;
//	int j;
//	if (listCensista != NULL && lenCensista > 0 && listFlight != NULL
//			&& lenFlight > 0) {
//		do {
//			resultOrder = 1;
//			lenCensista--;
//			for (i = 0; i < lenCensista; i++) {
//				for (j = 0; j < lenFlight; j++) {
//					if (listCensista[i].isEmpty == TAKEN
//							&& listCensista[i + 1].isEmpty == TAKEN) {
//						if (flagByCodeActive) {
//							if (strcmp(listCensista[i].flyCode,
//									listCensista[i + 1].flyCode) < 0
//									&& strcmp(listFlight[j].status, "ACTIVO")
//											== 0) {
//								auxCensista = listCensista[i];
//								listCensista[i] = listCensista[i + 1];
//								listCensista[i + 1] = auxCensista;
//								resultOrder = 0;
//							}
//
//						} else {
//							if (strcmp(listCensista[i].lastName,
//									listCensista[i + 1].lastName) == 0) {
//								if (strcmp(listCensista[i].flyCode,
//										listCensista[i + 1].flyCode) > 0) {
//									auxCensista = listCensista[i];
//									listCensista[i] = listCensista[i + 1];
//									listCensista[i + 1] = auxCensista;
//									resultOrder = 0;
//								}
//							} else if (strcmp(listCensista[i].lastName,
//									listCensista[i + 1].lastName) > 0) {
//								auxCensista = listCensista[i];
//								listCensista[i] = listCensista[i + 1];
//								listCensista[i + 1] = auxCensista;
//								resultOrder = 0;
//							}
//						}
//					}
//				}
//
//			}
//
//		} while (resultOrder == 0);
//	}
//
//}
//
//void sortHigherToLower(Censista listCensista[], int lenCensista,
//		Flight listFlight[], int lenFlight, int flagByCodeActive) {
//	Censista auxCensista;
//	int resultOrder;
//	int i;
//	int j;
//	if (listCensista != NULL && lenCensista > 0 && listFlight != NULL
//			&& lenFlight > 0) {
//		do {
//			resultOrder = 1;
//			lenCensista--;
//			for (i = 0; i < lenCensista; i++) {
//				for (j = 0; j < lenFlight; j++) {
//					if (listCensista[i].isEmpty == TAKEN
//							&& listCensista[i + 1].isEmpty == TAKEN) {
//						if (flagByCodeActive) {
//							if (strcmp(listCensista[i].flyCode,
//									listCensista[i + 1].flyCode) > 0
//									&& strcmp(listFlight[j].status, "ACTIVO")
//											== 0) {
//								auxCensista = listCensista[i];
//								listCensista[i] = listCensista[i + 1];
//								listCensista[i + 1] = auxCensista;
//								resultOrder = 0;
//							}
//
//						} else {
//							if (strcmp(listCensista[i].lastName,
//									listCensista[i + 1].lastName) == 0) {
//								if (strcmp(listCensista[i].flyCode,
//										listCensista[i + 1].flyCode) < 0) {
//									auxCensista = listCensista[i];
//									listCensista[i] = listCensista[i + 1];
//									listCensista[i + 1] = auxCensista;
//									resultOrder = 0;
//								}
//							} else if (strcmp(listCensista[i].lastName,
//									listCensista[i + 1].lastName) < 0) {
//								auxCensista = listCensista[i];
//								listCensista[i] = listCensista[i + 1];
//								listCensista[i + 1] = auxCensista;
//								resultOrder = 0;
//							}
//						}
//					}
//				}
//
//			}
//
//		} while (resultOrder == 0);
//	}
//}

//int calculateAveragePrice(Censista list[], int len) {
//	int resultCalculate = -1;
//	float accumulatedPrice = 0;
//	float averagePrice = 0;
//	int sumCensistas = 0;
//	int sumCensistasUpAvgPrice = 0;
//	int i;
//
//	if (list != NULL && len > 0) {
//
//		if (checkAtLeastOneRegister(list, len) == 0) {
//			for (i = 0; i < len; i++) {
//				if (list[i].isEmpty == TAKEN) {
//					accumulatedPrice += list[i].price;
//					sumCensistas++;
//				}
//
//			}
//			averagePrice = utn_calculateAverage(accumulatedPrice, sumCensistas);
//
//			for (i = 0; i < len; i++) {
//				if (list[i].isEmpty == TAKEN && list[i].price > averagePrice) {
//					sumCensistasUpAvgPrice++;
//				}
//
//			}
//			printf("\n==================================================");
//			printf(
//					"\nTotal precios: $%.2f\n\nPromedio precios: $%.2f\n\nCantidad de pasajeros que superan el precio promedio: %d",
//					accumulatedPrice, averagePrice, sumCensistasUpAvgPrice);
//			printf("\n==================================================");
//			resultCalculate = 0;
//		}
//
//	}
//
//	return resultCalculate;
//}

int checkAtLeastOneRegister(Censista list[], int len) {
	int resultAtLeastOne = -1;
	int i;
	if (list != NULL && len > 0) {

		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == TAKEN) {
				resultAtLeastOne = 0;
				break;
			}
		}
	}
	return resultAtLeastOne;
}

#endif /* CENSISTA_C_ */
