#include "cub3d.h"

int	check_cub(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i--] == 'b')
		if (str[i--] == 'u')
			if (str[i--] == 'c')
				if (str[i] == '.')
					return (1);
	return (0);
}

static int	count_lines(char *argv, char **line)
{
	int	fd;
	int	ret;
	int	i;

	i = 0;
	ret = 1;
	fd = open(argv, O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, line);
		if (ret == -1)
			return (-1);
		free(*line);
		i++;
	}
	close(fd);
	return (i);
}

char	**read_file(char *argv)
{
	char	*line;
	char	**raw_file;
	int		ret;
	int		i;
	int		fd;

	i = count_lines(argv, &line);
	if (i == -1)
		return (NULL);
	raw_file = (char **)malloc(sizeof(char *) * (i + 1));
	if (!raw_file)
		return (NULL);
	ret = 0;
	ret = 1;
	i = 0;
	fd = open(argv, O_RDONLY);
	while (ret > 0)
		ret = get_next_line(fd, &raw_file[i++]);
	raw_file[i] = NULL;
	close(fd);
	return (raw_file);
}