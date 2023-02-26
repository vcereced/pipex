# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 21:39:16 by vcereced          #+#    #+#              #
#    Updated: 2023/02/26 21:43:09 by vcereced         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex_path.c pipex.c pipexsplit.c error_handling.c pipex_forking.c

OBJT = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc

LIBFT = ./libft/libft.a

$(NAME): $(OBJT) $(LIBFT)
		$(CC)  $(CFLAGS) $(OBJT) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

all: $(NAME)

bonus: all 

exe: all
	gcc -L./libft -lft $(SRC)

clean:
	rm -f $(OBJT)

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean bonus re exe