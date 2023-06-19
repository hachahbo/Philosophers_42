# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 11:38:17 by hachahbo          #+#    #+#              #
#    Updated: 2023/06/19 21:41:17 by hachahbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc
#CFLAGS = -Werror -Wall -Wextra

OBJS = philo_bonus.o ft_change_the_type_1.o ft_parcing.o \
		ft_change_the_type_2.o ft_parcing2.o ft_philo_helper_one.o \
		routine.o

RM = rm -f

all : $(NAME)
	@echo "           __    _ __                       __                  "
	@echo "    ____  / /_  (_) /___  _________  ____  / /_  ___  __________"
	@echo "   / __ \/ __ \/ / / __ \/ ___/ __ \/ __ \/ __ \/ _ \/ ___/ ___/"
	@echo "  / /_/ / / / / / / /_/ (__  ) /_/ / /_/ / / / /  __/ /  (__  ) "
	@echo " / .___/_/ /_/_/_/\____/____/\____/ .___/_/ /_/\___/_/  /____/  "
	@echo "/_/                              /_/                            "

$(NAME) : $(OBJS)
	@cd libft && make 
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)
	
$(OBJS) : philo_bonus.h

clean : 
	@cd libft && make clean
	@$(RM) $(OBJS)

fclean : clean
	@cd libft && make fclean
	@$(RM) $(NAME)
	
re : fclean all