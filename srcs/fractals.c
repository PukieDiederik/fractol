#include "fractol.h"
#define MAX_ITER 100
#include "math.h"

int mandelbrot(double x_p, double y_p)
{
	int i;
	double x;
	double y;
	double temp;

	i = -1;
	while (++i < MAX_ITER)
	{
		if (x * x + y * y > 4)
			return(i);
		temp = x * x - y * y + x_p;
		y = 2 * x * y + y_p;
		x = temp;
	}
	return (i);
}

int burning_ship(double x_p, double y_p)
{
	int i;
	double x;
	double y;
	double temp;

	i = -1;
	while (++i < MAX_ITER)
	{
		if (x * x + y * y > 4)
			return(i);
		temp = x * x - y * y + x_p;
		y = fabs(2 * x * y) + y_p;
		x = temp;
	}
	return (i);
}