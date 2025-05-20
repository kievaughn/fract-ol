# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 12:11:12 by kbrandon          #+#    #+#              #
#    Updated: 2024/11/13 12:11:41 by kbrandon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_isascii.c ft_strchr.c ft_strrchr.c ft_isalnum.c ft_isdigit.c ft_strlen.c ft_tolower.c ft_isalpha.c ft_isprint.c ft_strncmp.c ft_toupper.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c ft_substr.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_putchar.c ft_putnbr_u.c ft_putnbr.c ft_putstr.c ft_puthex.c

BONUS_SRCS = ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c
             
OBJS = $(SRCS:.c=.o)

HEADERS = libft.h

all: $(TARGET)

$(TARGET): $(OBJS)
	ar -rcs $(TARGET) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar -rcs $(TARGET) $(OBJS) $(BONUS_OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: 
	rm -f $(OBJS) $(TARGET)

re: fclean all

.PHONY: all bonus clean fclean re 
