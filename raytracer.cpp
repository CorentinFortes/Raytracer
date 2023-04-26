/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** raytracer.cpp
*/

#include "raytracer.hpp"
#include "Math.hpp"
#include <utility>
#include "math.h"

RayTracer::Ray::Ray() : vector(Math::Vector3D()), point(Math::Point3D()) {}

RayTracer::Ray::Ray(Math::Vector3D vec, Math::Point3D po) : vector(vec), point(po) {}

RayTracer::Ray::Ray(RayTracer::Ray const& other) : vector(other.vector), point(other.point) {}

RayTracer::Ray::Ray(RayTracer::Ray &&other) : vector(Math::Vector3D()), point(Math::Point3D())
{
    std::exchange(vector, other.vector);
    std::exchange(point, other.point);
}

RayTracer::Ray& RayTracer::Ray::operator=(RayTracer::Ray const& other)
{
    vector = other.vector;
    point = other.point;
    return *this;
}

RayTracer::Ray& RayTracer::Ray::operator=(RayTracer::Ray &&other)
{
    std::exchange(vector, other.vector);
    std::exchange(point, other.point);
    return *this;
}

bool hits(RayTracer::Ray)
{
    return true;
}

RayTracer::Camera::Camera()
{
    Rectangle3D screen = Rectangle3D(Math::Point3D(0, 0, 0.5), Math::Vector3D(1, 0, 0), Math::Vector3D (0, 1, 0));
    origin = Math::Point3D(0, 0, 0);
}

RayTracer::Camera::Camera(Rectangle3D screen)
{
    this->screen = screen;
    origin = Math::Point3D(0, 0, 0);
}

RayTracer::Ray RayTracer::Camera::ray(double x, double y)
{
    return RayTracer::Ray(Math::Vector3D(x/2, y/2, 0) ,Math::Point3D(0, 0, 0));
}