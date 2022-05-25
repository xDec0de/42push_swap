# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danimart <danimart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 10:51:01 by danimart          #+#    #+#              #
#    Updated: 2022/05/25 17:47:18 by danimart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=gcc
CFLAGS=-Wall -Werror -Wextra
SANITIZE=-g3 -fsanitize=address
C_FILES=push_swap.c input_checker.c swap_func.c push_func.c rotate_func.c str_utils.c list_utils.c rev_rotate_func.c \
 push_swap_debugger.c sort_func.c sort_utils.c full_sort_utils.c

O_FILES=$(C_FILES:.c=.o)

all: $(NAME)
headermk:
	@printf "\n\e[1;31m> \e[1;36mMaking \e[1;34m$(NAME)\e[1;36m...\e[1;30m\n\n"
$(NAME): headermk $(O_FILES)
	@printf "\n\e[0;33m-\e[1;32m "
	$(CC)$(C_FLAGS) $(O_FILES) -o $(NAME)
	@printf "\n\033[0m"
clean:
	@printf "\n\e[1;31m> \e[1;36mRemoving \e[1;34m$(NAME)\e[1;36m objects...\e[1;30m\n\n"
	@printf "\e[0;33m-\e[1;32m "
	rm -rf $(O_FILES)
	@printf "\n\033[0m"
fclean:
	@printf "\n\e[1;31m> \e[1;36mRemoving \e[1;34m$(NAME)\e[1;36m program...\e[1;30m\n\n"
	@printf "\e[0;33m-\e[1;32m "
	rm -rf $(NAME) $(O_FILES)
	@printf "\n\033[0m"
sanitize: headermk $(O_FILES)
	@printf "\n\e[1;31m- \e[0;33mSanitize enabled\n\e[0;33m-\e[1;32m "
	$(CC)$(C_FLAGS) $(O_FILES) -o $(NAME) $(SANITIZE)
	@printf "\n\033[0m"
re: fclean $(NAME)
.PHONY: all clean fclean re