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

int julia(double x, double y)
{

//	zx = scaled x coordinate of pixel # (scale to be between -R and R)
//# zx represents the real part of z.
//	zy = scaled y coordinate of pixel # (scale to be between -R and R)
//# zy represents the imaginary part of z.
//
//	iteration = 0
//	max_iteration = 1000
//
//	while (zx * zx + zy * zy < R**2  AND  iteration < max_iteration)
//	{
//		xtemp = zx * zx - zy * zy
//		zy = 2 * zx * zy  + cy
//		zx = xtemp + cx
//
//		iteration = iteration + 1
//	}
//
//	if (iteration == max_iteration)
//		return black;
//	else
//		return iteration;

	int i;
	double temp;

	i = -1;
	while (++i < MAX_ITER)
	{
		if (x * x + y * y > 256)
			return(i);
		temp = x * x - y * y;
		x = 2 * x * y + 0.156;
		y = temp + -0.8;
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