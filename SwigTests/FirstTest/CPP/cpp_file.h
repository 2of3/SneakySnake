#pragma once  

#ifdef CPP_EXPORTS
#define CPP_API __declspec(dllexport)
#else
#define CPP_API __declspec(dllimport)
#endif

#include <array>

#include <iostream>
#include "Foo.h"
class cpp_file
{
	


public:
	cpp_file(void);
	~cpp_file(void);

	//OK
	void testFoo(Foo f);

	void testArray(std::array<float, 3>);

	//std::array<float, 3> testF(Foo f);

	//void ray_cast(float start[3], float end[3], float location[3], float normal[3], int &index);

	

	
};