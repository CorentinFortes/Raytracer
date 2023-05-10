/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** sphere
*/

#include "Shape.hpp"

Sphere::Sphere(Math::Point3D center, double radius) : center(center), radius(radius) {}

double Sphere::hits(RayTracer::Ray ray)
{
    Math::Vector3D oc = ray.point - center;
    double a = ray.vector.dot(ray.vector);
    double b = 2 * oc.dot(ray.vector);
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return 0;
    }
    if (discriminant == 0) {
        double t = -b / (2.0 * a);
        double z = ray.point.z + t * ray.vector.z;
        return z;
    }
    double rassine = sqrt(discriminant);
    double t1 = (-b - rassine) / (2.0 * a);
    double t2 = (-b + rassine) / (2.0 * a);
    if (t1 < 0.0 && t2 < 0.0) {
        return 0;
    }
    else {
        if (t1 < t2) {
            double z = ray.point.z + t1 * ray.vector.z;
            return z;
        } else if (t2 < t1) {
            double z = ray.point.z + t2 * ray.vector.z;
            return z;
        }
    }
    return 0;
}

Math::Vector3D Sphere::normal(RayTracer::Ray ray)
{
    Math::Vector3D oc = ray.point - center;
    double a = ray.vector.dot(ray.vector);
    double b = 2 * oc.dot(ray.vector);
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant == 0) {
        double t = -b / (2.0 * a);
        double z = ray.point.z + t * ray.vector.z;
        double x = ray.point.x + t * ray.vector.x;
        double y = ray.point.y + t * ray.vector.y;
        Math::Point3D pi(x, y, z);
        Math::Vector3D normal = pi - center;
        double n = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
        normal = normal / n;
        return normal;
    }
    double rassine = sqrt(discriminant);
    double t1 = (-b - rassine) / (2.0 * a);
    double t2 = (-b + rassine) / (2.0 * a);
    if (t1 < t2) {
        double z = ray.point.z + t1 * ray.vector.z;
        double x = ray.point.x + t1 * ray.vector.x;
        double y = ray.point.y + t1 * ray.vector.y;
        Math::Point3D pi(x, y, z);
        Math::Vector3D normal = pi - center;
        double n = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
        normal = normal / n;
        return normal;
    } else if (t2 < t1) {
        double z = ray.point.z + t2 * ray.vector.z;
        double x = ray.point.x + t2 * ray.vector.x;
        double y = ray.point.y + t2 * ray.vector.y;
        Math::Point3D pi(x, y, z);
        Math::Vector3D normal = pi - center;
        double n = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
        normal = normal / n;
        return normal;
    }
    Math::Vector3D n(0, 0, 0);
    return n;
}

Plane::Plane(double y, char a) : coo(y), axis(a) {}

double Plane::hits(RayTracer::Ray ray)
{
    if (axis == 'x') {
        double value = (coo - ray.point.x);
        if (std::abs(value) < std::abs(value + ray.vector.x))
            return 0;
        else {
            Math::Point3D p1(coo, 100, 200);
            Math::Point3D p2(coo, 200, -100);
            Math::Point3D p3(coo, -30, -50);
            Math::Vector3D v1 = p2 - p1;
            Math::Vector3D v2 = p3 - p1;
            Math::Vector3D normal = v1 * v2;
            double n = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
            normal = normal / n;
            double t = normal.dot(p1 - ray.point) / normal.dot(ray.vector);
            Math::Point3D i = ray.point + ray.vector * t;
            if (i.z < 0)
                i.z = i.z * -1;
            return i.z;
        }
    }
    if (axis == 'y') {
        double value = (coo - ray.point.y);
        if (std::abs(value) < std::abs(value + ray.vector.y))
            return 0;
        else {
            Math::Point3D p1(100, coo, 200);
            Math::Point3D p2(200, coo, -100);
            Math::Point3D p3(-30, coo, -50);
            Math::Vector3D v1 = p2 - p1;
            Math::Vector3D v2 = p3 - p1;
            Math::Vector3D normal = v1 * v2;
            double n = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
            normal = normal / n;
            double t = normal.dot(p1 - ray.point) / normal.dot(ray.vector);
            Math::Point3D i = ray.point + ray.vector * t;
            if (i.z < 0)
                i.z = i.z * -1;
            return i.z;
        }
    }
    if (axis == 'z') {
        double value = (coo - ray.point.z);
        if (std::abs(value) < std::abs(value + ray.vector.z))
            return 0;
        else {
            Math::Point3D p1(100, 200, coo);
            Math::Point3D p2(200, -100, coo);
            Math::Point3D p3(-30, -50, coo);
            Math::Vector3D v1 = p2 - p1;
            Math::Vector3D v2 = p3 - p1;
            Math::Vector3D normal = v1 * v2;
            double n = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
            normal = normal / n;
            double t = normal.dot(p1 - ray.point) / normal.dot(ray.vector);
            Math::Point3D i = ray.point + ray.vector * t;
            if (i.z < 0)
                i.z = i.z * -1;
            return i.z;
        }
    }
    return 0;
}

Math::Vector3D Plane::normal(RayTracer::Ray ray)
{
    if (axis == 'x') {
        Math::Point3D p1(coo, 100, 200);
        Math::Point3D p2(coo, 200, -100);
        Math::Point3D p3(coo, -30, -50);
        Math::Vector3D v1 = p2 - p1;
        Math::Vector3D v2 = p3 - p1;
        Math::Vector3D normal = v1 * v2;
        double n = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
        normal = normal / n;
        return normal;
    }
    if (axis == 'y') {
        Math::Point3D p1(100, coo, 200);
        Math::Point3D p2(200, coo, -100);
        Math::Point3D p3(-30, coo, -50);
        Math::Vector3D v1 = p2 - p1;
        Math::Vector3D v2 = p3 - p1;
        Math::Vector3D normal = v1 * v2;
        double n = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
        normal = normal / n;
        return normal;
    }
    if (axis == 'z') {
        Math::Point3D p1(100, 200, coo);
        Math::Point3D p2(200, -100, coo);
        Math::Point3D p3(-30, -50, coo);
        Math::Vector3D v1 = p2 - p1;
        Math::Vector3D v2 = p3 - p1;
        Math::Vector3D normal = v1 * v2;
        double n = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
        normal = normal / n;
        return normal;
    }
    Math::Vector3D n(0, 0, 0);
    return n;
}

Cylindre::Cylindre(Math::Point3D center, double radius, char ax) : center(center), radius(radius), axis(ax) {}

double Cylindre::hits(RayTracer::Ray ray)
double Cylindre::hits(RayTracer::Ray ray)
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
        return 0;
    }
    if (discriminant == 0) {
        double t = -b / (2.0 * a);
        double z = ray.point.z + t * ray.vector.z;
        return z;
        return 0;
    }
    if (discriminant == 0) {
        double t = -b / (2.0 * a);
        double z = ray.point.z + t * ray.vector.z;
        return z;
    }
    double rassine = sqrt(discriminant);
    double t1 = (-b - rassine) / (2.0 * a);
    double t2 = (-b + rassine) / (2.0 * a);
    if (t1 < 0.0 && t2 < 0.0) {
        return 0;
    }
    else {
        if (t1 < t2) {
            double z = ray.point.z + t1 * ray.vector.z;
            return z;
        } else if (t2 < t1) {
            double z = ray.point.z + t2 * ray.vector.z;
            return z;
        }
    }
    return 0;
}

Math::Vector3D Cylindre::normal(RayTracer::Ray ray)
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
    if (discriminant == 0) {
        double t = -b / (2.0 * a);
        double z = ray.point.z + t * ray.vector.z;
        double x = ray.point.x + t * ray.vector.x;
        double y = ray.point.y + t * ray.vector.y;
        Math::Point3D pi(x, y, z);
        Math::Vector3D normal = pi - center;
        double n = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
        normal = normal / n;
        return normal;
    }
    double rassine = sqrt(discriminant);
    double t1 = (-b - rassine) / (2.0 * a);
    double t2 = (-b + rassine) / (2.0 * a);
    if (t1 < t2) {
        double z = ray.point.z + t1 * ray.vector.z;
        double x = ray.point.x + t1 * ray.vector.x;
        double y = ray.point.y + t1 * ray.vector.y;
        Math::Point3D pi(x, y, z);
        Math::Vector3D normal = pi - center;
        double n = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
        normal = normal / n;
        return normal;
    } else if (t2 < t1) {
        double z = ray.point.z + t2 * ray.vector.z;
        double x = ray.point.x + t2 * ray.vector.x;
        double y = ray.point.y + t2 * ray.vector.y;
        Math::Point3D pi(x, y, z);
        Math::Vector3D normal = pi - center;
        double n = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
        normal = normal / n;
        return normal;
    }
    Math::Vector3D n(0, 0, 0);
    return n;
}