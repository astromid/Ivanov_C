#include "f_allocator.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

extern char const filename[] = "test_memory.txt";

int main()
{
	cout << "ASSUMING DIRECT CONTROL OF ALLOCATOR MAGIC" << endl;
	vector<int, f_allocator<int, filename>> NewVector(10);
	NewVector[0] = 0;
	NewVector[1] = 3;
	
	system("pause");
	return 0;
}