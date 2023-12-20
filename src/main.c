#include "../include/vector.h"
#include "../include/color.h"
#include "../include/parsing.h"
#include "../include/MLX42/include/MLX42/MLX42.h"
#include "../include/image.h"
#include "../include/ray.h"
#include <stdio.h>
#include <stdbool.h>

static void	calculate_upper_left(t_viewport *view)
{
	t_vector	res1;
	t_vector	res2;
	t_vector	res3;

	res1 = minus_vec(view->camera_center, create_vector(0, 0, view->focal_lenght));
	res2 = div_vec(view->u, 2);
	res3 = div_vec(view->v, 2);
	view->upper_left = minus_vec(res1, res2);
	view->upper_left = minus_vec(view->upper_left, res3);
	printf("upper_left: ");
	print_vec(view->upper_left);
}

static void	calculate_p00_loc(t_viewport *view)
{
	t_vector	res1;

	res1 = mul_vec(add_vec(view->pixel_delta_u, view->pixel_delta_v), 0.5);
	view->pixel00_loc = add_vec(view->upper_left, res1);
	printf("pixel_00: ");
	print_vec(view->pixel00_loc);
}

// ajoute une Shape au tableau
void add_shape(t_shapes_arr *arr, e_shape_type type, u_geom geo)
{
	if (type == SPHERE)
		arr->shapes[arr->count].type = SPHERE;
	else if (type == CYLINDER)
		arr->shapes[arr->count].type = CYLINDER;
	arr->shapes[arr->count].geom = geo;
	arr->count++;

}

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_viewport	viewport;
	t_data		data;
	t_count		count;

	if (argc != 2)
	{
		ft_printf_fd(2, "Trop de argument ou pas assez you dum biche\n");
		return (1);
	}
	ft_bzero(&count, sizeof(count));
	if (parsing(argv[1], &count) == -1)
		return (1);
	add_shape(&data.shapes, SPHERE, (u_geom)create_sphere(0, 0, 10, 3, (t_vector){1,0,0}));
	// add_shape(&shapes, SPHERE, (u_geom)create_sphere(10, -10, -10, 3,(t_vector){0,1,0}));
	// add_shape(&shapes, SPHERE, (u_geom)create_sphere(0, -10, -10, 2,(t_vector){0,0,1}));
	// add_shape(&shapes, SPHERE, (u_geom)create_sphere(0, -10, -10, 5,(t_vector){1,1,0}));

	viewport.ratio = IMAGE_WIDTH / IMAGE_HEIGHT;
	viewport.height = 2.0;
	viewport.width = viewport.height * viewport.ratio;
	viewport.v = create_vector(viewport.width, 0, 0);
	viewport.u = create_vector(0, -viewport.height, 0);
	viewport.pixel_delta_u = div_vec(viewport.u, IMAGE_HEIGHT);
	viewport.pixel_delta_v = div_vec(viewport.v, IMAGE_WIDTH);
	read_map(argv[1], &data, &viewport);
	calculate_upper_left(&viewport);
	calculate_p00_loc(&viewport);
	mlx = mlx_init(IMAGE_WIDTH, IMAGE_HEIGHT, "coucou", true);
	image = mlx_new_image(mlx, IMAGE_WIDTH, IMAGE_HEIGHT);
	create_rays(&viewport, &data, image);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
}
