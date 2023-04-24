/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** vector.cpp
*/

#include "Math.hpp"

Math::Vector3D::Vector3D() : x(0), y(0), z(0) {}

Math::Vector3D::Vector3D(Math::Vector3D const& other) : x(other.x), y(other.y), z(other.z) {}

Math::Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

Math::Vector3D::Vector3D(Math::Vector3D &&other) : x(0), y(0), z(0)
{
    std::exchange(x, other.x);
    std::exchange(y, other.y);
    std::exchange(z, other.z);
}

double Math::Vector3D::length() const
{
    return sqrt(x * x + y * y + z * z);
}

Math::Vector3D& Math::Vector3D::operator=(Math::Vector3D const& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

Math::Vector3D& Math::Vector3D::operator=(Math::Vector3D&& other)
{
    x = std::move(other.x);
    y = std::move(other.y);
    z = std::move(other.z);
    return *this;
}

Math::Vector3D Math::Vector3D::operator+(Math::Vector3D const& other)
{
    return Math::Vector3D(x + other.x, y + other.y, z + other.z);
}

Math::Vector3D Math::Vector3D::operator+=(Math::Vector3D const& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Math::Vector3D Math::Vector3D::operator-(Math::Vector3D const& other)
{
    return Math::Vector3D(x - other.x, y - other.y, z - other.z);
}

Math::Vector3D Math::Vector3D::operator-=(Math::Vector3D const& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Math::Vector3D Math::Vector3D::operator*(Math::Vector3D const& other)
{
    return Math::Vector3D(x * other.x, y * other.y, z * other.z);
}

Math::Vector3D Math::Vector3D::operator*=(Math::Vector3D const& other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

Math::Vector3D Math::Vector3D::operator/(Math::Vector3D const& other)
{
    return Math::Vector3D(x / other.x, y / other.y, z / other.z);
}

Math::Vector3D Math::Vector3D::operator/=(Math::Vector3D const& other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

Math::Vector3D Math::Vector3D::operator*(double value)
{
    return Math::Vector3D(x * value, y * value, z * value);
}

Math::Vector3D Math::Vector3D::operator*=(double value)
{
    x *= value;
    y *= value;
    z *= value;
    return *this;
}

Math::Vector3D Math::Vector3D::operator/(double value)
{
    return Math::Vector3D(x / value, y / value, z / value);
}

Math::Vector3D Math::Vector3D::operator/=(double value)
{
    x /= value;
    y /= value;
    z /= value;
    return *this;
}

double Math::Vector3D::dot(Math::Vector3D const& other) const
{
    return x * other.x + y * other.y + z * other.z;
}

Math::Point3D::Point3D() : x(0), y(0), z(0) {}

Math::Point3D::Point3D(Math::Point3D const& other) : x(other.x), y(other.y), z(other.z) {}

Math::Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

Math::Point3D::Point3D(Math::Point3D &&other) : x(0), y(0), z(0)
{
    std::exchange(x, other.x);
    std::exchange(y, other.y);
    std::exchange(z, other.z);
}