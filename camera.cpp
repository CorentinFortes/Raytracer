/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** camera.cpp
*/

#include "camera.hpp"

Rectangle3D::Rectangle3D() {}

Rectangle3D::Rectangle3D(Math::Point3D origin, Math::Vector3D bottom_side, Math::Vector3D left_side) : origin(origin), bottom_side(bottom_side), left_side(left_side) {}

Math::Point3D Rectangle3D::pointAt(double u, double v)
{
    Math::Point3D point(u, v, 0);
    return point;
}
