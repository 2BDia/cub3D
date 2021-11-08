#include "cub3d.h"

char	*get_each_texture(t_map *map, char *prefix, int offset)
{
	int	i;
	int	j;

	i = 0;
	while (map->raw_file[i])
	{
		j = 0;
		while (map->raw_file[i][j] == ' ')
			j++;
		if (!ft_strncmp_space(prefix, map->raw_file[i], offset))
		{
			while (map->raw_file[i][offset + j] == ' ')
				offset++;
			return (map->raw_file[i] + (offset + j));
		}
		i++;
	}
	return (NULL);
}

int	get_textures(t_map *map)
{
	map->n_texture = get_each_texture(map, "NO", 2);
	map->s_texture = get_each_texture(map, "SO", 2);
	map->w_texture = get_each_texture(map, "WE", 2);
	map->e_texture = get_each_texture(map, "EA", 2);
	map->f_color = get_each_texture(map, "F", 1);
	map->c_color = get_each_texture(map, "C", 1);
	if (!map->n_texture || !map->s_texture || !map->w_texture || !map->e_texture || !map->f_color || !map->c_color)
	{
		write(1, "Wrong texture path\n", 19);
		return (1);
	}
	return (0);
}

int	check_only_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' || line[i] != '\n')
			return (0);
	}
	return (1);
}

int	get_map(t_map *map)
{
	int	i;
	int	save;
	int	j;

	i = 0;
	while (map->raw_file[i] && (map->raw_file[i][0] != '1' && map->raw_file[i][0] != '0'))
	{
		if (map->raw_file[i][0] == 'N' || map->raw_file[i][0] == 'S')
			if (map->raw_file[i][1] != 'O')
				break ;
		if (map->raw_file[i][0] == 'W')
			if (map->raw_file[i][1] != 'E')
				break ;
		if (map->raw_file[i][0] == 'E')
			if (map->raw_file[i][1] != 'A')
				break ;
		i++;
	}
	save = i;
	while (map->raw_file[i])
	{
		if (check_only_spaces(map->raw_file[i]))
		{
			i--;
			break ;
		}
		i++;
	}
	map->map_f = (char **)malloc(sizeof(char *) * (i - save) + 1);
	if (!map->map_f)
		return (1);
	j = 0;
	while (save <= i)
		map->map_f[j++] = map->raw_file[save++];
	map->map_f[j] = NULL;
	return (0);
}

int	parsing(char *argv, t_map *map)
{
	map->raw_file = read_file(argv);
	if (get_textures(map))
		return (1);
	if (get_map(map))
		return (1);
	return (0);
}
