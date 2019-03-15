#include <iostream>
#include "include/Vector3.hpp"

int main()
{
	cfs::Vector3 v(1.f, 0, 0);
	cfs::Vector3 w(0, 1.f, 0);
	float z = cfs::Vector3::dot(v, w);
	std::cout << cfs::Vector3::angle(v,w) << std::endl;
	return 0;
}
