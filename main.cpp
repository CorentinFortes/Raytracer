/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** main.cpp
*/

#include "include.hpp"

int main ()
{
    RayTracer::Camera cam;
    RayTracer::Sphere s(RayTracer::Point3D(0 , 0 , -1) , 0.5);
    for (/* go through the Y axis */) {
        for (/* go through the X axis */) {
            double u = /* get a certain amount of X */;
            double v = /* get a certain amount of Y */;
            RayTracer::Ray r = cam.ray(u, v);
            if (s.hits(r)) {
            // something
            } else {
            // something else
            }
        }
    }
}