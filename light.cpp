/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** light.cpp
*/

#include "light.hpp"

Directional::Directional(Math::Vector3D l, double p) : light(l), pourcent(p) {}

double Directional::color_pourcent(Math::Vector3D normal)
{
    double cos = light.dot(normal);
    if (light.length() == 0 || normal.length() == 0)
        return ((cos / 0.0001 * pourcent));
    cos = cos / (light.length() * normal.length());
    return cos * pourcent;
}