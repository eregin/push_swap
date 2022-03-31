# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ereginia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 17:20:51 by ereginia          #+#    #+#              #
#    Updated: 2021/10/18 12:25:31 by ereginia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c\
		ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c\
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c\
		ft_strrchr.c ft_strnstr.c ft_tolower.c ft_toupper.c ft_substr.c\
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		ft_putnbr_fd.c
SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		 ft_lstmap.c
OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}
GCC = gcc
CFLAGS = -Wall -Wextra -Werror
DEL = rm -rf
LIB = ar rcs
HEADER = libft.h

NAME = libft.a 

.c.o:
		${GCC} ${CFLAGS} -c  $< -o ${<:.c=.o}

${NAME}:${OBJS} ${HEADER}
		${LIB} ${NAME} ${OBJS}

all: ${NAME}

bonus:	${OBJS} ${OBJS_B} ${HEADER}
		${LIB} ${NAME} ${OBJS} ${OBJS_B} 

clean:	
		${DEL} ${OBJS} ${OBJS_B}

fclean:	clean
		${DEL} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
	




