/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** sphere
*/

#include "raytracer.hpp"

RayTracer::Sphere::Sphere(Math::Point3D center, double radius) : center(center), radius(radius)
{
}

bool RayTracer::Sphere::hits(RayTracer::Ray ray)
{
    Math::Vector3D x(center.x, center.y, center.z);
    Math::Vector3D oc = ray.vector - x;
    double a = oc.dot(ray.vector);
    double b = 2 * oc.dot(ray.vector);
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return false;
    }
    else {
        return true;
    }
}
