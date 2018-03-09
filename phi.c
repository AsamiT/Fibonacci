//
//  fib_formtest.c
//  Fibonacci-XCode
//
//  Created by Asami on 3/8/18.
//  Copyright © 2018 New American Technologies. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define int_phi 1.618

int main() {
    
    int fibnum = 55; //fib(10)
    double fibplusone;
    fibplusone = int_phi * fibnum;
    printf("%f\n", fibplusone);
    
    fibplusone = round(fibplusone);
    fibnum = (int) fibplusone;
    
    printf("%d\n", fibnum);
    return 0;
}
