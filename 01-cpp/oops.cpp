#include <iostream>
using namespace std;

// Inheritance : Inherit attributes and methods (Vehicle, Car) --> abstract
// Inheritance : Inherit attributes and methods (Google doc, CV doc) 
// Polymorphism : use same expression to denote different operations --> SoundHorn() of Vehicle fleet, Area() of shapes

struct Date {
	int yy;
	int mm;
	int dd;
};

// Class : A template for creating objects and manipulating their state
// Object : An instance of a class

// A class is an abstraction of an object
class MyDate {
	private: // Encapsulation 
		int yy;
		int mm;
		int dd;
		bool CheckDateValidity(); // Encapsulation 
	public:
		// Initialization
		// Zero-parameter Constructor
		MyDate();
		// Interaction
		void GetDate(int& p_yy,int& p_mm, int& p_dd);
		void SetDate(int t_yy,int t_mm,int t_dd);
		void PrintDate(); // Abstraction : Don't need to know how it prints 
		unsigned long int NumDaysTo(int i_yy,int i_mm,int i_dd); // Abstraction: Don't need to know how it calculates this
		~MyDate();
};

// & = Reference : Used for aliasing
// Pointer-like, except
// References cannot be null
// References cannot be 'freed'
// References always refer to an instantiated object (or primitive)
void MyDate::GetDate(int& p_yy,int& p_mm, int& p_dd)
{
	p_yy = yy;
	p_mm = mm;
	p_dd = dd;
}

// Note: No return value
MyDate::MyDate()
// :: = scope resolution operator (std::cout) 
{
	yy = 0;
	mm = 1;
	dd = 1;

	// Compiler creates one for you if you don't create this
}

void MyDate::PrintDate()
{
	cout << "Date(mm-dd-yy): " << mm << "-" << dd << "-" << yy << endl;
	// std::cout not needed because we invoke using namespace std
}

// Note: No return value
MyDate::~MyDate()
{
	cout << "destructor called\n";
		
}

int main()
{

	struct Date d;
	d.yy = 1980;
	d.mm = 14;
	d.dd = 10;

	MyDate m;
	/*
	m.yy = 1980;
	m.mm = 14;
	m.dd = 10;
	*/

	m.PrintDate();

	return 0;
}

/*

struct Point2D {
	double x;
	double y;
};

// Student 
class Student {
	string StudentName;
	string StudentId;
	Time DateOfBirth;
	unsigned float Height;
	CourseStream courseStm;
};

// Abstraction: A way of expressing the essence of an object (or a method)
// If I have to create instances of a Car class, what are all the
// variables I need ? <-- if a car dealership approaches ? if a service center approaches
// public methods I need to write ?


// Car
class Car {
	string carMake; // Mahindra, Tata
	string carModel; // Verito, Nexon
	string VIN;     
	int manufactureYr;
	DriveType drvType; // AWD, FWD, RWD, 4WD
};

// Encapsulation: Information hiding
// Abstraction usually requires encapsulation: Providing a way of hiding internal details of objects and processes 
// IceCreamMachine
class IceCreamMachine {
	
};

*/
