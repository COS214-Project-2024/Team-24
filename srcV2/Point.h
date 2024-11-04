#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(double x = 0.0, double y = 0.0);
    
    // Getters
    double getX() const { return x; }
    double getY() const { return y; }
    
    // Distance calculation
    double distanceTo(const Point& other) const;
    
    // Operators
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

private:
    double x;
    double y;
};

#endif // POINT_H
