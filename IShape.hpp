/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** IShape.hpp
*/

#pragma once

namespace RayTracer {
    class Ray;
}

class IShape
{
public:
    IShape(/* args */) = default;
    ~IShape() = default;
    virtual bool hits(RayTracer::Ray) = 0;
};

