/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 00:55:29 by mnaji             #+#    #+#             */
/*   Updated: 2019/04/15 01:48:25 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_buff(char *buf, int ret)
{
	int		i;
	int		count_l;
	int		count_sharp;

	i = 0;
	count_sharp = 0;
	count_l = 0;
	while (i < 20)
	{
		count_l++;
		if (buf[i] != '#' && buf[i] != '.' && (buf[i] != '\n' || count_l != 5))
			return (-1);
		else if (buf[i] == '#')
			count_sharp++;
		if (count_l == 5)
			count_l = 0;
		i++;
	}
	if (count_sharp != 4)
		return (-1);
	if ((ret == 19) || (ret == 20 && buf[i] == '\n'))
		return (0);
	if (buf[i] == '\n' && buf[i + 1] == '\n')
		return (0);
	return (0);
}

void	param_tetri_2(t_tetri *tetri)
{
	if (tetri->tetri == 34952)
		tetri = param_w_and_h_tetri(tetri, 1, 4);
	else if (tetri->tetri == 61440)
		tetri = param_w_and_h_tetri(tetri, 4, 1);
	else if (tetri->tetri == 52224)
		tetri = param_w_and_h_tetri(tetri, 2, 2);
	else if (tetri->tetri == 35008 || tetri->tetri == 50240\
	|| tetri->tetri == 17600 || tetri->tetri == 51328 || tetri->tetri == 19584\
	|| tetri->tetri == 35904 || tetri->tetri == 35968 || tetri->tetri == 19520)
		tetri = param_w_and_h_tetri(tetri, 2, 3);
	else if (tetri->tetri == 11776 || tetri->tetri == 59392\
	|| tetri->tetri == 36352 || tetri->tetri == 57856 || tetri->tetri == 27648\
	|| tetri->tetri == 50688 || tetri->tetri == 19968 || tetri->tetri == 58368)
		tetri = param_w_and_h_tetri(tetri, 3, 2);
}

t_tetri	*param_tetri(t_tetri *tetri)
{
	int		i;

	tetri->temp = tetri->tetri;
	param_tetri_2(tetri);
	i = 3;
	while (i >= 0)
	{
		tetri->l_tetri[i] = tetri->temp % 16;
		tetri->temp = tetri->temp / 16;
		i--;
	}
	return (tetri);
}

int		create_tetri(t_tetri *tetri, char *buff)
{
	int		i;

	i = 0;
	while (i < 19)
	{
		if (buff[i] == '.')
			tetri->tetri = tetri->tetri * 2;
		else if (buff[i] == '#')
			tetri->tetri = tetri->tetri * 2 + 1;
		i++;
	}
	if (((tetri->tetri / 8) % 2 == 1 && (tetri->tetri / 16) % 2 == 1) ||\
		((tetri->tetri / 128) % 2 == 1 && (tetri->tetri / 256) % 2 == 1) ||\
		((tetri->tetri / 2048) % 2 == 1 && (tetri->tetri / 4096) % 2 == 1))
		return (-1);
	while (tetri->tetri < 61440 && tetri->tetri != 35008 &&\
	tetri->tetri != 11776 && tetri->tetri != 50240 && tetri->tetri != 59392 &&\
	tetri->tetri != 17600 && tetri->tetri != 36352 && tetri->tetri != 51328 &&\
	tetri->tetri != 57856 && tetri->tetri != 52224 && tetri->tetri != 34952 &&\
	tetri->tetri != 27648 && tetri->tetri != 50688 && tetri->tetri != 19584 &&\
	tetri->tetri != 35904 && tetri->tetri != 19968 && tetri->tetri != 35968 &&\
	tetri->tetri != 58368 && tetri->tetri != 19520)
		tetri->tetri = tetri->tetri * 2;
	tetri = param_tetri(tetri);
	return ((tetri->tetri > 61440) ? -1 : 0);
}

t_map	*readfile(t_map *map, char *file)
{
	int		fd;
	char	buff[22];
	int		ret;
	int		i;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (free_map(map));
	i = 0;
	map->nbr_tetri = 0;
	while ((ret = read(fd, buff, 21)) > 0)
	{
		buff[ret] = '\0';
		if (ret < 20 || check_buff(buff, ret) == -1)
			return (close(fd) == -1 ? free_map(map) : free_map(map));
		map->tetri[i].letter = 'A' + i;
		if ((create_tetri(&map->tetri[i], buff)) == -1)
			return (close(fd) == -1 ? free_map(map) : free_map(map));
		if ((map->nbr_tetri = map->nbr_tetri + 1) > 26)
			return (close(fd) == -1 ? free_map(map) : free_map(map));
		i++;
		if (ret == 20)
			break ;
	}
	return ((ret != 20 || close(fd) == -1) ? free_map(map) : map);
}
