/*
** EPITECH PROJECT, 2020
** neutrinos
** File description:
** neutrinos
*/

#include "../include/Neutrinos.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

Neutrinos::Neutrinos()
{
}

Neutrinos::~Neutrinos()
{
}

int	Neutrinos::SaveValues(char **av)
{
    this->n = atoi(av[1]);
    this->a = atof(av[2]);
    this->h = atof(av[3]);
    this->sd = atof(av[4]);
    return (this->Loop());
}

double	Neutrinos::StandardDeviation(int nextValue)
{
    double get = pow(this->sd, 2) * (double)this->n;
    return (sqrt(1.0 / (double)(this->n + 1) * (get + (pow(((double)nextValue - this->ArithmeticMean(nextValue)), 2)))));
}

double	Neutrinos::HarmonicMean(int nextValue)
{
    return ((double)(this->n + 1) / (((double)this->n / this->h) + (1.0 / (double)nextValue)));
}

double	Neutrinos::ArithmeticMean(int nextValue)
{
    return (((this->a * (double)this->n) + (double)nextValue) / (double)(this->n + 1));
}

int	Neutrinos::Loop(void)
{
    std::cout << "Enter next value: ";
    getline(std::cin, this->next_value);
    if (this->next_value.compare("END") == 0) {
        return 0;
    } else {
        if (check_if_number(this->next_value) != 0 || \
            this->next_value.empty() || stoi(this->next_value) == 0) {
            std::cout << "Number larger than 0 expected!" << std::endl;
            exit (84);
        } else {
            this->a = this->ArithmeticMean(std::stoi(this->next_value));
            this->h = this->HarmonicMean(std::stoi(this->next_value));
            this->sd = this->StandardDeviation(std::stoi(this->next_value));
//            this->root = this->RootMeanSquare(std::stoi(this->next_value));
            this->n++;
            std::cout << "\tNumber of values:\t" << this->n << std::endl;
            std::cout << "\tStandard deviation:\t" << std::fixed << std::setprecision(2) << this->sd << std::endl;
            std::cout << "\tArithmetic mean:\t" << std::fixed << std::setprecision(2) << this->a << std::endl;
            std::cout << "\tRoot mean square:\t" << std::fixed << std::setprecision(2) << (sqrt(pow(this->a, 2) + pow(this->sd, 2))) << std::endl;
            std::cout << "\tHarmonic mean:\t\t" << std::fixed << std::setprecision(2) << this->h << "\n" << std::endl;
            this->Loop();
        }
    }
    return 0;
}
