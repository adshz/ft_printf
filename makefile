# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szhong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 00:35:41 by szhong            #+#    #+#              #
#    Updated: 2024/01/24 15:38:59 by szhong           ###   ########.fr        #
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
			ft_print_undecimal\
			ft_printptr
SRCS		=	 $(addsuffix .c, $(SRC))

SRCB_DIR	=	srcb
SRCB		=	ft_printf\
			buf_mgr\
			render_char\
			render_fmt\
			render_int\
			render_str\
			parser\
			base_utils\
			set_pad_space\
			set_pad_zero


SRCBS		=	$(addsuffix .c, $(SRCB))

VPATH		=	$(SRCB_DIR)/buf_utils:$(SRCB_DIR)/display_fmt:$(SRCB_DIR)/parse_fmt:$(SRCB_DIR)/utils


MAKEFLAGS	+=	--no-print-directory
OBJ_DIR		=	obj
OBJB_DIR	=	objb

OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJBS		=	$(SRCBS:%.c=$(OBJB_DIR)/%.o)

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

bonus: $(LIBFT) $(OBJB_DIR) $(OBJBS)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJBS)
	@echo "$(GREEN)[ft_print bonus]:$(YELLOW)BONUS Build Complete!$(DEFAULT)\n"

$(OBJB_DIR)/%.o:$(SRCB_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJB_DIR):
	@mkdir -p $(OBJB_DIR)

$(LIBFT):
	@$(MAKE) $(MAKEFLAGS) -C $(LIBFT_PATH) all

clean:
	@$(MAKE) $(MAKEFLAGS) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ_DIR)
	@$(RM) $(OBJB_DIR)
	@$(RM) test/test_bonus
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
