#pragma once
#include <iostream>
#include <cmath>
#include <sstream>

class Triangle {
private:
  double a, b, c;

public:
  Triangle();
  Triangle(double a, double b, double c);
  Triangle(const Triangle& other);

  double getA() const { return a; }
  double getB() const { return b; }
  double getC() const { return c; }
  void setA(double newA);
  void setB(double newB);
  void setC(double newC);
  void setSides(double newA, double newB, double newC);

  double calculatePerimeter() const;
  double calculateArea() const;
  void calculateAngles(double& angleA, double& angleB, double& angleC) const; // Обчислення кутів

  bool isValid() const;

  operator std::string() const;

  Triangle& operator=(const Triangle& other);
  friend std::istream& operator>>(std::istream& in, Triangle& triangle);
  friend std::ostream& operator<<(std::ostream& out, const Triangle& triangle);
  friend Triangle& operator++(Triangle& triangle);
  friend Triangle operator++(Triangle& triangle, int);
  friend Triangle& operator--(Triangle& triangle);
  friend Triangle operator--(Triangle& triangle, int);

  operator double() const { return calculatePerimeter(); }
};
