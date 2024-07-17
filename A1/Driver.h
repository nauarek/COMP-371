#ifndef DRIVER_H
#define DRIVER_H

#include "Triangle.h"

// Class Driver
// Allow user to create a triangle
// Allow user to translate the triangle
// Allow user to calculate the area of the triangle
// Allow user to display the coordinates of the triangle
class Driver {
private:
    Triangle* triangle;
    Point* vertex_1;
    Point* vertex_2;
    Point* vertex_3;

public:
    void run();
};

#endif // DRIVER_H
