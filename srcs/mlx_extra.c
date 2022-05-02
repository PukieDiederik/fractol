#include "mlx.h"
#include "stdlib.h"
#include "fractol.h"

t_data	*init(int width, int height)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(0);
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data);
		exit(0);
	}
	data->window = mlx_new_window(data->mlx, width, height, "Fract'ol");
	data->img = mlx_new_image(data->mlx, width, height);
	if (!data->window || !data->img)
	{
		exit_clean(data);
		return (0);
	}
	return (data);
}

void	exit_clean(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->window);
	free(data);
	exit(0);
}
