#include "Span.h"
#include <iostream>
#include <vector>
#include <list>

void test_from_subject();
void test_overflow_span();
void test_empty_span();
void test_only_one_element_in_span();
void test_many_elements(unsigned int elements_number, unsigned int step);
void test_multiple_insert_using_container(unsigned int elements_number, unsigned int step);

int main(void)
{
    unsigned int elements_standard_num = 10000;
    unsigned int elements_standard_step = 1;

    test_from_subject();
    test_overflow_span();
    test_empty_span();
    test_only_one_element_in_span();
    test_many_elements(elements_standard_num, 0);
    test_many_elements(elements_standard_num, elements_standard_step);
    test_many_elements(20000, 3);

    std::cout << std::endl;
    std::cout << "///////// Testing multiple insert using vector" << std::endl;
//    std::vector<int> v(elements_standard_num);
    test_multiple_insert_using_container(elements_standard_num, elements_standard_step);

//    std::cout << std::endl;
//    std::cout << "///////// Testing multiple insert using list" << std::endl;
//    std::list<int> l;
//    test_multiple_insert_using_container(l, elements_standard_num, elements_standard_step);
}

void test_from_subject()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

void test_overflow_span()
{
    Span sp = Span(1);

    sp.addNumber(123);
    try {
        sp.addNumber(234);
    } catch (std::exception &e)
    {
        std::cout << "Caught exception when overflow Span" << std::endl;
    }
}

void test_empty_span()
{
    Span sp = Span(100500);

    try {
        sp.shortestSpan();
    } catch (std::exception &e)
    {
        std::cout << "Caught exception when called Span::shortestSpan() on empty Span" << std::endl;
    }

    try {
        sp.longestSpan();
    } catch (std::exception &e)
    {
        std::cout << "Caught exception when called Span::longestSpan() on empty Span" << std::endl;
    }
}

void test_only_one_element_in_span()
{
    Span sp = Span(100500);

    sp.addNumber(123);
    try {
        sp.shortestSpan();
    } catch (std::exception &e)
    {
        std::cout << "Caught exception when called Span::shortestSpan() on Span with only one number" << std::endl;
    }

    try {
        sp.longestSpan();
    } catch (std::exception &e)
    {
        std::cout << "Caught exception when called Span::longestSpan() on Span with only one number" << std::endl;
    }
}

void test_many_elements(unsigned int elements_number, unsigned int step)
{
    Span sp = Span(elements_number);

    unsigned int i = 1;
    while (i <= elements_number)
    {
        sp.addNumber(i * step);
        i++;
    }

    std::cout << "Result of Span::shortestSpan() on " << elements_number << " elements generated with step " << step
        << ": " << sp.shortestSpan() << std::endl;
    std::cout << "Result of Span::longestSpan() on " << elements_number << " elements generated with step " << step
        << ": " << sp.longestSpan() << std::endl;
}

void test_multiple_insert_using_container(unsigned int elements_number, unsigned int step)
{
    Span sp = Span(elements_number);

    std::vector<int> v(elements_number);
    std::vector<int>::iterator i = v.begin();
    v.insert(i, 1);
    i++;
    v.insert(i, 2);
    i++;
    v.insert(i, 4);
    sp.addNumbers(v.begin(), v.end());

    std::cout << "Result of multiple inserted Span::shortestSpan() on " << elements_number
        << " elements generated with step " << step
        << ": " << sp.shortestSpan() << std::endl;
    std::cout << "Result of multiple inserted Span::longestSpan() on " << elements_number
        << " elements generated with step " << step
        << ": " << sp.longestSpan() << std::endl;
}