NAME = libft.a

CC = cc
INCDIRS = -I.
CFLAGS = -Wall -Werror -Wextra -g $(INCDIRS) -I$(PRINTF_DIR)
AR = ar rcs

# printf
PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
PRINTF_MAKE = $(MAKE) -C $(PRINTF_DIR)

# Temporary Directory
TMP_DIR = build

# Source files
CFILES = $(addsuffix .c, ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
	ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset ft_strchr ft_strdup ft_strjoin ft_strlcat \
	ft_strlcpy ft_strlen ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper \
	ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_atol)

OBJECTS = $(addprefix $(TMP_DIR)/, $(CFILES:.c=.o))

BONUS_SRC = $(addsuffix .c , ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstiter ft_lstmap ft_lstclear)
BONUS_OBJS = $(addprefix $(TMP_DIR)/, $(BONUS_SRC:.c=.o))

ALL_OBJ = $(OBJECTS) $(BONUS_OBJS)

# Targets
all: $(PRINTF_LIB) $(NAME)

$(PRINTF_LIB):
	@$(PRINTF_MAKE)

$(NAME): $(OBJECTS) $(PRINTF_LIB)
	@mkdir -p $(TMP_DIR)
	@$(AR) $(NAME) $(OBJECTS) printf/*.o
	@rm -rf $(TMP_DIR)

$(TMP_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(ALL_OBJ) $(PRINTF_LIB)
	@mkdir -p $(TMP_DIR)
	@cp $(PRINTF_LIB) $(TMP_DIR)/temp_printf.a
	@cd $(TMP_DIR) && $(AR) x temp_printf.a
	@$(AR) $(NAME) $(ALL_OBJ) $(TMP_DIR)/*.o
	@rm -rf $(TMP_DIR)

clean:
	@echo
	@echo "Removing all object files!"
	@echo
	rm -f $(OBJECTS) $(BONUS_OBJS)
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(PRINTF_LIB)

re: fclean all
	@echo
	@echo "Rebuilding libft"
	@echo

.PHONY: all clean fclean re bonus
