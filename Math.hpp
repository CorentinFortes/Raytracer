/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** vector.hpp
*/

#pragma once
#include "include.hpp"
#include "Point3D.hpp"

// Math::Point3D;

namespace Math {
    class Point3D;
}

namespace Math {
    class Vector3D {
        public:
        Vector3D();
        Vector3D(double x, double y, double z);
        Vector3D(Math::Vector3D const& other);
        Vector3D(Math::Vector3D&& other);
        ~Vector3D() {};
        double length() const;
        double dot(Math::Vector3D const& other) const;
        void translate(Math::Vector3D v);
        double scalaire(Math::Vector3D v);

        Vector3D& operator=(Math::Vector3D const& other);
        Vector3D& operator=(Math::Vector3D&& other);
        Vector3D operator+(Math::Vector3D const& other);
        Vector3D operator+=(Math::Vector3D const& other);
        Vector3D operator-(Math::Vector3D const& other);
        Vector3D operator-(Math::Point3D const& other);
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
