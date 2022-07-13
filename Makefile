FT_PRINTF_SRC	=  

OBJS 			= $(FT_PRINTF_SRC:.c=.o)

NAME			= libftprintf.a

CC				= gcc

FLAGS			= -Wall -Wextra -Werror -c -I. 

ARRC			= ar rcs

RM				= rm -f 

all		: $(NAME)

$(NAME)	: ${OBJS}
		make -C libft
		cp libft/libft.a ./$(NAME)
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
		
		




