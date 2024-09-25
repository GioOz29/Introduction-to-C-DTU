#include <iostream>
#include <cmath>
#include "shapes.h"

using namespace std;

Shape::~Shape() {}
Shape::Shape() {}

Rectangle::Rectangle(double height, double width) : h(height), w(width) {}
Rectangle::Rectangle(const Rectangle & r){
    h = r.h;
    w = r.w;
}

Rectangle::~Rectangle() {}

Square::Square(double length) : l(length) {}
Square::Square(const Square & s){
    l = s.l;
}
Square::~Square() {}

Circle::Circle(double radius) : r(radius) {}
Circle::Circle(const Circle & c){
    r = c.r;
}
Circle::~Circle() {}

// Implementing the rectangle
double Rectangle::area(void){
    return h * w;
}

double Rectangle::perimeter(void){
    return 2 * (h + w);
}

double Rectangle::height(void){
    return h;
}

double Rectangle::width(void){
    return w;
}

void Rectangle::rotate(void){
    double temp = h;
    h = w;
    w = temp;
}
// Implementing the square
double Square::area(void){
    return pow(l,2);
}

double Square::perimeter(void){
    return 4 * l;
}

double Square::height(void){
    return l;
}

double Square::width(void){
    return l;
}

void Square::rotate(void){
    // Do nothing
}
// Implementing the circle
double Circle::area(void){
    return M_PI * pow(r,2);
}

double Circle::perimeter(void){
    return 2 * M_PI * r;
}

double Circle::height(void){
    return 2 * r;
}

double Circle::width(void){
    return 2 * r;
}

void Circle::rotate(void){
    // Do nothing
}