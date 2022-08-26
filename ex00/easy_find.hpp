#include <algorithm>
#include <iterator>

template <typename T> typename T::iterator easy_find(T container, int needle)
{
    typename T::iterator result = std::find(container.begin(), container.end(), needle);
    if (result == container.end())
        throw std::exception();
	return result;
}