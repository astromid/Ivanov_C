#include <regex>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> FindPlainText(string& html_text)
{
	regex plain_pat(">[^<]+<");
	smatch mat;
	vector<string> plain_text;
	while (regex_search(html_text, mat, plain_pat))
	{
		string str = mat.str();
		str.erase(str.begin());
		str.erase(str.end() - 1);
		plain_text.push_back(str);
		html_text = mat.suffix().str();
	}
	return plain_text;
}

string FindTitle(string& html_text)
{
	regex title_pat("<title>[^<]+<\/title>");
	smatch mat;
	regex_search(html_text, mat, title_pat);
	string title = mat.str();
	html_text = regex_replace(html_text, title_pat, "", regex_constants::format_first_only);
	title = FindPlainText(title)[0];
	return title;
}

vector<string> FindHeader(string& html_text)
{
	string text = html_text;
	regex header_pat("<h(\\d)+>[^<]+<\/h(\\d)+>");
	smatch mat;
	vector<string> headers;
	while (regex_search(text, mat, header_pat))
	{
		string str = mat.str();
		str = FindPlainText(str)[0];
		headers.push_back(str);
		text = mat.suffix().str();
	}
	html_text = regex_replace(html_text, header_pat, "");
	return headers;
}

int main()
{
	fstream html_file;
	string html_text;
	html_file.open("tim.html", fstream::in);
	while (html_file.good())
	{
		string str;
		getline(html_file, str);
		html_text += str;
		html_text += ' ';
	}
	html_file.close();
	string title = FindTitle(html_text);
	vector<string> headers = FindHeader(html_text);
	vector<string> plain = FindPlainText(html_text);
	cout << title << endl;
	cout << endl;
	cout << endl;
	for (auto str : headers)
	{
		cout << str << endl;
		cout << endl;
		cout << endl;
	}
	for (auto str : plain)
	{
		cout << str << endl;
	}
	system("pause");
	return 0;
}
