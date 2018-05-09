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

## Standard things
#
NAME		:= libft.a
CC 			:= gcc
ARCH		:= ar rc
CFLAGS 		:= -I. -Wall -Wextra -Werror
LLFLAGS 	:= 
RM			:= rm -f
OBJECT_DIR	:= obj
COMP		:= $(CC) $(CFLAGS) -c -o
#

## Colors
#
BLUE		:= "\033[34m"
GREEN		:= "\033[32m"
RESET		:= "\033[0m"
PNAME		:= $(BLUE)$(NAME)$(RESET)
#

## Sources directories
#
SRC_DIRS	:= color gnl lists memory numeric output path string tree
#

.PHONY: all
all: $(NAME)

## Including sources files
#
include $(patsubst %, %/Sources.mk, $(SRC_DIRS))
#

OBJ_DIRS	:= $(patsubst %, %/obj, $(SRC_DIRS))

$(NAME): $(OBJ_DIRS) $(OBJECTS)
	$(ARCH) $(NAME) $(OBJECTS)
	@echo $(PNAME)$(GREEN) "generated !"$(RESET)

## Including compilation rules
#
include $(patsubst %, %/Rules.mk, $(SRC_DIRS))
#

$(OBJ_DIRS):
	@mkdir -p $(OBJ_DIRS)

.PHONY: clean
clean:
	@$(RM) -r $(OBJ_DIRS)
	@echo "Objects directories removed."

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)
	@echo $(PNAME) "deleted."

.PHONY: re
re: fclean all
