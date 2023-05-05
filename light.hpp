/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** light.hpp
*/

#pragma once
#include "include.hpp"
#include "Math.hpp"
#include "Point3D.hpp"
#include "camera.hpp"

// namespace Math {
//     class Vector3D;
// }

class Directional
{
public:
    Directional(Math::Vector3D light, double pourcent);
    ~Directional() {};
    Math::Vector3D light;
    double pourcent;
    double color_pourcent(Math::Vector3D light);
};

