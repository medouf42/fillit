/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 04:16:45 by mnaji             #+#    #+#             */
/*   Updated: 2019/04/15 01:48:59 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map			*free_map(t_map *map)
{
	free(map);
	map = NULL;
	return (NULL);
}

t_tetri			*param_w_and_h_tetri(t_tetri *tetri, int w, int h)
{
	tetri->width = w;
	tetri->height = h;
	return (tetri);
}

unsigned int	powerof_2(unsigned int power)
{
	unsigned int	res;

	res = 1;
	while (power != 0)
	{
		res = res * 2;
		power--;
	}
	return (res);
}

void			replace_tetri(t_tetri *tetri, int size_map)
{
	int		i;

	i = 20;
	while (--i >= 0)
		tetri->l_tetri[i] = 0;
	tetri->temp = tetri->tetri;
	i = 3;
	if (size_map == 3)
		while (i >= 0)
		{
			tetri->l_tetri[i] = (tetri->temp % 16) / 2;
			tetri->temp = tetri->temp / 16;
			i--;
		}
	else
		while (i >= 0)
		{
			tetri->l_tetri[i] = (tetri->temp % 16) * powerof_2(size_map - 4);
			tetri->temp = tetri->temp / 16;
			i--;
		}
	param_tetri_2(tetri);
}

void			ft_putstr(char const *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}
