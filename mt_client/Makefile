# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 16:37:17 by sdummett          #+#    #+#              #
#    Updated: 2021/08/02 12:23:39 by stone            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
CFLAGS	= -Wall -Werror -Wextra
NAME	= client
SRC		= mt_client.c \
			utils.c
SRCBONUS= bonus/mt_client_bonus.c \
			bonus/utils_bonus.c
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
	cp client ..

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

bonus: $(OBJBONUS)
	$(CC) $(CFLAGS) $(OBJBONUS) -o $(NAME)
	cp client ..

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
