#include "fractol.h"
#include "math.h"

int mandelbrot(double x_p, double y_p, t_data *data)
{
	unsigned int i;
	double x;
	double y;
	double temp;

	i = -1;
	while (++i < data->max_iter)
	{
		if (x * x + y * y > 4)
			return(i);
		temp = x * x - y * y + x_p;
		y = 2 * x * y + y_p;
		x = temp;
	}
	return (i);
}

int julia(double x, double y, t_data *data)
{
	unsigned int i;
	double temp;

	i = -1;
	while (++i < data->max_iter)
	{
		if (x * x + y * y > 256)
			return(i);
		temp = x * x - y * y;
		y = 2 * x * y + 0.156;
		x = temp + -0.8;
	}
	return (i);
}

int burning_ship(double x_p, double y_p, t_data *data)
{
	unsigned int i;
	double x;
	double y;
	double temp;

	i = -1;
	while (++i < data->max_iter)
	{
		if (x * x + y * y > 4)
			return(i);
		temp = x * x - y * y + x_p;
		y = fabs(2 * x * y) + y_p;
		x = temp;
	}
	return (i);
}