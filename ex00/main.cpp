#include "easy_find.hpp"
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <iostream>

void print(int element)
{
    std::cout << element << std::endl;
}

template <typename T> void fullfill_normal(T &container)
{
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);
    container.push_back(4);
    container.push_back(5);
}

void fullfill_forward_list(std::forward_list<int> &container)
{
    container.push_front(5);
    container.push_front(4);
    container.push_front(3);
    container.push_front(2);
    container.push_front(1);
}

template <typename T> void test_normal_container_variation(T container, std::string container_typename)
{
    std::cout << "////////////// Testing easy find on " << container_typename << " :" << std::endl;
    fullfill_normal(container);

    std::cout << container_typename << " content: " << std::endl;

    std::for_each(container.begin(), container.end(), &print);

    std::cout << "Trying to find 3 and print iterator content: ";
    std::cout << *easy_find(container, 3) << std::endl;

    std::cout << "Trying to find 4 and print iterator content: ";
    std::cout << *easy_find(container, 4) << std::endl;

    std::cout << "Trying to find 6 and catching exception: ";
    try {
        easy_find(container, 6);
    } catch (std::exception &e)
    {
        std::cout << "Exception caught!" << std::endl;
    }
    std::cout << std::endl;
}

void test_forward_list(std::forward_list<int> container, std::string container_typename)
{
    std::cout << "////////////// Testing easy find on " << container_typename << " :" << std::endl;
    fullfill_forward_list(container);

    std::cout << container_typename << " content: " << std::endl;

    std::for_each(container.begin(), container.end(), &print);

    std::cout << "Trying to find 3 and print iterator content: ";
    std::cout << *easy_find(container, 3) << std::endl;

    std::cout << "Trying to find 4 and print iterator content: ";
    std::cout << *easy_find(container, 4) << std::endl;

    std::cout << "Trying to find 6 and catching exception: ";
    try {
        easy_find(container, 6);
    } catch (std::exception &e)
    {
        std::cout << "Exception caught!" << std::endl;
    }
    std::cout << std::endl;
}

int main(void)
{
    std::vector<int> v;
    test_normal_container_variation(v, "Vector");

    std::list<int> l;
    test_normal_container_variation(l, "List");

    std::deque<int> d;
    test_normal_container_variation(d, "Deque");

    std::forward_list<int> fl;
    test_forward_list(fl, "Forward List");
}