/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:03:30 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/21 13:30:36 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "Libft/libft.h"
# include "ray.h"
# include <fcntl.h>
# include <stdio.h>

enum e_error_parsing
{
	CORRECT,
	OPENWRONG,
	BADTYPE,
	BADALIGHT,
	BADCAMERA,
	BADLIGHT,
	BADPLANE,
	BADSPHERE,
	BADCYL,
	BADRGB,
	BADRATIO,
	BADFOV,
	BADTABS,
	BADVECTOR,
	BADORI,
	BADSYN,
	BADDIA,
	BADCOUNT,
	NOEXT,
	TOOEXT,
	WRONGEXT
};

typedef struct s_count
{
	int	cam;
	int	la;
	int	light;
	int	sphere;
	int	plane;
	int	cyl;
}				t_count;

// parsing
int	parsing(char *file, t_count *count);
int	p_ambient_light(char *line, t_count *count);
int	print_error(int err, int ret, int args);

// parsing_func
int	check_coma_point(char *line, int id);
int	check_syntaxe(char **input, int i, int j);

// parsing_utils
int	check_rgb(char *line, int i, int k);
int	check_ratio(char *line);
int	check_vector(char *line, int i, int k);
int	check_fov(char *line);
int	check_vector_orientation(char *line, int i, int k);

//line_read
int	p_camera(char *line, t_count *count);
int	p_light(char *line, t_count *count);
int	p_plane(char *line, t_count *count);
int	p_sphere(char *line, t_count *count);
int	p_cylindre(char *line, t_count *count);

//check_file
int	check_file(char *str);
int	is_there_tabs(char *line);
int	read_line(char *line, t_count *count);
int	check_diametre(char *line);

//read_map
void	read_map(char *file_path, t_data *data, t_viewport *viewport);

//create_shape
void		add_shape(t_shapes_arr *arr, e_shape_type type, u_geom geo);
void		pcreate_plane(char **line, t_data *data);
void		pcreate_sphere(char **line, t_data *data);
void		pcreate_cylindre(char **line, t_data *data);
t_vector	create_vector_str(char *str);


#endif