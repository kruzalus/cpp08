#include "easy_find.hpp"

int main(void)
{
	std::vector<int> clctn;

	clctn.push_back(3);
	clctn.push_back(4);

	std::cout << "Result: " << (easy_find(clctn.begin(), clctn.end(), 3) != clctn.end()) << std::endl;



}