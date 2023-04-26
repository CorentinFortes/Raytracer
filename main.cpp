/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-corentin.fortes
** File description:
** main.cpp
*/

#include "include.hpp"

int main ()
{
    RayTracer::Camera cam;         //  x  y    z
    RayTracer::Sphere s(Math::Point3D(20, 10 , 100) , 0.5);
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 120; x++) {
            double u = x;
            double v = y;
            RayTracer::Ray r = cam.ray(u, v);
            if (s.hits(r)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}