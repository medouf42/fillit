# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/10 18:26:23 by mnaji             #+#    #+#              #
#    Updated: 2019/04/15 01:19:15 by mnaji            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

SRCS = main.c ft_fct.c parsing.c solve.c move_tetri.c move_map.c print_map.c ft_bzero.c
OBJS = ${SRCS:.c=.o}
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		@gcc $(FLAGS) -c $(SRCS)
		@gcc $(FLAGS) -o $(NAME) $(OBJS)

clean:
		@rm -rf $(OBJS)

fclean: clean
		@rm -rf $(OBJS) $(NAME)

re: fclean clean all
