#include "../include/vector.h"
#include <stdio.h>

t_vector	add_vec(t_vector vec1, t_vector vec2)
{
	t_vector	res;

	res = create_vector(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
	return (res);
}

t_vector	minus_vec(t_vector vec1, t_vector vec2)
{
	t_vector	res;

	res = create_vector(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
	return (res);
}

t_vector	mul_vec(t_vector vec, double mul)
{
	t_vector	res;

	res = create_vector(vec.x * mul, vec.y * mul, vec.z * mul);
	return (res);
}

t_vector	div_vec(t_vector vec, double div)
{
	t_vector	res;

	res.x = vec.x / div;
	res.y = vec.y / div;
	res.z = vec.z / div;
	return (res);
}

void	print_vec(t_vector vec){
	printf("x: %f	y: %f	z: %f\n", vec.x, vec.y, vec.z);
}
