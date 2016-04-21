#include "f_allocator.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Function(vector<char, f_allocator<char>> &A)
{
	cout << "Start of the vector" << endl;
	unsigned int i = 0;
	for(i=0; i < A.size(); i++)
	{
		cout << "A[" << i << "] = " << A[i] << endl;
	}
}

int main()
{
	vector<char, f_allocator<char>> DVector(5);
	DVector[0] = 'a';
	DVector[1] = 'b';
	DVector[2] = 'c';
	DVector[3] = 'd';
	DVector[4] = 'e';
	cout << "SFKJGHSDUIJ4985934539G" << endl;
	Function(DVector);
	cout << "SFKJGHSDUIJG" << endl;

	vector<char, f_allocator<char>> NewVector(5);
	int j = 1;
	while(j < 10)
	{
		NewVector.resize(5*j);
		copy(DVector.begin(), DVector.end(), NewVector.begin() + (j-1)*5 );
		j++;
	}
	Function(NewVector);
	system("pause");
	return 0;
}