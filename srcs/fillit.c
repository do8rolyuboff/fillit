#include "../fillit.h"

static int	if_line_valid(char *line, int c_l)
{
	int		j;
	int		len;
	int		sharp;

	len = ft_strlen(line);
	j = 0;
	sharp = 0;
	if (c_l % 2 && len == 1 && line[0] != '\n')
		return (0);
	else if (!(c_l % 2) && len == 20)
	{
		while (line[j])
		{
			if (!((j + 1) % 5) && line[j] != '\n')
				return (0);
			if ((j + 1) % 5 && line[j] != '#' && line[j] != '.')
				return (0);
			if (line[j] == '#')
				sharp++;
			j++;
		}
		if (sharp != 4)
			return (0);
	}
	return (1);
}

static void	buff_to_t_arr(t_arr *arr, char *buff, char letter)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i])
	{
		if (buff[i] == letter)
		{
			arr->x[j] = i / 5;
			arr->y[j] = i % 5;
			j++;
		}
		i++;
	}
	add_size_n_coords(arr);
	arr->name = letter;
}

static void	len_to_t_arr(t_arr *arr, int len)
{
	int		i;

	i = 0;
	while (i < len)
		arr[i++].len = len;
}

static int	buff_handle(char *buff, int *k, int c_l, t_arr *figures)
{
	buff[*k] = '\0';
	if (!((c_l + 1) % 2))
		*k = 20;
	else
		*k = 1;
	if (!if_line_valid(buff, c_l))
		return (0);
	if (!(c_l % 2))
	{
		if (!if_tetrimino(buff, (char)'A' + c_l / 2))
			return (0);
		buff_to_t_arr(&figures[c_l / 2], buff, (char)'A' + c_l / 2);
	}
	return (1);
}

int			main(int ac, char **av)
{
	int		c_line;
	int		fd;
	char	buff[BUFF_SIZE];
	int		k;
	t_arr	figures[MAX_TERIMINO];

	c_line = 0;
	k = 20;
	buff[0] = '\0';
	if ((((fd = open(av[1], O_RDONLY)) < 0) || (ac != 2)) &&
		write(1, "usage: ./fillit source_file\n", 28))
		return (0);
	if (read(fd, buff, 0) == -1)
		return (0);
	while ((read(fd, buff, k)))
	{
		if (!buff_handle(buff, &k, c_line, figures) && write(1, "error\n", 6))
			return (0);
		c_line++;
	}
	if ((buff[0] == '\n' || !buff[0]) && write(1, "error\n", 6))
		return (0);
	len_to_t_arr(figures, (c_line + 1) / 2);
	solve(figures);
	return (0);
}
