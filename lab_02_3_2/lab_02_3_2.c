#include <stdio.h>
#include <math.h>
#define EPS 0.0000001
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main()
{
	double x1, y1, x2, y2, xa, ya;
	int ck1, ck2, ck3;
	int result;

	puts("Input the coordinates of the first point of the line \
	(separate them by space):");
	ck1 = scanf("%lf %lf", &x1, &y1);
	puts("Input the coordinates of the second point of the line \
	(separate them by space):");
	ck2 = scanf("%lf %lf", &x2, &y2);
	puts("Input the coordinates of the third point to analyse it \
	(separate them by space)");
	ck3 = scanf("%lf %lf", &xa, &ya);
	
	double a = (xa - x1) * (y2 - y1) - (ya - y1) * (x2 - x1);
	if (ck1 != 2 || ck2 != 2 || ck3 != 2 || (fabs(x1 - x2) < EPS && 
	    fabs(y1 - y2) < EPS))
		return EXIT_FAILURE;

	if (fabs(a) < EPS)
		result = 1;
	else
	{
		if (a < -EPS)
			result = 0;
		else
			result = 2;
	};

	printf("%d", result);

	return EXIT_SUCCESS;
}