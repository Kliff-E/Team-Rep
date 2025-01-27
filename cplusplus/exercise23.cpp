#include "exercise23.h"

void Shape::printArea() const
{
    std::cout << "Area: " << getArea() << std::endl;
}

Circle::Circle(Point center, float radius) : center(center), radius(radius) {}

float Circle::getArea() const
{
    return M_PI * radius * radius;
}

bool Circle::operator==(const Circle &other) const
{
    return this->radius == other.radius;
}

void Circle::printArea() const
{
    std::cout << "Circle Area: " << getArea() << std::endl;
}

Square::Square(float length) : length(length) {}

float Square::getArea() const
{
    return length * length;
}

void Square::printArea() const
{
    std::cout << "Square Area: " << getArea() << std::endl;
}

void printAreaOfShape(const Shape &shape)
{
    shape.printArea();
}
