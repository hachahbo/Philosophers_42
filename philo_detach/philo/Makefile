# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 11:38:17 by hachahbo          #+#    #+#              #
#    Updated: 2023/06/19 15:32:14 by hachahbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = philosophers
# CC = cc
# CFLAGS =  -Werror -Wall -Wextra #-fsanitize=thread

# SRS = philosophers.c ft_change_the_type_1.c ft_parcing.c \
# 		ft_change_the_type_2.c ft_parcing2.c ft_philo_helper_one.c \
# 		routine.c
# OBJS = $(SRS:%.c=%.o)

# RM = rm -f

# LIBFT_DIR = ./libft
# LIBFT_LIB = $(LIBFT_DIR)/libft.a

# SRCS_LIBFT = ft_putstr_fd.c \
# ft_calloc.c ft_isalnum.c ft_isalpha.c \
# ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
# ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
# ft_memset.c ft_split.c ft_strchr.c ft_strdup.c \
# ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
# ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
# ft_strtrim.c ft_tolower.c ft_toupper.c  ft_bzero.c \
# ft_atoi.c ft_strlen.c ft_substr.c ft_putchar_fd.c ft_putendl_fd.c \
# ft_putnbr_fd.c ft_striteri.c  ft_lstnew.c ft_lstadd_front.c\
# ft_lstsize.c ft_lstadd_back.c ft_lstlast.c

# LIBFT_OBJ = ${SRCS_LIBFT:%.c=./libft/%.o}

# all : $(NAME)
# 	@echo "           __    _ __                       __                  "
# 	@echo "    ____  / /_  (_) /___  _________  ____  / /_  ___  __________"
# 	@echo "   / __ \/ __ \/ / / __ \/ ___/ __ \/ __ \/ __ \/ _ \/ ___/ ___/"
# 	@echo "  / /_/ / / / / / / /_/ (__  ) /_/ / /_/ / / / /  __/ /  (__  ) "
# 	@echo " / .___/_/ /_/_/_/\____/____/\____/ .___/_/ /_/\___/_/  /____/  "
# 	@echo "/_/                              /_/                            "
	
# $(NAME) : $(OBJS)  $(LIBFT_OBJ) 
# 	@make -C $(LIBFT_DIR)
# 	 $(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $@
	
# %.o : %.c libft/libft.h
# 	@$(CC) $(CFLAGS) -c $< -o $@

# bonus : all $(NAME_BONUS)

# clean :
# 	@make -C $(LIBFT_DIR) $@
# 	@$(RM) $(OBJS)

# fclean :
# 	@make -C $(LIBFT_DIR) $@
# 	@$(RM) $(OBJS)
# 	@$(RM) $(NAME)
	
# re : fclean all


NAME = philo
CC = cc
CFLAGS = -Werror -Wall -Wextra

OBJS = philo.o ft_change_the_type_1.o ft_parcing.o \
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
	
$(OBJS) : philo.h

clean : 
	@cd libft && make clean
	@$(RM) $(OBJS)

fclean : clean
	@cd libft && make fclean
	@$(RM) $(NAME)
	
re : fclean all