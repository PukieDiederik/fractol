/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:49:49 by drobert-          #+#    #+#             */
/*   Updated: 2022/05/06 12:49:54 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

int		get_fractal(char *str, t_data *data);
void	print_help(void);

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		print_help();
		exit(0);
	}
	data = init(600);
	if (!data || !data->mlx || !data->window || !get_fractal(argv[1], data))
		exit_clean(data);
	mlx_key_hook(data->window, hook_key_mgr, data);
	mlx_mouse_hook(data->window, hook_mouse_mgr, data);
	mlx_expose_hook(data->window, hook_expose_mgr, data);
	mlx_hook(data->window, 17, 0, exit_clean, data);
	render_fractal(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img->img, 0, 0);
	mlx_loop(data->mlx);
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	print_help(void)
{
	ft_putstr_fd("Valid use of this command: ./fractol [fractal name]\n", 1);
	ft_putstr_fd("Fractals:\n", 1);
	ft_putstr_fd("\t- mandelbrot\n", 1);
	ft_putstr_fd("\t-julia\n", 1);
	ft_putstr_fd("\t- burning_ship\n", 1);
}

int	get_fractal(char *str, t_data *data)
{
	data->fractal = 0;
	if (!ft_strcmp(str, "mandelbrot"))
		data->fractal = mandelbrot;
	else if (!ft_strcmp(str, "julia"))
		data->fractal = julia;
	else if (!ft_strcmp(str, "burning_ship"))
		data->fractal = burning_ship;
	else
	{
		print_help();
		return (0);
	}
	return (1);
}
