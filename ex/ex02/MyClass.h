#ifndef _MYCLASS
#define _MYCLASS

#include <iostream>

class MyClass
{
public:
	MyClass();
	MyClass(int x, int y);
    MyClass(const MyClass &rhs); // Copy Constructor
    MyClass& operator =(const MyClass& a);
	virtual ~MyClass();
	int set_x(int x);
	int set_y(int y);
	int get_x();
	int get_y();
private:
	int m_x;
	int m_y;

};

#endif
