# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blavonne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 18:43:11 by blavonne          #+#    #+#              #
#    Updated: 2019/09/11 18:47:02 by blavonne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
srcs = *.c
os = *.o
F = -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME):
	gcc $F $(srcs)
	ar rcs $(NAME) $(os)
clean:
	rm -rf $(os)
fclean: clean
	rm -rf $(NAME)
re: fclean all