#ifndef CPP08_SPAN_H
#define CPP08_SPAN_H
#include <set>
#include <iterator>

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
    void addNumbers(std::set<int>::iterator from, std::set<int>::iterator to);
    unsigned int shortestSpan();
    unsigned int longestSpan();

};


#endif //CPP08_SPAN_H
