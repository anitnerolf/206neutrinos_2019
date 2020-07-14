/*
** EPITECH PROJECT, 2020
** neutrinos
** File description:
** header file
*/

#ifndef NEUTRINOS_HPP_
#define NEUTRINOS_HPP_

#include <string>

class Neutrinos {
public:
    Neutrinos();
    ~Neutrinos();
    int	SaveValues(char **);
    int Loop(void);
    double ArithmeticMean(int);
    double HarmonicMean(int);
    double StandardDeviation(int);
private:
    int n;
    double a;
    double h;
    double sd;
    std::string next_value;
};

void	print_usage(void);
int	get_arguments(int, char **);
int	check_if_number(std::string);

#endif /* NEUTRINOS_HPP_ */
