/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** Parser.hpp
*/

#pragma once
#include "raytracer.hpp"
#include "IShape.hpp"

class Parser {
    public:
    Parser(std::string path);
    ~Parser() {};
    std::unique_ptr<RayTracer::Camera> getCamera();
    void getShape(std::string name);
    void parsing();


    libconfig::Config cfg;
    std::string path;
    std::map<int, std::unique_ptr<IShape>> shapes;
};

