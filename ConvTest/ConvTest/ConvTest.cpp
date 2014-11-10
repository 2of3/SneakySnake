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

void parse_code(vector<string> strvec) {
	string fctname;

	for each (string str in strvec)
	{
		const char* cstr = str.c_str();

		const char *tmp = strstr(cstr, "func = RNA_def_function");
		if (tmp != NULL)
			cout << "Funktionsdefinition: " << tmp << endl;
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

