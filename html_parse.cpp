#include <regex>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string FindTitle(vector<string> html_text)
{

}

vector<string> FindHeaders(vector<string> html_text)
{

}

int main()
{
	fstream html_file;
	html_file.open("html_file.html", fstream::in);
	regex title_pat("<([a-z])*>(\s)*([a-z])*(\s)*<\/([a-z])*>");
	return 0;
}
