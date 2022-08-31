#include "MutantStack.hpp"
#include <iostream>
#include <unistd.h>
#include <list>

int test_from_subject();
int test_from_subject_std_list();
template <typename T>
void push(MutantStack<T> &ms, T v);

int main(void)
{
    std::cout << "//////// Testing subject main when MutantStack used: " << std::endl;
    test_from_subject();
    std::cout << "//////// Testing subject main when std::list used: " << std::endl;
    test_from_subject_std_list();

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

    return 0;
}

int test_from_subject()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
//[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

int test_from_subject_std_list()
{
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
//[...]
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::list<int> s(mstack);
    return 0;
}

template <typename T>
void push(MutantStack<T> &ms, T v)
{
    std::cout << "Pushing " << v << std::endl;
    ms.push(v);
}
