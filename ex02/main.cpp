#include "MutantStack.hpp"
#include <iostream>

template <typename T>
void push(MutantStack<T> &ms, T v)
{
    std::cout << "Pushing " << v << std::endl;
    ms.push(v);
}

int main(void)
{
    MutantStack<int> m = MutantStack<int>();

    std::cout << "//////// Testing general functions " << std::endl;
    std::cout << "Is empty in the beginning? " << m.empty() << std::endl;

    push(m, 2);
    push(m, 1);
    push(m, 4);
    std::cout << "Is empty after multiple pushes? " << m.empty() << std::endl;

    std::cout << "Size: " << m.size() << std::endl;
    std::cout << "Top: " << m.top() << std::endl;
    std::cout << "Pop ... " << std::endl;
    m.pop();
    std::cout << "Size: " << m.size() << std::endl;
    std::cout << "Top: " << m.top() << std::endl;

    std::cout << "//////// Testing operator= " << std::endl;
    std::cout << "Creating the second stack " << std::endl;
    MutantStack<int> m2;

    std::cout << "Assigning the first stack to the second stack " << std::endl;
    m2 = m;

    std::cout << "Pushing to the second stack" << std::endl;
    push(m2, 5);
    std::cout << "Size of the second stack: " << m2.size() << std::endl;
    std::cout << "Size of the first stack: " << m.size() << std::endl;

    return 0;
}