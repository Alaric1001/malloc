# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asenat <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 17:26:46 by asenat            #+#    #+#              #
#    Updated: 2018/05/12 18:49:14 by asenat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

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
TEST_DIRS	:= tests
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
	@echo $(SHORT_NAME)$(GREEN) "->" $(PNAME)$(GREEN) "generated"$(RESET)

## Including compilation rules
#
include $(patsubst %, %/Rules.mk, $(SRC_DIRS))
#

$(LIBFT):
	@$(MAKELIBFT)

%/$(OBJECT_DIR):
	mkdir $@

## Including tests
#
-include $(patsubst %, %/Rules.mk, $(TEST_DIRS))
#

.PHONY: clean
clean:
	@$(RM) -r $(OBJ_DIRS)
	@echo "Objects directories removed"

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME) $(SHORT_NAME) $(TEST_TARGETS)
	@$(MAKELIBFT) fclean
	@echo $(NAME) "and" $(SHORT_NAME) "deleted"

.PHONY: re
re: fclean all
