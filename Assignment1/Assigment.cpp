#include <iostream>
using namespace std;

// Part 1

// Take in the size of the array
// Return an array of the specified size
int* createArray(int size){

    int *arr = new int[size];
    
    return arr;

}

// Take in the array pointer, and size of the array
// Populate the array
// Return the populated array
void initializeArray(int* ptr, int size){
    
    for(int i=0; i<size; i++){

        ptr[i] = i;

    }
}

// Take in the array pointer, and size of the array
// Loop through the array and print the values
void printArray(int* ptr, int size){

    for(int i=0; i < size ; i++){

        cout << ptr[i] << endl;
        
    }
}

// Take in the array pointer
// Delete the array, and set the pointer to nullptr
void deleteArray(int* ptr){
    delete[] ptr;
    ptr = nullptr;
}

// Driver function for part 1
void part1()
{
    int size;
    cout << "Size: ";
    cin >> size;

    int* arr = createArray(size);
    initializeArray(arr, size);
    printArray(arr, size);
    deleteArray(arr);
}

// Part 2

// Class Point
// Has 3 private variables x, y, z
// These will hold the coordinates of the point
// We use getters to access these values, from the Triangle class
// Also has the translate function, which takes in a distance and an axis. And moves the point in the given axis by the given distance
class Point{
    private:
        int x;
        int y;
        int z;
    public:
        // Take in the distance and the axis
        // Move the point on the specified axis, using the given distance
        // In the case there is a non-integer distance, return -2
        // In the case the axis given is not 'x', 'y', or 'z', return -1
        // Otherwise return 0
        int translate(int d, char axis){
            if (int(d) != d){
                
                return -2;
            }
            if(axis == 'x'){
                x+=d;
                return 0;
            }
            else if(axis =='y'){
                y+=d;
                return 0;
            }
            else if(axis == 'z'){
                z+=d;
                return 0;
            }
            else{
                return -1;
            }
        }
        

        // Getters for the x, y, and z coordinates
        // These are needed for the Triangle class to access the coordinates
        int getX(){
            return x;
        }
        
        int getY(){
            return y;
        }
        
        int getZ(){
            return z;
        }

        // Constructor for the Point class
        // Takes in the x, y, and z coordinates
        // And creates a point with those coordinates
        Point(int x, int y, int z){
            this -> x = x;
            this -> y = y;
            this -> z = z;
        }

        // Destructor for the Point class
        // Since the variables are simply integers, we do not need to do anything special in the destructor
        ~Point() = default;
        
};


// Class Triangle
// Has 3 private variables, vertex_1, vertex_2, vertex_3
// These are pointers to Point objects
// We use these to store the coordinates of the triangle
// We have a translate function, which takes in a distance and an axis
// This function calls the translate function of the Point class, for each of the vertices
// We have a calcArea function, which calculates the area of the triangle
// We have a display function, which displays the coordinates of the triangle
// We have a constructor, which takes in 3 Point pointers, and sets the vertices to these pointers
// We have a default constructor, which sets the vertices to nullptr
// We have a destructor, which deletes the vertices
class Triangle{
    private:
        Point* vertex_1;
        Point* vertex_2;
        Point* vertex_3;
    public:
        int translate(int d, char axis){
            // If any of the vertices return -2, we return -2
            // If any of the vertices return -1, we return -1
            // Since the distance and axis are either valid or invalid for all vertices
            // We call vertex_1
            int result = vertex_1->translate(d, axis);
            if(result == 0){
                vertex_2->translate(d, axis);
                vertex_3->translate(d, axis);
                return 0;
            }
            else{
                return result;
            }
        }

        // 1/2 |(x1(y2-y3) + x2(y3-y1) + x3(y1-y2))|
        double calcArea(){
            return (0.5 * (abs( vertex_1->getX() * (vertex_2->getY() - vertex_3->getY()) 
                            + vertex_2->getX() * (vertex_3->getY() - vertex_1->getY()) 
                            + vertex_3->getX() * (vertex_1->getY() - vertex_2->getY()) )));
        }

        void display(){
            cout << "Vertex 1: x=" << vertex_1->getX() << ", y=" << vertex_1->getY() << ", z=" << vertex_1->getZ() << endl;
            cout << "Vertex 2: x=" << vertex_2->getX() << ", y=" << vertex_2->getY() << ", z=" << vertex_2->getZ() << endl; 
            cout << "Vertex 3: x=" << vertex_3->getX() << ", y=" << vertex_3->getY() << ", z=" << vertex_3->getZ() << endl; 
        }

        Triangle(Point* vertex_1, Point* vertex_2, Point* vertex_3){
            this->vertex_1 = vertex_1;
            this->vertex_2 = vertex_2;
            this->vertex_3 = vertex_3;
        }

        Triangle(){
            vertex_1 = nullptr;
            vertex_2 = nullptr;
            vertex_3 = nullptr;
        }

        ~Triangle(){
            delete vertex_1;
            delete vertex_2;
            delete vertex_3;
        }


};

class Driver{
    // Allow user to create a triangle
    // Allow user to translate the triangle
    // Allow user to calculate the area of the triangle
    // Allow user to display the coordinates of the triangle
    private:
        Triangle* triangle;
        Point* vertex_1;
        Point* vertex_2;
        Point* vertex_3;
       

    public:
        void run(){
            int x,y,z,d;
            char axis;
            cout << "Enter the coordinates for the first vertex of the triangle: ";
            cin >> x >> y >> z;
            vertex_1 = new Point(x,y,z);
            cout << "Enter the coordinates for the second vertex of the triangle: ";
            cin >> x >> y >> z;
            vertex_2 = new Point(x,y,z);
            cout << "Enter the coordinates for the third vertex of the triangle: ";
            cin >> x >> y >> z;
            vertex_3 = new Point(x,y,z);
            triangle = new Triangle(vertex_1, vertex_2, vertex_3);
            cout << "Triangle created" << endl;
            // Menu option
            int choice =0;
            while(true){
                cout << "1. Display the Triangle" << endl;
                cout << "2. Translate the Triangle" << endl;
                cout << "3. Calculate the area of the Triangle" << endl;
                cout << "4. Exit" << endl;
                cin >> choice;
                switch (choice){
                    case 1:
                        triangle->display();
                        break;
                    case 2:
                        cout << "Enter the translate distance:";
                        cin >> d;
                        // Input verification before calling the method so we don't have to worry about invalid input
                        while(cin.fail()){
                            cout << "Invalid distance" << endl;
                            cout << "Enter a valid distance: ";
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> d;
                            if(!cin.fail()){
                                break;
                            }
                        }
                        cout << "Enter the axis :";
                        cin >> axis;
                        while (triangle->translate(d,axis) != 0){
                            cout << "Invalid axis" << endl;
                            cout << "Enter a valid axis :";
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> axis;
                            break;
                        }
                        triangle->translate(d,axis);
                        cout << "Translation saved" << endl;
                        break;
                    case 3:
                        cout << triangle->calcArea() << endl;
                        break;
                    case 4:
                        return;
                }
            }
        }
};

int main(){
        part1();
        // Now time for part 2
        Driver driver;
        driver.run();
        return 0;
}