#ifndef POINT_H
#define POINT_H

// Class Point
// Has 3 private variables x, y, z
// These will hold the coordinates of the point
// We use getters to access these values, from the Triangle class
// Also has the translate function, which takes in a distance and an axis. And moves the point in the given axis by the given distance
class Point {
private:
    int x;
    int y;
    int z;

public:
    int translate(int d, char axis);

    int getX() const;
    int getY() const;
    int getZ() const;

    Point();
    Point(int x, int y, int z);
    ~Point();
};

#endif // POINT_H
