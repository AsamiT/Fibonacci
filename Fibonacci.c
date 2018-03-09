/*
 *
 * Fibonacci.c
 * Fibonacci algorithms for Project #2
 * Robert Maloy (2612)
 * 22 Feb 2018
 *
 */

/* "You say we've gotta look at the bright side,
 I say 'Maybe, if you want to go blind', but my eyes are getting too dark now,
 Boy you've never seen my mind." */

#define MAX_Huge_INTEGER 200

#include <limits.h> // maximum unsigned value is 4,294,967,295 as defined by macOS 10.13
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Fibonacci.h"

/** This function, intpow, will return an integer version of the pow() standard function in C. **/
unsigned long long int intpow(unsigned long long int base, int power) {
    unsigned long long int result = 1;
    for(int count = 0; count < power; count++) result *= base;
    return result;
}

HugeInteger *parseString(char *str) {
    if (!str) {
        return NULL;
    }
    struct HugeInteger *a = malloc(sizeof(struct HugeInteger));
    if (str[0] == '\0') {
        str = "0";
    }
    a->length = strlen(str);
    a->digits = malloc(sizeof(int) * a->length);
    /* create a new item from structure HugeInteger,
    assign to a->length the string length of str + /0,
    and then malloc a->digits at the size of an integer * the length. */
        char *mysub = malloc(sizeof(char)*2); //temporary buffer which holds one character from str.
        mysub[1] = '\0';
        for (int i = 0; i < strlen(str); i++) {
            strncpy(mysub, &str[(strlen(str)-1)-i], 1); //copy the data over to str[i]
            int x = (int) strtol(mysub, NULL, 10); //convert to integer
            a->digits[i] = x; //push to a->digits
        }
    return a;
}

HugeInteger *hugeDestroyer(HugeInteger *p) {
    /*  as far as I'm aware, this is literally all that is necessary to free memory.
        Implementation of a debug function which calls _msize(p) shows that the memory
        allocation for this goes from 8 to -1, thus becoming a null value. */
    free(p);
    return NULL;
}

int chkint(unsigned int n) {

    if (n == 0) {
        return n; //if n is zero, then we're okay.
    }

    //otherwise, forget it and kick null back to the main.
    return -1;
}

HugeInteger *parseInt(unsigned int n) {;
    struct HugeInteger *a = malloc(sizeof(struct HugeInteger)); //create new structure
    unsigned long int tempint = n; //assign the value of n to a temporary long int
    unsigned long int int_len = 0; //create new marker for our length

    if (!n) {
        chkint(n); //check n if the compiler thinks it's a null value.
    }

    if (n == 0) { //if n = 0
        a->length=1;
        a->digits=malloc((sizeof(int) * a->length+1));
        a->digits[0] = n;
    }
    else { //if n > 0
        while (tempint > 0) { //execute a while loop that counts up the length of our integer number
            tempint /= 10;
            int_len++;
        }
        a->length=int_len; //assign length
        a->digits= malloc(sizeof(int) * a->length+1); //dynamically create our digits array
        unsigned long int digit; //declare integer

        for (int i = 0; i <= a->length; i++) {
            digit = n % 10;
            a->digits[i] = digit;
            n /= 10;
        }
    }
    return a;

}

void correctHugeIntegerLength(HugeInteger *huge) {
        for(int i = MAX_Huge_INTEGER-1; i > -1; i--) { // determine proper length;
        if(huge->digits[i] != 0) {
            //printf("DEBUG: digit @ %i = %i\n", i+1, huge->digits[i]);
            huge->length = i + 1;
            return;
        }
    }
}

HugeInteger *hugeAdd(HugeInteger *a, HugeInteger *b) {
    /** I'd rather be locked in a closet with a Commodore 64
        and have to program in 6502 Assembler for eight hours than do this. **/
    HugeInteger *result = (HugeInteger *) malloc(sizeof(HugeInteger));
    result->digits = (int *) calloc(sizeof(int), MAX_Huge_INTEGER); //warn: magic number -- check the preprocessor definitions!
    for(int i = 0; i < MAX_Huge_INTEGER; i++) {
        int nextA = (i < a->length)? a->digits[i] : 0;
        int nextB = (i < b->length)? b->digits[i] : 0;
        result->digits[i] += (nextA + nextB);
        if(result->digits[i] >= 10) {
            result->digits[i] -= 10;
            result->digits[i+1]++;
        }
    }
    correctHugeIntegerLength(result);
    return result; //take the array back I don't want it
}f

unsigned int *toUnsignedInt(HugeInteger *p) {
    unsigned int *x = malloc(sizeof(unsigned int));
    unsigned int hold = 0;
    if (p == NULL) return NULL; //if p is a null pointer, then don't do anything
    if (p->length > 10) return NULL; //if p->length exceeds length of UINT_MAX, then don't do it.
    else {
        for(int i = (p->length-1); i >= 0; i--) {
            hold += p->digits[i] * intpow(10, i);
        }
        *x=hold;
        return x;
    }
}

HugeInteger *fib(int n) {
    HugeInteger *z;
    HugeInteger *x;
    HugeInteger *result;
    switch(n) {
        case 1: case 0:
            return parseInt(n);
        default:
            z=fib(n-2);
            x=fib(n-1);
            result = hugeAdd(z,x);
            hugeDestroyer(z);
            hugeDestroyer(x);
            return result;
    }
}

double difficultyRating(void) {
    double diff = 5.0; //extremely difficult, to the point of medically inducing panic and anxiety attacks.
    return diff;
}


double hoursSpent(void) {
    int hrs = 120; //way too many hours dude, i have other things to do than this
    return hrs;

}
