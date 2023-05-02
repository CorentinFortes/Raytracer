/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** IShape.hpp
*/

#pragma once
#include "raytracer.hpp"
#include "Math.hpp"

class IShape {
    public:
    virtual ~IShape() = default;
    virtual bool hits(RayTracer::Ray) = 0;
};

