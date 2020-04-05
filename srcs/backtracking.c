#include "../fillit.h"

static int	square_print(t_sq *sq)
{
	int		i;
	int		j;

	i = 0;
	while (i < *sq->size)
	{
		j = 0;
		while (j < *sq->size)
			write(1, &sq->arr[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
	return (1);
}

static int	tetri_can_put(t_sq *sq, int i, int j, t_arr figure)
{
	int		k;

	k = 1;
	while (k < 4)
	{
		if ((i + figure.x[k] >= *sq->size) ||
			(j + figure.y[k] >= *sq->size) ||
			(sq->arr[i + figure.x[k]][j + figure.y[k]] != '.'))
			return (0);
		k++;
	}
	return (1);
}

static void	tetri_put(t_sq *sq, int i, int j, t_arr figure)
{
	sq->arr[i][j] = figure.name;
	sq->arr[i + figure.x[1]][j + figure.y[1]] = figure.name;
	sq->arr[i + figure.x[2]][j + figure.y[2]] = figure.name;
	sq->arr[i + figure.x[3]][j + figure.y[3]] = figure.name;
}

static void	tetri_remove(t_sq *sq, int i, int j, t_arr figure)
{
	sq->arr[i][j] = '.';
	sq->arr[i + figure.x[1]][j + figure.y[1]] = '.';
	sq->arr[i + figure.x[2]][j + figure.y[2]] = '.';
	sq->arr[i + figure.x[3]][j + figure.y[3]] = '.';
}

int			find_solution(t_sq *sq, t_arr *figures, int n)
{
	int		i;
	int		j;

	if (n == figures[0].len)
		return (square_print(sq));
	i = 0;
	while (i < *sq->size - figures[n].h)
	{
		j = 0;
		while (j < *sq->size - figures[n].w)
		{
			if (sq->arr[i][j] == '.' && tetri_can_put(sq, i, j, figures[n]))
			{
				tetri_put(sq, i, j, figures[n]);
				if (find_solution(sq, figures, n + 1))
					return (1);
				else
					tetri_remove(sq, i, j, figures[n]);
			}
			j++;
		}
		i++;
	}
	return (0);
}
