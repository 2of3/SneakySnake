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
	if (is_rna_type(str, "USE_REPO")) return rna_none;
	if (is_rna_type(str, "ui_desc"))  return rna_uidesc;
	if (is_rna_type(str, "return"))   return rna_return;
	if (is_rna_type(str, "function")) return rna_function;

	// param stuff
	if (is_rna_type(str, "pointer"))  return rna_pointer;
	if (is_rna_type(str, "boolean"))  return rna_boolean;
	if (is_rna_type(str, "enum"))     return rna_enum;
	if (is_rna_type(str, "REQUIRED")) return rna_flag_req;
	
	return rna_unknown;
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

void parse_code(vector<string> strvec)
{
	vector<bpyfunc> funcs;

	// parse funcs
	for (string str : strvec)
	{
		rna_def_type def_type = get_def_type(str);

		switch (def_type)
		{
			case rna_none:
				continue;
				
			case rna_unknown:
				if (!funcs.back().error) cout << endl;
				cout << funcs.back().name << ": Unknown RNA function (";
				cout << get_def_func(str) << ")" << endl;

				funcs.back().error = true;

				break;

			case rna_function:
			{
				string namestr = get_params(str)[1];
			
				bpyfunc newfunc;
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

	for (bpyfunc func : funcs)
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

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream infile("test.c", std::ios_base::in);
	string str((std::istreambuf_iterator<char>(infile)),
		std::istreambuf_iterator<char>());

	/* test */
	regex reg1(R"(/\*.*\*/)");			// comments
	regex reg2(R"(^[\t ]+|[\t ]+$)");	// whitespaces
	regex reg3(R"(RNA_def_)");			// RNA_def_
	regex reg4(R"(\);)");				// );

	str = regex_replace(str, reg1, "");
	str = regex_replace(str, reg2, "");
	
	vector<string> strvec = split(str, regex("\n"));
	vector<string> defstr;

	string tmpline;
	for (string line : strvec)
	{
		if (regex_search(tmpline + line, reg3))
		{
			tmpline += line;

			if (regex_search(tmpline, reg4))
			{
				defstr.push_back(tmpline);
				tmpline.clear();
			}
		}
	}

	parse_code(defstr);

	int tmp;
	std::cin >> tmp;

	return 0;
}

