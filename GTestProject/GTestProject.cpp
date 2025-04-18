#include <iostream>
#include <string>
#include <cmath>
#include <gtest/gtest.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


using namespace std;

class Shape
{
public:
    virtual double area() const = 0;
    virtual std::string getName() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double area() const override
    {
        return M_PI * radius * radius;
    }
    std::string getName() const override
    {
        return "Circle";
    }
};
class Square : public Shape
{
private:
    double height;

public:
    Square(double r) : height(r) {}
    double area() const override
    {
        return height * height;
    }
    std::string getName() const override
    {
        return "Square";
    }
};

class Rectangle : public Shape
{
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override
    {
        return width * height;
    }
    std::string getName() const override
    {
        return "Rectangle";
    }
};

enum ShapeType
{
    CIRCLE,
    RECTANGLE,
    SQUARE
};

class ShapeFactory
{
public:
    static Shape* createShape(ShapeType type, double a, double b = 0)
    {
        switch (type)
        {
        case CIRCLE:
            return new Circle(a);
        case RECTANGLE:
            return new Rectangle(a, b);
        case SQUARE:
            return new Square(a);
        default:
            return nullptr;
        }
    }
};

TEST(ShapeTest, SquareArea)
{
    Shape* square = ShapeFactory::createShape(SQUARE, 2.0);
    ASSERT_NE(square, nullptr);
    EXPECT_NEAR(square->area(), 4.0, 1e-6);
    EXPECT_EQ(square->getName(), "Square");
    delete square;
}

TEST(ShapeTest, RectangleArea)
{
    Shape* rectangle = ShapeFactory::createShape(RECTANGLE, 3.0, 4.0);
    ASSERT_NE(rectangle, nullptr);
    EXPECT_DOUBLE_EQ(rectangle->area(), 12.0);
    EXPECT_EQ(rectangle->getName(), "Rectangle");
    delete rectangle;
}
TEST(ShapeTest, CircleArea)
{
    Shape* circle = ShapeFactory::createShape(CIRCLE, 2.0);
    ASSERT_NE(circle, nullptr);
    EXPECT_NEAR(circle->area(), M_PI * 4, 1e-6);
    EXPECT_EQ(circle->getName(), "Circle");
    delete circle;
}
// --- Main ---
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}