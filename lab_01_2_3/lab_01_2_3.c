#include <stdio.h>
#include <math.h>

int main() 
{
	double r1, r2, r3;
	double r0;

	puts("Input resistance values(separate the by space): ");
	scanf("%lf %lf %lf", &r1, &r2, &r3);

	r0 = (r1 * r2 * r3) / (r1 * r2 + r2 * r3 + 
		r1 * r3);

	printf("Total resistance of the electrical circuit is %lf", r0);
	
	return 0;
}