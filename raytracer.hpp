/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** raytracer.hpp
*/

#include "camera.hpp"
#include "Math.hpp"

namespace RayTracer
{
    class Ray
    {
    public:
        Ray();
        Ray(Math::Vector3D vector, Math::Point3D point);
        Ray(Ray const& other); //cpy
        Ray(Ray&& other); //mv

        Ray& operator=(Ray const& other);
        Ray& operator=(Ray&& other);
        ~Ray() {};
        Math::Vector3D vector;
        Math::Point3D point;
    };

    class Sphere
    {
    public:
        Math::Point3D center;
        double radius;
        Sphere(Math::Point3D center, double radius);
        ~Sphere() {};
        bool hits(RayTracer::Ray);
    };

    class Camera
    {
    public:
        Camera();
        ~Camera() {};
        Math::Point3D origin;
        Rectangle3D screen;
        RayTracer::Ray ray(double u, double v);
    };
}
