#include "../include/vector.h"
#include "../include/color.h"
#include "../include/MLX42/include/MLX42/MLX42.h"
#include "../include/image.h"
#include <stdio.h>
#include <stdbool.h>


int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_viewport	viewport;

	viewport.ratio = 16.0 / 9.0;
	viewport.width = 300;
	viewport.height = viewport.width / viewport.ratio;
	mlx = mlx_init(1920, 1080, "coucou", true);
	// create_vector(viewport.u, viewport.width, 0, 0);
	// create_vector(viewport.v, viewport.width, 0, 0);
	image = mlx_new_image(mlx, viewport.width, viewport.height);
	for (int w = 0; w < viewport.width; w++){
		for (int h = 0; h < (int)viewport.height; h++){
			mlx_put_pixel(image, w, h, 50);
		}
	}
	mlx_image_to_window(mlx, image, 1920/4, 1080/4);
	mlx_loop(mlx);
}