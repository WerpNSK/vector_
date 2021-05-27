#include "vector_.h"

vector_::vector_()
{
	this->arr = nullptr;
	this->size = 0;
}

vector_::vector_(int cnt, int val)
{
	this->arr = new int[cnt];
	for (size_t i = 0; i < cnt; i++)
	{
		this->arr[i] = val;
	}
	this->size = cnt;
}

vector_::~vector_()
{
	if(this->arr!=nullptr)
		delete[]arr;
	this->arr = nullptr;
	this->size = 0;
}

vector_::vector_(const vector_& g):vector_()
{
	if (g.arr == nullptr)
		return;
	this->size = g.size;
	this->arr = new int[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		this->arr[i] = g.arr[i];
	}
}


void vector_::push_back(int val)
{
	if (this->size == 0) {
		this->arr = new int[1];
		this->arr[0] = val;
		this->size = 1;
		return;
	}
	int* tmp = new int[this->size + 1];
	for (size_t i = 0; i < this->size; i++)
	{
		tmp[i] = this->arr[i];
	}
	tmp[this->size] = val;
	delete[]this->arr;
	this->arr = tmp;
	this->size++;
}

void vector_::pop_back()
{
	if (this->size == 0)
		return;
	if (this->size == 1) {
		this->clear();
		return;
	}
	int* tmp = new int[this->size - 1];
	for (size_t i = 0; i < this->size - 1; i++)
	{
		tmp[i] = this->arr[i];
	}
	delete[]this->arr;
	this->arr = tmp;
	this->size--;
}

void vector_::clear()
{
	this->~vector_();
}

void vector_::erase(int pos)
{
	if (pos >= 0 && pos < this->size) {
		if (this->size == 1) {
			this->~vector_();
			return;
		}
		int* tmp = new int[this->size - 1];
		for (int i = 0; i < this->size - 1; i++)
		{
			if(i<pos)
				tmp[i] = this->arr[i];
			else
				tmp[i] = this->arr[i + 1];
		}
		delete[]this->arr;
		this->arr = tmp;
		this->size--;
	}
}

void vector_::insert(int pos, int val)
{
	if (pos<0 || pos>this->size)
		return;
	if (pos == this->size) {
		this->push_back(val);
		return;
	}
	int* tmp = new int[this->size + 1];
	for (size_t i = 0; i < this->size+1; i++)
	{
		if (i < pos)
			tmp[i] = this->arr[i];
		else if (i == pos)
			tmp[i] = val;
		else
			tmp[i] = this->arr[i-1];
	}
	delete[]this->arr;
	this->arr = tmp;
	this->size++;
}

void vector_::print() const
{
	for (size_t i = 0; i < this->size; i++)
	{
		cout << this->arr[i] << " ";
	}
	cout << endl;
}


ostream& operator<<(ostream& os, const vector_& v) {
	for (size_t i = 0; i < v.getSize(); i++)
	{
		cout << v[i] << " ";
	}
	return os;
}

istream& operator>>(istream& is, vector_& v)
{
	v.clear();
	cout << "Enter count of elements\n";
	int cnt;
	cin >> cnt;
	for (size_t i = 0; i < cnt; i++)
	{
		int val;
		cin >> val;
		v.push_back(val);
	}
	return is;
}
