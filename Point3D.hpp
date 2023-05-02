/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** Point3D.hpp
*/

#pragma once
#include "Math.hpp"
#include "include.hpp"

namespace Math {
    class Vector3D;
}

namespace Math {

    class Point3D {
        public:
        Point3D();
        Point3D(double x, double y, double z);
        Point3D(Math::Point3D const& other);
        Point3D(Math::Point3D&& other);
        ~Point3D() {};
        Point3D& operator=(Math::Point3D const& other);
        Point3D& operator=(Math::Point3D&& other);
        Point3D operator+(Math::Vector3D const &other);
        Point3D operator-(Math::Vector3D const &other);
        double x;
        double y;
        double z;
    };
}