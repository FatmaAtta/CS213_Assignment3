// File name: main.cpp
// Purpose: Template - Set
// Author(s): Iyad Mahdy Mahrous
// ID(s): 20220075
// Section: S9
// Date: December 6 2023
// Version: 1
#include "header.h"
#include "functions.cpp"

int main(){
	int arr[] = {5, 1, 2, 6, 1};
	MySet<int> m(arr);

	/*m.add_item(5);
	m.add_item(1);
	m.add_item(2);
	m.add_item(6);
	m.add_item(1);*/

	cout << "6 is " << (m.check_item(6) ? "" : "NOT") << " in the set." << endl;
	cout << "3 is " << (m.check_item(3) ? "" : "NOT") << " in the set." << endl;
	m.remove_item(6);
	cout << "6 is " << (m.check_item(6) ? "" : "NOT") << " in the set." << endl;
	cout << "Size of set: " << m.get_size() << endl;
	m.print_set();

	int* ptr = m.create_array();

	cout << "Array Elements: ";
	int i = 0;
	while (ptr[i])
		cout << ptr[i++] << " ";
	cout << endl;

	delete[] ptr;
}

