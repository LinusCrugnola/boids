#include <gtest/gtest.h>

#include <iostream>

GTEST_API_ int main(int argc, char **argv) 
{
    std::cout << "Running se-states Unit Tests" << std::endl;

	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}