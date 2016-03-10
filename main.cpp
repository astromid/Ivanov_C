#include <iostream>
#include "singly_linked_list.cpp"

int main()
{
	List<int> NewList1;
	NewList1.append(20);
	NewList1.append(30);
	NewList1.append(40);
	//cout << NewList1[0] << " " << NewList1[1] << " " << NewList1[2] << endl;
	NewList1.insert(10, 0);
	cout << NewList1[0] << " " << NewList1[1] << " " << NewList1[2] << " " << NewList1[3] << endl;
	//NewList1.remove(1);
	//cout << NewList1[0] << " " << NewList1[1] << " " << NewList1[2] << endl;

	List<int> ::bid_list_iterator bIterator1;
	List<int> ::bid_list_iterator bIterator2;

	bIterator1 = NewList1.get_head();
	bIterator2 = NewList1.get_head();
	bIterator2 = NewList1.get_end();
	reverse(bIterator1, bIterator2);
	cout << NewList1[0] << " " << NewList1[1] << " " << NewList1[2] << " " << NewList1[3] << endl;
	//cout << NewList1[0] << " " << NewList1[1] << " " << NewList1[2] << endl;
	system("pause");
	return 0;
}