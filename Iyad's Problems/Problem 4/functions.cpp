#include "header.h"
#include <algorithm>

template <typename T>
MySet<T>::MySet(){}

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































