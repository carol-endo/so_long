#include <mlx.h>
#include <stdlib.h>

#define WIN_WIDTH 600
#define WIN_HEIGHT 300

#define MLX_ERROR 1

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"My first window!");
	if (win_ptr == NULL)
	{
		free(mlx_ptr);
		return (MLX_ERROR);
	}
	while (1)
		;
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}

/*
mlx_init creates a structure that contains all the information about the connection
between the software and the graphical system
- returns a void pointer (under the hood = the address of a t_xvar element)
*/