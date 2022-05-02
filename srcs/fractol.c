#include "fractol.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

int main()
{
	void *mlx = mlx_init();
	if (!mlx)
		return (0);
	void *window = mlx_new_window(mlx, 600, 600, "Fract'ol");
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
}