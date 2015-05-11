#pragma once  

#ifdef CPP_EXPORTS  
#define CPP_API __declspec(dllexport)  
#else  
#define CPP_API __declspec(dllimport)  
#endif  

class CPP_API cpp_file
{
public:
	cpp_file(void);
	~cpp_file(void);

	int times2(int arg);
	void test(int *i);
	int* test2();
	
};