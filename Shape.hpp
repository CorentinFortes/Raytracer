/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** Shape.hpp
*/

#pragma once

#include "include.hpp"

class Sphere : public IShape
{
public:
    Math::Point3D center;
    double radius;
    Sphere(Math::Point3D center, double radius);
    ~Sphere() {};
    bool hits(RayTracer::Ray) override;
};

class Plane : public IShape
{
public:
    Plane(double y, char axis);
    ~Plane() {};
    bool hits(RayTracer::Ray) override;
    double coo;
    char axis;
};

