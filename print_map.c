/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 09:59:08 by mnaji             #+#    #+#             */
/*   Updated: 2019/03/29 20:14:14 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*place_letter(t_tetri tetri, char *str, int map_size)
{
	int		i;
	int		ligne;
	int		power;

	i = 0;
	ligne = 0;
	while (ligne < map_size)
	{
		power = map_size - 1;
		while (power >= 0)
		{
			if (tetri.l_tetri[ligne] / powerof_2(power) == 1)
				str[i] = tetri.letter;
			tetri.l_tetri[ligne] = tetri.l_tetri[ligne] % powerof_2(power);
			power--;
			i++;
		}
		str[i++] = '\n';
		ligne++;
	}
	return (str);
}

int		print_map(t_map map)
{
	char	*str;
	int		i;

	if (!(str = (char*)malloc(sizeof(char) * (map.size * (map.size + 1)) + 1)))
		return (-1);
	i = 0;
	while (i < (map.size * (map.size + 1)))
	{
		str[i] = '.';
		i++;
	}
	str[i] = '\0';
	i = 0;
	while (i < map.nbr_tetri)
	{
		str = place_letter(map.tetri[i], str, map.size);
		i++;
	}
	ft_putstr(str);
	free(str);
	str = NULL;
	return (0);
}
