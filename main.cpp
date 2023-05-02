/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** main.cpp
*/

#include "raytracer.hpp"

int main ()
{
    Parser parser("input.txt");
    parser.parsing();
    std::unique_ptr<RayTracer::Camera> cam = parser.getCamera();
    std::ofstream file("test.ppm");
    file << "P3" << std::endl;
    file << cam->width << " " << cam->height << std::endl;
    file << 255 << std::endl;
    std::unique_ptr<IShape> s = std::make_unique<Sphere>(Math::Point3D(100, 100, 50), 0.5);
    for (int y = 0; y < cam->height; y++) {
        for (int x = 0; x < cam->width; x++) {
            double u = x;
            double v = y;
            RayTracer::Ray r = cam->ray(u, v);
            if (s->hits(r)) {
                file << 255 << " " << 0 << " " << 0 << " ";
            } else {
                file << 150 << " " << 150 << " " << 255 << " ";
            }
        }
        file << std::endl;
    }
}
