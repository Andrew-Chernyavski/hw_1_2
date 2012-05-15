#include <iostream>

class Exception
{

};

class A
{
public:
    A()
    {
        std::cout << "Constructor A\n";
    }
    ~A()
    {
        std::cout << "Destructor A\n";
    }
};

class B
{
public:
    B()
    {
        std::cout << "Constructor B\n";
    }
    ~B()
    {
        std::cout << "Destructor B\n";
    }
};

int main()
{
    try
    {
        std::cout << "Creating an object of class A...\n";
        A a;
        std::cout << "Creating an object of class B...\n";
        B b;
        std::cout << "Generating of exception...\n";
        throw Exception();
    }
    catch (Exception)
    {
        std::cout << "Exception worked up\n";
    }
    return 0;
}
