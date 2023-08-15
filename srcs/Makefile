# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmiho-en <cmiho-en@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 11:29:46 by cmiho-en          #+#    #+#              #
#    Updated: 2023/08/15 12:27:31 by cmiho-en         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================== FLAGS ====================================== #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -lXext -lX11

# =============================== PATHS ====================================== #

LIBFT_PATH = ./libft/
SRCS_PATH = ./srcs/
INC_PATH = ./include/
MAP_PATH = ./maps/


# =============================== FILES ====================================== #

SRCS = $(wildcard $(SRCS_PATH)/*.c)
OBJS = $(SRCS:.c=.o)
HEADER = $(wildcard $(INC)/*.h) 

# =============================== RULES ====================================== #

all: $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIBFT_PATH)
	@gcc $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_PATH) -lft

%.o: %.c $(HEADER)
	@gcc $(CFLAGS) -I $(INC_PATH) -c $< -o $@

leak:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(MAP_PATH)$(MAP)

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJS)
	
fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re