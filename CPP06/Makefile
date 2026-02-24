# Color definitions
BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
RESET = \033[0m

# Text formatting
BOLD = \033[1m
DIM = \033[2m
ITALIC = \033[3m
UNDERLINE = \033[4m
BLINK = \033[5m
REVERSE = \033[7m
STRIKETHROUGH = \033[9m

# Variable to control valgrind usage
VALGRIND = valgrind --leak-check=full

all: 
	make -j$(nproc) -C ex00
	make -j$(nproc) -C ex01 
	make -j$(nproc) -C ex02
	make -j$(nproc) -C ex03

clean:
	@make -C ex00 clean > /dev/null
	@make -C ex01 clean > /dev/null
	@make -C ex02 clean > /dev/null
	@make -C ex03 clean > /dev/null
	@echo "$(BOLD)$(YELLOW)Cleaning up...$(RESET)"

fclean:
	@make -C ex00 fclean > /dev/null
	@make -C ex01 fclean > /dev/null
	@make -C ex02 fclean > /dev/null
	@make -C ex03 fclean > /dev/null
	@rm -rf *_shrubbery
	@echo "$(BOLD)$(YELLOW)FCleaning up...$(RESET)"

# Debugging
d: fclean
	make -j$(nproc) -C ex00 DEBUG=1
	make -j$(nproc) -C ex01 DEBUG=1
	make -j$(nproc) -C ex02 DEBUG=1
	make -j$(nproc) -C ex03 DEBUG=1

# Run Exercises

# all - compile once, run all with valgrind
run: fclean all
	@echo "$(BOLD)$(YELLOW)Running ex00 (Bureaucrat):$(RESET)"
	$(VALGRIND) ./bur
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Form):$(RESET)"
	$(VALGRIND) ./form
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (AForm):$(RESET)"
	$(VALGRIND) ./form2
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex03 (Intern):$(RESET)"
	$(VALGRIND) ./form3

# all - compile once, run all without valgrind
runfast: fclean all
	@echo "$(BOLD)$(YELLOW)Running ex00 (Bureaucrat):$(RESET)"
	./bur
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Form):$(RESET)"
	./form
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (AForm):$(RESET)"
	./form2
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex03 (Intern):$(RESET)"
	./form3

# all - compile once in debug mode, run all with valgrind
rund: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (Bureaucrat) - DEBUG:$(RESET)"
	$(VALGRIND) ./bur
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Form) - DEBUG:$(RESET)"
	$(VALGRIND) ./form
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (AForm) - DEBUG:$(RESET)"
	$(VALGRIND) ./form2
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex03 (Intern) - DEBUG:$(RESET)"
	$(VALGRIND) ./form3

# all - compile once in debug mode, run all without valgrind
rundfast: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (Bureaucrat) - DEBUG:$(RESET)"
	./bur
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Form) - DEBUG:$(RESET)"
	./form
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (AForm) - DEBUG:$(RESET)"
	./form2
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex03 (Intern) - DEBUG:$(RESET)"
	./form3

# Individual exercises (compile and run with valgrind)
# ex00
bur: fclean
	make -j$(nproc) -C ex00
	$(VALGRIND) ./bur

burd: fclean
	make -j$(nproc) -C ex00 DEBUG=1
	$(VALGRIND) ./bur

# ex01
form: fclean
	make -j$(nproc) -C ex01
	$(VALGRIND) ./form

formd: fclean
	make -j$(nproc) -C ex01 DEBUG=1
	$(VALGRIND) ./form

# ex02
aform: fclean
	make -j$(nproc) -C ex02
	$(VALGRIND) ./form2

aformd: fclean
	make -j$(nproc) -C ex02 DEBUG=1
	$(VALGRIND) ./form2

# ex03
intern: fclean
	make -j$(nproc) -C ex03
	$(VALGRIND) ./form3

internd: fclean
	make -j$(nproc) -C ex03 DEBUG=1
	$(VALGRIND) ./form3

# Individual exercises (just run, no compilation)
# ex00
burr:
	$(VALGRIND) ./bur

# ex01
formr:
	$(VALGRIND) ./form

# ex02
aformr:
	$(VALGRIND) ./form2

# ex03
internr:
	$(VALGRIND) ./form3

re: fclean all

.PHONY: all clean fclean re d run runfast rund rundfast bur burd burr form formd formr aform aformd aformr intern internd internr