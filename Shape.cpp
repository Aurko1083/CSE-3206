#include <iostream>
using namespace std;

class ShapeFactory{
    public:
        
        virtual float area() = 0;
};

class CircleFactory : public ShapeFactory{
    public:
        int r;
        CircleFactory(int r) : r(r) {}
        
        float area() override {
            return 3.14 * r * r;
        }
};

class SquareFactory : public ShapeFactory{
    public:
        int a;
        SquareFactory(int a){
            this->a = a;
        };
        
        float area() override {
            return a * a;
        }
};

class RectangleFactory : public ShapeFactory{
    public:
    int x, y;
    RectangleFactory(int x, int y) : x(x), y(y) {}
        
        float area() override {
            return x *y;
        }
};

int main(){
    ShapeFactory* circle = new CircleFactory(4);
    
    cout << "Area of Circle: " << circle->area() << endl;

    ShapeFactory* square = new SquareFactory(3);
    
    cout << "Area of Square: " << square->area() << endl;

    ShapeFactory* rectangle = new RectangleFactory(3, 4);

    cout << "Area of Rectangle: " << rectangle->area() << endl;

    

    return 0;
}
