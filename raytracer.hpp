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
#include "light.hpp"

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
        Math::Point3D get_point(double z, Math::Point3D origin);
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
