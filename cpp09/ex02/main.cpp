#include "PmergeMe.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: no arguments provided." << std::endl;
		return 1;
	}
	std::vector<int> input;
	for (int i = 1; i < argc; i++)
	{
		char *end;
		long num = std::strtol(argv[i], &end, 10);
		if (*end != '\0' || num <= 0 || num > 2147483647)
		{
			std::cerr << "Error: invalid input \"" << argv[i] << "\"." << std::endl;
			return 1;
		}
		input.push_back(static_cast<int>(num));
	}
	PmergeMe sorter(input);
	sorter.sort();
	sorter.displayResults();
	return 0;
}

// ./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "\n" " ")

// Vector stores continous, caches locally, Deque uses chunks of data
