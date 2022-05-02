#include "fractol.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

int main()
{
	t_data *data = init(600, 600);
	mlx_key_hook(data->window, hook_key_mgr, data);
	mlx_loop(data->mlx);
}