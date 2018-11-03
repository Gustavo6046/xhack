#include <iostream>
#include <cstdio>

#include "camera.h"


int main(int argc, char** argv)
{
    Camera cam;
    cam.yaw = 80 * D2R;

    ScreenPoint spa = project(cam, 0.5, 0.1, 0.5);
    ScreenPoint spb = project(cam, -2, 10, 1.5);

    printf("Input Point A: (0.5, 0.1, 0.5)\n");
    printf("Projected Point A: (%f, %f) - depth %f\n\n", spa.x, spa.y, spa.depth);

    printf("Input Point B: (-2, 10, 1.5)\n");
    printf("Projected Point B: (%f, %f) - depth %f\n", spb.x, spb.y, spb.depth);

    return 0;
}
