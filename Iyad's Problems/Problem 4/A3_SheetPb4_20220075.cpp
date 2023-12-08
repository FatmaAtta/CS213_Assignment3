// File name: main.cpp
// Purpose: Template - Set
// Author(s): Iyad Mahdy Mahrous
// ID(s): 20220075
// Section: S9
// Date: December 6 2023
// Version: 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class MySet{
	private:
		vector<T> values;
	public:
		MySet() = default;
		MySet(T arr[]);
		void add_item(T item);
		void remove_item(T item);
		size_t get_size();
		bool check_item(T item);
		T* create_array();
		void print_set();
};

template <typename T>
MySet<T>::MySet(T arr[]){
	int i = 0;

	while (arr[i]){
		if (find(values.begin(), values.end(), arr[i]) == values.end())
			values.push_back(arr[i]);
		i++;
	}
	sort(values.begin(), values.end());
}

template <typename T>
void MySet<T>::add_item(T item){
	if (find(values.begin(), values.end(), item) == values.end())
		this->values.push_back(item);
	sort(values.begin(), values.end());
	return;
}

template <typename T>
void MySet<T>::remove_item(T item){
	auto it =  find(values.begin(), values.end(), item);
	if (it != values.end())
		values.erase(it);
}

template <typename T>
size_t MySet<T>::get_size(){
	return (values.size());
}

template <typename T>
bool MySet<T>::check_item(T item){
	return (find(values.begin(), values.end(), item) == values.end() ? false : true);
}

template <typename T>
void MySet<T>::print_set(){
	for (auto i : values){
		cout << i << endl;
	}
}

template <typename T>
T* MySet<T>::create_array(){
	T* arr = new T[values.size()];

	int idx = 0;
	for (auto i : values)
		arr[idx++] = i;

	return arr;
}

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































