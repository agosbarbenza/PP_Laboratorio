/*
 * Utn.h
 *
 *  Created on: 17 may. 2022
 *      Author: agosb
 */

#ifndef UTN_H_
#define UTN_H_

/** \brief Gets an incremental id
 *
 * \param idToIncrement int
 * \return int Return the incremented ID
 *
 */

int utn_getIncrementalId(int idToIncrement);

/** \brief Shows a menu with options
 *
 * \param msg[] char
 * \param optionOne[] char
 * \param optionOne[] char
 * \param optionTwo[] char
 * \param optionThree[] char
 * \param optionFour[] char
 * \param optionFive[] char
 * \return void
 *
 */
void utn_showMenu(char msg[], char optionOne[], char optionTwo[],
		char optionThree[], char optionFour[], char optionFive[], char optionSix[], char optionSeven[], char optionEight[], char optionNine[]);

/** \brief Validates if an array of char is alphabetic
 *
 * \param array[] char
 * \return int 0 if is alphabetic - -1 if it's not alphabetic
 *
 */
int utn_validateAlphabeticCharArray(char *array);
/** \brief Validates if an array of char is alphanumeric
 *
 * \param array[] char
 * \return int 0 if is alphanumeric - -1 if it's not alphanumeric
 *
 */
int utn_validateAlphanumericCharArray(char *array);
/** \brief Validates if an array of char is an int number
 *
 * \param number[] char
 * \return int 0 if is int - -1 if it's not int
 *
 */
int utn_validateInt(char *number);

/** \brief Validates if an array of char is a float number
 *
 * \param number[] char
 * \return int 0 if is float - -1 if it's not float
 *
 */
int utn_validateFloat(char *number);

/** \brief Gets an array of alphabetic chars
 *
 * \param array[] char
 * \param msg[] char
 * \param errorMsg[] char
 * \param maxRetries int
 * \return int 0 if the process was ok - -1 if the process was not ok
 *
 */
int utn_getArrayCharAlphabetic(char *array, char *msg, char *errorMsg, int maxRetries);
/** \brief Gets an array of alphanumeric chars
 *
 * \param array[] char
 * \param msg[] char
 * \param errorMsg[] char
 * \param maxRetries int
 * \return int 0 if the process was ok - -1 if the process was not ok
 *
 */
int utn_getArrayCharAlphanumeric(char *array, char *msg, char *errorMsg, int maxRetries);
/** \brief Gets an int number
 *
 * \param pNumber* int
 * \param msg[] char
 * \param errorMsg[] char
 * \param max int
 * \param min int
 * \param maxRetries int
 * \return int  0 if the process was ok - -1 if the process was not ok
 *
 */
int utn_getInt(int *pNumber, char *msg, char *errorMsg, int max,
		int min, int maxRetries);
/** \brief Gets a float number
 *
 * \param pNumber* float
 * \param msg[] char
 * \param errorMsg[] char
 * \param max int
 * \param min int
 * \param maxRetries int
 * \return int  0 if the process was ok - -1 if the process was not ok
 *
 */
int utn_getFloat(float *pNumber, char *msg, char *errorMsg, int max, int min,
		int maxRetries);
/** \brief Validates if an array of chars hasn't spaces
 *
 * \param array[] char
 * \return int  0 if the array hasn't spaces - -1 if the array has spaces
 *
 */
int utn_validateArrayWithoutSpaces(char *array);
/** \brief Determines if an operation is confirmed
 *
 * \param msg[] char
 * \param errorMsg[] char
 * \return int  0 if the operation is confimed - -1 if the operation is not confirmed
 *
 */
int confirmOperation(char *msg, char *errorMsg);
/** \brief Calculates an average
 *
 * \param accumulatedValue float
 * \param qty y
 * \return int <> -1 calculated average - -1 if the average was not calculated
 *
 */
float utn_calculateAverage(float accumulatedValue, int qty);

#endif /* UTN_H_ */
