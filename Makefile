# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danimart <danimart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 10:51:01 by danimart          #+#    #+#              #
#    Updated: 2021/11/22 16:10:28 by danimart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=gcc
CFLAGS=-Wall -Werror -Wextra
PS_C_FILES=push_swap.c
PS_O_FILES=$(PS_C_FILES:.c=.o)
LIB_C_FILES=libft/ft_isdigit.c
LIB_O_FILES=$(LIB_C_FILES:.c=.o)

all: $(NAME)
$(NAME): $(LIB_O_FILES) $(PS_O_FILES)
	@printf "\033[1;33m"
	$(CC)$(C_FLAGS) $(LIB_O_FILES) $(PS_O_FILES) -o $(NAME)
	@printf "\033[0m"
clean:
	@printf "\033[1;33m"
	rm -rf $(O_FILES)
	@printf "\033[0m"
fclean: clean
	@printf "\033[1;33m"
	rm -rf $(NAME)
	@printf "\033[0m"
re: fclean $(NAME)
.PHONY: all clean fclean re