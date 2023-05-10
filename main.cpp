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
    Directional light(Math::Vector3D(2, 0, -1), 1);
    for (int y = 0; y < cam->height; y++) {
        for (int x = 0; x < cam->width; x++) {
            double u = (double)x / (double)(cam->width - 1);
            double v = (double)y / (double)(cam->height - 1);
            RayTracer::Ray r = cam->ray(u, v);
            std::map<int, double> inter;
            int t = 0, i = 0;
            for (auto &shape : parser.shapes) {
                if (shape.second->hits(r) != 0) {
                    inter[i] = shape.second->hits(r);
                    t = 1;
                }
                i++;
            }
            if (t == 1) {
                double minValue = std::numeric_limits<double>::max();
                int minKey = -1;
                for (const auto& elem : inter) {
                    if (elem.second <= minValue) {
                        minValue = elem.second;
                        minKey = elem.first;
                    }
                }
                parser.shapes[minKey]->printColor(&file, light.color_pourcent(parser.shapes[minKey]->normal(r), ));
            } else if (t == 0)
                file << 150 << " " << 150 << " " << 255 << std::endl;
        }
        file << std::endl;
    }
}
