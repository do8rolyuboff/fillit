/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogeonosi <ogeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:37:10 by ogeonosi          #+#    #+#             */
/*   Updated: 2019/10/19 18:49:07 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# define MAX_TERIMINO 27
# define BUFF_SIZE 21

typedef struct	s_arr
{
	char		x[4];
	char		y[4];
	char		name;
	int			len;
	char		h;
	char		w;
}				t_arr;

typedef struct	s_sq
{
	char		**arr;
	char		*size;
}				t_sq;
int				if_tetrimino(char *s, char letter);
void			solve(t_arr *figures);
int				find_solution(t_sq *sq, t_arr *figures, int n);
void			square_free(t_sq *sq, int size);
size_t			ft_strlen(const char *str);
void			add_size_n_coords(t_arr *arr);

#endif
