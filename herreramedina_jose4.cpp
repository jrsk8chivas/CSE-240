#include <iostream>
#include <math.h>

using namespace std;

class Polygon
{
private:
	float apothem;
	float perimeter;
public:
	virtual float area()
	{
		return (1 / 2) * apothem * perimeter;
	}
};

// Q1: Create an Triangle class that inherits from Polygon class:
//     - Create a constructor for the triangle class, which captures the base and the height [5 pts]
//     - Create an area function, which overrides the Polygon class, for a triangle. [5 pts]
class Triangle : public Polygon
{
protected:
	float base;
	float height;

public:
	Triangle() { }


	// ----- Start coding here ----- //
	//- Create a constructor for the triangle class, which captures the base and the height [5 pts]
	Triangle(float triangleBase, float triangleHeight) :base(triangleBase), height(triangleHeight){}
	
	//- Create an area function, which overrides the Polygon class, for a triangle. [5 pts]
	float area()
	{
		return (1. / 2) * base* height;
	}

	// ----- End coding here ----- //
};

// Q3: Create an EquilateralTriangle class that inherits from Triangle:  
//     - Create 2 overload constructors to capture base and height; or length of a side. (HINT: Set other values to -1 if not used) [10 pts]
//     - Create an area function, which overrides the Triangle class, for an equilateral triangle. [5 pts]
class EquilateralTriangle : public Triangle
{
private:
	float side;

public:
	EquilateralTriangle() { }

	// ----- Start coding here ----- //
	//     - Create 2 overload constructors to capture base and height;
	EquilateralTriangle(float triangleBase, float triangleHeight) :side(triangleBase),
		Triangle(triangleBase, triangleHeight){}

	//or length of a side. (HINT: Set other values to -1 if not used) [10 pts]
	EquilateralTriangle(float triangleSide) : side(triangleSide)
	{
		base == triangleSide;
		height == side*pow(3, 0.5) / 2;
	}

	//- Create an area function, which overrides the Triangle class, for an equilateral triangle. [5 pts]
	float area()
	{
		return Triangle::area();
	}
	// ----- End coding here ----- //
};

// Q4: Create an Rectangle class that inherits from Polygon class (Class must be labeled as "Rectangle"):  
//     - Create a constructor to capture the base and the height. [5 pts]
//     - Create an area function, which calculates the area for a rectangle and also overrides the Polygon class. [5 pts]
// ----- Start coding here ----- //

class Rectangle : public Polygon
{
protected:
	float base;
	float height;

public:
	Rectangle() { }

	//     - Create a constructor to capture the base and the height. [5 pts]
	Rectangle(float Base, float Height) :base(Base), height(Height){}
	//     - Create an area function, which calculates the area for a rectangle and also overrides the Polygon class. [5 pts]
	float area()
	{
		return base* height;
	}
};
// ----- End coding here ----- //

// Q5: Create an Square class that inherits from Rectangle class (Class must be labled as "Square"):  
//     - Create 2 overload constructors to capture the base and the height; or the length of a side. [10 pts]
//     - Create an area function, which calculates the ares for a square. [5 pts]
// ----- Start coding here ----- //
class Square : public Rectangle
{
private:
	float side;

public:
	Square() { }

	//- Create 2 overload constructors to capture the base and the height;
	Square(float Base, float Height) :side(Base),
		Rectangle(Base, Height){}
	//or the length of a side. [10 pts]
	Square(float Side) : side(Side)
	{
		base = Side;
		height = Side;
	}
	//     - Create an area function, which calculates the ares for a square. [5 pts]
	float area()
	{
		return side*side;
	}
};
	// ----- End coding here ----- //

	int main()
	{
		Polygon *shape;

		// Uncomment these 3 lines of code when you're ready to test the Triangle class
		shape = new Triangle(5, 10);
		cout << "The area for a triangle is " << shape->area() << "\n\n";
		delete(shape);

		// Uncomment these 3 lines of code when you're ready to test the EquilateralTriangle class
		shape = new EquilateralTriangle(5);
		cout << "The area for an equilateral triangle is " << shape->area() << "\n\n"; 
		delete(shape); 

		// Uncomment these 3 lines of code when you're ready to test the EquilateralTriangle class
		shape = new EquilateralTriangle(5, 4.3301270189221932338186158537647);
		cout << "The area for an equilateral triangle is " << shape->area() << "\n\n";
		delete(shape);

		// Uncomment these 3 lines of code when you're ready to test the Rectangle class
		shape = new Rectangle(5, 10);
		cout << "The area for a rectangle is " << shape->area() << "\n\n";
		delete(shape);

		// Uncomment these 3 lines of code when you're ready to test the Square class
		shape = new Square(5);
		cout << "The area for a square is " << shape->area() << "\n\n";
		delete(shape);
	}
	