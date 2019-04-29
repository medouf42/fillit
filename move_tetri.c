/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 23:34:50 by mnaji             #+#    #+#             */
/*   Updated: 2019/03/25 23:21:26 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetri_move_down(t_tetri *tetri, int size_map)
{
	int		i;

	i = 0;
	while (tetri_is_bol(*tetri, size_map) != 1)
		tetri_move_left(tetri, size_map);
	while (--size_map > 0)
		tetri->l_tetri[size_map] = tetri->l_tetri[size_map - 1];
	tetri->l_tetri[0] = 0;
	tetri->height++;
}

void	tetri_move_left(t_tetri *tetri, int size_map)
{
	int		i;

	i = 0;
	while (i < size_map)
	{
		tetri->l_tetri[i] = tetri->l_tetri[i] * 2;
		i++;
	}
	tetri->width--;
}

int		tetri_is_bol(t_tetri tetri, int size_map)
{
	int		i;

	i = 0;
	while (i < size_map)
	{
		if (tetri.l_tetri[i] / powerof_2(size_map - 1) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	tetri_move_right(t_tetri *tetri, int size_map)
{
	int		i;

	i = 0;
	while (i < size_map)
	{
		tetri->l_tetri[i] = tetri->l_tetri[i] / 2;
		i++;
	}
	tetri->width++;
}

int		move_tetri(t_tetri *tetri, int size_map)
{
	if (tetri->width == size_map && tetri->height == size_map)
		return (-1);
	else if (tetri->width == size_map)
		tetri_move_down(tetri, size_map);
	else
		tetri_move_right(tetri, size_map);
	return (0);
}
