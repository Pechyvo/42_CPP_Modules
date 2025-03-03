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
	@echo "Cleaning up..."

fclean:
	@make -C ex00 fclean > /dev/null
	@make -C ex01 fclean > /dev/null
	@make -C ex02 fclean > /dev/null
	@make -C ex03 fclean > /dev/null
	@echo "FCleaning up..."

#Debugging
d: fclean
	make -j$(nproc) -C ex00 DEBUG=1
	make -j$(nproc) -C ex01 DEBUG=1
	make -j$(nproc) -C ex02 DEBUG=1
	make -j$(nproc) -C ex03 DEBUG=1

#Run Exercises
z: fclean all
	valgrind --leak-check=full ./zombie

zd: fclean d
	valgrind --leak-check=full ./zombie

h: fclean all
	valgrind --leak-check=full  ./horde

hd: fclean d
	valgrind --leak-check=full  ./horde

b: fclean all
	valgrind --leak-check=full  ./brain

w: fclean all
	valgrind --leak-check=full  ./weapon

wd: fclean d
	valgrind --leak-check=full  ./weapon

re: fclean all

.PHONY: all clean fclean re