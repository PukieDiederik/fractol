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
#include "mlx.h"

int get_color_from_index(unsigned int color_i)
{
	const int color_arr[] = { 0x00000000, 0x0099d98c,
							  0x0003071e, 0x006b9080,
							  0x00ffffff, 0x001a759f,
							  0x00ffba08, 0x00f6fff8
			};
	return (color_arr[color_i]);
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
			color = get_color(get_color_from_index(data->color_i), get_color_from_index(data->color_i + MAX_COLORS), fractal, data->max_iter);
			img_put_pixel(data->img, x, y, color);
		}
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img->img, 0, 0);
}
