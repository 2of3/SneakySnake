#include "cpp_file.h"  

cpp_file::cpp_file(void)
{
}

cpp_file::~cpp_file(void)
{
}



//Foo Stuff
void cpp_file::testFooIn(Foo f)
{
	std::cout << "void testFooIn(Foo f)" << std::endl;
}

Foo cpp_file::testFooOut()
{
	std::cout << "Foo testFooIn()" << std::endl;
	Foo retval;
	return retval;
}

Foo cpp_file::testFooInOut(Foo f)
{

	std::cout << "Foo testFooInOut(Foo f)"; f.talk();  std::cout<< std::endl;
	Foo retval;
	return retval;
}


//array stuff
void cpp_file::testArrayIn(std::array<float, 3>)
{
	std::cout << "void testArrayIn(std::array<float, 3>)" << std::endl;
}

std::array<float, 3> cpp_file::testArrayOut()
{
	std::cout << "std::array<float, 3> testArrayOut()" << std::endl;
	std::array<float, 3> retval = { 1.1f, 2.2f, 3.3f };
	return retval;
}

std::array<float, 3> cpp_file::testArrayInOut(std::array<float, 3> myArray)
{
	std::cout << "std::array<float, 3> testArrayInOut(std::array<float, 3> myArray)" << std::endl;
	std::array<float, 3> retval = { 1.1f, 2.2f, 3.3f };
	return retval;
}



//mixed stuff
Foo cpp_file::ArrayInFooOut(std::array<float, 3> a)
{
	std::cout << "Foo ArrayInFooOut(std::array<float, 3> a)" << std::endl;
	Foo retval;
	return retval;
}

std::array<float, 3> cpp_file::FooInArrayOut(Foo f)
{
	std::cout << "std::array<float, 3> FooInArrayOut(Foo f)" << std::endl;
	std::array<float, 3> retval = { 1.1f, 2.2f, 3.3f };
	return retval;
}