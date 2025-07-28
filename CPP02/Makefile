all: 
	make -j$(nproc) -C ex00 
	make -j$(nproc) -C ex01 
	make -j$(nproc) -C ex02

clean:
	@make -C ex00 clean > /dev/null
	@make -C ex01 clean > /dev/null
	@make -C ex02 clean > /dev/null
	@echo "$(BOLD)$(YELLOW)Cleaning up...$(RESET)"

fclean:
	@make -C ex00 fclean > /dev/null
	@make -C ex01 fclean > /dev/null
	@make -C ex02 fclean > /dev/null
	@echo "$(BOLD)$(YELLOW)FCleaning up...$(RESET)"

#Debugging
d: fclean
	make -j$(nproc) -C ex00 DEBUG=1
	make -j$(nproc) -C ex01 DEBUG=1
	make -j$(nproc) -C ex02 DEBUG=1

#Run Exercises

# Variable to control valgrind usage
VALGRIND = valgrind --leak-check=full

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

#all - compile once, run all with valgrind
run: fclean all
	@echo "$(BOLD)$(YELLOW)Running ex00 (fixed):$(RESET)"
	$(VALGRIND) ./fixed
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (fixed1):$(RESET)"
	$(VALGRIND) ./fixed1
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (fixed2):$(RESET)"
	$(VALGRIND) ./fixed2

#all - compile once, run all without valgrind
runfast: fclean all
	@echo "$(BOLD)$(YELLOW)Running ex00 (fixed):$(RESET)"
	./fixed
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (fixed1):$(RESET)"
	./fixed1
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (fixed2):$(RESET)"
	./fixed2

#all - compile once in debug mode, run all with valgrind
rund: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (fixed) - DEBUG:$(RESET)"
	$(VALGRIND) ./fixed
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (fixed1) - DEBUG:$(RESET)"
	$(VALGRIND) ./fixed1
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (fixed2) - DEBUG:$(RESET)"
	$(VALGRIND) ./fixed2

#all - compile once in debug mode, run all without valgrind
rundfast: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (fixed) - DEBUG:$(RESET)"
	./fixed
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (fixed1) - DEBUG:$(RESET)"
	./fixed1
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (fixed2) - DEBUG:$(RESET)"
	./fixed2

#Individual exercises (compile and run with valgrind)
#ex00
fxd: fclean all
	$(VALGRIND) ./fixed

fxdd: fclean d
	$(VALGRIND) ./fixed

#ex01
fxd1: fclean all
	$(VALGRIND)  ./fixed1

fxd1d: fclean d
	$(VALGRIND)  ./fixed1

#ex02
fxd2: fclean all
	$(VALGRIND)  ./fixed2

fxd2d: fclean d
	$(VALGRIND)  ./fixed2

#Individual exercises (just run, no compilation)
#ex00
fxdr:
	$(VALGRIND) ./fixed

#ex01
fxd1r:
	$(VALGRIND)  ./fixed1

#ex02
fxd2r:
	$(VALGRIND)  ./fixed2

re: fclean all

.PHONY: all clean fclean re