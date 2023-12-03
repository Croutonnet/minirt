#ifndef PARSING_H
# define PARSING_H

# include "Libft/libft.h"
# include "ray.h"
# include <fcntl.h>

# define CORRECT 0
# define OPENWRONG 1
# define BADTYPE 2
# define BADALIGHT 3
# define BADCAMERA 4
# define BADLIGHT 5
# define BADPLANE 6
# define BADSPHERE 7
# define BADCYL 8

// parsing
int		is_there_tabs(char *line);
int		p_ambient_light(char *line);
int		read_line(char *line);
int		parsing(char *file);
void	print_error();

//line_read
int		p_camera(char *line);
int		p_light(char *line);
int		p_plane(char *line);
int		p_sphere(char *line);
int		p_cylindre(char *line);

#endif