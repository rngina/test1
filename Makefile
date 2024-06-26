# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 13:49:25 by rtavabil          #+#    #+#              #
#    Updated: 2024/04/29 16:16:57 by rtavabil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

SRC := tokens.c token_utils.c token_utils2.c \
	   token_utils3.c strings.c minishell.c \
	   init_list.c init_inf.c init_outf.c\
	   parse.c
OBJ := $(SRC:%.c=%.o)

CC := cc -g
CFLAGS := -Wall -Wextra -Werror 

OBJ_PATH := obj/
OBJS := $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir -p $(OBJ_PATH)
	@$(CC)  -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) -lreadline

clean:
	@rm -rf $(OBJ_PATH) 

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean 