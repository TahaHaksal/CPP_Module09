#include "../include/PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2)
	{
		std::cerr << "Usage: ./PmergeMe 1 2 3 4...\n";
		exit(1);
	}
	{
		intVec a;
		for (int i = 1; i < ac; i++)
		{
			int num = atoi(av[i]);
			if (num < 0)
			{
				std::cerr << "Error\n";
				exit(1);
			}
			a.push_back(num);
		}
		PmergeMe b(a);
	}
	{
		intList c;
		for (int i = 1; i < ac; i++)
		{
			int num = atoi(av[i]);
			if (num < 0)
			{
				std::cerr << "Error\n";
				exit(1);
			}
			c.push_back(num);
		}
		PmergeMe d(c);
	}
}
