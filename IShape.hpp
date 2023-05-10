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
    virtual double hits(RayTracer::Ray) = 0;
    virtual void printColor(std::ofstream *, double p) = 0;
    virtual void setColor(int r, int g, int b) = 0;
    virtual Math::Vector3D normal(RayTracer::Ray l) = 0;
};
