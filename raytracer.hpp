/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** raytracer.hpp
*/

#pragma once

#include "camera.hpp"
#include <cmath>
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

    class Camera
    {
    public:
        Camera();
        Camera(Rectangle3D screen);
        ~Camera() {};
        Math::Point3D origin;
        Rectangle3D screen;
        RayTracer::Ray ray(double u, double v);
    };
}
