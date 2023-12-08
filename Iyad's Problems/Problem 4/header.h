#ifndef problem2_h
#define problem2_h

#include <iostream>
#include <vector>
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


#endif
