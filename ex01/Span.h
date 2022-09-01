#ifndef CPP08_SPAN_H
#define CPP08_SPAN_H
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

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
    {
        inserting_count++;
    }

    unsigned int actual_size = values.size();

    std::cout << "inserting_count " << inserting_count << std::endl;
    std::cout << "real_size " << values.size() << std::endl;

    if (actual_size + inserting_count > N)
    {
        throw std::exception();
    }

    values.insert(from, to);
    std::cout << "real_size " << values.size() << std::endl;
}

#endif //CPP08_SPAN_H
