NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRCS =  ft_utils.c ft_check.c ft_printf.c\
		 puts.c \
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< 

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all