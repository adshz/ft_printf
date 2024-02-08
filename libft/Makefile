# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szhong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 16:46:51 by szhong            #+#    #+#              #
#    Updated: 2024/01/20 00:54:12 by szhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME		:= libft.a
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror

AR		:= ar -rcs

RM		:= rm -rf

MANDATORY	:= ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strlen.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_strnstr.c \
		  ft_atoi.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c\
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_striteri.c	  

BONUS		:= ft_lstnew.c \
		  ft_lstadd_front.c \
		  ft_lstsize.c \
		  ft_lstlast.c \
		  ft_lstadd_back.c \
		  ft_lstdelone.c \
		  ft_lstclear.c \
		  ft_lstiter.c \
		  ft_lstmap.c

OBJS		:= $(MANDATORY:.c=.o)

OBJS_BONUS	:= $(BONUS:.c=.o)

INCLUDE		= ../include

%.o:		%.c
			@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@echo "$(YELLOW)[libft] $(GREEN)Build Complete!$(DEFAULT)"

bonus:		$(OBJS_BONUS)
		@$(AR) $(NAME) $(OBJS_BONUS)

all:		$(NAME) bonus

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re bonus
