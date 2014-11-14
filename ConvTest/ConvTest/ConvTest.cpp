// ConvTest.cpp

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

string get_def_func(string str)
{
	regex reg(R"(\((.*)$)");
	return regex_replace(str, reg, "");
}

rna_def_type get_def_type(string str)
{
	// function stuff (watch order)
	if (is_rna_type(str, "USE_REPO")) return rna_def_none;
	if (is_rna_type(str, "ui_desc"))  return rna_uidesc;
	if (is_rna_type(str, "return"))   return rna_return;
	if (is_rna_type(str, "function")) return rna_function;

	// param stuff
	if (is_rna_type(str, "pointer"))  return rna_pointer;
	if (is_rna_type(str, "boolean"))  return rna_boolean;
	if (is_rna_type(str, "enum"))     return rna_enum;
	if (is_rna_type(str, "REQUIRED")) return rna_flag_req;
	
	return rna_def_unknown;
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
		rna_def_type def_type = get_def_type(str);

		switch (def_type)
		{
			case rna_def_none:
				continue;
				
			case rna_def_unknown:
				if (funcs.size() > 0)
				{
					if (!funcs.back().error) cout << endl;
					cout << funcs.back().name << ": Unknown RNA function (";
					cout << get_def_func(str) << ")" << endl;

					funcs.back().error = true;
				}
				else
				{
					cout << "Unknown RNA function (";
					cout << get_def_func(str) << ")" << endl;
				}

				break;

			case rna_function:
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

			case rna_uidesc:
			{
				string descstr = get_params(str)[1];
				funcs.back().desc = trim_param_str(descstr);
				break;
			}

			case rna_pointer:
			{
				vector<string> pmstr = get_params(str);
				funcs.back().params.push_back(
					extract_param(pmstr[1], pmstr[2], pmstr[4]));
				funcs.back().params.back().required = false;

				break;
			}

			case rna_boolean:
			{
				vector<string> pmstr = get_params(str);
				funcs.back().params.push_back(
					extract_param(pmstr[1], "bool", pmstr[4], pmstr[2]));
				funcs.back().params.back().required = false;

				break;
			}

			case rna_enum:
			{
				vector<string> pmstr = get_params(str);
				funcs.back().params.push_back(
					extract_param(pmstr[1], pmstr[2], pmstr[5], pmstr[3]));
				funcs.back().params.back().required = false;

				break;
			}

			case rna_flag_req:
			{
				funcs.back().params.back().required = true;
				break;
			}

			case rna_return:
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
			// value missing
			new_enum.params.push_back(new_param);
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

	// dummy input
	int tmp;
	std::cin >> tmp;

	return 0;
}

