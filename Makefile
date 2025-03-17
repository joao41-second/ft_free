# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 14:51:15 by jperpect          #+#    #+#              #
#    Updated: 2025/03/14 23:11:52 by jperpct          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLGS = -Wall -Wextra -Werror

NAME = ft_free.a

AR = ar rcs

SRCS = ft_free.c ft_free_utilis.c ft_free_pocket.c ft_list.c ft_string.c ft_struct_free.c\
 

OBJECT = $(SRCS:.c=.o) 


CC = cc 

RM = rm -f

COUNT_FILE = count.txt

# Verifica se o arquivo existe; se não, cria com valor inicial 0

COUNT = $(shell cat $(COUNT_FILE))


.SILENT:

all: $(NAME)

$(NAME): $(OBJECT)
	@$(AR) $@ $^
	@rm -f $(COUNT_FILE)

bonus: $(OBJECT_B) $(NAME)
	@ar rcs $(NAME) $(Free_DIR) $^
	@rm -f $(COUNT_FILE)


%.o:%.c $(NAME)
	@cc -c  $(FLGS) -o $@ $< 
	$(eval COUNT=$(shell echo $$(( $(COUNT) + 1 ))))

	# Salva o novo valor de COUNT no arquivo


show_progress:	
	clear

	@PERCENT=$$(($(COUNT) * 100 / $(words $(SRCS)))); \
	PROG_LEN=$$(($$PERCENT / 10)); \
	echo -n "  $(NAME) ["; \
	for i in `seq 1 $$PROG_LEN`; do \
		echo -n "#"; \
	done; \
	for i in `seq $$PROG_LEN 10`; do \
		echo -n " "; \
	done; \
	echo "] $$PERCENT%"


clean:
	$(RM)  $(OBJECT) $(OBJECT_B)
		@rm -f $(COUNT_FILE)

fclean: clean
	$(RM) $(NAME)

re: fclean all
