# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 14:55:40 by crmanzan          #+#    #+#              #
#    Updated: 2024/05/04 18:30:32 by crmanzan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD
OBJ_DIR = obj/
INC = libft.h

SRCS = 	ft_isalnum.c	ft_split.c		ft_strdup.c			ft_substr.c \
		ft_strlen.c		ft_memset.c 	ft_putstr_fd.c 		ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c 	ft_striteri.c 		ft_strmapi.c \
		ft_atoi.c 		ft_itoa.c 		ft_calloc.c 		ft_bzero.c \
		ft_strtrim.c 	ft_strlcpy.c 	ft_strjoin.c 		ft_strnstr.c \
		ft_memcmp.c 	ft_strrchr.c 	ft_strchr.c 		ft_memmove.c \
		ft_memchr.c 	ft_isalpha.c 	ft_isascii.c 		ft_isdigit.c \
		ft_isprint.c 	ft_tolower.c 	ft_toupper.c 		ft_strlcat.c \
		ft_strncmp.c 	ft_memcpy.c 
		
SRCS_BONUS =		ft_lstadd_back.c	ft_lstaddd_front.c \
					ft_lstclear.c 		ft_lstdelone.c \
					ft_lstiter.c 		ft_lstlast.c \
					ft_lstnew.c 		ft_lstsize.c \
					ft_lstmap.c

OBJ = $(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))
OBJ_BONUS = $(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS_BONUS))

DEP = $(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	ar rcs $(NAME) $(OBJ)

-include $(DEP)

$(OBJ_DIR)%.o : %.c Makefile $(INC)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: .bonus

.bonus : $(OBJ) $(OBJ_BONUS) $(INC)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)
	touch $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
.PHONY: all clean fclean re bonus
