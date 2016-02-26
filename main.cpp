#include <iostream>
#include "singly_linked_list.cpp"
int main()
{
	List<int> NewList1;
	NewList1.append(10);
	NewList1.append(20);
	NewList1.append(30);
	std::cout << NewList1[0] << " " << NewList1[1] << " " << NewList1[2];
	system("pause");
	return 0;
}