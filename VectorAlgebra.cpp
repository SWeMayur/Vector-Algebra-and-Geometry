#include <iostream>
#include <cmath>

struct Point {
    double x, y, z;
};

void normalizeVector(double &dx, double &dy, double &dz) {
    double magnitude = std::sqrt(dx * dx + dy * dy + dz * dz);
    dx /= magnitude;
    dy /= magnitude;
    dz /= magnitude;
}

Point findPointBWithDirection(Point A, double dx, double dy, double dz, double distance) {
    normalizeVector(dx, dy, dz);
    Point B;
    B.x = A.x + distance * dx;
    B.y = A.y + distance * dy;
    B.z = A.z + distance * dz;
    return B;
}

Point findPointBWithSlope(Point A, double slopeDegrees, double distance) {
    double radians = slopeDegrees * M_PI / 180.0;  
    double dx = std::cos(radians);  
    double dy = std::sin(radians);  
    double dz = 0;  

    return findPointBWithDirection(A, dx, dy, dz, distance);
}

int main() {
    Point A = {5, 2, 0}; 
    double distance = 15;  

    double dx1 = 3, dy1 = 4, dz1 = 0;
    Point B1 = findPointBWithDirection(A, dx1, dy1, dz1, distance);
    std::cout << "Point B with given direction vector: (" << B1.x << ", " << B1.y << ", " << B1.z << ")\n";

    double slopeDegrees = 45;
    Point B2 = findPointBWithSlope(A, slopeDegrees, distance);
    std::cout << "Point B with 45-degree slope: (" << B2.x << ", " << B2.y << ", " << B2.z << ")\n";

    return 0;
}
