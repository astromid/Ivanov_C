#include <iostream>
#include "bid_iterator.h"



int main()
{
	sl_list<int> NewList;
	NewList.insert(1, 0);
	NewList.insert(2, 1);
	NewList.insert(3, 2);
	NewList.insert(4, 3);
	cout << "List test #1:" << endl;
	cout << NewList[0] << " " << NewList[1] << " " << NewList[2] << " " << NewList[3] << endl;

	f_iterator<int> fIt1;
	f_iterator<int> fIt2;
	fIt1 = NewList.get_head();
	cout << "Forward iterator test #1: " << *fIt1 << endl;
	fIt1++;
	cout << "Forward iterator test #2: " << *fIt1 << endl;

	
	fIt1 = NewList.get_head();
	fIt2 = NewList.get_end();
	cout << "Forward iterator test #3 (distance): " << distance(fIt1, fIt2) << endl;
	advance(fIt1, 2);
	cout << "Forward iterator test #4 (advance): " << *fIt1 << endl;
	

	bid_iterator<int> bIt1;
	bid_iterator<int> bIt2;

	bIt1 = NewList.get_head();
	bIt2 = NewList.get_end();
	reverse(bIt1, bIt2);
	cout << "Bidirectional iterator test #1 (reverse): " << endl;
	cout << NewList[0] << " " << NewList[1] << " " << NewList[2] << " " << NewList[3] << endl;
	system("pause");
	return 0;
}