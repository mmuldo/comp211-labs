/* Matt Muldowney
 * Lab 2 (2/6)
 * Leap year
 *
 * Tells user if input year is a leap year
 */

#include <stdio.h>
#include <stdbool.h>

int isLeapYear(int year);

int isLeapYear(int year) {
	return (!(year % 4) && !(!(year % 100) && (year % 400))) ? 1 : 0;
}

int main(void) {
	int year;
	char checkAnother;



	do {
		printf("Enter a year: ");
		scanf(" %d", &year);

		if (isLeapYear(year)) {
			printf("%d is a leap year\n", year);
		} else {
			printf("%d is not a leap year\n", year);
		}

		printf("Would you like to check another year? [y/n] ");
		scanf(" %c", &checkAnother);
	} while (checkAnother == 'y');

	return 0;
}
