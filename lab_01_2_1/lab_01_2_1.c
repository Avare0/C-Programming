#include <stdio.h>
#include <math.h>

int main()
{
	double x1, x2, x3, y1, y2, y3;
	double a, b, c, p;
	
	puts("Input integer coordinates of the point (separate them by space): ");
	scanf("%lf %lf", &x1, &y1);
	puts("Input integer coordinates of the point (separate them by space): ");
	scanf("%lf %lf", &x2, &y2);
	puts("Input integer coordinates of the point (separate them by space): ");
	scanf("%lf %lf", &x3, &y3);

	a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
	c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
	 
	p = a + b + c;

	printf("Square of the triangle is %lf", p);

	return 0;
}