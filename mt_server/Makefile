# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 19:56:40 by sdummett          #+#    #+#              #
#    Updated: 2021/08/02 12:18:31 by stone            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
CFLAGS	= -Wall -Werror -Wextra
NAME	= server
SRC		= mt_server.c \
			utils.c \
			ft_itoa.c
SRCBONUS= bonus/mt_server_bonus.c \
			bonus/utils_bonus.c \
			bonus/ft_itoa_bonus.c
OBJ		= $(SRC:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)

# ************************************ #
#                                      #
#                RULES                 #
#                                      #
# ************************************ #

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	cp server ..

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

bonus: $(OBJBONUS)
	$(CC) $(CFLAGS) $(OBJBONUS) -o $(NAME)
	cp server ..

clean:
	rm -f $(OBJ) $(OBJBONUS)
	

fclean: clean
	rm -f $(NAME)

re: fclean all
