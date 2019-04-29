/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:18:26 by mnaji             #+#    #+#             */
/*   Updated: 2019/03/29 20:46:31 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		smallest_sqare(t_map *map)
{
	int		size;
	int		i;

	size = 2;
	i = 0;
	while (size * size < map->nbr_tetri * 4)
		size++;
	if (size < 4)
	{
		while (i < map->nbr_tetri)
		{
			if (size < map->tetri[i].width)
				size = map->tetri[i].width;
			if (size < map->tetri[i].height)
				size = map->tetri[i].height;
			i++;
		}
		if (size == 2)
			ft_putstr("AA\nAA\n");
	}
	return (size);
}

void	resize_tetri(t_tetri *tetri, int size, int new_size, int nbr)
{
	int		i;
	int		size_temp;

	i = -1;
	if (new_size != size)
		while (++i < nbr)
		{
			if (new_size == 3)
			{
				tetri[i].l_tetri[0] = tetri[i].l_tetri[0] / 2;
				tetri[i].l_tetri[1] = tetri[i].l_tetri[1] / 2;
				tetri[i].l_tetri[2] = tetri[i].l_tetri[2] / 2;
			}
			else
			{
				size_temp = size;
				while (size_temp++ < new_size)
				{
					tetri[i].l_tetri[0] = tetri[i].l_tetri[0] * 2;
					tetri[i].l_tetri[1] = tetri[i].l_tetri[1] * 2;
					tetri[i].l_tetri[2] = tetri[i].l_tetri[2] * 2;
					tetri[i].l_tetri[3] = tetri[i].l_tetri[3] * 2;
				}
			}
		}
}

int		check_tetri(t_tetri tetri_1, t_tetri tetri_2, int size_map)
{
	int		i;
	int		i2;

	i = 0;
	while (i < size_map)
	{
		i2 = 0;
		while (i2 < size_map)
		{
			if (tetri_1.l_tetri[i] % 2 == 1 && tetri_2.l_tetri[i] % 2 == 1)
				return (-1);
			tetri_1.l_tetri[i] = tetri_1.l_tetri[i] / 2;
			tetri_2.l_tetri[i] = tetri_2.l_tetri[i] / 2;
			i2++;
		}
		i++;
	}
	return (0);
}

int		check_map(t_map *map)
{
	int		i;
	int		i2;

	i = 0;
	while (i <= map->nbr_tetri)
	{
		i2 = 0;
		while (i2 <= map->nbr_tetri)
		{
			if (i != i2 &&\
			check_tetri(map->tetri[i], map->tetri[i2], map->size) == -1)
				return (-1);
			i2++;
		}
		i++;
	}
	return (1);
}

t_map	*solve_fillit(t_map *map)
{
	if ((map->size = smallest_sqare(map)) == 2)
		return (map);
	resize_tetri(map->tetri, 4, map->size, map->nbr_tetri);
	while (move_map(map) == -1)
	{
		map->size++;
		resize_tetri(map->tetri, map->size - 1, map->size, map->nbr_tetri);
	}
	return (map);
}
