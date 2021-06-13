#ifndef __HASH_FUNCTIONS__H
#define __HASH_FUNCTIONS__H

#define INT_HASH	10
#define	STRING_HASH	8497

#include <string>

/* Basic hash function for integer keys. */
unsigned int hashingFunction(int x){
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

#endif // __HASH_FUNCTIONS__H