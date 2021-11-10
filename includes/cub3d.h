#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_file
{
	char	**raw_file;
	char	**map;
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	char	*f_color;
	char	*c_color;
	int		p_pos_x;
	int		p_pos_y;
	char	p_ori;
}	t_file;

int		get_next_line(int fd, char **line);
int		ft_modstrlen(const char *s, int mod);
char	*ft_modstrjoin(char const *s1, char const *s2);

char	**read_file(char *argv);
int		check_cub(char *str);

int		free_all(t_file *map);

int		parsing(char *argv, t_file *map);

int		get_textures(t_file *map);
int		get_pos(t_file *map);

int		get_map(t_file *map);

#endif