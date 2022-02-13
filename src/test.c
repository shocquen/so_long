#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mlx.h"
// #include "so_long.h"
typedef struct	data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
}	data_t;


int main(void)
{
	data_t	data;
	int			width;
	int			height;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (EXIT_FAILURE);
	data.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, "img/wall.xpm", &width, &height);
	data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 640, "so_long");
	if (!data.mlx_win)
			return (EXIT_FAILURE);
	for (int i = 0; i < 10; i++)
	{
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.mlx_img, 0, 64 * i); // fist column
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.mlx_img, 64 * 9, 64 * i); // last column
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.mlx_img, 64 * i, 0); // first row
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.mlx_img, 64 * i, 64 * 9); // last row
	}
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.mlx_img, 64 * 1, 64 *2); // fist column
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
