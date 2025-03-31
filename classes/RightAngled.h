#pragma once
#include "Triangle.h"

class RightAngled {
private:
  Triangle triangle;
  double area;

public:
  RightAngled();
  RightAngled(const Triangle& triangle);
  RightAngled(const RightAngled& other);

  Triangle getTriangle() const;
  double getArea() const;

  void setTriangle(const Triangle& triangle);

  operator std::string() const;

  RightAngled& operator=(const RightAngled& other);
  friend std::istream& operator>>(std::istream& in, RightAngled& rightAngled);
  friend std::ostream& operator<<(std::ostream& out, const RightAngled& rightAngled);
  friend RightAngled& operator++(RightAngled& rightAngled);
  friend RightAngled operator++(RightAngled& rightAngled, int);
  friend RightAngled& operator--(RightAngled& rightAngled);
  friend RightAngled operator--(RightAngled& rightAngled, int);

  operator double() const;
};