#include "Span.h"
#include <iostream>

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

int main(void)
{
    test_default();

//    Span s(3);

//    s.addNumber(777);
//    s.addNumber(888);
//    s.shortestSpan();

}