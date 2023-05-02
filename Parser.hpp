/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** Parser.hpp
*/

#pragma once
#include "IShape.hpp"
#include "Shape.hpp"
#include "Math.hpp"
#include "camera.hpp"
#include "raytracer.hpp"
#include <libconfig.h++>
#include <fstream>
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <map>

class Parser {
    public:
    Parser(std::string path);
    ~Parser() {};
    std::unique_ptr<RayTracer::Camera> getCamera();
    std::unique_ptr<IShape> getShape(std::string name);
    void parsing();


    libconfig::Config cfg;
    std::string path;
    std::map<std::string, std::unique_ptr<IShape>> shapes;
};

