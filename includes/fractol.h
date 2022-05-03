#ifndef FRACTOL_H
# define FRACTOL_H

#if defined(__APPLE__)
# define K_ESC 53
#else //assume linux cause F windows
# include <keysymdef.h>
# define K_ESC XK_Escape
#endif

//structs
typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct s_data
{
	void *mlx;
	void *window;
	t_img_data *img;
}	t_data;

// Functions
//initializes stuff from mlx
t_data *init(int width, int height);
int exit_clean(t_data *data);
//puts pixel on img
void img_put_pixel(t_img_data *img, int x, int y, unsigned int color);

//hooks
int hook_key_mgr(int keycode, t_data *data);
int hook_expose_mgr(t_data *data);


#endif
