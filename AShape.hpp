/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** AShape.hpp
*/

#include "IShape.hpp"

class AShape : public IShape {
    public:
    AShape() {};
    ~AShape() {};
    virtual std::unique_ptr<Math::Point3D>hits(RayTracer::Ray) = 0;
    void printColor(std::ofstream *file, double pourcent);
    void setColor(int r, int g, int b);
    int color_r;
    int color_g;
    int color_b;
};