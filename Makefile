# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 07:16:06 by lprieto-          #+#    #+#              #
#    Updated: 2025/05/22 19:16:47 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ipcalc

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -MMD

RM = rm -rf
 
# **************************************************************************** #

SRCS = ip_calc.c ip_convert.c ip_prints.c ip_utils.c

SRC_PATH := ./src/
OBJ_PATH := ./tmp/

H_PATH := ./inc/
HEADERS = -I$(H_PATH)

DIRSRC = $(addprefix $(SRC_PATH), $(SRCS))
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

DEPS = $(OBJS:.o=.d)

# **************************************************************************** #

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	$(call show_progress)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -MMD -c $< -o $@

clean :
	$(RM) $(OBJ_PATH)

fclean :
	$(RM) $(NAME) $(OBJ_PATH)

re :
	make fclean --silent
	make all --silent

.PHONY: all, clean, fclean, re

.SILENT:

-include $(DEPS)

# **************************************************************************** #

BGRAY =	\033[1;90m
BRED = \033[1;91m
BGREEN = \033[1;92m
BYELLOW = \033[1;33m
BBLUE = \033[1;94m
BCIAN = \033[1;96m
BWHITE = \033[1;97m
GRAY =	\033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
CIAN = \033[0;96m
WHITE = \033[0;97m
PURPLE = \033[0;95m
OR = \033[38;5;214m
BOLD = \033[1m
PHA = \e[1;107;94m
MOU = \e[1;97;44m
RES = \e[0m
EYE = \e[30;47m

# **************************************************************************** #

BAR_LEN := 50
PROGRESS_DURATION := 1 # Duración de la barra de progreso en segundos
TOTAL_ITEMS := $(words $(OBJS))

define show_progress
	@echo; \
	printf " $(GREEN) ▄▄▄▄▄                $(GREEN)▄▄▄▄            $(WHITE)▄   ▄▄▄▄  \n \
 $(GREEN) █    █               $(GREEN)█   █          $(WHITE) █   █   █     ▄██▀ █▀██ \n \
 $(GREEN) █▄   █               $(GREEN)█▄  █          $(WHITE) █   █   █   ▄██▀   ▄█▀▄\n \
 $(GREEN) ██   █ ▄▄▄▄ ▄▄▄▄ $(WHITE)▀▀▀ $(GREEN)██▀▀▀▄ ▄  ▄▄▄▄▄$(WHITE) █▄  █▄▄▄█   ▀▀▀▀██ ▀▀▀▀\n \
 $(GREEN) ██   █ █ ▄▀ █        $(GREEN)██   █ █▄ █▄  █$(WHITE) ██  ██          ▀▀ \n \
 $(GREEN) ██▄▄▄▀ ██▄▄ ██▄▄     $(GREEN)██▄▄▄▀ ██ ██  █$(WHITE) ██  ██       Barcelona\n\n"; \

	total_ticks=$$((PROGRESS_DURATION * 10)); # 20 ticks por segundo para una actualización fluida
	item_progress=0; \
	while [ $$item_progress -le $(TOTAL_ITEMS) ]; do \
		percentage=$$(( 100 * $$item_progress / $(TOTAL_ITEMS) )); \
		filled_len=$$(( $(BAR_LEN) * $$item_progress / $(TOTAL_ITEMS) )); \
		unfilled_len=$$(( $(BAR_LEN) - $$filled_len )); \
		bar=$$(printf "%0.s█" $$(seq 1 $$filled_len)); \
		bar=$$bar$$(printf "%0.s-" $$(seq 1 $$unfilled_len)); \
		printf "\r$(WHITE)[$(GRAY)-%s$(WHITE)] $(WHITE)[$(BWHITE)%d%%$(WHITE)]$(WHITE)" "$$bar" "$$percentage"; \
		sleep $$(echo "scale=2; $(PROGRESS_DURATION) / $(TOTAL_ITEMS)" | bc); \
		item_progress=$$(( $$item_progress + 1 )); \
	done; \
	
	printf "\n\n  $(YELLOW)▄████▄           $(BBLUE)▄█████▄  ${RED}▄█████▄  ${BCIAN}▄█████▄  ${OR}▄█████▄  $(PURPLE)▄█████▄\n \
$(YELLOW)████▄███    $(WHITE)▄▄    $(BBLUE)██${PHA}▄${RES}$(BBLUE)█$(PHA)▄${RES}$(BBLUE)██  ${RED}█${EYE}▄ ${RED}█$(EYE)▄ ${RED}█  ${BCIAN}█$(EYE) ▄${RES}${BCIAN}█$(EYE) ▄${BCIAN}█${RES}  ${OR}█$(EYE) ▀${OR}█$(EYE) ▀${OR}█${RES}  ${PURPLE}█$(EYE)▀ ${PURPLE}█$(EYE)▀ ${RES}${PURPLE}█\n \
$(YELLOW)████▄       $(WHITE)▀▀    $(BBLUE)█${PHA}▀▄▀▄▀${RES}${BBLUE}█${RES}  ${RED}███████  ${BCIAN}███████  ${OR}███████  ${PURPLE}███████\n \
$(YELLOW) ▀████▀  $(BGREEN)lprieto- $(BBLUE)█▀█▀█▀█  ${RED}█▀█▀█▀█  ${BCIAN}█▀█▀█▀█  ${OR}█▀█▀█▀█  ${PURPLE}█▀█▀█▀█\n\n"; \

endef
