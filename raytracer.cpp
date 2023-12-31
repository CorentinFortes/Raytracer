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

RayTracer::Camera::Camera()
{
    Rectangle3D screen = Rectangle3D(Math::Point3D(0, 0, 0.5), Math::Vector3D(1, 0, 0), Math::Vector3D (0, 1, 0));
    origin = Math::Point3D(0, 0, 0);
    width = 1; height = 1;
}

RayTracer::Camera::Camera(Math::Point3D o, double w, double h)
{
    screen = Rectangle3D(Math::Point3D(-0.5 + o.x, -0.5 + o.y, 1 + o.z), Math::Vector3D(1, 0, 0), Math::Vector3D (0, 1, 0));
    origin = o;
    width = w; height = h;
}

RayTracer::Ray RayTracer::Camera::ray(double x, double y)
{
    return RayTracer::Ray(Math::Vector3D(x + screen.origin.x - origin.x, y + screen.origin.y - origin.y, screen.origin.z - origin.z) , origin);
}

Math::Point3D RayTracer::Ray::get_point(double z, Math::Point3D origin)
{
    Math::Point3D point = Math::Point3D(vector.x * z + origin.x, vector.y * z + origin.y, vector.z * z + origin.z);
    return point;
}