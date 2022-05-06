/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:42:24 by drobert-          #+#    #+#             */
/*   Updated: 2022/05/06 12:43:30 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

void	zoom_in(t_data *data, int x, int y)
{
	double	scaling;

	scaling = 0.9;
	data->x_offset = data->x_offset + (((double)x / data->size) * data->scale)
		- ((data->scale * scaling) / 2);
	data->y_offset = data->y_offset + (((double)y / data->size) * data->scale)
		- ((data->scale * scaling) / 2);
	data->scale *= scaling;
	render_fractal(data);
}

void	zoom_out(t_data *data)
{
	double	scaling;

	scaling = 1.1;
	data->x_offset += (data->scale - (data->scale * ((scaling * 0.5) + 0.5)));
	data->y_offset += (data->scale - (data->scale * ((scaling * 0.5) + 0.5)));
	data->scale *= scaling;
	render_fractal(data);
}
