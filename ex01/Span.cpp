#include "Span.h"

Span::Span(unsigned int n) {
    N = n;
}

void Span::addNumber(unsigned int v) {

}

Span::Span()
{
}

Span::Span(const Span &f) {
    N = f.N;
}

Span &Span::operator=(const Span &other) {
    N = other.N;
    return this;
}

Span::~Span() {

}

