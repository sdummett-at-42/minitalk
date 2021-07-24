# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 16:37:17 by sdummett          #+#    #+#              #
#    Updated: 2021/07/24 22:58:32 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
CFLAGS	= -Wall -Werror -Wextra
NAME	= client
SRC		= mt_client.c \
			utils.c \
			convert_str_to_bits.c \
			debugging_funcs.c

OBJ		= $(SRC:.c=.o)

# ************************************ #
#                                      #
#                RULES                 #
#                                      #
# ************************************ #

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

bonus: all

clean:
	rm -f $(OBJ)
	

fclean: clean
	rm -f $(NAME)

re: fclean all