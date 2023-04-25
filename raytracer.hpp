/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** raytracer.hpp
*/

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
        Math::Vector3D radius;
        Sphere(Math::Point3D center, Math::Vector3D radius);
        ~Sphere() {};
        bool hits(RayTracer::Ray);
    };
}