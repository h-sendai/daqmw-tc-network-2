#include <cstdio>
#include <fstream>
#include <iostream>

#include "MyClass.h"
using namespace std;

void my_function(MyClass x)
{
    return;
}

int main(int argc, char *argv[])
{
    MyClass a;
    MyClass b(1, 2);
    
    int x = b.get_x();
    int y = b.get_y();
    cerr << "b.m_x: " << x << endl;
    cerr << "b.m_y: " << y << endl;

    a.set_x(10);
    a.set_y(20);
    x = a.get_x();
    y = a.get_y();
    cerr << "a.m_x: " << x << endl;
    cerr << "a.m_y: " << y << endl;

    cerr << "use copy ctor" << endl;
    MyClass c(a);
    MyClass d = a;

    cerr << "use assignment operator" << endl;
    MyClass e;
    e = a;

    cerr << "array" << endl;
    MyClass my_array[5];

    cerr << "function call" << endl;
    my_function(a);

    cerr << "program end" << endl;
    return 0;
}
