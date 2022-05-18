/*
 * Censista.h
 *
 *  Created on: 17 may. 2022
 *      Author: agosb
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	int age;
	FechaNacimiento dateOfBirth;
	Direccion address;
	int isEmpty;
}Censista;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Censista* Pointer to array of Censistas
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initCensistas(Censista [], int );


/** \brief add in a existing list of Censistas the values received as parameters
* in the first empty position
* \param list Censista*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typeCensista int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addCensista(Censista listCensista[], int lenCensista, int id, char name[],
		char lastName[], int age, FechaNacimiento date, Direccion address);

/** \brief Gets Censista data from user and adds in a existing list of Censistas the values received as parameters
 * in the first empty position
 * \param CensistaList* Censista
 * \param CensistaLen int
 * \param flightList* Flight
 * \param flightLen int
 * \param incrementalId *int
 * \param name[] char
 * \param lastName[] char
 * \param price float
 * \param flyCode[] char
 * \param typeCensista *int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int getCensistaData(Censista CensistaList[], int CensistaLen,
		int *incrementalId, char name[], char lastName[], int *age,
		FechaNacimiento date, Direccion address);
/** \brief find a Censista by Id en returns the index position in array.
*
* \param list Censista*
* \param len int
* \param id int
* \return Return Censista index position or (-1) if [Invalid length or
NULL pointer received or Censista not found]
*
*/
int findCensistaById(Censista list[], int len,int id);

/** \brief Remove a Censista by Id (put isEmpty Flag in 1)
*
* \param list Censista*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a Censista] - (0) if Ok
*
*/

int removeCensista(Censista list[], int len,int id);

/** \brief print the content of one Censista
 *
 * \param struct one Censista
 * \return int
 *
 */
void printCensista(Censista Censista);



/** \brief print the content of Censistas array
*
* \param listCensista Censista*
* \param lenCensista int
* \param listFlight Flight*
* \param lenFlight int
* \param onlyActive int
* \return int
*
*/
int printCensistas(Censista listCensista[], int lenCensista);

/** \brief Finds an index where isEmpty equals EMPTY
 *
 * \param list Censista*
 * \param len int
 * \return int (-1) if Error, int index if OK
 *
 */
int findEmptyIndex(Censista list[], int len);

/** \brief Hardcodes a Censista's array with 15 Censistas
 *
 * \param list Censista*
 * \param len int
 * \return void
 *
 */
void hardCodeCensistas(Censista list[], int len);

/** \brief Shows a menu and gives the chance to user to pick a field to modify
 *
 * \param void
 * \return void
 *
 */
void subMenuModify(void);


/** \brief Modifies a field from a Censista
 *
 * \param list Censista*
 * \param len int
 * \param id int
 * \return int (-1) if Error, 0 if OK
 *
 */
int modifyCensista(Censista list[], int len, int id);

/** \brief Sort the elements in the array of Censistas, the argument order
indicate UP or DOWN order
 *
 * \param listCensista Censista*
 * \param lenCensista int
 * \param listFlight Flight*
 * \param lenFlight int
 * \param order int [1] indicates UP - [0] indicates DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
//int sortCensistas(Censista listCensista[], int lenCensista,
//		Flight listFlight[], int lenFlight, int order, int flagByCodeActive);

/** \brief Sort the elements in the array of Censistas from down to up
 *
 * \param listCensista Censista*
 * \param lenCensista int
 * \param listFlight Flight*
 * \param lenFlight int
 * \param flagByCodeActive int
 * \return void
 *
 */
//void sortLowerToHigher(Censista listCensista[], int lenCensista,
//		Flight listFlight[], int lenFlight, int flagByCodeActive);

/** \brief Sort the elements in the array of Censistas from up to down
 *
 * \param listCensista Censista*
 * \param lenCensista int
 * \param listFlight Flight*
 * \param lenFlight int
 * \param flagByCodeActive int
 * \return void
 *
 */
//void sortHigherToLower(Censista listCensista[], int lenCensista,
//		Flight listFlight[], int lenFlight, int flagByCodeActive);


/** \brief Shows submenu giving the user inform options
 *
 * \param void
 * \return no
 *
 */

void subMenuInform(void);

/** \brief Shows a list of fly codes
 *
 * \param void
 * \return void
 *
 */

void showFlyCodes(void);

/** \brief Shows submenu giving the user the chance to pick order criteria
 *
 * \param void
 * \return no
 *
 */
void subMenuOrderCriteria(void);

/** \brief Calculates the average plane ticket price of an array of Censistas
 *
 * \param list Censista*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
//int calculateAveragePrice(Censista list[], int len);

/** \brief Checks if there is at least one Censista on the database
 *
 * \param list Censista*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int checkAtLeastOneRegister(Censista list[], int len);

#endif /* CENSISTA_H_ */
