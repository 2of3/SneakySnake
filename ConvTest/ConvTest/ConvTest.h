// ConvTest.cc

#include <tchar.h>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define is_rna_type(a, b)  (a.find(b) != string::npos) 

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

const string demofunc = "func = RNA_def_function(srna, \"to_mesh\", \"rna_Object_to_mesh\");\n"
	"RNA_def_function_ui_description(func, \"Create a Mesh datablock with modifiers applied\");\n"
	"RNA_def_function_flag(func, FUNC_USE_REPORTS);\n"
	"parm = RNA_def_pointer(func, \"scene\", \"Scene\", \"\", \"Scene within which to evaluate modifiers\");\n"
	"RNA_def_property_flag(parm, PROP_REQUIRED | PROP_NEVER_NULL);\n"
	"parm = RNA_def_boolean(func, \"apply_modifiers\", 0, \"\", \"Apply modifiers\");\n"
	"RNA_def_property_flag(parm, PROP_REQUIRED);\n"
	"parm = RNA_def_enum(func, \"settings\", mesh_type_items, 0, \"\", \"Modifier settings to apply\");\n"
	"RNA_def_property_flag(parm, PROP_REQUIRED);\n"
	"RNA_def_boolean(func, \"calc_tessface\", true, \"Calculate Tessellation\", \"Calculate tessellation faces\");\n"
	"RNA_def_boolean(func, \"calc_undeformed\", false, \"Calculate Undeformed\", \"Calculate undeformed vertex coordinates\");\n"
	"parm = RNA_def_pointer(func, \"mesh\", \"Mesh\", \"\", \"Mesh created from object, remove it if it is only used for export\");\n"
	"RNA_def_function_return(func, parm);";