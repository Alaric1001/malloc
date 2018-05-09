# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asenat <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 17:26:46 by asenat            #+#    #+#              #
#    Updated: 2018/05/08 17:59:49 by asenat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Retrieving HOSTTYPE if it doesn't exists
#
ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
#


## Libft
LIBFT		:= libft/libft.a
MAKELIBFT	:= make -C libft
#

## Standard things
#
NAME		:= libft_malloc_$(HOSTTYPE).so
SHORT_NAME	:= libft_malloc.so
CC 			:= gcc
CFLAGS		:= -I. -fPIC -Wall -Wextra -Werror
LFLAGS		:= -shared
RM			:= rm -f
OBJECT_DIR	:= obj
COMP		:= $(CC) $(CFLAGS) -c -o
#

## Sources directories
#
SRC_DIRS	:= malloc
#

## Colors
#
BLUE		:= "\033[34m"
GREEN		:= "\033[32m"
RESET		:= "\033[0m"
PNAME		:= $(BLUE)$(NAME)$(RESET)
#
.PHONY: all
all: $(NAME) $(SHORT_NAME)

## Including sources files
#
include $(patsubst %, %/Sources.mk, $(SRC_DIRS))
#

OBJ_DIRS	:= $(patsubst %, %/obj, $(SRC_DIRS))

$(NAME): $(LIBFT) $(OBJ_DIRS) $(OBJECTS)
	$(CC) $(LFLAGS) -o $(NAME) $(LIBFT) $(OBJECTS)
	@echo $(PNAME)$(GREEN) "linking complete"$(RESET)

$(SHORT_NAME):
	ln -fs $(NAME) $(SHORT_NAME)
	@echo $(SHORT_NAME)$(GREEN) "->" $(PNAME)$(GREEN) "generated"

## Including compilation rules
#
include $(patsubst %, %/Rules.mk, $(SRC_DIRS))
#

$(LIBFT):
	@$(MAKELIBFT)

$(OBJ_DIRS):
	@mkdir -p $(OBJ_DIRS)

.PHONY: clean
clean:
	@$(RM) -r $(OBJ_DIRS)
	@echo "Objects directories removed"

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME) $(SHORT_NAME)
	@$(MAKELIBFT) fclean
	@echo $(NAME) "and" $(SHORT_NAME) "deleted"

.PHONY: re
re: fclean all
