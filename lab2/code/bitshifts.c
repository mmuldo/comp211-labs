/* Matt Muldowney
 * Lab 2 2/6
 * bit shift
 *
 * multiplies by shifting bits
 */

#include <stdio.h>

int by2(int num) {
	return num << 1;
}

int byPow2(int num, int pow) {
	return num << pow;
}

int multiply(int num, int x) {
	return 0;
}

int main(void) {
	int num, pow;
	char another;

	do {
		printf("Enter a number and power: ");
		scanf(" %d %d", &num, &pow);

		printf("%d * 2^%d = %d\n", num, pow, byPow2(num, pow));
		
		printf("Another? [y/n]");
		scanf(" %c", &another);
	} while (another == 'y');

	return 0;
}
