# Directories
PROJECT		=	libftprintf
BINDIR		?=	.
BUILDDIR	?=	build
SHELL		=	bash
NAME		=	$(BINDIR)/libftprintf.a

# Compiler options
CC			=	clang
CFLAGS		=	$(addprefix -I,$(INCLUDE)) -Wall -Wextra -Werror -g

# Color output
BLACK		=	"\033[0;30m"
RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[0;34m"
MAGENTA		=	"\033[0;35m"
CYAN		=	"\033[0;36m"
WHITE		=	"\033[0;37m"
END			=	"\033[0m"

SRC += digits.c
SRC += eval_post.c
SRC += ft_snprintf.c
SRC += ft_dprintf.c
SRC += ft_vsnprintf.c
SRC += ft_sprintf.c
SRC += s_conv.c
SRC += percent.c
SRC += ft_vdprintf.c
SRC += eval_fmt.c
SRC += parsers.c
SRC += ft_printf.c
SRC += get_result.c
SRC += ft_vsprintf.c
SRC += ws_conv.c
SRC += ft_asprintf.c
SRC += ft_vprintf.c
SRC += i_conv.c
SRC += p_conv.c
SRC += ft_vasprintf.c
SRC += n_conv.c

LIB += libvect.a
LIB += libft.a

OBJECTS		=	$(addprefix $(BUILDDIR)/, $(SRC:%.c=%.o))
LIBRARIES	=	$(addprefix $(BUILDDIR)/, $(LIB))
LIBLINK		=	$(addprefix -l, $(LIB:lib%.a=%))

all: $(NAME)

$(BUILDDIR)/%.a: %
	@printf $(BLUE)$(PROJECT)$(END)'\t'
	BINDIR=$(CURDIR)/$(BUILDDIR) BUILDDIR=$(CURDIR)/$(BUILDDIR) \
		   make -C $<

$(BUILDDIR)/%.o: %.c
	@[ -d $(BUILDDIR) ] || mkdir $(BUILDDIR)
	@printf $(YELLOW)$(PROJECT)$(END)'\t'
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBRARIES) $(OBJECTS)
	@printf $(YELLOW)$(PROJECT)$(END)'\t'
	@ar rc $(@) $(addprefix $(BUILDDIR)/, $(shell ls $(BUILDDIR)/))
	@echo OK

.PHONY: clean fclean re

clean:
	@printf $(YELLOW)$(PROJECT)$(END)'\t'
	rm -rf build/

fclean: clean
	@printf $(YELLOW)$(PROJECT)$(END)'\t'
	rm -rf $(NAME)

re: fclean all
