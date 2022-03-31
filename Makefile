# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 17:20:51 by ereginia          #+#    #+#              #
#    Updated: 2022/03/17 14:26:36 by ereginia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

M_NAME = push_swap

B_NAME = checker

LIBFTNAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS_M = push_swap_mandatory/ft_clean.c push_swap_mandatory/ft_is_sorted.c\
		push_swap_mandatory/ft_quick_sort_left.c push_swap_mandatory/ft_quick_sort_right.c\
		push_swap_mandatory/ft_stk_base_op.c push_swap_mandatory/ft_stk_descript.c\
		push_swap_mandatory/push_swap.c push_swap_mandatory/stack_operate.c\
		push_swap_mandatory/ft_quick_sort_r_utils.c push_swap_mandatory/ft_quick_sort_l_utils.c\
		push_swap_mandatory/ft_print_optimaise.c push_swap_mandatory/ft_validation.c\
		push_swap_mandatory/ft_print_opt_cases.c

SRCS_B = push_swap_bonus/ft_clean.c push_swap_bonus/ft_command_handler.c\
		push_swap_bonus/ft_sort_checker.c push_swap_bonus/ft_stk_base_op.c\
		push_swap_bonus/ft_validation.c push_swap_bonus/get_next_line.c\
		push_swap_bonus/checker.c push_swap_bonus/stack_operate.c

OBJS_M = ${SRCS_M:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

LIBFTPATH = libft/

M_PATH = push_swap_mandatory/

B_PATH = push_swap_bonus/

M_HEADER = $(M_PATH)push_swap.h

B_HEADER = $(B_PATH)push_swap_bonus.h

${M_NAME}: ${OBJS_M} ${M_HEADER}
	make -C ${LIBFTPATH}
	${CC} ${FLAGS} -I $(LIBFTPATH) ${OBJS_M} $(LIBFTPATH)${LIBFTNAME} -o ${M_NAME}

${B_NAME}: ${OBJS_B} ${B_HEADER}
	make -C ${LIBFTPATH}
	${CC} ${FLAGS} -I $(LIBFTPATH) ${OBJS_B} $(LIBFTPATH)${LIBFTNAME} -o ${B_NAME}

all: $(M_NAME)

bonus: $(B_NAME)

%.o: %.c	$(M_HEADER) $(B_HEADER)
			$(CC) -I $(LIBFTPATH) -c $(FLAGS) -o $@ $<

clean:
	make clean -C ${LIBFTPATH}
	rm -rf $(M_PATH)${OBJS_M}
	rm -rf $(B_PATH)${OBJS_B}

fclean: clean
	make fclean -C ${LIBFTPATH}
	rm -f $(M_NAME) $(B_NAME)

re: fclean ${NAME}

PHONY: all bonus clean fclean re