#include "../fillit.h"

void	square_free(t_sq *sq, int size)
{
	while (size > -1)
		free(sq->arr[size--]);
	free(sq->arr);
	free(sq->size);
	free(sq);
}
