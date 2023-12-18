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
	BADCOUNT
};

typedef struct	s_count
{
	int	cam;
	int	la;
	int	light;
	int	sphere;
	int	plane;
	int	cyl;
}				t_count;


// parsing
int		is_there_tabs(char *line);
int		read_line(char *line, t_count *count);
int		parsing(char *file);
int		p_ambient_light(char *line, t_count *count);
int		print_error(int err, int ret, int args);

// parsing_func
int	check_coma_point(char *line, int id);
int	check_syntaxe(char **input, int i, int j);
int	check_diametre(char *line);

// parsing_utils
int	check_rgb(char *line, int i, int k);
int	check_ratio(char *line);
int	check_vector(char *line, int i, int k);
int	check_fov(char *line);
int	check_vector_orientation(char *line, int i, int k);

//line_read
int		p_camera(char *line, t_count *count);
int		p_light(char *line, t_count *count);
int		p_plane(char *line, t_count *count);
int		p_sphere(char *line, t_count *count);
int		p_cylindre(char *line, t_count *count);

#endif