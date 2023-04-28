/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** Paeser.cpp
*/

#include "Parser.hpp"

// Parser::Parser(std::string path)
// {
//     cfg.readFile(path.c_str());
// }

// std::unique_ptr<Camera> Parser::getCamera()
// {
//     int camera_width = cfg.lookup("camera.resolution.width");
//     int camera_height = cfg.lookup("camera.resolution.height");
//     double cam_x = cfg.lookup("camera.position.x");
//     double cam_y = cfg.lookup("camera.position.y");
//     double cam_z = cfg.lookup("camera.position.z");
//     std::unique_ptr<Camera> cam(new Camera(Math::Point3D(cam_x, cam_y, cam_z)));
//     return cam;
// }