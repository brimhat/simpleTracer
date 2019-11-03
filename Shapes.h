//
// Created by csanders on 11/2/19.
//

#ifndef SIMPLETRACER_SHAPES_H
#define SIMPLETRACER_SHAPES_H

#include "Vec.h"
#include "Texture.h"

struct Sphere {
    Vec3f center;
    float radius;
    Texture texture;

    Sphere(Vec3f c, float r, Texture t) : center(c), radius(r), texture(t) {}

    bool intersect(const Ray &ray, float &t0) const {
        Vec3f L = center - ray.origin;      // center at origin

        float tca = L.dot(ray.direction);
        if (tca < 0) return false;

        float d2 = L.dot(L) - tca*tca;
        if (d2 > radius*radius) return false;

        float thc = std::sqrt(radius*radius - d2);
        t0 = tca - thc;
        float t1 = tca + thc;

        if (t0 < 0) t0 = t1;
        return t0 >= 0;
    }
};


#endif //SIMPLETRACER_SHAPES_H
