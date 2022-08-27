#include "Span.h"
#include <iostream>

int main(void)
{
    test_default();
    test_overflow_span();
    test_when_empty_span();
    test_when_only_one_element_in_span();
    test_on_many_elements(10000, 0);
    test_on_many_elements(10000, 1);
    test_on_many_elements(20000, 3);
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

void test_when_empty_span()
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

void test_when_only_one_element_in_span()
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

void test_on_many_elements(unsigned int elements_number, unsigned int step)
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
