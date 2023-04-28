/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** main.cpp
*/

#include "include.hpp"

int main ()
{
    std::ofstream file("test.ppm");
    file << "P3" << std::endl;
    file << 200 << " " << 200 << std::endl;
    file << 255 << std::endl;
    RayTracer::Camera cam;         //  x  y    z
    std::unique_ptr<IShape> s = std::make_unique<Sphere>(Math::Point3D(70, 70, 100), 0.5);
    for (int y = 0; y < 200; y++) {
        for (int x = 0; x < 200; x++) {
            double u = x;
            double v = y;
            RayTracer::Ray r = cam.ray(u, v);
            if (s->hits(r)) {
                file << 255 << " " << 0 << " " << 0 << " ";
            } else {
                file << 150 << " " << 150 << " " << 255 << " ";
            }
        }
        file << std::endl;
    }
}