# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szhong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 00:35:41 by szhong            #+#    #+#              #
#    Updated: 2024/01/20 01:24:14 by szhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# Define Color 
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
MAGENTA = \033[0;95m
YELLOW = \033[0;93m
CYAN =\033[0;96m
WHITE = \033[0;97m
BOLD = \033[91m

CC		=	cc
CFLAGS		=	-Wextra -Werror -Werror -g3
AR		=	ar
ARFLAGS		=	rcs
RM		=	rm -rf

SRC_DIR		=	src
SRC		=	ft_printf\
			ft_printf_utils\
			ft_printhex\
			ft_print_undecimal
SRCS		=	 $(addsuffix .c, $(SRC))


MAKEFLAGS	+=	--no-print-directory
OBJ_DIR		=	obj
OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

INCLUDE		=	include

#how to use static library
#cc -L. -llibftprintf -o myprogram
#-L look for directory 
#-llibftprint links against libftprintf

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS) 
	@cp $(LIBFT) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(YELLOW)[ft_print]:$(GREEN)Build Complete!$(DEFAULT)\n"	

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) $(MAKEFLAGS) -C $(LIBFT_PATH) all

clean:
	@echo "$(CYAN)Object files is cleaning$(DEFAULT)\n"
	@$(MAKE) $(MAKEFLAGS) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(MAKE) $(MAKEFLAGS) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@echo   "$(CYAN)Removed $(LIBFT)$(DEFAULT)"
	@echo   "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

re: fclean all

test: all
	@echo "\n$(YELLOW)Testing.......$(DEFAULT)\n"
	@$(CC) $(CFLAGS) -I $(INCLUDE) test/main.c -L. -llibftprintf -o test/test
	@test/test | cat -e
	@$(RM) test/test
	@echo "$(GREEN) Test Complete!$(DEFAULT)\n"

.PHONY: all clean fclean re test
