# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stone <stone@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 11:44:20 by stone             #+#    #+#              #
#    Updated: 2021/08/02 12:27:38 by stone            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Minitalk Makefile

NAME	= minitalk

all: $(NAME)

$(NAME):
	make -C mt_server
	make -C mt_client

bonus:
	make bonus -C mt_server
	make bonus -C mt_client

clean:
	make clean -C mt_server
	make clean -C mt_client

fclean:
	make fclean -C mt_server
	make fclean -C mt_client
	rm -f server client

re: fclean all
