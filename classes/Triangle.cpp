#include "Triangle.h"
#define _USE_MATH_DEFINES
#include <cmath>

Triangle::Triangle() : a(0), b(0), c(0) {}

Triangle::Triangle(double a, double b, double c) {
    setSides(a, b, c);
}

Triangle::Triangle(const Triangle& other) : a(other.a), b(other.b), c(other.c) {}

void Triangle::setA(double newA) {
    if (newA <= 0 || (b + c <= newA && b != 0 && c != 0))
        throw std::invalid_argument("Invalid side length");
    a = newA;
}

void Triangle::setB(double newB) {
    if (newB <= 0 || (a + c <= newB && a != 0 && c != 0))
        throw std::invalid_argument("Invalid side length");
    b = newB;
}

void Triangle::setC(double newC) {
    if (newC <= 0 || (a + b <= newC && a != 0 && b != 0))
        throw std::invalid_argument("Invalid side length");
    c = newC;
}

void Triangle::setSides(double newA, double newB, double newC) {
    if (newA <= 0 || newB <= 0 || newC <= 0 ||
        newA + newB <= newC ||
        newA + newC <= newB ||
        newB + newC <= newA) {
        throw std::invalid_argument("Invalid triangle sides");
    }
    a = newA;
    b = newB;
    c = newC;
}

bool Triangle::isValid() const {
    return a > 0 && b > 0 && c > 0 &&
        a + b > c &&
        a + c > b &&
        b + c > a;
}

double Triangle::calculatePerimeter() const {
    return a + b + c;
}

double Triangle::calculateArea() const {
    if (!isValid()) return 0.0;
    double p = calculatePerimeter() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::calculateAngles(double& angleA, double& angleB, double& angleC) const {
    if (!isValid()) {
        angleA = angleB = angleC = 0.0;
        return;
    }

    angleA = acos((b * b + c * c - a * a) / (2 * b * c)) * 180.0 / std::acos(-1);
    angleB = acos((a * a + c * c - b * b) / (2 * a * c)) * 180.0 / std::acos(-1);
    angleC = 180.0 - angleA - angleB;
}

Triangle::operator std::string() const {
    std::stringstream ss;
    ss << "Triangle [a=" << a << ", b=" << b << ", c=" << c << "]";
    return ss.str();
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
        c = other.c;
    }
    return *this;
}

std::istream& operator>>(std::istream& in, Triangle& triangle) {
    double a, b, c;
    std::cout << "Enter triangle sides (a b c): ";
    in >> a >> b >> c;
    triangle.setSides(a, b, c);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Triangle& triangle) {
    out << static_cast<std::string>(triangle);
    return out;
}

Triangle& operator++(Triangle& triangle) {
    triangle.a++;
    triangle.b++;
    triangle.c++;
    return triangle;
}

Triangle operator++(Triangle& triangle, int) {
    Triangle temp = triangle;
    ++triangle;
    return temp;
}

Triangle& operator--(Triangle& triangle) {
    triangle.a--;
    triangle.b--;
    triangle.c--;
    return triangle;
}

Triangle operator--(Triangle& triangle, int) {
    Triangle temp = triangle;
    --triangle;
    return temp;
}
