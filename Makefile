# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 10:51:01 by danimart          #+#    #+#              #
#    Updated: 2025/03/13 20:09:50 by daniema3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fdiagnostics-color=always

SRC_DIR = ./src
OBJ_DIR = ./objs

# > ~ List utilities

SRCS =	util/lst/ps_lstinit.c\
		util/lst/ps_lstsize.c

# > ~ General utilities

SRCS +=	util/ps_exit.c\
		util/ps_isdigit.c\
		util/ps_malloc.c\
		util/stack_provider.c\

# > ~ Movements

SRCS +=	movements/push.c\
		movements/rev_rotate.c\
		movements/rotate.c\
		movements/swap.c

# > ~ Main project files

SRCS +=	push_swap.c\
		input_parser.c\
		list_utils.c\
		sort_func.c\
		sort_utils.c\
		full_sort_utils.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS_AMOUNT = $(words $(SRCS))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo -n "\r⏳ \e[0;33mCompiling $(notdir $<)                               "
	@{\
		ERR=$$( ($(CC) $(CFLAGS) -c $< -o $@) 2>&1 );\
		if [ $$? -ne 0 ]; then\
			echo -n "\r❌ \e[0;31mFailed to compile $(notdir $<):        \e[0m";\
			echo "\n$$ERR";\
			exit 1;\
		fi;\
	}

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo -n "\r✅ \e[1;36mpush_swap \e[0;32msuccessfully compiled!             "
	@echo 

clean:
	@echo -n "\r⏳ \e[0;33mRemoving $(NAME) objs.                               "
	@rm -rf $(OBJ_DIR)
	@echo -n "\r✅ \e[0;32mSuccessfully removed $(NAME) objs.                   "
	@echo 

fclean: clean
	@echo -n "\r⏳ \e[0;33mRemoving $(NAME) executable.                         "
	@rm -rf $(NAME)
	@echo -n "\r✅ \e[0;32mSuccessfully removed $(NAME) executable.             "
	@echo 

re: fclean $(NAME)

.PHONY: all clean fclean re
