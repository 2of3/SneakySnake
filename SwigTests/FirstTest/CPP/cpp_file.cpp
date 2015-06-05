#include "cpp_file.h"  

cpp_file::cpp_file(void)
{
}

cpp_file::~cpp_file(void)
{
}



//ok
void cpp_file::testFoo(Foo f)
{
	std::cout << "void testFoo(Foo f)" << std::endl;
}

void cpp_file::testArray(std::array<float, 3>)
{
	std::cout << "void testArray(std::array<float, 3>)" << std::endl;
}

//std::array<float, 3> cpp_file::testF(Foo f)
//{
//
//	std::array<float, 3> retval = { 1.1f, 2.2f, 3.3f };
//	return retval;
//}


/*void cpp_file::ray_cast(float start[3], float end[3], float location[3], float normal[3], int &index)
{
	// not implemented
}*/