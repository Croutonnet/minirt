#include "../include/vector.h"
#include <malloc/_malloc.h>
#include <stdio.h>

t_vector	create_vector(int x, int y, int z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

double	length_vec(t_vector vec)
{
	return (sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}

// float	dot_vec(t_vector *vec1, t_vector *vec2)
// {
// 	// return ();
// }

t_vector	mul_2vec(t_vector vec1, t_vector vec2)
{
	t_vector	res;

	res = create_vector(vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z);
	return (res);
}

t_vector	div_2vec(t_vector vec1, t_vector vec2)
{
	t_vector	res;

	res = create_vector(vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z);
	return (res);
}
