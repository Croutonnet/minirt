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
	viewport.camera_center = create_vector(0, 0, 0);
	viewport.u = create_vector(viewport.width, 0, 1);
	viewport.v = create_vector(0, viewport.height, 1);
	viewport.pixel_delta_u = div_vec(viewport.u, IMAGE_WIDTH);
	print_vec(viewport.pixel_delta_u);
	viewport.pixel_delta_v = div_vec(viewport.v, IMAGE_HEIGHT);
	printf ("COUCOU : %f\n", length_vec(viewport.pixel_delta_v));
	print_vec(viewport.pixel_delta_v);
	mlx = mlx_init(IMAGE_WIDTH, IMAGE_HEIGHT, "coucou", true);
	image = mlx_new_image(mlx, viewport.width, viewport.height);
	for (int w = 0; w < viewport.width; w++){
		for (int h = 0; h < (int)viewport.height; h++){
			mlx_put_pixel(image, w, h, 50);
		}
	}
	mlx_image_to_window(mlx, image, IMAGE_WIDTH/2.5, IMAGE_HEIGHT/2.5);
	mlx_loop(mlx);
}
