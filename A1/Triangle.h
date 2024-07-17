#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

// Class Triangle
// Uses three Point objects to represent its vertices
// Can translate all its vertices by a given distance along a given axis
// Can calculate its area
// Can display the coordinates of its vertices
class Triangle {
private:
    Point* vertex_1;
    Point* vertex_2;
    Point* vertex_3;

public:
    int translate(int d, char axis);

    double calcArea() const;

    void display() const;

    Triangle(Point* vertex_1, Point* vertex_2, Point* vertex_3);
    Triangle();
    ~Triangle();
};

#endif // TRIANGLE_H
