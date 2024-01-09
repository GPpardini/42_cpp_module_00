#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; av[i] != NULL; i++)
		{
			for (int j = 0; av[i][j] != NULL; j++)
				std::cout << (char)toupper(av[i][j]);
			if (ac - 1 > i)
				std::cout << ' ';
		}
	}
	std::cout << std::endl;
	return (0);
}
