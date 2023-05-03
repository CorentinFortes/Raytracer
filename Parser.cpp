/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** Paeser.cpp
*/

#include "Parser.hpp"

Parser::Parser(std::string path) : path(path)
{
    cfg.readFile(path.c_str());
}

std::unique_ptr<RayTracer::Camera> Parser::getCamera()
{
    int camera_width = cfg.lookup("camera.resolution.width");
    int camera_height = cfg.lookup("camera.resolution.height");
    double cam_x = cfg.lookup("camera.position.x");
    double cam_y = cfg.lookup("camera.position.y");
    double cam_z = cfg.lookup("camera.position.z");
    std::unique_ptr<RayTracer::Camera> cam(new RayTracer::Camera(Math::Point3D(cam_x, cam_y, cam_z), camera_width, camera_height));
    return cam;
}

void Parser::getShape(std::string name)
{
    std::string line;
    std::ifstream inFile;
    inFile.open(path);
    while (line.find("lights") == std::string::npos) {
        std::getline(inFile, line);
        if (line.find("spheres") != std::string::npos) {
            const libconfig::Setting& spheres = cfg.lookup("shapes.spheres");
            for (int i = 0; i < spheres.getLength(); ++i) {
                const libconfig::Setting& sphere = spheres[i];
                double x = sphere["x"];
                double y = sphere["y"];
                double z = sphere["z"];
                double r = sphere["radius"];
                std::unique_ptr<IShape> shape(new Sphere(Math::Point3D(x, y, z), r));
                shapes.insert(std::pair<int, std::unique_ptr<IShape>>(i, std::move(shape)));
            }
        }
        if (line.find("planes") != std::string::npos) {
            // const libconfig::Setting& spheres = cfg.lookup("shapes.planes");
            // for (int i = 0; i < spheres.getLength(); ++i) {
            //     const libconfig::Setting& sphere = spheres[i];
            //     char axis = sphere["axis"];
            //     double pos = sphere["position"];
            //     std::unique_ptr<IShape> shape(new Plane(pos, axis));
            //     shapes.insert(std::pair<int, std::unique_ptr<IShape>>(i, std::move(shape)));
            // }
        }
    }
}

void Parser::parsing()
{
    std::ifstream inFile;
    inFile.open(path);
    while (!inFile.eof()) {
        std::string line;
        std::getline(inFile, line);
        if (line.find("shapes") != std::string::npos)
            getShape(line);
    }
    inFile.close();
}