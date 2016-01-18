#include <mlx.h>
#include <math.h>

void	cercle(int r, char *mlx, char *win)
{
	int x;
	int y;
	int i;

	x = 600;
	y = 600;
	i = 0;
	while (i < 200)
	{
		x = x - i;
		mlx_pixel_put(mlx, win, x, y, 0x0011DDFF);
		mlx_pixel_put(mlx, win, x + 50, y, 0x0011DDFF);
		y = y - i;
		mlx_pixel_put(mlx, win, x, y, 0x0011DDFF);
		mlx_pixel_put(mlx, win, x + 50, y, 0x0011DDFF);
		i++;
	}
}

int	main()
{
	void	*mlx;
	void 	*win;
	int		x;
	int		y;
	int		i;
	int		i2;

	x = 600;
	y = 600;
	i = 0;
	i2 = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, x, y, "My first beautifull window");
	while (i2 < 5)
	{
		i = 0;
		while (i < 50)
		{
			mlx_pixel_put(mlx, win, (x + i2) / 2, (y + i) / 2, 0x00FF22FF);
			mlx_pixel_put(mlx, win, (x + 50 + i2) / 2, (y + 5 + i) / 2, 0x00FFFF22);
			mlx_pixel_put(mlx, win, (x + 5 + i) / 2, (y + i2) / 2, 0x00FFFFFF);
			mlx_pixel_put(mlx, win, (x + i) / 2, (y + 50 + i2) / 2, 0x0022FFFF);
			i++;
		}
		i2++;
	}
	cercle(200, mlx, win);
	cercle(200, mlx, win);
	mlx_loop(mlx);
	return (0);
}
