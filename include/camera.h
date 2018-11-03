#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "matrix.h"


#define D2R 0.01745329252


struct ScreenPoint {
    double x, y;
    double depth;
};

struct Camera {
    double x = 0, y = 0, z = 0;          // position
    double pitch = 0, yaw = 0, roll = 0; // rotation
    double fov = 90 * D2R;               // field of view
    double near = 1, far = 10000;        // clipping points
};

Matrix projMat(Camera& cam);
ScreenPoint project(Camera& cam, double x, double y, double z);

#endif // CAMERA_H_INCLUDED
