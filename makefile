# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szhong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 00:35:41 by szhong            #+#    #+#              #
#    Updated: 2024/02/05 19:57:49 by szhong           ###   ########.fr        #
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
			ft_printf_itoa\
			ft_printf_utoa\
			ft_printf_utils\
			ft_printf_xtoa\
			ft_flags\
			ft_nbr_len\
			ft_print_char\
			ft_print_hex\
			ft_print_int\
			ft_print_ptr\
			ft_print_str\
			ft_print_unsigned\
SRCS		=	 $(addsuffix .c, $(SRC))



MAKEFLAGS	+=	--no-print-directory
OBJ_DIR		=	obj
OBJB_DIR	=	objb

OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

INCLUDE		=	include


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS) 
	@cp $(LIBFT) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(YELLOW)[ft_print]:$(GREEN)Build Complete!$(DEFAULT)\n"	

bonus: all


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) $(MAKEFLAGS) -C $(LIBFT_PATH) all

clean:
	@$(MAKE) $(MAKEFLAGS) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ_DIR)
	@$(RM) test/test
	@echo "$(CYAN)Objects removed$(DEFAULT)\n"

fclean: clean
	@$(MAKE) $(MAKEFLAGS) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@echo   "$(CYAN)Removed $(LIBFT)$(DEFAULT)"
	@echo   "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

re: fclean all

test: all
	@echo "\n$(YELLOW)Testing.......$(DEFAULT)\n"
	@$(CC) $(CFLAGS) -I $(INCLUDE) test/main.c -L. -lftprintf -o test/test
	@test/test | cat -e
	@echo "$(GREEN) Test Complete!$(DEFAULT)\n"

test_bonus: bonus
	@echo "\n$(YELLOW)Testing.......$(DEFAULT)\n"
	@$(CC) $(CFLAGS) -I $(INCLUDE) test/main_bonus.c -L. -lftprintf -o test/test_bonus -g3
	@test/test_bonus | cat -e
	@echo "$(GREEN) Test  BONUS  Complete!$(DEFAULT)\n"


.PHONY: all clean fclean re bonus test test_bonus
