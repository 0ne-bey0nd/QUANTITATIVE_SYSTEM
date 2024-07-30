#include "test.h"

int separator(int length)
{
	for (int i = 0; i < length; ++i) {
		std::cout << "-";
	}
	std::cout << std::endl;
	return 0;
}

int main()
{
	std::cout << "This is a cpp test programme." << std::endl;
    for (int i = 0; i < numFunctions; ++i) {
		separator(20);
        testFunctions[i](0, nullptr);

    }
	separator(20);
	return 0;
}