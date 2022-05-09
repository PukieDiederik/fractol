#include "fractol.h"
#include "math.h"
#include "mlx.h"

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
		y = 2 * x * y + data->m_y;
		x = temp + data->m_x;
	}
	return (i);
}

void	update_julia_mouse(t_data *data)
{
	int	x;
	int	y;

	if (data->fractal == julia)
	{
		mlx_mouse_get_pos(data->mlx, data->window, &x, &y);
		data->m_x = (double)x / (data->size >> 1) - 1;
		data->m_y = (double)y / (data->size >> 1) - 1;
		data->scale = 2.5;
		data->x_offset = -1.25;
		data->y_offset = -1.25;
		render_fractal(data);
	}
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