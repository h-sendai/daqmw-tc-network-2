#include "MyClass.h"

// Default Constructor
MyClass::MyClass(): m_x(0), m_y(0)
{
	std::cerr << "MyClass default ctor()" << std::endl;
}

// Constructor with two arguments
MyClass::MyClass(int x, int y): m_x(x), m_y(y)
{
	std::cerr << "MyClass ctor(int, int)" << std::endl;
}

MyClass::MyClass(const MyClass &rhs): m_x(rhs.m_x), m_y(rhs.m_y)
{
    std::cerr << "MyClass copy ctor" << std::endl;
}

MyClass& MyClass::operator =(const MyClass& rhs)
{
    std::cerr << "assignment operator" << std::endl;
    if (this != &rhs) {
        m_x = rhs.m_x;
        m_y = rhs.m_y;
    }
    return *this;
}

// Destructor
MyClass::~MyClass()
{
	std::cerr << "MyClass dtor()" << std::endl;
}

int MyClass::set_x(int x)
{
	m_x = x;
	return 0;
}

int MyClass::set_y(int y)
{
	m_y = y;
	return 0;
}

int MyClass::get_x()
{
	return m_x;
}

int MyClass::get_y()
{
	return m_y;
}
