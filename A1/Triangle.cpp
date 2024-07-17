#include "Triangle.h"
#include <iostream>


using namespace std;

Triangle::Triangle(Point* vertex_1, Point* vertex_2, Point* vertex_3) {
    this->vertex_1 = vertex_1;
    this->vertex_2 = vertex_2;
    this->vertex_3 = vertex_3;
}

Triangle::Triangle() {
    vertex_1 = nullptr;
    vertex_2 = nullptr;
    vertex_3 = nullptr;
}

Triangle::~Triangle() {
    delete vertex_1;
    delete vertex_2;
    delete vertex_3;
}

int Triangle::translate(int d, char axis) {
    // If any of the vertices return -2, we return -2
    // If any of the vertices return -1, we return -1
    // Since the distance and axis are either valid or invalid for all vertices
    // We call vertex_1
    int result = vertex_1->translate(d, axis);
    if (result == 0) {
        vertex_2->translate(d, axis);
        vertex_3->translate(d, axis);
        return 0;
    }
    else {
        return result;
    }
}

double Triangle::calcArea() const {
    return (0.5 * (abs(vertex_1->getX() * (vertex_2->getY() - vertex_3->getY())
        + vertex_2->getX() * (vertex_3->getY() - vertex_1->getY())
        + vertex_3->getX() * (vertex_1->getY() - vertex_2->getY()))));
}

void Triangle::display() const {
    cout << "Vertex 1: x=" << vertex_1->getX() << ", y=" << vertex_1->getY() << ", z=" << vertex_1->getZ() << endl;
    cout << "Vertex 2: x=" << vertex_2->getX() << ", y=" << vertex_2->getY() << ", z=" << vertex_2->getZ() << endl;
    cout << "Vertex 3: x=" << vertex_3->getX() << ", y=" << vertex_3->getY() << ", z=" << vertex_3->getZ() << endl;
}
