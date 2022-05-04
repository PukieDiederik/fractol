#ifndef FRACTOL_H
# define FRACTOL_H

# if defined(__APPLE__)
#  define K_ESC 53

#  define K_UP 126
#  define K_DOWN 125
#  define K_LEFT 123
#  define K_RIGHT 124

#  define K_W 13
#  define K_S 1
#  define K_A 0
#  define K_D 2
# else //assume linux cause F windows
#  define K_ESC 65307

#  define K_UP 65362
#  define K_DOWN 65364
#  define K_LEFT 65361
#  define K_RIGHT 65363

#  define K_W 119
#  define K_S 115
#  define K_A 97
#  define K_D 100
# endif

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
	double scale;
	double x_offset;
	double y_offset;
	unsigned int size;
}	t_data;

// Functions
//initializes stuff from mlx
t_data *init(int size);
int exit_clean(t_data *data);
//puts pixel on img
void img_put_pixel(t_img_data *img, unsigned int x, unsigned int y, unsigned int color);

//hooks
int hook_key_mgr(int keycode, t_data *data);
int hook_expose_mgr(t_data *data);

//fractals
int mandelbrot(double x_p, double y_p);

//rendering
void render_fractal(t_data *data);

#endif
