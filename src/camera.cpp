#include <cmath>
#include <cstdio>

#include "camera.h"
#include "matrix.h"


Matrix projMat(Camera& cam) {
    double pc = cos(-cam.pitch);
    double ps = sin(-cam.pitch);
    double yc = cos(-cam.yaw);
    double ys = sin(-cam.yaw);
    double rc = cos(-cam.roll);
    double rs = sin(-cam.roll);
    double S = 1 / tan(cam.fov);
    double C1 = -cam.far / (cam.far - cam.near);
    double C2 = C1 * cam.near;

    /*
    printf("      SIN \t\tCOS \t\tRAD\n");
    printf("PITCH %f\t\t%f\t%f\n", ps, pc, cam.pitch, cam.pitch / D2R);
    printf("YAW   %f\t\t%f\t%f\n", ys, yc, cam.yaw, cam.yaw / D2R);
    printf("ROLL  %f\t\t%f\t%f\n\n", rs, rc, cam.roll, cam.roll / D2R);
    */

    return Matrix(4, 4, new double[16] {
        1,  0,  0,  -cam.x,
        0,  1,  0,  -cam.y,
        0,  0,  1,  -cam.z,
        0,  0,  0,  1,
    }) * Matrix(4, 4, new double[16] {
        rc, -rs,0,  0,
        rs, rc, 0,  0,
        0,  0,  1,  0,
        0,  0,  0,  1
    }) * Matrix(4, 4, new double[16] {
        yc, 0,  ys, 0,
        0,  1,  0,  0,
        -ys,0,  yc, 0,
        0,  0,  0,  1
    }) * Matrix(4, 4, new double[16] {
        1,  0,  0,  0,
        0,  pc, -ps,0,
        0,  ps, pc, 0,
        0,  0,  0,  1
    }) * Matrix(4, 4, new double[16] {
        S,  0,  0,  0,
        0,  S,  0,  0,
        0,  0,  C1, C2,
        0,  0,  1,  0
    });
}

ScreenPoint project(Camera& cam, double x, double y, double z) {
    double* arr = new double[4] {
        x,
        y,
        z,
        1
    };

    Matrix colMat = Matrix(4, 1, arr);
    Matrix projM = projMat(cam);
    Matrix resM = projM * colMat;
    printf("( %f, %f, %f, %f ) &%p as matrix:\n", arr[0], arr[1], arr[2], arr[3], arr);
    colMat.print();

    ScreenPoint resP;
    resP.x = resM.data[0] / resM.data[3];
    resP.y = resM.data[1] / resM.data[3];
    resP.depth = resM.data[2] / resM.data[3];

    return resP;
}
