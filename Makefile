
SRC				= 	ft_printf.c\
					src/ft_checks.c\
					src/ft_concheck.c\
					src/ft_flagscheck.c\
					src/ft_initializeflags.c\
					src/ft_print_percent.c\
					src/ft_print.c\
					src/ft_print_char.c\
					src/ft_print_str.c\
					src/ft_precision_width.c\
					src/ft_print_null.c\
					src/ft_s_only_dot.c\

OBJS 			= 	ft_printf.o\
					src/ft_checks.o\
					src/ft_concheck.o\
					src/ft_flagscheck.o\
					src/ft_initializeflags.o\
					src/ft_print_percent.o\
					src/ft_print.o\
					src/ft_print_char.o\
					src/ft_print_str.o\
					src/ft_precision_width.o\
					src/ft_print_null.o\
					src/ft_s_only_dot.o\

NAME			= libftprintf.a

CC				= gcc

FLAGS			= -Wall -Wextra -Werror -c -I.

ARRC			= ar rcs

RM				= rm -f 

all		: $(NAME)

bonus	: all

$(NAME)	: ${OBJS}
		make -C libft
		cp libft/libft.a .
		mv libft.a $(NAME)
		${ARRC} ${NAME} ${OBJS}

%.o		: %.c
		${CC} ${FLAGS} $< -o $@

clean	:
		make clean -C libft
		${RM} ${OBJS}

fclean	: clean
		make fclean -C libft
		${RM} ${NAME}

re		: fclean all

.PHONY	:all clean fclean re
		
		




