# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 13:26:02 by vgoncalv          #+#    #+#              #
#    Updated: 2023/05/31 15:45:45 by vgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=animals

CC = c++
CFLAGS = -Wall -Werror -Wextra -Wshadow --pedantic-errors -std=c++98

SRC_DIR := ./src
BUILD_DIR = ./build

SRCS := main.cpp AAnimal.cpp Brain.cpp Cat.cpp Dog.cpp

OBJS := $(addprefix $(BUILD_DIR)/,$(SRCS:%.cpp=%.o))
SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
