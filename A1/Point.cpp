#include "Point.h"

// Take in the distance and the axis
// Move the point on the specified axis, using the given distance
// In the case there is a non-integer distance, return -2
// In the case the axis given is not 'x', 'y', or 'z', return -1
// Otherwise return 0
int Point::translate(int d, char axis) {
    if (int(d) != d) {
        return -2;
    }
    if (axis == 'x') {
        x += d;
        return 0;
    }
    else if (axis == 'y') {
        y += d;
        return 0;
    }
    else if (axis == 'z') {
        z += d;
        return 0;
    }
    else {
        return -1;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

int Point::getZ() const {
    return z;
}

Point::Point() {
    x = 0;
    y = 0;
    z = 0;
}

Point::Point(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::~Point() = default;
