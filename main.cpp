#include <iostream>
#include "sl_list.h"
#include "f_allocator.h"
#include <fstream>
#include <vector>

int main()
{
	sl_list<int> NewList;
	NewList.insert(1, 0);
	NewList.insert(2, 1);
	NewList.insert(3, 2);
	NewList.insert(4, 3);
	cout << "List test #1 (insert):" << endl;
	cout << NewList[0] << " " << NewList[1] << " " << NewList[2] << " " << NewList[3] << endl;

	f_iterator<int> fIt1 = NewList.begin();
	f_iterator<int> fIt2 = NewList.end();
	cout << "Forward iterator test #1: " << *fIt1 << endl;
	fIt1++;
	cout << "Forward iterator test #2: " << *fIt1 << endl;

	fIt1 = NewList.begin();
	cout << "Forward iterator test #3 (distance): " << distance(fIt1, fIt2) << endl;
	advance(fIt1, 2);
	cout << "Forward iterator test #4 (advance): " << *fIt1 << endl;
	
	bid_iterator<int> bIt1 = NewList.bbegin();
	bid_iterator<int> bIt2 = NewList.bend();

	reverse(bIt1, bIt2);
	cout << "Bidirectional iterator test #1 (reverse): " << endl;
	cout << NewList[0] << " " << NewList[1] << " " << NewList[2] << " " << NewList[3] << endl;

	/*cout << "ASSUMING DIRECT CONTROL OF ALLOCATOR MAGIC" << endl;
	fstream m_file("test_memory.txt", fstream::app);
	vector<int, f_allocator<int>> NewVector(10);
	NewVector[0] = 0;
	NewVector[1] = 3;
	*/
	system("pause");
	return 0;
}