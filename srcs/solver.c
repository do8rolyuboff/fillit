#include "../fillit.h"

static int	square_min_size(int n)
{
	int min_size;

	min_size = 0;
	while (min_size * min_size < n * 4)
		min_size++;
	return (min_size);
}

static t_sq	*square_make(int size)
{
	int		i;
	int		j;
	t_sq	*sq;

	i = 0;
	if (!(sq = (t_sq *)malloc(sizeof(t_sq))) ||
		!(sq->size = (char *)malloc(sizeof(char))) ||
		!(sq->arr = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(sq->arr[i] = (char *)malloc(sizeof(char) * (size + 1))))
		{
			square_free(sq, i);
			return (0);
		}
		j = 0;
		while (j < size)
			sq->arr[i][j++] = '.';
		sq->arr[i++][j] = '\0';
	}
	sq->arr[i] = NULL;
	*sq->size = size;
	return (sq);
}

void		solve(t_arr *figures)
{
	t_sq	*square;
	int		i;

	i = square_min_size(figures[0].len);
	square = square_make(i);
	while (!find_solution(square, figures, 0))
	{
		square_free(square, i);
		i++;
		square = square_make(i);
	}
	square_free(square, i);
}
