#ifndef CPP08_MUTANTSTACK_H
#define CPP08_MUTANTSTACK_H
#include <vector>
#include <iostream>

template <typename T>
class MutantStack
{
    typedef typename std::vector<T>::size_type size_type;
protected:
    std::vector<T> C;
public:
    T& top();
    void push(const T& value);
    void pop();
    bool empty() const;
    typename MutantStack<T>::size_type size() const;
    MutantStack();
    MutantStack(const MutantStack &f);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();
};

template <typename T>
T &MutantStack<T>::top() {
    return C.back();
}

template <typename T>
void MutantStack<T>::push(const T &value) {
    C.push_back(value);
}

template <typename T>
void MutantStack<T>::pop() {
    C.pop_back();
}

template <typename T>
bool MutantStack<T>::empty() const {
    return C.empty();
}

template <typename T>
typename MutantStack<T>::size_type MutantStack<T>::size() const {
    return C.size();
}

template <typename T>
MutantStack<T>::MutantStack()
{
    std::vector<T> tmp;
    C = tmp;

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &f)
{

}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack& other)
{
    std::cout << "TTTT" << std::endl;
    C = other.C;
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{

}

#endif //CPP08_MUTANTSTACK_H
