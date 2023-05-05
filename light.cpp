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
    double cos = (light.x + normal.x) + (light.y + normal.y) + (light.z + normal.z);
    cos = cos / sqrt(light.x * light.x + light.y * light.y + light.z * light.z) * sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
    return cos * pourcent;
}