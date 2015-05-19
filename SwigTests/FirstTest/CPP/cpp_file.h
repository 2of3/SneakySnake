#pragma once  

#ifdef CPP_EXPORTS  
#define CPP_API __declspec(dllexport)  
#else  
#define CPP_API __declspec(dllimport)  
#endif 


#include <array>

#include <iostream>
#include "Foo.h"
class CPP_API cpp_file
{
	
#define myint int
#define myfloat float

public:
	cpp_file(void);
	~cpp_file(void);

	
	void gravity(std::array<float, 3> param);

	std::array<float, 3> gravity2(std::array<float, 3> param);

	std::array<float, 3> testF(Foo f);

	//void ray_cast(float start[3], float end[3], float location[3], float normal[3], int &index);

	

	
};