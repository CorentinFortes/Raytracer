/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** Shape.hpp
*/

#pragma once

#include "include.hpp"
#include "AShape.hpp"
#include "Math.hpp"
#include "Point3D.hpp"
#include "raytracer.hpp"

namespace RayTracer {
    class Ray;
}

class Sphere : public AShape
{
public:
    Math::Point3D center;
    double radius;
    Sphere(Math::Point3D center, double radius);
    ~Sphere() {};
    bool hits(RayTracer::Ray) override;
};

class Plane : public AShape
{
public:
    Plane(double y, char axis);
    ~Plane() {};
    bool hits(RayTracer::Ray) override;
    double coo;
    char axis;
};

class Cylindre : public IShape
{
public:
    Cylindre(Math::Point3D center, double radius, char axis);
    ~Cylindre() {};
    bool hits(RayTracer::Ray) override;
    Math::Point3D center;
    char axis;
    double radius;
};