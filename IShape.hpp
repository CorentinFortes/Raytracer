/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** IShape.hpp
*/

#pragma once
#include "raytracer.hpp"
#include "Math.hpp"

namespace RayTracer {
    class Ray;
}

class IShape {
    public:
    virtual ~IShape() = default;
    virtual bool hits(RayTracer::Ray) = 0;
    virtual void printColor(std::ofstream *, double p) = 0;
    virtual void setColor(int r, int g, int b) = 0;
    // virtual void getnormal(Math::Point3D, Math::Point3D) = 0;
};
