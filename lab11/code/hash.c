/* COMP 211, Spring 2019
 * Lab 11
 *
 * Sets and hash tables
 */

#include <stdlib.h>

#include "set.h"

unsigned int hash(unsigned int key) {
    return key % NUM_BUCKET;
}

