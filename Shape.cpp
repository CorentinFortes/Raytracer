/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** sphere
*/

#include "Shape.hpp"

Sphere::Sphere(Math::Point3D center, double radius) : center(center), radius(radius)
{
}

bool Sphere::hits(RayTracer::Ray ray)
{
    Math::Vector3D oc = ray.vector - center;
    double a = oc.dot(ray.vector);
    double b = 2 * oc.dot(ray.vector);
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant <= 0) {
        return false;
    }
    double rassine = sqrt(discriminant);
    double t1 = (-b - rassine) / (2.0 * a);
    double t2 = (-b + rassine) / (2.0 * a);
    if (t1 < 0.0 && t2 < 0.0) {
        return false;
    }
    else {
        return true;
    }
}

Plane::Plane(double y, char a) : coo(y), axis(a) {}

bool Plane::hits(RayTracer::Ray ray)
{
    return true;
}