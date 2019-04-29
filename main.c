/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 13:29:53 by mnaji             #+#    #+#             */
/*   Updated: 2019/04/15 01:37:19 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (-1);
	ft_bzero(map, sizeof(t_map));
	if (argc != 2 || (map = readfile(map, argv[1])) == NULL)
	{
		if (argc != 2)
		{
			free(map);
			map = NULL;
		}
		ft_putstr((argc != 2) ? "usage : ./fillit file\n" : "error\n");
		return (-1);
	}
	map = solve_fillit(map);
	if (map->size > 2)
		print_map(*map);
	free(map);
	map = NULL;
	return (0);
}
