#include <iostream>
#include "./classes/Triangle.h"
#include "./classes/RightAngled.h"

void demonstrateTriangle() {
    std::cout << "\n=== Triangle Class Demonstration ===\n";

    Triangle t1;
    std::cout << "Enter triangle sides (a b c): ";
    std::cin >> t1;

    std::cout << "\nTriangle information:\n" << t1 << std::endl;

    std::cout << "Perimeter: " << t1.calculatePerimeter() << std::endl;
    std::cout << "Area: " << t1.calculateArea() << std::endl;

    double angleA, angleB, angleC;
    t1.calculateAngles(angleA, angleB, angleC);
    std::cout << "Angles: " << angleA << "°, " << angleB << "°, " << angleC << "°\n";

    std::cout << "\nChanging side a to 5: ";
    t1.setA(5);
    std::cout << t1 << std::endl;

    std::cout << "Changing all sides to 6, 8, 10: ";
    t1.setSides(6, 8, 10);
    std::cout << t1 << std::endl;

    std::cout << "\nOperator demonstration:\n";
    std::cout << "Original triangle: " << t1 << std::endl;
    Triangle t2 = t1++;
    std::cout << "After t2 = t1++: t1=" << t1 << ", t2=" << t2 << std::endl;
    t2 = ++t1;
    std::cout << "After t2 = ++t1: t1=" << t1 << ", t2=" << t2 << std::endl;
}

void demonstrateRightAngled() {
    std::cout << "\n=== RightAngled Class Demonstration ===\n";

    RightAngled r1;
    std::cout << "Enter right-angled triangle sides (a b c): ";
    std::cin >> r1;

    std::cout << "\nRight-angled triangle information:\n" << r1 << std::endl;
    std::cout << "Perimeter: " << static_cast<double>(r1) << std::endl;
    std::cout << "Area: " << r1.getArea() << std::endl;

    Triangle newTriangle(5, 12, 13);
    std::cout << "\nChanging triangle to new (5, 12, 13): ";
    r1.setTriangle(newTriangle);
    std::cout << r1 << std::endl;

    std::cout << "\nOperator demonstration:\n";
    std::cout << "Original: " << r1 << std::endl;
    RightAngled r2 = r1++;
    std::cout << "After r2 = r1++: r1=" << r1 << ", r2=" << r2 << std::endl;
    r2 = ++r1;
    std::cout << "After r2 = ++r1: r1=" << r1 << ", r2=" << r2 << std::endl;
}

void showClassSizes() {
    std::cout << "\n=== Class Sizes ===\n";
    std::cout << "Triangle size: " << sizeof(Triangle) << " bytes\n";
    std::cout << "RightAngled size: " << sizeof(RightAngled) << " bytes\n";

#pragma pack(push, 1)
    std::cout << "\nWith #pragma pack(1):\n";
    std::cout << "Triangle size: " << sizeof(Triangle) << " bytes\n";
    std::cout << "RightAngled size: " << sizeof(RightAngled) << " bytes\n";
#pragma pack(pop)
}

int main() {
    try {
        demonstrateTriangle();
        demonstrateRightAngled();
        showClassSizes();
    }
    catch (const std::exception& e) {
        std::cerr << "\nError: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
