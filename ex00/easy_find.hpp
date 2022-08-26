#include <algorithm>
#include <iterator>

template <typename T> T<int> easy_find(T container, int needle)
{
	return std::find(container.begin(), container.end(), needle);
}