NAME=libftprintf.a

CC=cc
INCDIRS=-I.
CFLAGS=-Wall -Werror -Wextra -g $(INCDIRS)
AR = ar rcs


CFILES= $(addsuffix .c, ft_printf print_ptr print_str print_int helper_utils hexa_lowercase hexa_uppercase print_unsignednbr ft_error ft_putchar)
OBJECTS= $(addsuffix .o, ft_printf print_ptr print_str print_int helper_utils hexa_lowercase hexa_uppercase print_unsignednbr ft_error ft_putchar) 

ALL_OBJ = $(OBJECTS)

all: $(NAME)

$(NAME):$(OBJECTS)
	@$(AR) $(NAME) $(OBJECTS) 

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

re: fclean $(NAME)
	@echo 
	@echo "Rebuilding"
	@echo

clean:
	@echo 
	@echo "Removing all executables!"
	@echo
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re