#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int	draw_first_carre(char *mlx, char *win, int x, int y)
{
	int	i;
	int i2;

	i = 0;
	i2 = 0;
	while (i2 < 5)
	{
		i = 0;
		while (i < 50)
		{
			mlx_pixel_put(mlx, win, (x + i2) / 2, (y + i) / 2, 0x00FF22FF);
			mlx_pixel_put(mlx, win, (x + 50 + i2) / 2, (y + 5 + i) / 2, 0x00FF22FF);
			mlx_pixel_put(mlx, win, (x + 5 + i) / 2, (y + i2) / 2, 0x00FF22FF);
			mlx_pixel_put(mlx, win, (x + i) / 2, (y + 50 + i2) / 2, 0x00FF22FF);
			i++;
		}
		i2++;
	}
	return (1);
}

int	draw_arc_en_ciel(char *mlx, char *win, int x, int y)
{
	int 	r;
	int 	ecart;
	int		centre_x;
	int		xx;
	int		centre_y;

	r = x / 3;
	ecart = 0;
	centre_x = x / 2;
	centre_y = y / 2;
	xx = x;

	y = y / 2;
	while (y > 0)
	{
		x = xx;
		while (x > 0)
		{
			if ((ecart = ((centre_x - x) * (centre_x - x) + (centre_y - y) * (centre_y - y)) < (r * r) * 0.3))
				mlx_pixel_put(mlx, win, x, y, 0x000000);
			else if ((ecart = ((centre_x - x) * (centre_x - x) + (centre_y - y) * (centre_y - y)) < (r * r) * 0.4))
				mlx_pixel_put(mlx, win, x, y, 0xDD22DD);
			else if ((ecart = ((centre_x - x) * (centre_x - x) + (centre_y - y) * (centre_y - y)) < (r * r) * 0.5))
				mlx_pixel_put(mlx, win, x, y, 0x11AAFF);
			else if ((ecart = ((centre_x - x) * (centre_x - x) + (centre_y - y) * (centre_y - y)) < (r * r) * 0.6))
				mlx_pixel_put(mlx, win, x, y, 0x00FF33);
			else if ((ecart = ((centre_x - x) * (centre_x - x) + (centre_y - y) * (centre_y - y)) < (r * r) * 0.7))
				mlx_pixel_put(mlx, win, x, y, 0xEEEE11);
			else if ((ecart = ((centre_x - x) * (centre_x - x) + (centre_y - y) * (centre_y - y)) < (r * r) * 0.8))
				mlx_pixel_put(mlx, win, x, y, 0xFFBB00);
			else if ((ecart = ((centre_x - x) * (centre_x - x) + (centre_y - y) * (centre_y - y)) < (r * r) * 0.9))
				mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			x--;
		}
		y--;
	}
	return (1);
}

int	close_win(int keycode, void *param)
{
	printf("key = %d\n", keycode);
	if (keycode == 53 || keycode == 12)
		exit(0);
	return (1);
}

int	main()
{
	void	*mlx_arc;
	void	*win_arc;
	void	*arc;
	void	*licorne;
	int		x;
	int		y;

	x = 300;
	y = 300;
	mlx_arc = mlx_init();
	win_arc = mlx_new_window(mlx_arc, 900, 900, "Test recup new_image");
	draw_arc_en_ciel(mlx_arc, win_arc, x, y);
	draw_arc_en_ciel(mlx_arc, win_arc, 600, 600);
	draw_arc_en_ciel(mlx_arc, win_arc, 900, 900);
	mlx_key_hook(win_arc, close_win, 0);
	mlx_loop(mlx_arc);
	return (0);
}
