# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechung <sechung@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 20:38:13 by sechung           #+#    #+#              #
#    Updated: 2023/05/15 16:14:51 by sechung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strcmp.c

BNS_SRCS	= ft_lstnew.c \
			ft_lstsize.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(BNS_SRCS:.c=.o)

NAME		=	libft.a
RM			=	rm -f
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ_SWITCH = $(OBJS) $(OBJS_BONUS)
else
	OBJ_SWITCH = $(OBJS)
endif

$(NAME)		:	$(OBJ_SWITCH)
			ar rc $@ $^

.c.o		:
			$(CC) $(CFLAGS) -c $< -o $@ -I./

all			:	$(NAME)

clean		:
			@$(RM) $(OBJS) $(OBJS_BONUS)

fclean		:	clean
			@$(RM) $(NAME)

re			:	fclean all

bonus		:
			$(MAKE) WITH_BONUS=1 $(NAME)

.PHONY		:	all clean fclean re bonus
