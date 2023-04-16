#include "../include/RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2)
	{
		std::cerr << "Error: usage ./rpn <equation>\n";
		exit(1);
	}
	RPN a(av[1]);
	std::cout << a.computeRPN() << "\n";
	return 0;
}
