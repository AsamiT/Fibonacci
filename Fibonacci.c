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

#include <limits.h> // maximum unsigned value is 4,294,967,295 as defined by macOS 10.13
#include <malloc.h> // used for debugging. Don't remove!
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Fibonacci.h"

HugeInteger *parseString(char *str) {
    if (!str) {
        return NULL; //if str is not defined, then return NULL
    }

    struct HugeInteger *a = malloc(sizeof(struct HugeInteger));
    a->length=strlen(str)+1;
    a->digits = malloc(sizeof(int) * a->length);
    /* create a new item from structure HugeInteger,
    assign to a->length the string length of str + /0,
    and then malloc a->digits at the size of an integer * the length. */
//
//    for (int i = 0; i < a->length-1; i++) {
//        c = str[i];
//        fubar = atoi(c);
//        a->digits[i] = fubar;
//        printf("%d\n", a->digits[i]);
//    }

    char *x = "12345";
    char *y = &x[2];
    int z = strtol(y, &y, 10);
    printf("%d\n", z);


//
//    for (int i = 0; i < a->length; i++) {
//        a->digits[i] = str[i];
//        printf("%d\n", a->digits[i]);
//    }

    return a;
}

HugeInteger *hugeDestroyer(HugeInteger *p) {
    //null
}

HugeInteger *parseInt(unsigned int n) {;
    //null
}

HugeInteger *hugeAdd(HugeInteger *p, HugeInteger *q) {
    //null
}


unsigned int *toUnsignedInt(HugeInteger *p) {
    //null
}


HugeInteger *fib(int n) {
    //null
}


double difficultyRating(void) {
    double diff = 5.0;
}


double hoursSpent(void) {
    int hrs = 40;

}



