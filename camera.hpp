/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** camera.hpp
*/

#pragma once

#include "Math.hpp"

class Rectangle3D {
    public:
    Math::Point3D origin;
    Math::Vector3D bottom_side;
    Math::Vector3D left_side;

    Rectangle3D() = default;
    Rectangle3D(Math::Point3D origin, Math::Vector3D bottom_side, Math::Vector3D left_side);
    ~Rectangle3D() {};
    Math::Point3D pointAt(double u, double v);
};
