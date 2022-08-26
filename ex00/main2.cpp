#include <algorithm>
#include <vector>
#include <iostream>
#include "easy_find.hpp"

template <class T> void show_container(T container)
{
	std::vector<int>::iterator i = container.begin();
	while (i != container.end())
	{
		std::cout << *i << std::endl;
		i = std::next(i, 1);
	}
}

int main(void)
{
	std::vector<int> vector_container;

	vector_container.push_back(3);
	vector_container.push_back(4);

//	bool res = std::find(vector_container.begin(), vector_container.end(), 2) != vector_container.end();
//	std::cout << "Result: " << res << std::endl;
	std::cout << "/////// Testing vector:" << std::endl;
	std::cout << "Vector content:" << std::endl;
    show_container(vector_container);

	std::cout << "Default Searching for: " << *std::find(vector_container.begin(), vector_container.end(), 4) << std::endl;
	std::cout << "Default Searching for 2: " << (std::find(vector_container.begin(), vector_container.end(), 5) != vector_container.end()) << std::endl;

	std::cout << "My Searching for: " << *easy_find(vector_container, 4) << std::endl;
//	std::cout << "My Searching for 2: " << *easy_find(vector_container, 5) << std::endl;



}