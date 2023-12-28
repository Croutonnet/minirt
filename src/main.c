#include "../include/vector.h"
#include "../include/color.h"
#include "../include/MLX42/include/MLX42/MLX42.h"
#include "../include/image.h"
#include "../include/ray.h"
#include <stdio.h>
#include <stdbool.h>

t_viewport	viewport;
mlx_image_t	*image;
t_shapes_arr shapes;

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
	//print_vec(view->upper_left);
}

void	calculate_p00_loc(t_viewport *view)
{
	t_vector	res1;

	res1 = mul_vec(add_vec(view->pixel_delta_u, view->pixel_delta_v), 0.5);
	view->pixel00_loc = add_vec(view->upper_left, res1);
	print_vec(view->pixel00_loc);
}

// ajoute une Shape au tableau
void add_shape(t_shapes_arr *arr, e_shape_type type, u_geom geo)
{
	if (type == SPHERE)
		arr->shapes[arr->count].type = SPHERE;
	else if (type == CYLINDER)
		arr->shapes[arr->count].type = CYLINDER;
	else if (type == PLANE)
		arr->shapes[arr->count].type = PLANE;
	arr->shapes[arr->count].geom = geo;
	arr->count++;

}

//void cam_move(void *param)
//{
	// mlx_t *mlx = param;	
	// if (mlx_is_key_down(mlx, MLX_KEY_UP))
	// {

	// }
	// else if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	// {

	// }
	// else if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	// {
	// 	//viewport.pixel00_loc.z -= 1;
	// 	//viewport.upper_left.x -= 1;
	// 	viewport.camera_center.z -= 1;

	// }
	// else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	// {
	// 	//viewport.pixel00_loc.z += 1;
	// 	//viewport.upper_left.x += 1;
	// 	viewport.camera_center.z += 1;
	// }
	// create_rays(&viewport, &shapes, image);
//}

int	main(void)
{
	mlx_t		*mlx;
	shapes.count = 0;
	add_shape(&shapes, PLANE, (u_geom)create_plane((t_vector){0,0,-20}, (t_vector){0.4,1,0}, (t_color){0,0,1}));
	add_shape(&shapes, SPHERE, (u_geom)create_sphere((t_vector){0, 0, -10}, 3, (t_vector){1,0,0}));
	//add_shape(&shapes, SPHERE, (u_geom)create_sphere((t_vector){10, 0, -10}, 3,(t_vector){0,1,0}));
	//add_shape(&shapes, SPHERE, (u_geom)create_sphere((t_vector){0, 10, -10}, 2,(t_vector){0,0,1}));
	//add_shape(&shapes, SPHERE, (u_geom)create_sphere((t_vector){0, -10, -10},5,(t_vector){1,1,0}));
	//add_shape(&shapes, CYLINDER, (u_geom)create_cylinder((t_vector){10,5,-10},(t_vector){0,1,0}, 3, 8, (t_vector){1,1,0}));
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
	image = mlx_new_image(mlx, IMAGE_WIDTH, IMAGE_HEIGHT);
	create_rays(&viewport, &shapes, image);
	mlx_image_to_window(mlx, image, 0, 0);
	//mlx_loop_hook(mlx, cam_move, mlx);
	mlx_loop(mlx);
}
