#ifndef EXERCISE23_H
#define EXERCISE23_H

#include <iostream>
#include <cmath>

class Point
{
public:
    float x, y;

    Point(float x = 0, float y = 0) : x(x), y(y) {}
};

class Shape
{
public:
    virtual float getArea() const = 0;
    virtual void printArea() const;

    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    Point center;
    float radius;

public:
    Circle(Point center = Point(), float radius = 0.0f);
    float getArea() const override;
    bool operator==(const Circle &other) const;
    void printArea() const override;
};

class Square : public Shape
{
private:
    float length;

public:
    Square(float length = 0.0f);
    float getArea() const override;
    void printArea() const override;
};

void printAreaOfShape(const Shape &shape);

#endif // SHAPE_H
