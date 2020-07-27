# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skarry <skarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/04 20:43:39 by skarry            #+#    #+#              #
#    Updated: 2020/07/12 12:01:25 by skarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/
ADAPT = ./adaptation/
OUT = ./output/

SRC = ft_printf.c $(LIBFT)ft_putchar.c $(LIBFT)ft_isdigit.c\
	$(LIBFT)work_with_star.c $(LIBFT)ft_isflag.c $(LIBFT)ft_atoi.c\
	$(LIBFT)ft_strlen.c $(LIBFT)ft_intlen.c $(LIBFT)ft_putnbr.c\
	$(LIBFT)ft_putstr.c $(LIBFT)ft_ulen.c $(LIBFT)ft_putunbr.c\
	$(ADAPT)check_flags.c $(LIBFT)ft_xlen.c $(LIBFT)ft_putxnbr.c\
	$(LIBFT)ft_putxbignbr.c $(LIBFT)ft_putpnbr.c $(LIBFT)ft_plen.c\
	$(OUT)type_proc.c $(OUT)type_c.c $(OUT)type_s.c $(OUT)type_di.c\
	$(OUT)type_u.c $(OUT)type_x.c $(OUT)type_p.c
OBJ = $(SRC:.c=.o)

NAME = libftprintf.a
HEADER = ft_printf.h

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)
$(NAME): $(OBJ)
	@ar rc $(NAME) $?
	@ranlib $(NAME)
%.o: %.c $(HEADER)
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:		clean all
