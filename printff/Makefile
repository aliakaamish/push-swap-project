NAME	=	libftprintf.a
SRCS = file1.c printf.c file2.c file3.c file4.c file5.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
all: $(NAME)
$(NAME): $(OBJS)
	ar	rcs	$(NAME)	$(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
