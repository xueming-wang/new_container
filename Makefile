# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 18:10:07 by xuwang            #+#    #+#              #
#    Updated: 2022/03/31 15:15:48 by xuwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_container

CC 	= c++

CFLAGS 	= -Wall -Wextra -Werror -std=c++98

$(NAME): realcontainer mycontainer

realcontainer : 
		$(CC) $(CFLAGS) ./test_comp/real_container.cpp -o real_container

mycontainer : 
		$(CC) $(CFLAGS) ./test_comp/my_container.cpp -o my_container

fclean:
		rm -rf real_container my_container

all: $(NAME)

re: fclean all 

.PHONY: all fclean re