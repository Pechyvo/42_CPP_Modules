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
	@echo "$(BOLD)$(YELLOW)Running ex00 (Polymorphism):$(RESET)"
	$(VALGRIND) ./poly
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Fire):$(RESET)"
	$(VALGRIND) ./fire
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Abstract class):$(RESET)"
	$(VALGRIND) ./class

#all - compile once, run all without valgrind
runfast: fclean all
	@echo "$(BOLD)$(YELLOW)Running ex00 (Polymorphism):$(RESET)"
	./poly
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Fire):$(RESET)"
	./fire
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Abstract class):$(RESET)"
	./class

#all - compile once in debug mode, run all with valgrind
rund: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (Polymorphism) - DEBUG:$(RESET)"
	$(VALGRIND) ./poly
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Fire) - DEBUG:$(RESET)"
	$(VALGRIND) ./fire
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Abstract class) - DEBUG:$(RESET)"
	$(VALGRIND) ./class

#all - compile once in debug mode, run all without valgrind
rundfast: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (Polymorphism) - DEBUG:$(RESET)"
	./poly
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Fire) - DEBUG:$(RESET)"
	./fire
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Abstract class) - DEBUG:$(RESET)"
	./class

#Individual exercises (compile and run with valgrind)
#ex00
pl: fclean all
	$(VALGRIND) ./poly

pld: fclean d
	$(VALGRIND) ./poly

#ex01
fr: fclean all
	$(VALGRIND)  ./fire

frd: fclean d
	$(VALGRIND)  ./fire

#ex02
cls: fclean all
	$(VALGRIND)  ./class

clsd: fclean d
	$(VALGRIND)  ./class

#Individual exercises (just run, no compilation)
#ex00
plr:
	$(VALGRIND) ./poly

#ex01
frr:
	$(VALGRIND)  ./fire

#ex02
clsr:
	$(VALGRIND)  ./class

re: fclean all

.PHONY: all clean fclean re