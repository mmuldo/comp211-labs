/*
 * Spring 2019, COMP 211: Lab 2
 * Examples of core C programming instructions
 *
 */

#include <stdio.h>

int main(void) {

    /*
     * Arithmetic operations
     */
    int u = 5 + 2; // 7
    int v = 10 - 3; // = 7
    int w = 5 / 2; // = 2
    double x = 5 / 2; // = 1.5
    int y = 5 * 2; // = 10

    /*
     * Modulus operator in C: %
     */
    int z = 5 % 2; // = 1

    printf("------------------------------------------\n");
    printf("u=%d, v=%d, w=%d, x=%f, y=%d, z=%d\n", u, v, w, x, y, z);

    /*
     * Conditional
     */
    printf("------------------------------------------\n");
    printf("Flow control statements\n");
    if (u == v && u == y) {
        printf("%d == %d and %u == %d\n", u, v, u, y);
    } else if (u == v || u == y) {
        printf("%d == %d or %u == %d\n", u, v, u, y);
    } else if (u != v) {
        printf("%d != %d\n", u, v);
    } else {
        printf("nothing else\n");
    }

    /*
     * Loops
     */
    printf("------------------------------------------\n");
    printf("For loop\n");

    // i++ <-> i = i+1
    // i-- <-> i = i-1
    //
    for (int i = 0; i < 10; i++) {
        printf("i = %d\n", i);
    }

    printf("------------------------------------------\n");
    printf("While loop\n");

    int j = 10;
    while (j > 0) {
        j--;
        printf("j = %d\n", j);
    }

    printf("------------------------------------------\n");
    printf("Do while loop\n");

    j = 10;
    do {
        j--;
        printf("j = %d\n", j);
    } while (j > 0);


    /*
     * Bit shift
     */
    unsigned int b = 10;

    printf("------------------------------------------\n");
    printf("b = %u, b shifted left 2 bits = %u\n", b, b << 2);


}
