#ifndef __Shape__
#define __Shape__

class Shape{
    public:
        // Standard constructor
        Shape();

        // Standard destructor
        ~Shape();

        virtual double area(void) = 0;
        virtual double perimeter(void) = 0;
        virtual double height(void) = 0;
        virtual double width(void) = 0;
        virtual void rotate(void) = 0;
};

class Rectangle : public Shape{
    public:
        // Standard constructor
        Rectangle(double height, double width);
        Rectangle(const Rectangle & r);
        ~Rectangle();

        double area(void);
        double perimeter(void);
        double height(void);
        double width(void);
        void rotate(void);

    private:
        double h;
        double w;
};

class Square : public Shape{
    public:
        // Standard constructor
        Square(double length);
        Square(const Square & s);
        ~Square();

        double area(void);
        double perimeter(void);
        double height(void);
        double width(void);
        void rotate(void);

    private:
        double l;
};

class Circle : public Shape{
    public:
        // Standard constructor
        Circle(double radius);
        Circle(const Circle & c);
        ~Circle();

        double area(void);
        double perimeter(void);
        double height(void);
        double width(void);
        void rotate(void);

    private:
        double r;
};

#endif