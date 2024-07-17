#include "Driver.h"
#include <iostream>

using namespace std;

void Driver::run() {
    int x, y, z, d;
    char axis;
    cout << "Enter the coordinates for the first vertex of the triangle: ";
    cin >> x >> y >> z;
    vertex_1 = new Point(x, y, z);
    cout << "Enter the coordinates for the second vertex of the triangle: ";
    cin >> x >> y >> z;
    vertex_2 = new Point(x, y, z);
    cout << "Enter the coordinates for the third vertex of the triangle: ";
    cin >> x >> y >> z;
    vertex_3 = new Point(x, y, z);
    triangle = new Triangle(vertex_1, vertex_2, vertex_3);
    cout << "Triangle created" << endl;

    // Menu option
    int choice = 0;
    while (true) {
        cout << "1. Display the Triangle" << endl;
        cout << "2. Translate the Triangle" << endl;
        cout << "3. Calculate the area of the Triangle" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            triangle->display();
            break;
        case 2:
            cout << "Enter the translate distance: ";
            cin >> d;
            // Input verification before calling the method so we don't have to worry about invalid input
            while (cin.fail()) {
                cout << "Invalid distance" << endl;
                cout << "Enter a valid distance: ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> d;
                if(!cin.fail()) {
                    cin.clear();
                    cin.ignore(256, '\n');
                    break;
                }
            }
            cout << "Enter the axis: ";
            cin >> axis;
            while (triangle->translate(d, axis) != 0) {
                cout << "Invalid axis" << endl;
                cout << "Enter a valid axis: ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> axis;
            }
            cout << "Translation saved" << endl;
            cout << "Press 1. to display the new coordinates" << endl;
            break;
        case 3:
            cout <<"the area of your triangle is: " << triangle->calcArea() << endl;
            break;
        case 4:
            cout << "Exiting..." << endl;
            return;
        }
    }
}
