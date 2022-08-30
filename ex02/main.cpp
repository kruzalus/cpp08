#include "MutantStack.hpp"
#include <iostream>
#include <unistd.h>
template <typename T>
void push(MutantStack<T> &ms, T v)
{
    std::cout << "Pushing " << v << std::endl;
    ms.push(v);
}

int main(void)
{
//    while (1)
//    {

    MutantStack<int> m = MutantStack<int>();

    std::cout << "//////// Testing general functions " << std::endl;
    std::cout << "Is empty in the beginning? " << m.empty() << std::endl;

    std::cout << "Pushing value 5 ... " << std::endl;
    m.push(5);
    std::cout << "Is empty after push? " << m.empty() << std::endl;
    std::cout << "Size: " << m.size() << std::endl;
    std::cout << "Top: " << m.top() << std::endl;

    std::cout << "Pushing value 6 ... " << std::endl;
    m.push(6);
    std::cout << "Is empty after push? " << m.empty() << std::endl;
    std::cout << "Size: " << m.size() << std::endl;
    std::cout << "Top: " << m.top() << std::endl;

    std::cout << "Pushing value 7 ... " << std::endl;
    m.push(7);
    std::cout << "Is empty after push? " << m.empty() << std::endl;
    std::cout << "Size: " << m.size() << std::endl;
    std::cout << "Top): " << m.top() << std::endl;

    std::cout << "Pop ... " << std::endl;
    m.pop();
    std::cout << "Size: " << m.size() << std::endl;
    std::cout << "Top: " << m.top() << std::endl;

    std::cout << "Pop ... " << std::endl;
    m.pop();
    std::cout << "Size: " << m.size() << std::endl;
    std::cout << "Top: " << m.top() << std::endl;

    std::cout << "Pop ... " << std::endl;
    m.pop();
    std::cout << "Size: " << m.size() << std::endl;
    std::cout << "Top: " << m.top() << std::endl;

    std::cout << "Is empty after popes? " << m.empty() << std::endl;



    std::cout << "//////// Testing operator= " << std::endl;
    std::cout << "Creating the second stack " << std::endl;
    MutantStack<int> m2;

    std::cout << "Assigning the first stack to the second stack " << std::endl;
    m2 = m;

    std::cout << "Pushing to the second stack" << std::endl;
    push(m2, 5);
    std::cout << "Size of the first stack: " << m.size() << std::endl;
    std::cout << "Size of the second stack: " << m2.size() << std::endl;

    std::cout << "//////// Testing copy constructor " << std::endl;
    MutantStack<int> m3(m);
    std::cout << "Pushing to the third stack" << std::endl;
    push(m3, 5);
    std::cout << "Size of the first stack: " << m.size() << std::endl;
    std::cout << "Size of the third stack: " << m3.size() << std::endl;



//        usleep(1000000);
//    }
    return 0;
}