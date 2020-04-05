#include "../fillit.h"

static char	ft_range(char *numbers)
{
	int		j;
	char	max;

	max = 0;
	j = 0;
	while (j < 4)
	{
		if (max < numbers[j])
			max = numbers[j];
		j++;
	}
	return (char)(max - numbers[0]);
}

static void	set_relative_coords(t_arr *arr)
{
	int		j;

	j = 1;
	while (j < 4)
	{
		arr->x[j] -= arr->x[0];
		arr->y[j] -= arr->y[0];
		j++;
	}
}

void		add_size_n_coords(t_arr *arr)
{
	arr->h = ft_range(arr->x);
	arr->w = ft_range(arr->y);
	set_relative_coords(arr);
}
