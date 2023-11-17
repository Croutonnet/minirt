#include "../include/vector.h"
#include "../include/color.h"
#include "../include/MLX42/include/MLX42/MLX42.h"
#include "../include/image.h"
#include <stdio.h>
#include <stdbool.h>

void	calculate_upper_left(t_viewport *view, float focal_length)
{
	t_vector	res1;
	t_vector	res2;
	t_vector	res3;

	res1 = minus_vec(view->camera_center, create_vector(0, 0, focal_length));
	res2 = div_vec(view->u, 2);
	res3 = div_vec(view->v, 2);
	view->upper_left = minus_vec(res1, res2);
	view->upper_left = minus_vec(view->upper_left, res3);
	print_vec(view->upper_left);
}

void	calculate_p00_loc(t_viewport *view)
{
	t_vector	res1;

	res1 = mul_vec(add_vec(view->pixel_delta_u, view->pixel_delta_v), 0.5);
	view->pixel00_loc = add_vec(view->upper_left, res1);
	print_vec(view->pixel00_loc);
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_viewport	viewport;

	viewport.ratio = IMAGE_WIDTH / IMAGE_HEIGHT;
	viewport.height = 2.0;
	viewport.width = viewport.height * viewport.ratio;
	viewport.camera_center = create_vector(0, 0, 0);
	viewport.v = create_vector(viewport.width, 0, 0);
	viewport.u = create_vector(0, -viewport.height, 0);
	viewport.pixel_delta_u = div_vec(viewport.u, IMAGE_HEIGHT);
	viewport.pixel_delta_v = div_vec(viewport.v, IMAGE_WIDTH);
	calculate_upper_left(&viewport, 1.0);
	calculate_p00_loc(&viewport);
	mlx = mlx_init(IMAGE_WIDTH, IMAGE_HEIGHT, "coucou", true);
	image = mlx_new_image(mlx, viewport.width, viewport.height);
	mlx_loop(mlx);
}
