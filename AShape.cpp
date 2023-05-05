/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** IShape.cpp
*/

#include "AShape.hpp"

void AShape::printColor(std::ofstream *file, double pourcent)
{
    if (pourcent >= 1)
        pourcent = 1;
    if (pourcent <= 0)
        pourcent = 0;
    *file << std::fixed << std::setprecision(0) << color_r * pourcent << " " << std::fixed << std::setprecision(0) << color_g * pourcent << " " << std::fixed << std::setprecision(0) << color_b * pourcent << " " << std::endl;
}

void AShape::setColor(int r, int g, int b)
{
    color_r = r;
    color_g = g;
    color_b = b;
}
