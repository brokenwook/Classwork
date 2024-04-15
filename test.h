#include <iostream>
#include <vector>
#include "test.h"

std::vector<int> creat_vec(int amount)
{
	std::vector<int> num;
	num.push_back(1);
	num.push_back(num[0] * 2);
	num.push_back(num[1] * 2);
	num.push_back(num[2] * 2);
	num.push_back(num[3] * 2);
	num.push_back(22);



	return std::vector<int>(num);
}


int main()
{
	setlocale(0, "");
	test::test_some_func(creat_vec);
	return 0;
}
