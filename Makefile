NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_utils.c ft_data.c\
	  ft_parse_flags.c ft_libft.c ft_conv_s.c\
	  ft_conv_c.c ft_conv_u.c ft_conv_d.c\
	  ft_conv_x.c ft_conv_p.c ft_conv_pc.c\
	  ft_put.c
OBJ = $(SRC:.c=.o)
INC = libftprintf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c $(INC)
	gcc -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
