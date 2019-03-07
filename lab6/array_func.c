/* Matt Muldowney
 * Lab 6 on 3/6/2019
 *
 * array_func.c
 *
 */

#include "array_func.h"

int bin_search(char A[], char x, int l, int h) {
	if (l > h) {
		return -1;
	}

	int m = (l+h)/2;
	if (A[m] == x) {
		return m;
	}

	return (A[m] > x) ? bin_search(A, x, l, m-1) : bin_search(A, x, m+1, h);
}

/* returns true if the subarray [0, n-1] of A contains no repeats
 * 	   false otherwise.
 */
bool all_distinct(char A[], int n) {
	for (int i=0; i < n; i++) {
		if (bin_search(A, A[i], i+1, n-1) != -1) {
		       return false;
		}
	}		

	return true;
}

/* returns number of distinct characters in A.
 */
int count_distinct(char A[], int n) {
	int count = 1;
	char curr_char = A[0];
	for (int i=1; i<n; i++) {
		if (A[i] != curr_char) {
			curr_char = A[i];
			count++;
		}
	}

	return count;
}

/* Assigns only one copy of each element of A to B
 */
void remove_duplicates(char A[], int n, char B[], int m) {
	char curr_char = A[0];
	B[0] = A[0];
	int j=1;
	for (int i=1; i<n; i++) {
		if (A[i] != curr_char) {
			curr_char = A[i];
			B[j++] = A[i];
		}
	}
}
