#include "cub3d.h"

static int	check_only_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_after_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1' || line[i] == '0' || line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
	{
		if (line[i] == 'N' || line[i] == 'S')
			if (line[i + 1] == 'O')
				return (1);
		if (line[i] == 'W')
			if (line[i + 1] == 'E')
				return (1);
		if (line[i] == 'E')
			if (line[i + 1] == 'A')
				return (1);
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
	while (map->raw_file[i] && (map->raw_file[i][0] != '1' && map->raw_file[i][0] != '0' && check_after_spaces(map->raw_file[i])))
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
