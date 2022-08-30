#include "Span.h"
#include <iostream>

void test_default();
void test_overflow_span();
void test_empty_span();
void test_only_one_element_in_span();
void test_many_elements(unsigned int elements_number, unsigned int step);
void test_multiple_insert(unsigned int elements_number, unsigned int step);

int main(void)
{
    test_default();
    test_overflow_span();
    test_empty_span();
    test_only_one_element_in_span();
    test_many_elements(10000, 0);
    test_many_elements(10000, 1);
    test_many_elements(20000, 3);
    test_multiple_insert(10000, 1);
}

void test_default()
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

void test_multiple_insert(unsigned int elements_number, unsigned int step)
{
    Span sp = Span(elements_number);

    std::multiset<int> v;
    v.insert(1);
    v.insert(2);
    v.insert(4);
    sp.addNumbers(v.begin(), v.end());

    std::cout << "Result of multiple inserted Span::shortestSpan() on " << elements_number
        << " elements generated with step " << step
        << ": " << sp.shortestSpan() << std::endl;
    std::cout << "Result of multiple inserted Span::longestSpan() on " << elements_number
        << " elements generated with step " << step
        << ": " << sp.longestSpan() << std::endl;
}