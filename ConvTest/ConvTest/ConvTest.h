// ConvTest.cc

#include <tchar.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::regex;

#define is_rna_type(a, b) (regex_search(a, regex(b))) 

enum rna_def_type
{
	rna_none,
	rna_unknown,
	rna_function,
	rna_uidesc,
	rna_pointer,
	rna_boolean,
	rna_enum,
	rna_flag_req,
	rna_return
};

struct fctparam
{
	string name;
	string type;
	string desc;
	bool required;
	string defval;
};

struct bpyfunc
{
	string name;
	string desc;
	fctparam rettype;
	vector <fctparam> params;
};