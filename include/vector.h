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
t_vector	create_vector(double x, double y, double z);
t_vector	mul_2vec(t_vector vec1, t_vector vec2);
t_vector	div_2vec(t_vector vec1, t_vector vec2);
float		length_vec(t_vector vec);
float		dot_vec(t_vector vec1, t_vector vec2);
t_vector	normalize(t_vector vec);
float		length_sqr(t_vector vec);

//vector_math.c
t_vector	add_vec(t_vector vec1, t_vector vec2);
t_vector	minus_vec(t_vector vec1, t_vector vec2);
t_vector	mul_vec(t_vector vec, double mul);
t_vector	div_vec(t_vector vec, double div);
void		print_vec(t_vector vec); // a enlever

#endif