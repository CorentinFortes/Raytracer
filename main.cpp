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
    parser.parsing(); parser.getLight();
    std::unique_ptr<RayTracer::Camera> cam = parser.getCamera();
    std::ofstream file("test.ppm");
    file << "P3" << std::endl;
    file << cam->width << " " << cam->height << std::endl;
    file << 255 << std::endl;
    // std::unique_ptr<Point> light(new Point(Math::Point3D(0, 1, 0), 1));
    for (int y = 0; y < cam->height; y++) {
        for (int x = 0; x < cam->width; x++) {
            double u = (double)x / (double)(cam->width - 1);
            double v = (double)y / (double)(cam->height - 1);
            RayTracer::Ray r = cam->ray(u, v);
            std::map<int, std::unique_ptr<Math::Point3D>> inter;
            int t = 0, i = 0;
            for (auto &shape : parser.shapes) {
                if (shape.second->hits(r) != nullptr) {
                    inter[i] = shape.second->hits(r);
                    t = 1;
                }
                i++;
            }
            if (t == 1) {
                double minValue = std::numeric_limits<double>::max();
                int minKey = -1;
                for (const auto& elem : inter) {
                    if (sqrt(pow(elem.second->x - cam->origin.x, 2) + pow(elem.second->y - cam->origin.y, 2)
                         + pow(elem.second->z - cam->origin.z, 2)) <= minValue) {
                        // minValue = elem.second->z;
                        // faire par rapport au premier point
                        minValue = sqrt(pow(elem.second->x - cam->origin.x, 2) + pow(elem.second->y - cam->origin.y, 2)
                         + pow(elem.second->z - cam->origin.z, 2));
                        minKey = elem.first;
                    }
                }
                double pourcent = light->color_pourcent(parser.shapes[minKey]->normal(r), *inter[minKey]);
                RayTracer::Ray ray((light->light), *inter[minKey]);
                double dd = 0;
                for (auto &shape : parser.shapes) {
                    if (shape.second->hits(ray) != nullptr && shape.first != minKey) {
                        dd = 1;
                    }
                }
                if (dd != 0) {
                    parser.shapes[minKey]->printColor(&file, pourcent / 4);
                } else {
                    parser.shapes[minKey]->printColor(&file, pourcent);
                }
                // parser.shapes[minKey]->printColor(&file, light->color_pourcent(parser.shapes[minKey]->normal(r), *inter[minKey]));
            } else if (t == 0)
                file << 255 << " " << 255 << " " << 255 << std::endl;
        }
        file << std::endl;
    }
}
