#ifndef CPP08_SPAN_H
#define CPP08_SPAN_H
#include <set>
#include <iterator>
#include <algorithm>

class Span {
private:
    unsigned int N;
    std::multiset<unsigned int> values;
    void silent_check();
public:
    Span(unsigned int);

    Span();
    Span(const Span &f);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(unsigned int v);
    template<typename T>
    void addNumbers(T from, T to);

    unsigned int shortestSpan();
    unsigned int longestSpan();
};

template<typename T> void Span::addNumbers(T from, T to)
{
    unsigned int inserting_count = 0;
    for (T iter = from; iter != to; ++iter)
        inserting_count++;

    if (values.size() + inserting_count > N)
        throw std::exception();

    values.insert(from, to);
}

#endif //CPP08_SPAN_H
