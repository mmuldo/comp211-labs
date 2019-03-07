/* Matt Muldowney
 * Lab 3 (2/13)
 * name.c
 *
 * Reads in user's first name, then last name, then prints full name
 */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50

int readstr(char * str, int length) {
	fgets(str, length, stdin);

	str[strlen(str)-1] = '\0';

	return 0;
}

int copyarr(char * dest, char * src, int start, int length) {
	for (int i = 0; i < length; i++) {
		dest[start + i] = src[i];
	}

	return 0;
}

int main(void) {
	char firstName[MAX_LENGTH], lastName[MAX_LENGTH], fullName[MAX_LENGTH*2];

	printf("Enter your first name: ");
	readstr(firstName, MAX_LENGTH);
	printf("Enter your last name: ");
	readstr(lastName, MAX_LENGTH);

	copyarr(fullName, firstName, 0, strlen(firstName));
	copyarr(fullName, lastName, strlen(firstName) + 1, strlen(lastName));
	fullName[strlen(firstName)] = ' ';

	printf(fullName);
	printf("\n");

	return 0;
}
