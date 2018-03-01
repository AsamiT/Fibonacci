//
//  temp_store.c
//  Fibonacci-XCode
//
//  Created by Asami on 3/1/18.
//  Copyright © 2018 New American Technologies. All rights reserved.
//

#include <stdio.h>

HugeInteger *hugeAdd(HugeInteger *p, HugeInteger *q) {
    /** This function creates a new array based off of HugeInteger,
     along with some variables to do number management. After creating unsigned
     long long integers with the number stored in each array (p and q), it creates
     a sum number (int_res), which is then pushed to the new array. **/
    struct HugeInteger *array = malloc(sizeof(struct HugeInteger));
    unsigned long long int a_add = 0;
    unsigned long long int b_add = 0;
    unsigned long long int int_res = 0;
    for (int x=0; x<=p->length; x++) {
        a_add += (p->digits[x] * intpow(10,x)); //see intpow() above for function purpose
    }
    for (int z=0; z<=q->length; z++) {
        b_add += (q->digits[z] * intpow(10,z)); //see intpow() for more info
    }
    int_res = a_add + b_add; //sum storage
    unsigned long long int temp_int = int_res; //temporary integer storage
    int count = 0;
    while (temp_int != 0) {
        temp_int /=10;
        count++;
    }
    array->length = count; //push length of array to count to keep track
    array->digits= malloc(sizeof(int) * array->length+1); //dynamically create our digits array
    for (int i = 0; i < array->length; i++) {
        temp_int = int_res % 10;
        array->digits[i] = temp_int;
        int_res /= 10;
    }
    return array; //give the array back, i don't want it
}
