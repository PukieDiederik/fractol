/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:41:04 by drobert-          #+#    #+#             */
/*   Updated: 2022/05/06 12:41:51 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

//manages key hooks
int	hook_key_mgr(int keycode, t_data *data)
{
	if (keycode == K_ESC)
		exit_clean(data);
	if (keycode == K_UP || keycode == K_W)
		data->y_offset -= data->scale * 0.1;
	else if (keycode == K_DOWN || keycode == K_S)
		data->y_offset += data->scale * 0.1;
	else if (keycode == K_RIGHT || keycode == K_D)
		data->x_offset += data->scale * 0.1;
	else if (keycode == K_LEFT || keycode == K_A)
		data->x_offset -= data->scale * 0.1;
	render_fractal(data);
	mlx_put_image_to_window(data->mlx, data->window,
		data->img->img, 0, 0);
	return (0);
}

int	hook_mouse_mgr(int button, int x, int y, t_data *data)
{
	if (button == 1)
		update_julia_mouse(data);
	if (button == 4)
		zoom_in(data, x, y);
	else if (button == 5)
		zoom_out(data);
	return (0);
}

int	hook_expose_mgr(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->window, data->img->img, 0, 0);
	return (0);
}