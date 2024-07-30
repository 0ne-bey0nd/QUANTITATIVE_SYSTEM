#include "lib_test.h"

int lib_test_main(int argc, char* argv[])
{
	std::cout << "This is lib test." << std::endl;
	int a = 1, b = 2;
	int c = add(a, b);
	std::cout << "c=" << c << std::endl;
	return 0;
}
