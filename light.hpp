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

class ILight
{
    public:
    virtual ~ILight() = default;
    virtual double color_pourcent(Math::Vector3D normal, Math::Point3D point) = 0;
};

class Directional : public ILight
{
public:
    Directional(Math::Vector3D light, double pourcent);
    ~Directional() {};
    Math::Vector3D light;
    double pourcent;
    double color_pourcent(Math::Vector3D light, Math::Point3D point) override;
};

class Point : public ILight
{
public:
    Point(Math::Point3D light, double pourcent);
    ~Point() {};
    Math::Point3D light;
    double pourcent;
    double color_pourcent(Math::Vector3D light, Math::Point3D point) override;
};
