#include "../fillit.h"

static int	recursive(char *s, int i, int j, char letter)
{
	int		n;

	n = 1;
	s[i * 5 + j] = letter;
	if (j + 1 < 4 && s[i * 5 + j + 1] == '#')
		n += recursive(s, i, j + 1, letter);
	if (j - 1 > -1 && s[i * 5 + j - 1] == '#')
		n += recursive(s, i, j - 1, letter);
	if (i + 1 < 4 && s[(i + 1) * 5 + j] == '#')
		n += recursive(s, i + 1, j, letter);
	if (i - 1 > -1 && s[(i - 1) * 5 + j] == '#')
		n += recursive(s, i - 1, j, letter);
	return (n);
}

int			if_tetrimino(char *s, char letter)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '#' && recursive(s, i / 5, i % 5, letter) == 4)
			return (1);
		i++;
	}
	return (0);
}
