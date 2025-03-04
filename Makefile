# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andsoare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 21:02:30 by andsoare          #+#    #+#              #
#    Updated: 2025/03/04 16:41:44 by andsoare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFILES = ft_printf.c ft_print_utils.c ft_print_utils1.c

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OFILES)
	@ar rcs $(NAME) $(OFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files: $(OFILES)"
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
