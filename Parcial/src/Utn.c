/*
 * Utn.c
 *
 *  Created on: 17 may. 2022
 *      Author: agosb
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define BUFFER_SIZE 100

int utn_validateAlphabeticCharArray(char *array) {
	int isAlphabetic = 0;
	int i;
	if (array != NULL && strlen(array) > 0) {
		for (i = 0; i < strlen(array); i++) {
			if (isalpha(array[i]) == 0) {
				isAlphabetic = -1;
				break;
			}

		}
	} else {
		isAlphabetic = -1;
	}
	return isAlphabetic;
}

int utn_validateAlphanumericCharArray(char *array) {
	int isAlphanumeric = 0;
	int i;
	if (array != NULL && strlen(array) > 0) {
		for (i = 0; i < strlen(array); i++) {
			if (isalpha(array[i]) == 0 && isdigit(array[i] == 0)) {
				isAlphanumeric = -1;
				break;
			}
		}
	} else {
		isAlphanumeric = -1;
	}
	return isAlphanumeric;
}

int utn_validateArrayWithoutSpaces(char *array) {
	int isValid = 0;
	int hasSpace = 0;
	int i;
	if (array != NULL) {
		for (i = 0; i < strlen(array); i++) {
			if (array[i] == ' ' || array[i] == '\n') {
				hasSpace = 1;
				break;
			}
		}
		if (hasSpace > 0) {
			isValid = -1;
		}
	}
	return isValid;

}

int utn_validateInt(char *number) {
	int isNumber = 0;
	int i;
	if (number != NULL) {
		for (i = 0; i < strlen(number); i++) {
			if (!isdigit(number[i])) {
				isNumber = -1;
				break;
			}
		}
	}
	return isNumber;

}

int utn_validateFloat(char *number) {
	int isFloat = 0;
	int countDecimal = 0;
	int i;
	if (number != NULL) {
		if (utn_validateArrayWithoutSpaces(number) == 0) {
			for (i = 0; i < strlen(number); i++) {
				if (number[i] == ',' || number[i] == '.') {
					countDecimal++;
				} else {
					if (number[i] < '0' || number[i] > '9') {
						isFloat = -1;
						break;
					}
				}

			}
		};

		if (countDecimal > 1) {
			isFloat = -1;
		}
	}
	return isFloat;

}

int utn_getInt(int *pNumber, char *msg, char *errorMsg, int max, int min,
		int maxRetries) {

	char auxNumber[52];
	int stringToNumber = -2;
	int result;
	int validation = -2;
	result = -1;
	if (pNumber != NULL && max >= min && maxRetries >= 0) {
		do {
			printf("%s\n", msg);
			fflush(stdin);
			scanf("%[^\n]", auxNumber);
			validation = utn_validateInt(auxNumber);
			stringToNumber = atoi(auxNumber);
			if (validation == 0) {
				*pNumber = stringToNumber;
				result = 0;
				break;
			} else {
				*pNumber = -1;
				printf("%s\n", errorMsg);
			}
			maxRetries--;
		} while (maxRetries > 0);
	}

	return result;
}

int utn_getFloat(float *pNumber, char *msg, char *errorMsg, int max, int min,
		int maxRetries) {

	char auxNumber[100];
	float stringToFloat = 0;
	int result;
	int validation = 0;
	result = 0;

	if (pNumber != NULL && max >= min && maxRetries >= 0) {
		do {
			printf("%s\n", msg);
			fflush(stdin);
			scanf("%[^\n]", auxNumber);
			validation = utn_validateFloat(auxNumber);
			stringToFloat = atof(auxNumber);
			if (validation != 0 || stringToFloat < min || stringToFloat > max) {
				printf("%s\n", errorMsg);
				result = -1;
			} else {
				*pNumber = stringToFloat;
				result = 0;
				break;
			}
			maxRetries--;
		} while (maxRetries > 0);
	}

	return result;
}

int utn_getArrayCharAlphabetic(char *array, char *msg, char *errorMsg,
		int maxRetries) {

	char auxArray[52];
	int result = 0;
	if (array != NULL && maxRetries >= 0) {
		do {
			printf("%s\n", msg);
			fflush(stdin);
			scanf("%[^\n]", auxArray);
			if (utn_validateAlphabeticCharArray(auxArray) != 0
					|| utn_validateArrayWithoutSpaces(auxArray) != 0) {
				printf("%s\n", errorMsg);
				result = -1;
			} else {
				strcpy(array, auxArray);
				result = 0;
				break;
			}
			maxRetries--;
		} while (maxRetries > 0);
	}
	return result;
}

int utn_getArrayCharAlphanumeric(char *array, char *msg, char *errorMsg,
		int maxRetries) {

	char auxArray[52];
	int result = 0;

	if (array != NULL && maxRetries >= 0) {
		do {
			printf("%s\n", msg);
			fflush(stdin);
			scanf("%[^\n]", auxArray);
			if (utn_validateAlphanumericCharArray(auxArray) != 0
					|| utn_validateArrayWithoutSpaces(auxArray) != 0) {
				printf("%s\n", errorMsg);
				result = -1;
			} else {
				strcpy(array, auxArray);
				result = 0;
				break;
			}
			maxRetries--;
		} while (maxRetries > 0);
	}

	return result;
}

int utn_getIncrementalId(int idToIncrement) {
	int finalId;
	if (idToIncrement > 0) {
		idToIncrement++;
		finalId = idToIncrement;
	}
	return finalId;
}

void utn_showMenu(char msg[], char optionOne[], char optionTwo[],
		char optionThree[], char optionFour[], char optionFive[],
		char optionSix[], char optionSeven[], char optionEight[], char optionNine[]) {
	printf(
			"\n========================================\n %s\n                  Menu \n========================================\nIngrese una opcion: \n",
			msg);
	printf(
			"\n1) %s\n2) %s \n3) %s \n4) %s\n5) %s\n6) %s\n7) %s\n8) %s\n9) %s\n========================================",
			optionOne, optionTwo, optionThree, optionFour, optionFive,
			optionSix, optionSeven, optionEight, optionNine);
}

/*
 * Funcion para confirmar la operacion
 */

int confirmOperation(char msg[], char errorMsg[]) {
	int resultOperation = -1;
	int confirm;
	if (utn_getInt(&confirm, msg, errorMsg, 1, 0, 2) == 0) {
		if (confirm == 1) {
			resultOperation = 0;
		}
	} else {
		printf(
				"\nNo se ha podido confirmar la operación. Vuelva a intentarlo.");
	}
	return resultOperation;
}

/*
 * Función SUMAR
 */
float sumar(float primerNum, float segundoNum) {
	float total;
	total = (float) primerNum + segundoNum;
	return total;
}

/*
 * Función RESTAR
 */
float restar(float primerNum, float segundoNum) {
	float total;
	total = (float) primerNum - segundoNum;
	return total;
}

/*
 * Función MULTIPLICAR
 */
float multiplicar(float primerNum, float segundoNum) {
	float total;
	total = (float) primerNum * segundoNum;
	return total;
}

/*
 * Función DIVIDIR
 */
float dividir(float primerNum, float segundoNum) {

	float error = 0;
	float total = 0;
	if (segundoNum == 0) {
		return error; //Si el segundo operador ingresado es  0, no se puede realizar la operación.
	} else {
		total = (float) primerNum / segundoNum;
		return total;
	}
}

/*
 * Función FACTORIAL
 */
double factorial(double num) {
	double fact = 1;
	double error = 0;
	if (num == 0) {
		return fact;
	} else {
		if (((num - (int) num) == 0) && num >= 1) { //Chequeo para saber si el usuario ingresó un numero decimal.
			for (int i = 1; i <= num; i++) {
				fact = fact * i;
			}
			return fact;
		} else { //si ingresó un numero decimal devuelve error ya que no se puede calcular el factorial de un decimal.
			return error;
		}
	}

}

/*
 * Función PROMEDIO
 */
float utn_calculateAverage(float accumulatedValue, int qty) {
	float resultAverage = -1;
	if (accumulatedValue > 0 && qty > 0) {
		resultAverage = accumulatedValue / qty;
	}
	return resultAverage;
}
