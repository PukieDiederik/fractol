/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:24:08 by drobert-          #+#    #+#             */
/*   Updated: 2022/05/12 14:07:21 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"
#include "mlx.h"

int	mandelbrot(double x_p, double y_p, t_data *data)
{
	unsigned int	i;
	double			x;
	double			y;
	double			temp;

	i = -1;
	x = 0;
	y = 0;
	while (++i < data->max_iter)
	{
		if (x * x + y * y > 4)
			return (i);
		temp = x * x - y * y + x_p;
		y = 2 * x * y + y_p;
		x = temp;
	}
	return (i);
}

int	julia(double x, double y, t_data *data)
{
	unsigned int	i;
	double			temp;

	i = -1;
	while (++i < data->max_iter)
	{
		if (x * x + y * y > 4)
			return (i);
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
		mlx_mouse_get_pos(data->window, &x, &y);
		if (y < 0 || y > (int)data->size || x < 0 || x > (int)data->size)
			return ;
		data->m_x = (double)x / (data->size >> 1) - 1;
		data->m_y = (double)y / (data->size >> 1) - 1;
		data->scale = 2.5;
		data->x_offset = -1.25;
		data->y_offset = -1.25;
		render_fractal(data);
	}
}

int	burning_ship(double x_p, double y_p, t_data *data)
{
	unsigned int	i;
	double			x;
	double			y;
	double			temp;

	i = -1;
	x = 0;
	y = 0;
	while (++i < data->max_iter)
	{
		if (x * x + y * y > 4)
			return (i);
		temp = x * x - y * y + x_p;
		y = fabs(2 * x * y) + y_p;
		x = temp;
	}
	return (i);
}
