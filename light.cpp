/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** light.cpp
*/

#include "light.hpp"

Directional::Directional(Math::Vector3D l, double p) : light(l), pourcent(p) {}

double Directional::color_pourcent(Math::Vector3D normal, Math::Point3D point)
{
    double cos = light.dot(normal);
    if (light.length() == 0 || normal.length() == 0)
        return ((cos / 0.0001 * pourcent));
    cos = cos / (light.length() * normal.length());
    return cos * pourcent;
}

Math::Vector3D Directional::get_vector(Math::Point3D point)
{
    return light;
}

Point::Point(Math::Point3D l, double p) : light(l), pourcent(p) {}

double Point::color_pourcent(Math::Vector3D normal, Math::Point3D point)
{
    Math::Vector3D vector = light - point;
    double cos = vector.dot(normal);
    if (vector.length() == 0 || normal.length() == 0)
        return ((cos / 0.0001 * pourcent));
    cos = cos / (vector.length() * normal.length());
    return cos * pourcent;
}

Math::Vector3D Point::get_vector(Math::Point3D point)
{
    return light - point;
}

