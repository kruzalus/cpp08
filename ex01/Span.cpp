#include "Span.h"

Span::Span(unsigned int n) {
    N = n;
}

void Span::addNumber(unsigned int value) {
    if (values.size() == N)
        throw std::exception();
    values.insert(value);
}

void Span::addNumbers(std::multiset<int>::iterator from, std::multiset<int>::iterator to) {
    values.insert(from, to);
}

unsigned int Span::shortestSpan()
{
    if (values.empty() or values.size() == 1)
        throw std::exception();

    std::vector<unsigned int> diffs(N - 1);
    std::transform(++values.begin(), values.end(),
                   values.begin(), diffs.begin(), std::minus<unsigned int>());
    return *std::min_element(diffs.begin(), diffs.end());
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

