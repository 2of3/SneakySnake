#include "ConvTest.h"

vector<string> split(const string &s, const regex &r)
{
	return{
		std::sregex_token_iterator(s.begin(), s.end(), r, -1),
		std::sregex_token_iterator()
	};
}

vector<string> get_params(string str)
{
	// get content of brackets
	regex reg1(R"(^(.*?)\(|\);$)");
	str = regex_replace(str, reg1, "");

	// split at commas outside of quotes
	regex reg2(R"(,(?=([^\"]*\"[^\"]*\")*[^\"]*$))");
	return split(str, reg2);
}

string trim_param_str(string str)
{
	// remove unnecessary whitespace and quotes
	str = regex_replace(str, regex("\""), "$1");
	return regex_replace(str, regex("^\\s+|\\s+$"), "");
}

fctparam extract_param(string name, string type, string desc, string def = "")
{
	fctparam tmpparam;
	tmpparam.name = trim_param_str(name);
	tmpparam.type = trim_param_str(type);
	tmpparam.desc = trim_param_str(desc);
	tmpparam.defval = trim_param_str(def);
	return tmpparam;
}

void parse_function_code(vector<string> strvec)
{
	vector<bpy_func> funcs;

	// parse funcs
	for (string str : strvec)
	{
		rna_def_type def_type = get_rnadef_enum(str);

		switch (def_type)
		{
			case rna_def_none:
				continue;
				
			case rna_def_unknown:
				if (funcs.size() > 0)
				{
					if (!funcs.back().error) 
						cout << "// " << funcs.back().name << endl;
					cout << "//\tUnknown RNA function (";
					cout << extract_rnadef_type(str) << ")" << endl;

					funcs.back().error = true;
				}
				else
				{
					cout << "// Unknown RNA function (";
					cout << extract_rnadef_type(str) << ")" << endl;
				}

				break;

			case rna_def_function:
			{
				string namestr = get_params(str)[1];
			
				bpy_func newfunc;
				newfunc.name = trim_param_str(namestr);
				newfunc.error = false;

				fctparam voidparam;
				voidparam.type = "void";
				newfunc.rettype = voidparam;

				funcs.push_back(newfunc);

				break;
			}

			case rna_def_function_ui_description:
			{
				string descstr = get_params(str)[1];
				funcs.back().desc = trim_param_str(descstr);
				break;
			}

			case rna_def_pointer:
			{
				vector<string> pmstr = get_params(str);
				funcs.back().params.push_back(
					extract_param(pmstr[1], pmstr[2], pmstr[4]));
				funcs.back().params.back().required = false;

				break;
			}

			case rna_def_boolean:
			{
				vector<string> pmstr = get_params(str);
				funcs.back().params.push_back(
					extract_param(pmstr[1], "bool", pmstr[4], pmstr[2]));
				funcs.back().params.back().required = false;

				break;
			}

			case rna_def_enum:
			{
				vector<string> pmstr = get_params(str);
				funcs.back().params.push_back(
					extract_param(pmstr[1], pmstr[2], pmstr[5], pmstr[3]));
				funcs.back().params.back().required = false;

				break;
			}

			case rna_def_property_flag:
			{
				if (regex_search(str, regex("PROP_REQUIRED")))
					funcs.back().params.back().required = true;
				break;
			}

			case rna_def_function_return:
			{
				funcs.back().rettype = funcs.back().params.back();
				funcs.back().params.pop_back();

				break;
			}
		}
	}

	// print funcs
	cout << endl << endl;

	for (bpy_func func : funcs)
	{
		// documentation
		cout << "/**" << endl << " * " << func.desc << endl;

		for (fctparam param : func.params) {
			cout << " * @param " << param.name << " ";
			cout << param.desc << endl;
		}

		if (func.rettype.type != "void")
			cout << " * @return " << func.rettype.desc << endl;

		cout << " */" << endl;

		// header
		cout << func.rettype.type << " ";
		cout << func.name << "(";

		for (fctparam param : func.params)
		{
			cout << param.type << " " << param.name;

			if (!param.required)
				cout << "=" << param.defval;

			if (param.name != func.params.back().name)
				cout << ", ";
		}

		cout << ")" << endl;

		// body
		cout << "{" << endl;
		cout << "    // dummy" << endl;
		cout << "}" << endl << endl;
	}
}

string get_enum_name(string str)
{
	regex reg(R"(^.+?Item\s(.+?)\[\].+$)");
	return regex_replace(str, reg, "$1");
}

vector<string> get_enum_items(string str)
{
	// get content of outer braces and split
	regex reg1(R"(^.*?\{|\};)");
	str = regex_replace(str, reg1, "");
	return split(str, regex(",(?=\\{)"));
}

string trim_enum_param(string &str)
{
	regex reg("^\\{|\\}$");
	return regex_replace(str, reg, "");
}

void parse_enum_code(vector<string> strvec)
{
	vector<bpy_enum> enums;

	for (string str : strvec)
	{
		vector<string> strparams = get_enum_items(str);

		bpy_enum new_enum;
		new_enum.name = trim_param_str(get_enum_name(str));

		for (string strparam : strparams)
		{
			strparam = trim_enum_param(strparam);
			vector<string> subparams = get_params(strparam);

			bpy_enum_param new_param;
			new_param.name = trim_param_str(subparams[1]);
			new_param.desc = trim_param_str(subparams[4]);
			new_param.value = trim_param_str(subparams[0]);
			new_enum.params.push_back(new_param);

			// in case of unsolved reference
			if (!regex_search(new_param.value, regex("^[0-9.-<>\\s()]+$")))
				unsolved_refs.push_back(new_param.value);
		}

		new_enum.params.pop_back();
		enums.push_back(new_enum);
	}

	// print enums
	for (bpy_enum tmp_enum : enums)
	{
		cout << "enum " << tmp_enum.name << endl;
		cout << "{" << endl;

		string last_name = tmp_enum.params.back().name;
		for (bpy_enum_param tmp_param : tmp_enum.params)
		{
			cout << "\t" << tmp_param.name;
			cout << "=" << tmp_param.value;
			if (tmp_param.name != last_name) cout << ",";
			cout << " /**< " << tmp_param.desc << " */" << endl;
		}

		cout << "};" << endl << endl;
	}

	cout << endl;
}

vector<string> filter_commands(vector<string> strvec, regex filter)
{
	string tmpline;
	vector<string> result;

	regex reg_end(R"(\);|\};)");

	for (string line : strvec)
	{
		if (regex_search(tmpline + line, filter))
		{
			tmpline += line;

			if (regex_search(tmpline, reg_end))
			{
				result.push_back(tmpline);
				tmpline.clear();
			}
		}
	}

	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// map enum
	setup_enum_mapping();
	
	// load main file
	std::ifstream infile("test.c", std::ios_base::in);
	string str((std::istreambuf_iterator<char>(infile)),
		std::istreambuf_iterator<char>());

	/* filter file and split up */
	regex reg1(R"(/\*.*\*/)");			// comments
	regex reg2(R"(^[\t ]+|[\t ]+$)");	// whitespaces

	str = regex_replace(str, reg1, "");
	str = regex_replace(str, reg2, "");
	
	vector<string> strvec = split(str, regex("\n"));

	// parse enums
	regex reg_enu(R"(EnumProperty)");
	vector<string> enumdef = filter_commands(strvec, reg_enu);
	parse_enum_code(enumdef);

	// parse functions
	regex reg_def(R"(RNA_def_)");
	vector<string> fctdef = filter_commands(strvec, reg_def);
	parse_function_code(fctdef);

	// resolve unsolved references
	vector<string> ref_file_str;
	ref_file_str.push_back("DNA_modifier_types.h");
	ref_file_str.push_back("BKE_depsgraph.h");

	for (string file_str : ref_file_str) {
		std::ifstream ref_file(file_str, std::ios_base::in);
		string ref_str((std::istreambuf_iterator<char>(ref_file)),
			std::istreambuf_iterator<char>());

		cout << endl << "// " << file_str << endl;

		vector<string> copy_ref = vector<string>(unsolved_refs);
		for (string ref : copy_ref) {
			std::smatch reg_match;
			regex reg(ref + R"([\s\t]+=(.*)\s*,)");

			if (regex_search(ref_str, reg_match, reg)) {
				string valmatch = regex_replace(reg_match.str(), reg, "$1");
				valmatch = trim_param_str(valmatch);

				std::cout << "#define " << ref << " " << valmatch << endl;

				auto it = std::find(unsolved_refs.begin(), unsolved_refs.end(), ref);
				if (it != unsolved_refs.end())
					unsolved_refs.erase(it);
			}
		}
	}

	if (unsolved_refs.size() > 0)
	{
		cout << endl << "// UNSOLVED REFERENCES: " << endl;

		for (string ref : unsolved_refs)
			cout << "// \t" << ref << endl;
	}

	// dummy input
	int tmp;
	std::cin >> tmp;

	return 0;
}

