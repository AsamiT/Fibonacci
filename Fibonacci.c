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
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Fibonacci.h"

/** This function, intpow, will return an integer version of the pow() standard function in C. **/
int intpow(int base, int power) {
    int result = 1;
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
    a->length=strlen(str);
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
        return n;
    }

    else {
        return NULL;
    }

}

HugeInteger *parseInt(unsigned int n) {;
    struct HugeInteger *a = malloc(sizeof(struct HugeInteger)); //create new structure
    unsigned long int tempint = n; //assign the value of n to a temporary long int
    unsigned long int int_len = 0; //create new marker for our length
    if (!n) {
        chkint(n);
    }
    if (n == 0) {
        a->length=1;
        a->digits=malloc((sizeof(int) * a->length+1));
        a->digits[0] = n;
    }
    else {
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

HugeInteger *hugeAdd(HugeInteger *p, HugeInteger *q) {
    unsigned long long int *array;
    unsigned long long int hold = 0;
    int carry = 0;
    *array = malloc(sizeof(unsigned long long int));
    if ((p->length) > (q->length)) {
        printf("p > q\n");
        return NULL;
    }
    else {
        printf("q >= p\n");
        return NULL;
    }
}


unsigned int *toUnsignedInt(HugeInteger *p) {
    unsigned int *x;
    x = malloc(sizeof(unsigned int));
    unsigned int hold = 0;

    if (p == NULL) { //if p is a null pointer, then don't do anything
        return NULL;
    }
    if (p->length > 10) {
        return NULL;
    } //if p->length exceeds length of UINT_MAX, then don't do it.

    else {
        for(int i = (p->length-1); i >= 0; i--) {
         hold += p->digits[i] * intpow(10, i);
        }
        *x=hold;
        return x;
    }
}


HugeInteger *fib(int n) {
    return NULL;
}


double difficultyRating(void) {
    double diff = 5.0;
    return diff;
}


double hoursSpent(void) {
    int hrs = 40;
    return hrs;

}



