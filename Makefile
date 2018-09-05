# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asenat <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 17:26:46 by asenat            #+#    #+#              #
#    Updated: 2018/09/05 11:25:38 by asenat           ###   ########.fr        #
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
ifeq ($(shell uname -s), Darwin)
LIBFT_FLAGS	:= -L./libft -lft
else
LIBFT_FLAGS	+= -L./libft -Wl,--whole-archive -lft -Wl,--no-whole-archive
endif
#

## pthread
PTHREAD_FLAGS	:= -lpthread -D_REENTRANT
#

## Standard things
#
.SUFFIXES:
NAME		:= libft_malloc_$(HOSTTYPE).so
SHORT_NAME	:= libft_malloc.so
CC 		:= clang
CFLAGS		:= -I. -fPIC -Wall -Wextra -Werror -g
LFLAGS		:= -shared $(PTHREAD_FLAGS) $(LIBFT_FLAGS)
RM		:= rm -f
OBJECT_DIR	:= obj
COMP		:= $(CC) $(CFLAGS) -c -o
ifeq ($(shell uname -s), Darwin)
ECHO		:= echo
else
ECHO		:= echo -e
endif
#

## Sources directories
#
TEST_DIRS	:= tests
SRC_DIRS	:= ft_malloc utils malloc
#

## Colors
#
BLUE		:= "\033[34m"
GREEN		:= "\033[32m"
RED		:= "\033[31m"
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

$(NAME): $(LIBFT) $(OBJ_DIRS) $(OBJECTS) $(IMPL_OBJS)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJECTS) $(IMPL_OBJS)
	@$(ECHO) $(PNAME)$(GREEN) "linking complete"$(RESET)

$(SHORT_NAME):
	ln -fs $(NAME) $(SHORT_NAME)
	@$(ECHO) $(SHORT_NAME)$(GREEN) "->" $(PNAME)$(GREEN) "generated"$(RESET)

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
	@$(ECHO) "Objects directories removed"

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME) $(SHORT_NAME) $(TEST_TARGETS)
	@$(MAKELIBFT) fclean
	@$(ECHO) $(NAME) "and" $(SHORT_NAME) "deleted"

.PHONY: re
re: fclean all
