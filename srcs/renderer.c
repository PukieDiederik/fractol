/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:43:55 by drobert-          #+#    #+#             */
/*   Updated: 2022/05/06 12:48:50 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"
#include "libft.h"
#include "mlx.h"

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	lerp(unsigned int a, unsigned int b, double t)
{
	return ((int)((1 - t) * (double)a + t * (double)b));
}

unsigned int	get_color(unsigned int c1, unsigned int c2, int i, int max)
{
	unsigned int	c;

	c = ((lerp(c1 >> 16 & 0xff, c2 >> 16 & 0xff, (float)i / (float)max)) << 16)
		| ((lerp(c1 >> 8 & 0xff, c2 >> 8 & 0xff, (float)i / (float)max)) << 8)
		| (lerp(c1 & 0xff, c2 & 0xff, (float)i / (float)max));
	return (c);
}

void	render_fractal(t_data *data)
{
	unsigned int	x;
	unsigned int	y;
	int				fractal;
	unsigned int	color;

	x = -1;
	while (++x < data->size)
	{
		y = -1;
		while (++y < data->size)
		{
			fractal = data->fractal(((double)x / data->size)
					* data->scale + data->x_offset,
					((double)y / data->size)
					* data->scale + data->y_offset, data);
			color = get_color(0x00000000, 0x00ffffff, fractal, data->max_iter);
			img_put_pixel(data->img, x, y, color);
		}
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img->img, 0, 0);
}
