# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 17:16:43 by mcutura           #+#    #+#              #
#    Updated: 2023/05/08 17:23:20 by mcutura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
LIBFT := libft/libft.a
FILES := $(wildcard *.c)
OBJS := $(FILES:%.c=%.o)
HEADER := ft_printf.h
CFLAGS := -Wall -Wextra -Werror
ARFLAGS := rcs

$(NAME): $(OBJS) $(HEADER) $(LIBFT)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C libft all

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
