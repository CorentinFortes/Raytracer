/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** main.cpp
*/

#include "include.hpp"

int main ()
{
    libconfig::Config cfg;
    cfg.readFile("input.txt");
    int camera_width = cfg.lookup("camera.resolution.width");
    int camera_height = cfg.lookup("camera.resolution.height");
    double cam_x = cfg.lookup("camera.position.x");
    double cam_y = cfg.lookup("camera.position.y");
    double cam_z = cfg.lookup("camera.position.z");
    std::ofstream file("test.ppm");
    file << "P3" << std::endl;
    file << camera_width << " " << camera_height << std::endl;
    file << 255 << std::endl;
    RayTracer::Camera cam(Math::Point3D(0, 0, 0), 1920, 1080);
    std::unique_ptr<IShape> s = std::make_unique<Sphere>(Math::Point3D(70, 70, 100), 0.5);
    for (int y = 0; y < camera_height; y++) {
        for (int x = 0; x < camera_width; x++) {
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