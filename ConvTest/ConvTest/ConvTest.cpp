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

bool check_param_types(string str)
{
	return
		str.find("pointer") != string::npos ||
		str.find("boolean") != string::npos ||
		str.find("enum")    != string::npos;
}

void parse_code(vector<string> strvec)
{
	string fctname;
	string fctcomment;
	fctparam fctreturn;
	vector <fctparam> fctparams;

	for (string str : strvec)
	{
		// function name
		if (str.find("RNA_def_function(") != string::npos)
		{
			string namestr = get_params(str)[1];
			fctname = get_str_content(namestr);
		}

		// function comment
		if (str.find("function_ui_desc") != string::npos)
		{
			string descstr = get_params(str)[1];
			fctcomment = get_str_content(descstr);
		}

		// function params
		if (check_param_types(str))
		{
			fctparam tmpparam;
			vector<string> paramstr = get_params(str);

			if (str.find("pointer") != string::npos)
			{
				tmpparam.type = paramstr[2];
				tmpparam.desc = paramstr[4];
			}

			if (str.find("boolean") != string::npos)
			{
				tmpparam.type = "bool";
				tmpparam.desc = paramstr[4];
				tmpparam.defval = paramstr[2];
			}

			if (str.find("enum") != string::npos)
			{
				tmpparam.type = paramstr[2];
				tmpparam.desc = paramstr[5];
			}

			tmpparam.name = get_str_content(paramstr[1]);
			tmpparam.type = get_str_content(tmpparam.type);
			tmpparam.desc = get_str_content(tmpparam.desc);

			fctparams.push_back(tmpparam);
		}

		// function param flag
		if (str.find("RNA_def_property") != string::npos)
		{
			if (str.find("PROP_REQUIRED") != string::npos)
				fctparams.back().required = true;
		}

		// return value
		if (str.find("def_function_return") != string::npos)
		{
			fctreturn = fctparams.back();
			fctparams.pop_back();

			// print complete function
			cout << "// " << fctcomment << endl;

			for (fctparam param : fctparams)
			{
				cout << "//    " << param.name;
				cout << ": " << param.desc;

				if (!param.required)
					cout << " (required)";

				cout << endl;
			}

			cout << fctreturn.type << " ";
			cout << fctname << "(";

			for (fctparam param : fctparams)
			{
				cout << param.type << " " << param.name;
				
				if (!param.required)
					cout << "=" << param.defval;

				if (param.name != fctparams.back().name)
					cout << ", ";
			}

			cout << ")" << endl;
			cout << "{" << endl;
			cout << "    // dummy" << endl;
			cout << "}" << endl;
		}
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

