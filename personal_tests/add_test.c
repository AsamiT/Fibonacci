
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../Fibonacci.h"

// print a HugeInteger (without a newline character)
void hugePrint(HugeInteger *p)
{
	int i;

	if (p == NULL || p->digits == NULL)
	{
		printf("(null pointer)");
		return;
	}

	for (i = p->length - 1; i >= 0; i--)
		printf("    %d", p->digits[i]);
    printf("\n");
}

int main(void)
{
	int i;
	HugeInteger *p, *q, *r;

	// calculate INT_MAX + 1
	p = parseInt(UINT_MAX);
    q = parseInt(1);
	r = hugeAdd(p, q);

	// print result of INT_MAX + 1 with HugeIntegers
	hugePrint(p);
	printf(" + \n");
	hugePrint(q);
	printf(" = \n");
	hugePrint(r);
	printf("\n\n");

	// free memory
	hugeDestroyer(p);
	hugeDestroyer(q);
	hugeDestroyer(r);

	return 0;
}
