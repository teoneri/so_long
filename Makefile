# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mneri <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:59:44 by mneri             #+#    #+#              #
#    Updated: 2023/02/01 11:38:09 by mneri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = SRC/so_long.c SRC/checkmap.c SRC/checkmap_utils.c SRC/rendermap.c SRC/movement.c SRC/checkmap_utils2.c SRC/enemy.c SRC/enemymovement.c

LINKS = mlx_linux/libmlx_Linux.a -lXext -lX11 -lm

SRC_OBJ = $(SRC:.c=.o)

LIB = ft_printf/libftprintf.a

FLAGS = -Wall -Wextra -Werror -fPIE -fPIC
all : $(NAME)

$(NAME): $(SRC_OBJ) $(HEAD)
	$(MAKE) -C ft_printf/
	$(MAKE) -C mlx_linux/
	$(MAKE) clean -C ft_printf/
	@gcc $(FLAGS) $(SRC_OBJ) $(LIB) $(LINKS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

bonus: all
        
clean:
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ft_printf/
	$(MAKE) clean -C mlx_linux/
re: fclean all
