#pragma once

#include "rna_def_types.h"

#include <tchar.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::regex;

#define is_rna_type(a, b) (regex_search(a, regex(b))) 

struct bpy_enum_param
{
	string name;
	string desc;
	string value;
};

struct bpy_enum
{
	string name;
	vector<bpy_enum_param> params;
};

struct fctparam
{
	string name;
	string type;
	string desc;
	bool required;
	string defval;
};

struct bpy_func
{
	string name;
	string desc;
	fctparam rettype;
	vector <fctparam> params;
	bool error;
};

extern vector<string> unsolved_refs;

vector<string> get_params(string str);
string trim_param_str(string str);
fctparam extract_param(string name, string type, string desc, string def = "");