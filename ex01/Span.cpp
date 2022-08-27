#include "Span.h"

Span::Span(unsigned int n) {
    N = n;
}

void Span::addNumber(unsigned int value) {
    N++;
    values.insert(value);
}

unsigned int Span::shortestSpan()
{
    unsigned int min_diff = longestSpan();
    std::multiset<unsigned int>::iterator i;

    if (values.empty() or values.size() == 1)
        throw std::exception();
    for (i = values.begin(); i != values.end(); i++)
    {
        if (i == values.begin())
            continue;
        if (min_diff > *i - *(std::prev(i, 1)))
            min_diff = *i - *(std::prev(i, 1));
    }
    return min_diff;
}

unsigned int Span::longestSpan()
{
    silent_check();
    return *values.rbegin() - *values.begin();;
}

void Span::silent_check()
{
    if (values.empty() or values.size() == 1)
        throw std::exception();
}

Span::Span()
{
}

Span::Span(const Span &f) {
    N = f.N;
}

Span &Span::operator=(const Span &other) {
    N = other.N;
    return *this;
}

Span::~Span() {

}

