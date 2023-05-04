/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** raytracer.hpp
*/

#pragma once

#include "include.hpp"
#include "Math.hpp"
#include "Point3D.hpp"
#include "camera.hpp"

namespace RayTracer
{
    class Ray
    {
    public:
        Ray();
        Ray(Math::Vector3D vector, Math::Point3D point);
        // Math::Vector3D is considered as an error type, why?
        // because it's not a pointer, it's a reference
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
        Camera(Math::Point3D o, double w, double h);
        ~Camera() {};
        Math::Point3D origin;
        Rectangle3D screen;
        int width;
        int height;
        RayTracer::Ray ray(double u, double v);
    };
}
