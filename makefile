# **************************************************************************** #
#                                LIBFT MAKEFILE                                #
# **************************************************************************** #

# === Compiler and Flags ===
NAME        := libft.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g
AR          := ar rcs

# === Directories ===
BUILD_DIR   := build
PRINTF_DIR  := printf
GNL_DIR     := get_next_line

INCDIRS     := -I. -I$(PRINTF_DIR) -I$(GNL_DIR)

# === Colors ===
GREEN       := \033[0;32m
YELLOW      := \033[0;33m
RED         := \033[0;31m
BLUE        := \033[0;34m
RESET       := \033[0m

# === Libft Sources ===
SRCS        := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
               ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
               ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
               ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_split.c ft_itoa.c \
               ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
               ft_atol.c free2d.c

OBJS        := $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

# === Bonus Sources ===
BONUS_SRCS  := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
               ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstclear.c
BONUS_OBJS  := $(addprefix $(BUILD_DIR)/, $(BONUS_SRCS:.c=.o))

# === GNL Sources ===
GNL_SRCS    := get_next_line_bonus.c get_next_line_utils_bonus.c
GNL_OBJS    := $(addprefix $(BUILD_DIR)/, $(addprefix $(GNL_DIR)/, $(GNL_SRCS:.c=.o)))

# === Printf Sources ===
PRINTF_SRCS := ft_error.c ft_printf.c ft_putchar.c helper_utils.c hexa_lowercase.c hexa_uppercase.c \
               print_int.c print_ptr.c print_str.c print_unsignednbr.c
PRINTF_OBJS := $(addprefix $(BUILD_DIR)/, $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRCS:.c=.o)))

# === All Objects ===
ALL_OBJS    := $(OBJS) $(GNL_OBJS) $(PRINTF_OBJS)
ALL_BONUS   := $(ALL_OBJS) $(BONUS_OBJS)

# **************************************************************************** #
#                                 TARGETS                                      #
# **************************************************************************** #

all: msg_start $(NAME)

$(NAME): $(ALL_OBJS)
	@echo "$(YELLOW)[AR] Creating $(NAME)$(RESET)"
	@$(AR) $@ $^

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)[CC] $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCDIRS) -c $< -o $@

$(BUILD_DIR)/$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)[CC] $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCDIRS) -c $< -o $@

$(BUILD_DIR)/$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)[CC] $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCDIRS) -c $< -o $@

bonus: msg_start $(NAME)_bonus

$(NAME)_bonus: $(ALL_BONUS)
	@echo "$(YELLOW)[AR] Creating $(NAME) with bonus$(RESET)"
	@$(AR) $(NAME) $^

clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo "$(RED)🧨 Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

msg_start:
	@echo "$(GREEN)🛠️  Building Libft with Printf & GNL...$(RESET)"

.PHONY: all clean fclean re bonus msg_start
