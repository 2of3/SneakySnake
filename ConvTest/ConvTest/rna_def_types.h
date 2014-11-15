#pragma once

#include "ConvTest.h"

#include <string>
#include <map>
#include <regex>

extern struct bpy_func;

typedef bool(*rna_def_ptr)(std::vector<bpy_func> &, std::string);

extern std::map <std::string, rna_def_ptr> rna_def_map;

void setup_enum_mapping();
std::string get_rna_def_type(std::string str);
rna_def_ptr get_rna_def_ptr(std::string str);