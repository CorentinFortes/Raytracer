/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** vector.hpp
*/

#pragma once
#include <iostream>
#include <algorithm>

namespace Math {

    class Point3D {
        public:
        Point3D() = default;
        Point3D(double x, double y, double z);
        Point3D(Math::Point3D const& other);
        Point3D(Math::Point3D&& other);

        double x;
        double y;
        double z;
    };

    class Vector3D {
        public:
        Vector3D() = default;
        Vector3D(double x, double y, double z);
        Vector3D(Math::Vector3D const& other);
        Vector3D(Math::Vector3D&& other);
        double length() const;
        double dot(Math::Vector3D const& other) const;

        Vector3D& operator=(Math::Vector3D const& other);
        Vector3D& operator=(Math::Vector3D&& other);
        Vector3D operator+(Math::Vector3D const& other);
        Vector3D operator+=(Math::Vector3D const& other);
        Vector3D operator-(Math::Vector3D const& other);
        Vector3D operator-=(Math::Vector3D const& other);
        Vector3D operator*(Math::Vector3D const& other);
        Vector3D operator*=(Math::Vector3D const& other);
        Vector3D operator/(Math::Vector3D const& other);
        Vector3D operator/=(Math::Vector3D const& other);
        Vector3D operator*(double value);
        Vector3D operator*=(double value);
        Vector3D operator/(double value);
        Vector3D operator/=(double value);

        double x;
        double y;
        double z;

    };
}