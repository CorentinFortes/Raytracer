/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** IShape.cpp
*/

#include "AShape.hpp"

void AShape::printColor(std::ofstream *file)
{
    *file << color_r << " " << color_g << " " << color_b << " " << std::endl;
}

void AShape::setColor(int r, int g, int b)
{
    color_r = r;
    color_g = g;
    color_b = b;
}
