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
    Math::Vector3D oc = ray.point - center;
    double a = ray.vector.dot(ray.vector);
    double b = 2 * oc.dot(ray.vector);
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return false;
    }
    double rassine = sqrt(discriminant);
    double t1 = (-b - rassine) / (2.0 * a);
    double t2 = (-b + rassine) / (2.0 * a);
    if (t1 < 0.0 && t2 < 0.0) {
        return false;
    }
    else
        return true;
}

Plane::Plane(double y, char a) : coo(y), axis(a) {}

bool Plane::hits(RayTracer::Ray ray)
{
    if (axis == 'x') {
        double value = (coo - ray.point.x);
        if (std::abs(value) < std::abs(value + ray.vector.x))
            return false;
        else
            return true;
    }
    if (axis == 'y') {
        double value = (coo - ray.point.y);
        if (std::abs(value) < std::abs(value + ray.vector.y))
            return false;
        else
            return true;
    }
    if (axis == 'z') {
        double value = (coo - ray.point.z);
        if (std::abs(value) < std::abs(value + ray.vector.z))
            return false;
        else
            return true;
    }
    return false;
}

Cylindre::Cylindre(Math::Point3D center, double radius, char ax) : center(center), radius(radius), axis(ax) {}

bool Cylindre::hits(RayTracer::Ray ray)
{
    if (axis == 'x') {
        ray.vector.x = 0;
        ray.point.x = 0;
        center.x = 0;
    }
    if (axis == 'y') {
        ray.vector.y = 0;
        ray.point.y = 0;
        center.y = 0;
    }
    if (axis == 'z') {
        ray.vector.z = 0;
        ray.point.z = 0;
        center.z = 0;
    }
    Math::Vector3D oc = ray.point - center;
    double a = ray.vector.dot(ray.vector);
    double b = 2 * oc.dot(ray.vector);
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return false;
    }
    double rassine = sqrt(discriminant);
    double t1 = (-b - rassine) / (2.0 * a);
    double t2 = (-b + rassine) / (2.0 * a);
    if (t1 < 0.0 && t2 < 0.0) {
        return false;
    }
    else
        return true;
    // if (axis == 'x') {
    //     Math::Vector3D oc = ray.point - center;
    //     double a = ray.vector.y * ray.vector.y + ray.vector.z * ray.vector.z;
    //     double b = 2 * (ray.point.y * oc.y + ray.point.z * oc.z);
    //     double c = oc.y * oc.y + oc.z * oc.z - radius * radius;
    //     double discriminant = b * b - 4 * a * c;
    //     if (discriminant < 0) {
    //         return false;
    //     }
    //     double rassine = sqrt(discriminant);
    //     double t1 = (-b - rassine) / (2.0 * a);
    //     double t2 = (-b + rassine) / (2.0 * a);
    //     if (t1 < 0.0 && t2 < 0.0) {
    //         return false;
    //     }
    //     else
    //         return true;
    // }
    // if (axis == 'y') {
    //     double a = ray.vector.x * ray.vector.x + ray.vector.z * ray.vector.z;
    //     double b = 2 * (ray.point.x * ray.vector.x + ray.point.z * ray.vector.z);
    //     double c = ray.point.x * ray.point.x + ray.point.z * ray.point.z - radius * radius;
    //     double discriminant = b * b - 4 * a * c;
    //     if (discriminant < 0) {
    //         return false;
    //     }
    //     double rassine = sqrt(discriminant);
    //     double t1 = (-b - rassine) / (2.0 * a);
    //     double t2 = (-b + rassine) / (2.0 * a);
    //     if (t1 < 0.0 && t2 < 0.0) {
    //         return false;
    //     }
    //     else
    //         return true;
    // }
    // if (axis == 'z') {
    //     double a = ray.vector.x * ray.vector.x + ray.vector.y * ray.vector.y;
    //     double b = 2 * (ray.point.x * ray.vector.x + ray.point.y * ray.vector.y);
    //     double c = ray.point.x * ray.point.x + ray.point.y * ray.point.y - radius * radius;
    //     double discriminant = b * b - 4 * a * c;
    //     if (discriminant < 0) {
    //         return false;
    //     }
    //     double rassine = sqrt(discriminant);
    //     double t1 = (-b - rassine) / (2.0 * a);
    //     double t2 = (-b + rassine) / (2.0 * a);
    //     if (t1 < 0.0 && t2 < 0.0) {
    //         return false;
    //     }
    //     else
    //         return true;
    // }
    return false;
}