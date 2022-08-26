#include <algorithm>
#include <vector>
#include <iostream>

template <class T> void show_container(T container)
{
	T<int> iterator = container.begin();
	while (iterator != container.end())
	{
		std::cout << iterator << std::endl;
		iterator = iterator.next();
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
	std::cout << "Vector content:" << show_container(vector_container) << std::endl;
	std::cout << "Searching for: " << (std::find(vector_container.begin(), vector_container.end(), 5) != vector_container.end()) << std::endl;
	std::cout << "Result: " << (std::find(vector_container.begin(), vector_container.end(), 5) != vector_container.end()) << std::endl;

}