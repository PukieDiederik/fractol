/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:29:29 by drobert-          #+#    #+#             */
/*   Updated: 2022/05/12 12:11:58 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "stdlib.h"
#include "fractol.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->img = malloc(sizeof(t_img_data));
	if (!data->img)
	{
		free(data);
		return (0);
	}
	data->window = 0;
	data->img->img = 0;
	data->max_iter = 100;
	data->scale = 2.5;
	data->x_offset = -1.25;
	data->y_offset = -1.25;
	data->color_i = 0;
	return (data);
}

t_data	*init(int size)
{
	t_data	*data;

	data = init_data();
	if (!data)
		exit(0);
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data->img);
		free(data);
		exit(0);
	}
	data->window = mlx_new_window(data->mlx, size, size, "Fractol");
	if (!data->window)
		exit_clean(data);
	data->img->img = mlx_new_image(data->mlx, size, size);
	if (!data->img->img)
		exit_clean(data);
	data->img->addr = mlx_get_data_addr(data->img->img,
			&data->img->bits_per_pixel,
			&data->img->line_length, &data->img->endian);
	data->size = size;
	return (data);
}

int	exit_clean(t_data *data)
{
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->img && data->img->img)
		mlx_destroy_image(data->mlx, data->img->img);
	free(data->mlx);
	free(data->img);
	free(data);
	exit(0);
}

void	img_put_pixel(t_img_data *img, unsigned int x,
		unsigned int y, unsigned int color)
{
	*((unsigned int *)(img->addr
				+ (y * img->line_length + x
					* (img->bits_per_pixel / 8)))) = color;
}
