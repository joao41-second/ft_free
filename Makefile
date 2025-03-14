# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rui <rui@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 06:17:31 by jperpect          #+#    #+#              #
#    Updated: 2025/03/14 22:41:25 by jperpct          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler flags
#WFLGS = -Wall -Wextra -Werror
#READ_FLG = -g 

Libft_dir = ./libft/libft
libft = $(Libft_dir)/libft


FLGS_LIB = $(Libft_dir)/libft.a ./libft/free/ft_free.a ./libft/list_/lsit.a
FLGS = $(WFLGS) $(READ_FLG) 

VAL = valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes --suppressions=readline.supp 

# Make flags
MAKEFLAGS += -s

# Source files
SRCS = $(shell find src -name '*.c')

# Object files
OBJS = $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRCS))

# Libraries
LIB = ./libft/libft/libft.a 

# Commands
AR = ar rcs
CC = cc
RM = rm -f
CAT = cat number.txt

# Output
NAME = minishell
OBJDIR = Objs

# Create object directory if it doesn't exist
$(shell mkdir -p $(OBJDIR))

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(FLGS) -o $@ $<


# Main target
$(NAME): $(OBJS)
	cd libft/free && make 
	cd libft/libft && make bonus
	cd libft/list_ && make 
	$(CC) $(OBJS)  $(FLGS_LIB) $(FLGS) -o $(NAME)
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Compiled Successfully!║"
	@echo "╚══════════════════════════╝"

# Compile all source files
$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(FLGS) -o $@ $<

# Phony targets
.PHONY: all clean fclean re exec norm normi

all: $(NAME)

clean:
	$(RM) -r $(OBJDIR)
	cd ./libft/libft/ && make clean
	cd ./libft/free/  && make clean
	cd ./libft/list_/  && make clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

exec:
	$(CC) -g $(FLGS) $(SRCS)

norm:
	yes y| python3 -m c_formatter_42 -c $(SRCS)

normi:
	norminette $(SRCS)
	cd ./libft && norminette

s:
	clear && make re 

