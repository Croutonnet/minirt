#include "../include/vector.h"
#include "../include/color.h"
#include "../include/parsing.h"
#include "../include/MLX42/include/MLX42/MLX42.h"
#include "../include/image.h"
#include "../include/ray.h"
#include <stdio.h>
#include <stdbool.h>

static void	calculate_upper_left(t_data *data)
{
	t_vector	res1;
	t_vector	res2;

	res1 = minus_vec(create_vector(0, 0, 0), create_vector(0, 0, data->viewport.focal_lenght));
	res2 = minus_vec(res1, div_vec(data->viewport.u, 2));
	data->viewport.upper_left = minus_vec(res2, div_vec(data->viewport.v, 2));
}

static void	calculate_p00_loc(t_data *data)
{
	t_vector	res1;

	res1 = mul_vec(add_vec(data->viewport.pixel_delta_u, data->viewport.pixel_delta_v), 0.5);
	data->viewport.pixel00_loc = add_vec(data->viewport.upper_left, res1);
}

void	key_func(mlx_key_data_t keydata, void *param)
{
	t_data *data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE){
		mlx_terminate(data->mlx);
		exit(0);
	}
	if (keydata.action != MLX_PRESS)
		return ;
	if (special_key(data, keydata.key) == true)
		return ;
	if (data->cam_selected == true)
	{
		change_camera(data, keydata.key);
		rotate_camera(data, keydata.key);
		final_viewport(data);
	}
	else if (data->light_selected == true)
		move_light(data, keydata.key);
	else
		return ;
	create_rays(data);
	return ;
}
void	initialisation(t_data *data, char *input)
{
	data->viewport.ratio = IMAGE_WIDTH / IMAGE_HEIGHT;
	data->viewport.height = 2.0;
	data->viewport.width = data->viewport.height * data->viewport.ratio;
	data->viewport.v = create_vector(data->viewport.width, 0, 0);
	data->viewport.u = create_vector(0, -data->viewport.height, 0);
	data->viewport.pixel_delta_v = div_vec(data->viewport.v, IMAGE_WIDTH);
	data->viewport.pixel_delta_u = div_vec(data->viewport.u, IMAGE_HEIGHT);
	read_map(input, data);
	data->viewport.viewport_center = minus_vec(create_vector(0, 0, 0), create_vector(0, 0, -data->viewport.focal_lenght));
	calculate_upper_left(data);
	calculate_p00_loc(data);
	read_rotation(data);
	data->mlx = mlx_init(IMAGE_WIDTH, IMAGE_HEIGHT, "coucou", true);
	data->image = mlx_new_image(data->mlx, IMAGE_WIDTH, IMAGE_HEIGHT);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_count	count;

	if (argc != 2)
	{
		ft_printf_fd(2, "Il faut loader une map dans map/quelquechose.rt et rien d'autre\n");
		return (1);
	}
	ft_bzero(&count, sizeof(count));
	ft_bzero(&data, sizeof(data));
	if (parsing(argv[1], &count) == -1)
		return (1);
	initialisation(&data, argv[1]);
	final_viewport(&data);
	create_rays(&data);
	mlx_image_to_window(data.mlx, data.image, 0, 0);
	mlx_key_hook(data.mlx, key_func, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}
