/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** vector.cpp
*/

#include "Math.hpp"
#include <utility>

Math::Vector3D::Vector3D() : x(0), y(0), z(0) {}

Math::Vector3D::Vector3D(Math::Vector3D const& other) : x(other.x), y(other.y), z(other.z) {}

Math::Vector3D::Vector3D(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {}

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

Math::Vector3D Math::Vector3D::operator-(Math::Point3D const& other)
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
    int nx, ny, nz;
    nx = y * other.z - z * other.y;
    ny = x * other.z - z * other.x;
    nz = x * other.y - y * other.x;
    return Math::Vector3D(nx, ny*(-1), nz);
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
    double nx, ny, nz;
    nx = x * other.x;
    ny = y * other.y;
    nz = z * other.z;
    return (nx + ny + nz);
}

void Math::Vector3D::translate(Math::Vector3D v)
{
    x += v.x;
    y += v.y;
    z += v.z;
}

double Math::Vector3D::scalaire(Math::Vector3D v)
{
    return (x * v.x + y * v.y + z * v.z);
}

Math::Point3D::Point3D() : x(0), y(0), z(0) {}

Math::Point3D::Point3D(Math::Point3D const& other) : x(other.x), y(other.y), z(other.z) {}

Math::Point3D::Point3D(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {}

Math::Point3D::Point3D(Math::Point3D &&other) : x(0), y(0), z(0)
{
    std::exchange(x, other.x);
    std::exchange(y, other.y);
    std::exchange(z, other.z);
}

Math::Point3D& Math::Point3D::operator=(Math::Point3D const& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

Math::Point3D& Math::Point3D::operator=(Math::Point3D&& other)
{
    x = std::move(other.x);
    y = std::move(other.y);
    z = std::move(other.z);
    return *this;
}

Math::Point3D Math::Point3D::operator+(Math::Vector3D const &other)
{
    x = x + other.x;
    y = y + other.y;
    z = z + other.z;
    return *this;
}

Math::Point3D Math::Point3D::operator-(Math::Vector3D const &other)
{
    x = x - other.x;
    y = y - other.y;
    z = z - other.z;
    return *this;
}

Math::Vector3D Math::Point3D::operator-(Math::Point3D const &other)
{
    return Math::Vector3D(x - other.x, y - other.y, z - other.z);
}