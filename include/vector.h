#ifndef VECTOR_H
# define VECTOR_H

# include "math.h"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

//vector.c
void		create_vector(t_vector *vec, int x, int y, int z);
t_vector	*mul_2vec(t_vector *vec1, t_vector *vec2);
t_vector	*div_2vec(t_vector *vec1, t_vector *vec2);
double		length_vec(t_vector *vec);
double		dot_vec(t_vector *vec1, t_vector *vec2);

//vector_math.c
t_vector	add_vec(t_vector *vec1, t_vector *vec2);
t_vector	minus_vec(t_vector *vec1, t_vector *vec2);
t_vector	mul_vec(t_vector *vec, float mul);
t_vector	div_vec(t_vector *vec, float div);

#endif