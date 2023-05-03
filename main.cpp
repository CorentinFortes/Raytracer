/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** main.cpp
*/

#include "raytracer.hpp"
#include "Parser.hpp"

int main ()
{
    Parser parser("input.txt");
    parser.parsing();
    std::unique_ptr<RayTracer::Camera> cam = parser.getCamera();
    std::ofstream file("test.ppm");
    file << "P3" << std::endl;
    file << cam->width << " " << cam->height << std::endl;
    file << 255 << std::endl;
    for (int y = 0; y < cam->height; y++) {
        for (int x = 0; x < cam->width; x++) {
            double u = (double)x / (double)cam->width;
            double v = (double)y / (double)cam->height;
            RayTracer::Ray r = cam->ray(u, v);
            int t = 0;
            for (auto &shape : parser.shapes) {
                t = 0;
                if (shape.second->hits(r)) {
                    file << 255 << " " << 64 << " " << 64 << " ";
                    t = 1;
                    break;
                }
            }
            if (t == 0)
                file << 150 << " " << 150 << " " << 255 << " ";
        }
        file << std::endl;
    }
}
