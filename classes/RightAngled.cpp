#include "RightAngled.h"

RightAngled::RightAngled() : triangle(), area(0) {}

RightAngled::RightAngled(const Triangle& triangle) : triangle(triangle) {
    area = triangle.calculateArea();
}

RightAngled::RightAngled(const RightAngled& other)
    : triangle(other.triangle), area(other.area) {}

Triangle RightAngled::getTriangle() const { return triangle; }
double RightAngled::getArea() const { return area; }

void RightAngled::setTriangle(const Triangle& triangle) {
    this->triangle = triangle;
    area = triangle.calculateArea();
}

RightAngled::operator std::string() const {
    std::stringstream ss;
    ss << "RightAngled " << static_cast<std::string>(triangle)
        << " (Area: " << area << ")";
    return ss.str();
}

RightAngled& RightAngled::operator=(const RightAngled& other) {
    if (this != &other) {
        triangle = other.triangle;
        area = other.area;
    }
    return *this;
}

std::istream& operator>>(std::istream& in, RightAngled& rightAngled) {
    std::cout << "Enter right-angled triangle sides (a b c): ";
    in >> rightAngled.triangle;
    rightAngled.area = rightAngled.triangle.calculateArea();
    return in;
}

std::ostream& operator<<(std::ostream& out, const RightAngled& rightAngled) {
    out << static_cast<std::string>(rightAngled);
    return out;
}

RightAngled& operator++(RightAngled& rightAngled) {
    ++rightAngled.triangle;
    rightAngled.area = rightAngled.triangle.calculateArea();
    return rightAngled;
}

RightAngled operator++(RightAngled& rightAngled, int) {
    RightAngled temp = rightAngled;
    ++rightAngled;
    return temp;
}

RightAngled& operator--(RightAngled& rightAngled) {
    --rightAngled.triangle;
    rightAngled.area = rightAngled.triangle.calculateArea();
    return rightAngled;
}

RightAngled operator--(RightAngled& rightAngled, int) {
    RightAngled temp = rightAngled;
    --rightAngled;
    return temp;
}

RightAngled::operator double() const {
    return triangle.calculatePerimeter();
}