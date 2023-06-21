# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 11:38:17 by hachahbo          #+#    #+#              #
#    Updated: 2023/06/21 12:55:24 by hachahbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc
CFLAGS = -Werror -Wall -Wextra

OBJS = philo_bonus.o ft_change_the_type_1.o ft_parcing.o \
		ft_change_the_type_2.o ft_parcing2.o ft_philo_helper_one.o \
		routine.o ft_isdigit.o ft_split.o ft_strjoin.o ft_lstadd_back.o \
		ft_atoi.o ft_lstlast.o ft_lstnew.o ft_strlen.o ft_substr.o ft_strdup.o\
		activities.o

RM = rm -f

all : $(NAME)
	@echo "           __    _ __                       __                  "
	@echo "    ____  / /_  (_) /___  _________  ____  / /_  ___  __________"
	@echo "   / __ \/ __ \/ / / __ \/ ___/ __ \/ __ \/ __ \/ _ \/ ___/ ___/"
	@echo "  / /_/ / / / / / / /_/ (__  ) /_/ / /_/ / / / /  __/ /  (__  ) "
	@echo " / .___/_/ /_/_/_/\____/____/\____/ .___/_/ /_/\___/_/  /____/  "
	@echo "/_/                              /_/                            "

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
$(OBJS) : philo_bonus.h

clean : 
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)
	
re : fclean all