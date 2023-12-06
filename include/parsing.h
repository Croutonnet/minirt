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
	BADORI
};

// parsing
int		is_there_tabs(char *line);
int		p_ambient_light(char *line);
int		read_line(char *line);
int		parsing(char *file);
int		print_error(int err, int ret);

// parsing_utils
int	check_rgb(char *line, int j, int i, int k);
int	check_ratio(char *line);
int	check_vector(char *line, int i, int j, int k);
int	check_fov(char *line);
int	check_vector_orientation(char *line, int i, int j, int k);

//line_read
int		p_camera(char *line);
int		p_light(char *line);
int		p_plane(char *line);
int		p_sphere(char *line);
int		p_cylindre(char *line);

#endif