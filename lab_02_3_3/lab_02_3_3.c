#include <stdio.h>
#include <math.h>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define EPS_0 0.0000001

int main()
{
	double eps, x1, t, s;
	int l = 1;
	double relative, absolute;
	int chk1, chk2;
	
	
	puts("Input x to calculate the result of the function:");
	chk1 = scanf("%lf", &x1);
	puts("Input the accuracy:");
	chk2 = scanf("%lf", &eps);

	s = 0;
	t = x1;
	
	if (chk1 == 0 || chk2 == 0 || fabs(x1) > 1 || eps < 0 || eps > 1 || 
	    fabs(x1) < EPS_0 || x1 == 0)
	{
		printf("Error");
		return EXIT_FAILURE;
	}

	while (fabs(t) / l > eps)
	{
		s += t / l;
		t *= -1 * x1 * x1;
		l += 2;
	}
	
	s += t / l;
	double arc = atan(x1);
	
	absolute = fabs(s - arc);
	relative = fabs(absolute / arc);
	
	printf("Approximate function value: %lf \n", s);
	printf("Exact value of the function: %lf \n", arc);
	printf("Absolute error: %lf \n", absolute);
	printf("Relative error: %lf \n", relative);
	
	return EXIT_SUCCESS;
}