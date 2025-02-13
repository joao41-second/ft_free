# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rui <rui@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 06:17:31 by jperpect          #+#    #+#              #
#    Updated: 2024/12/13 16:17:03 by rui              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler flags
#WFLGS = -Wall -Wextra -Werror
READ_FLG = -g 
FLGS = $(WFLGS) $(READ_FLG)

VAL = valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes --suppressions=readline.supp 

# Make flags
MAKEFLAGS += -s

# Source files
SRCS = $(shell find src -name '*.c')

# Object files
OBJS = $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRCS))

# Libraries
LIB = ./libft/libft.a ./libft/libftprintf.a ./libft/get_next_line.a 

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
	cd libft && make compile && make
	$(CC) $(FLGS) $(OBJS) $(LIB) -lreadline -o $(NAME)
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
	cd ./libft && make clean

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
	clear && make re && ./minishell
v:
	clear && make re && $(VAL) ./minishell
e:
	make re && env -i ./minishell
b:
	tmux \; split-window -h \; send-keys 'bash' C-m \; select-pane -t 1 \; send-keys 'make s' C-m \; setw synchronize-panes on
g:
	clear && gdb -tui ./minishell

t:
	make re && cd ./minishell_tester  && ./tester
