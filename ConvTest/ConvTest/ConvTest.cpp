// ConvTest.cpp

#include "ConvTest.h"

vector<string> &split(const string &s, char delim, vector<string> &elems) {
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
		elems.push_back(item);

	return elems;
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}

vector<string> get_params(string str)
{
	size_t startval = str.find_first_of("(") + 1;
	size_t endval = str.find(");") - startval;
	string paramstr = str.substr(startval, endval);
	return split(paramstr, ',');
}

string get_str_content(string str)
{
	size_t startval = str.find_first_of("\"") + 1;
	size_t endval = str.find_last_of("\"") - startval;
	return str.substr(startval, endval);
}

void parse_code(vector<string> strvec) {
	string fctname;
	string fctcomment;

	for each (string str in strvec)
	{
		// function name
		size_t isfunc = str.find("func = RNA_def_function");

		if (isfunc != string::npos) {
			string paramstr = get_params(str)[1];
			fctname = get_str_content(paramstr);
			cout << "Funktionsdefinition: " << fctname << endl;
		}

		// function comment
		size_t iscomment = str.find("function_ui_description");

		if (iscomment != string::npos)
		{
			string paramstr = get_params(str)[1];
			fctcomment = get_str_content(paramstr);
			cout << "Beschreibung: " << fctcomment << endl;
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

