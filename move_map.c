/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 02:31:46 by mnaji             #+#    #+#             */
/*   Updated: 2019/03/29 20:46:36 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		search_place(t_map *map, int i)
{
	static int	last_i = 0;

	if (last_i != i - 1)
		if (move_tetri(&map->tetri[i], map->size) == -1)
		{
			replace_tetri(&map->tetri[i], map->size);
			last_i = i;
			return (i - 1);
		}
	while (check_tetri_move(*map, i) == -1)
		if (move_tetri(&map->tetri[i], map->size) == -1)
		{
			replace_tetri(&map->tetri[i], map->size);
			last_i = i;
			return (i - 1);
		}
	last_i = i;
	return (i + 1);
}

int		check_tetri_move(t_map map, int i)
{
	int		i2;

	i2 = i - 1;
	while (i2 >= 0)
	{
		if (check_tetri(map.tetri[i2], map.tetri[i], map.size) == -1)
			return (-1);
		i2--;
	}
	return (0);
}

int		move_map(t_map *map)
{
	int		i;
	int		res;

	i = 1;
	while ((res = check_map(map)) == -1)
		if ((i = search_place(map, i)) == -1)
			break ;
	if (res == -1)
		replace_tetri(&map->tetri[0], map->size);
	return (res);
}
