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
    std::cout << "cam_x: " << cam_x << std::endl;
    std::cout << "cam_y: " << cam_y << std::endl;
    std::cout << "cam_z: " << cam_z << std::endl;
    std::cout << "camera_width: " << camera_width << std::endl;
    std::cout << "camera_height: " << camera_height << std::endl;
    std::unique_ptr<RayTracer::Camera> cam(new RayTracer::Camera(Math::Point3D(cam_x, cam_y, cam_z), camera_width, camera_height));
    return cam;
}

std::unique_ptr<IShape> Parser::getShape(std::string name)
{
    // if (name.find("spheres") == std::string::npos) {
    //     double x = cfg.lookup("spheres.x");
    //     double y = cfg.lookup("spheres.y");
    //     double z = cfg.lookup("spheres.z");
    //     double radius = cfg.lookup("spheres.r");
    //     std::unique_ptr<IShape> shape(new Sphere(Math::Point3D(x, y, z), radius));
    //     return shape;
    // }
    return nullptr;
}

void Parser::parsing()
{
    std::ifstream inFile;
    inFile.open(path);
    while (!inFile.eof()) {
        std::string line;
        std::getline(inFile, line);
        std::cout << line << std::endl;
        std::unique_ptr<IShape> shape = getShape(line);
        if (shape != nullptr)
            shapes.insert(std::pair<std::string, std::unique_ptr<IShape>>(line, std::move(shape)));
    }
    inFile.close();
    for (auto &shape : shapes) {
        std::cout << shape.first << std::endl;
    }
}