# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 10:51:01 by danimart          #+#    #+#              #
#    Updated: 2025/03/10 04:36:37 by daniema3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3

SRC_DIR = ./src
OBJ_DIR = ./objs

SRCS =	util/ps_malloc.c\
		push_swap.c\
		stack_manager.c\
		input_checker.c\
		swap_func.c\
		push_func.c\
		rotate_func.c\
		str_utils.c\
		list_utils.c\
		rev_rotate_func.c\
		sort_func.c\
		sort_utils.c\
		full_sort_utils.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS_AMOUNT = $(words $(SRCS))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo -n "\r⏳ \e[0;33mCompiling $(notdir $<)..."
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo -n "\r✅ \e[0;32mpush_swap successfully compiled!                   "
	@echo 

clean:
	@echo -n "\r⏳ \e[0;33mRemoving $(NAME) objs."
	@rm -rf $(OBJS)
	@echo -n "\r✅ \e[0;32mSuccessfully removed $(NAME) objs."
	@echo 

fclean: clean
	@echo -n "\r⏳ \e[0;33mRemoving $(NAME) executable."
	@rm -rf $(OBJS)
	@echo -n "\r✅ \e[0;32mSuccessfully removed $(NAME) executable."
	@echo 

re: fclean $(NAME)

.PHONY: all clean fclean re
