# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 10:51:01 by danimart          #+#    #+#              #
#    Updated: 2025/03/17 18:36:45 by daniema3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fdiagnostics-color=always

SRC_DIR = ./src
OBJ_DIR = ./objs

# > ~ List utilities

SRCS =	util/lst/ps_lstadd_back.c\
		util/lst/ps_lstinit.c\
		util/lst/ps_lstlast.c\
		util/lst/ps_lstmin_unmod.c\
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

# > ~ Sorting - General

SRCS +=	sort/check_sorted.c\
		sort/small_sort.c\
		sort/sorter.c

# > ~ Sorting - Full

SRCS +=	sort/full/full_sort.c\
		sort/full/get_pos.c\
		sort/full/send_to_a.c\
		sort/full/send_to_b.c\
		sort/full/simplify_stack.c

# > ~ Main project files

SRCS +=	input_parser.c\
		push_swap.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo -n "\r⏳ \e[0;33mCompiling $(notdir $<)\e[0m                          "
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
