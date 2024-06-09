# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 11:10:27 by noben-ai          #+#    #+#              #
#    Updated: 2024/06/08 10:43:36 by noben-ai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC	= cc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

NAME	= libft.a

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memcmp.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_memchr.c ft_strrchr.c ft_itoa.c \
ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_calloc.c ft_atoi.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_memmove.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_striteri.c ft_split.c ft_strnstr.c get_next_line.c get_next_line_utils.c \

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS	= $(SRCS:.c=.o)

OBJBONUS = $(BONUS:.c=.o)

all:	$(NAME) 

$(NAME):	$(OBJS)
	ar rcs $@ $^

bonus: $(OBJBONUS) 
	ar rcs $(NAME) $^ 

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJBONUS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all 