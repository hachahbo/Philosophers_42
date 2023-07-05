# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 11:38:17 by hachahbo          #+#    #+#              #
#    Updated: 2023/07/05 10:09:46 by hachahbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CCFLAGS = -Werror -Wall -Werror  #-fsanitize=thread

SRS =  philo.c ft_change_the_type_1.c ft_parcing.c \
		ft_change_the_type_2.c ft_parcing2.c ft_philo_helper_one.c \
		routine.c ft_isdigit.c ft_split.c ft_strjoin.c ft_lstadd_back.c \
		ft_atoi.c ft_lstlast.c ft_lstnew.c ft_strlen.c ft_substr.c ft_strdup.c \
		activities.c

OBJS = $(SRS:.c=.o)

all : $(NAME)
	@echo "           __    _ __                       __                  "
	@echo "    ____  / /_  (_) /___  _________  ____  / /_  ___  __________"
	@echo "   / __ \/ __ \/ / / __ \/ ___/ __ \/ __ \/ __ \/ _ \/ ___/ ___/"
	@echo "  / /_/ / / / / / / /_/ (__  ) /_/ / /_/ / / / /  __/ /  (__  ) "
	@echo " / .___/_/ /_/_/_/\____/____/\____/ .___/_/ /_/\___/_/  /____/  "
	@echo "/_/                              /_/                            "
	
%.o : %.c philo.h
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -Werror $^ -o $@

bonus : all

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

CFLAGS = -Werror -Wall -Werror 
re : fclean all

.phony : all bonus clean fclean re