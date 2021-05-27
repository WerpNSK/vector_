#pragma once
#include <iostream>
using namespace std;
class vector_
{
private:
	int* arr;
	int size;
public:
	vector_();	
	vector_(int cnt, int val);
	~vector_();
	vector_(const vector_& g);
	
	void push_back(int val);
	void pop_back();
	void clear();
	void erase(int pos);
	void insert(int pos, int val);

	inline bool empty()const { return this->size == 0; }
	inline int getSize()const {	return this->size;}

	void print()const;

	int& operator[](int pos) const{
		return this->arr[pos];
	}
	void resize(int newSize);

	vector_& operator=(const vector_& v) {
		if (this == &v)
			return *this;
		this->~vector_();
		if (v.arr == nullptr)
			return *this;

		this->size = v.size;
		this->arr = new int[this->size];
		for (size_t i = 0; i < this->size; i++)
		{
			this->arr[i] = v.arr[i];
		}
		return *this;
	}

};

ostream& operator<<(ostream& os, const vector_& v);
istream& operator>>(istream& is, vector_& v);


