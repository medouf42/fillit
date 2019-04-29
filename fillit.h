/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:42:51 by mnaji             #+#    #+#             */
/*   Updated: 2019/04/15 01:48:24 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_tetri
{
	unsigned int	tetri;
	unsigned int	l_tetri[20];
	unsigned int	temp;
	int				width;
	int				height;
	char			letter;
}				t_tetri;

typedef struct	s_map
{
	int					size;
	int					nbr_tetri;
	t_tetri				tetri[26];
}				t_map;

int				check_buff(char *buf, int ret);
t_tetri			*param_tetri(t_tetri *tetri);
int				create_tetri(t_tetri *tetri, char *buff);
t_map			*readfile(t_map *map, char *file);
void			initialise_tetri(t_tetri *tetri, int i);
t_tetri			*param_w_and_h_tetri(t_tetri *tetri, int w, int h);
int				smallest_sqare(t_map *map);
t_map			*solve_fillit(t_map *map);
void			resize_tetri(t_tetri *tetri, int size, int new_size, int nbr);
unsigned int	powerof_2(unsigned int power);
int				check_tetri(t_tetri tetri_1, t_tetri tetri_2, int size_map);
int				tetri_is_bol(t_tetri tetri, int size_map);
void			tetri_move_down(t_tetri *tetri, int size_map);
void			tetri_move_left(t_tetri *tetri, int size_map);
void			tetri_move_right(t_tetri *tetri, int size_map);
int				move_tetri(t_tetri *tetri, int size_map);
void			replace_tetri(t_tetri *tetri, int size_map);
int				check_map(t_map *map);
int				check_tetri_move(t_map map, int i);
int				search_place(t_map *map, int i);
int				move_map(t_map *map);
void			print_tetri(t_map *map, int i);
void			param_tetri_2(t_tetri *tetri);
int				print_map(t_map map);
char			*place_letter(t_tetri tetri, char *str, int map_size);
void			ft_putstr(char const *s);
void			ft_bzero(void *s, size_t n);
t_map			*free_map(t_map *map);
#endif
