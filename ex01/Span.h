#ifndef CPP08_SPAN_H
#define CPP08_SPAN_H
#include <set>

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
    unsigned int shortestSpan();
    unsigned int longestSpan();

};


#endif //CPP08_SPAN_H
