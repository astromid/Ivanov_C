#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
	fstream films_list;
	fstream user_marks;
	films_list.open("films.txt", fstream::in);
	user_marks.open("rating.txt", fstream::in);

	return 0;
}