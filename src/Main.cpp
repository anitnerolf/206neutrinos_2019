/*
** EPITECH PROJECT, 2020
** neutrinos
** File description:
** main
*/

#include "../include/Neutrinos.hpp"
#include <iostream>
#include <cstring>
#include <string>

int	main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        print_usage();
    } else if (ac == 5) {
        return (get_arguments(ac, av));
    } else {
        print_usage();
        return 84;
    }
    return 0;
}

void	print_usage(void)
{
    std::cout << "USAGE\n\t./206neutrinos n a h sd\n" << std::endl;
    std::cout << "DESCRIPTION\n\tn\tnumber of values" << std::endl;
    std::cout << "\ta\tarithmetic mean" << std::endl;
    std::cout << "\th\tharmonic mean" << std::endl;
    std::cout << "\tsd\tstandard deviation" << std::endl;
}

int	get_arguments(int ac, char **av)
{
    Neutrinos n;

    for (int i = 1; i < ac; i++) {
        if (check_if_number(av[i]) != 0) {
            std::cout << "You must enter positive number!" << std::endl;
            return (84);
        }
    }
    return (n.SaveValues(av));
}

int	check_if_number(std::string str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 57 || str[i] < 48)
            return 84;
        i++;
    }
    return 0;
}
