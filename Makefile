# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 14:56:28 by iverniho          #+#    #+#              #
#    Updated: 2024/04/25 11:58:49 by iverniho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c stack_utils.c utils.c operations_a.c operations_b.c operations_c.c \
	operations_d.c algorithm.c algorithm_utils.c create_node.c algorithm_utils2.c \
	stack_utils2.c

LIBFT = libft/
LIB := libft/libft.a
PRINTF := printf/libftprintf.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make bonus -C $(LIBFT)
	@make -C printf/
	$(CC) -g $(CFLAGS) $(OBJ) $(LIB) $(PRINTF) -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(LIBFT)/*.o
	rm -rf printf/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a
	rm -f printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re
