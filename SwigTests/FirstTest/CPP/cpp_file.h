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

	//Foo Stuff - works
	void testFooIn(Foo f);

	Foo testFooOut();

	Foo testFooInOut(Foo f);


	//Array Stuff - works
	void testArrayIn(std::array<float, 3>);

	std::array<float, 3> testArrayOut();

	std::array<float, 3> testArrayInOut(std::array<float,3> myArray);


	//Mixed Stuff

	//- works
	Foo ArrayInFooOut(std::array<float, 3> a);

	//- not
	std::array<float, 3> FooInArrayOut(Foo f);



	

	
};