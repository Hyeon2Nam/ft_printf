# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 19:37:13 by hyenam            #+#    #+#              #
#    Updated: 2021/04/09 14:17:07 by hyenam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
LIB_PATH	= ./libft
LIBFT		= libft.a
CFLAGS = -Wall -Werror -Wextra
INC = -I.
CC = gcc
AR = ar rcs
RM = rm -rf

SRCS = 	ft_printf.c \
		put_char.c \
		put_nbr.c \
		put_str.c \
		printf_util.c \

OBJS = $(SRCS:.c=.o)

all : ${NAME}

$(NAME) : $(OBJS)
	make all -C $(LIB_PATH)/
	cp $(LIB_PATH)/$(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(INC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS) 
	make clean -C $(LIB_PATH)/

fclean: clean
	$(RM) $(NAME) 
	make fclean -C $(LIB_PATH)/

re: fclean all

.PHONY: all clean fclean re
