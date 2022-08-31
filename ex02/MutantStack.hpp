#ifndef CPP08_MUTANTSTACK_H
#define CPP08_MUTANTSTACK_H
#include <vector>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack &f);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();
};

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &f)
{
    this->c = f.c;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack& other)
{
    this->c = other.c;
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

#endif //CPP08_MUTANTSTACK_H
