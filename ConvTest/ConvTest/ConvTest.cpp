// ConvTest.cpp

#include "ConvTest.h"

vector<string> &split(const string &s, char delim, vector<string> &elems)
{
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
		elems.push_back(item);

	return elems;
}

vector<string> split(const string &s, char delim)
{
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}

vector<string> get_params(string str)
{
	size_t startval = str.find_first_of("(") + 1;
	size_t endval = str.find(");") - startval;
	string paramstr = str.substr(startval, endval);

	vector<string> strvec = split(paramstr, ',');
	vector<string> newstrvec;

	for (string astr : strvec)
		newstrvec.push_back(astr.erase(0, 1));

	return newstrvec;
}

string get_str_content(string str)
{
	size_t startval = str.find_first_of("\"") + 1;
	size_t endval = str.find_last_of("\"") - startval;
	return str.substr(startval, endval);
}

rna_def_type get_def_type(string str)
{
	if (!is_rna_type(str, "RNA_def"))   return rna_none;
	if ( is_rna_type(str, "function(")) return rna_function;
	if ( is_rna_type(str, "USE_REPOR")) return rna_none;
	if ( is_rna_type(str, "ui_desc"))   return rna_uidesc;
	if ( is_rna_type(str, "pointer"))   return rna_pointer;
	if ( is_rna_type(str, "boolean"))   return rna_boolean;
	if ( is_rna_type(str, "enum"))      return rna_enum;
	if ( is_rna_type(str, "REQUIRED"))  return rna_flag_req;
	if ( is_rna_type(str, "return"))    return rna_return;

	return rna_unknown;
}

fctparam extract_param(string name, string type, string desc, string def="")
{
	fctparam tmpparam;
	tmpparam.name = get_str_content(name);
	tmpparam.type = get_str_content(type);
	tmpparam.desc = get_str_content(desc);
	tmpparam.defval = get_str_content(def);
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
				cout << "Unknown RNA def function: " << str << endl;
				break;

			case rna_function:
			{
				string namestr = get_params(str)[1];
			
				bpyfunc newfunc;
				newfunc.name = get_str_content(namestr);

				fctparam voidparam;
				voidparam.type = "void";
				newfunc.rettype = voidparam;

				funcs.push_back(newfunc);

				break;
			}

			case rna_uidesc:
			{
				string descstr = get_params(str)[1];
				funcs.back().desc = get_str_content(descstr);
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
					extract_param(pmstr[1], pmstr[2], pmstr[5]));
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
	for (bpyfunc func : funcs)
	{
		cout << "// " << func.desc << endl;

		for (fctparam param : func.params)
		{
			cout << "//    " << param.name;
			cout << ": " << param.desc;
			
			if (param.required)
				cout << " (required)";

			cout << endl;
		}

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
		cout << "{" << endl;
		cout << "    // dummy" << endl;
		cout << "}" << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> splitted;

	splitted = split(demofunc, '\n');
	parse_code(splitted);

	int tmp;
	cin >> tmp;

	return 0;
}

