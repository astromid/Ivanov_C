#include <iostream>
#include "singly_linked_list.cpp"

using namespace std;

int main()
{
	List<int> NewList1;
	NewList1.append(10);
	NewList1.append(20);
	NewList1.append(30);
	cout << NewList1[0] << " " << NewList1[1] << " " << NewList1[2] << endl;
	NewList1.insert(5, 0);
	cout << NewList1[0] << " " << NewList1[1] << " " << NewList1[2] << " " << NewList1[3] << endl;
	NewList1.remove(1);
	cout << NewList1[0] << " " << NewList1[1] << " " << NewList1[2] << endl;
	system("pause");
	return 0;
}