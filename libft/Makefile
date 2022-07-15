

SRCS 		= ft_substr.c\
			  ft_atoi.c\
			  ft_strdup.c\
			  ft_strlen.c\
			  ft_putstr_fd.c\
			  
INCLUDES 	= .

OBJS		= $(SRCS:.c=.o)
		  
NAME		= libft.a

FLAGS		= -Wall -Wextra -Werror -c

CC 			= gcc

LIB 		= ar rcs

CLEAN 		= rm -f ${OBJS}

FCLEAN 		= rm -f $(NAME)

all 	:	$(NAME)

$(NAME) : ${OBJS}
		${LIB} $(NAME) ${OBJS}
	
%.o		: %.c
		${CC} ${FLAGS} -I ${INCLUDES} $< -o ${<:.c=.o} 

clean 	: 
		${CLEAN}

fclean 	: clean 
		${FCLEAN}

re 		:	fclean all

.PHONY	:all clean fclean re
