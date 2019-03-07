/* Matt Muldowney
 * Lab 6 on 3/6/2019
 *
 * tests.c
 *
 */

#include "array_func.h"

bool test_all_distinct(char A[], int n, bool exp) {
	return all_distinct(A, n) == exp;
}

bool test_count_distinct(char A[], int n, int exp) {
	return (count_distinct(A, n) == exp);
}

void test_remove_duplicates(char A[], int n, char B[], int m) {
	remove_duplicates(A, n, B, m);
	for (int i=0; i<m; i++) {
		printf("%c, ", B[i]);
	}
	printf("\n");
}

int main(void) {
	char A[] = {'a', 'a', 'b', 'b', 'b', 'c'};
	int m = count_distinct(A, 6);
	char B[m];

	test_remove_duplicates(A, 6, B, m);
	return 0;
}
