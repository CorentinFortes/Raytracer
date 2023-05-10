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
    std::unique_ptr<Math::Point3D>hits(RayTracer::Ray) override;
    Math::Vector3D normal(RayTracer::Ray l) override;
};

class Plane : public AShape
{
public:
    Plane(double y, char axis);
    ~Plane() {};
    std::unique_ptr<Math::Point3D> hits(RayTracer::Ray) override;
    Math::Vector3D normal(RayTracer::Ray l) override;
    double coo;
    char axis;
};

class Cylindre : public AShape
{
public:
    Cylindre(Math::Point3D center, double radius, char axis);
    ~Cylindre() {};
    std::unique_ptr<Math::Point3D> hits(RayTracer::Ray) override;
    Math::Vector3D normal(RayTracer::Ray l) override;
    Math::Point3D center;
    char axis;
    double radius;
};