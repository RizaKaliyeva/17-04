#include <iostream>
#include <iomanip>
using namespace std;
class Vector {
private:
	int cur_size;
	int buf_size;
	int *els;

public:
	//default constructor
	Vector() {
		cur_size = 0;
		buf_size = 0;
		els = nullptr;
	}

	Vector(int size) {
		this->cur_size = size;
		this->buf_size = size;
		this->els = new int[size];
		for (int i = 0; i < size; i++)
			els[i] = 0;
	}
	//copy constructor
	Vector(const Vector&src) {
		this->cur_size = src.cur_size;
		this->buf_size = src.cur_size;
		this->els = new int[cur_size];

		for (int i = 0; i < cur_size; i++)
			els[i] = src.els[i];
	}

	void push_back(const int & e){ 
		
		if (cur_size >=buf_size)
		{
			int * temp;
			buf_size *= 2;
			temp = new int[buf_size];
			for (int i = 0; i < cur_size; i++)
				temp[i] = els[i];
			delete[] els;
			els = temp;
			els[cur_size++] = e; 
		}
	}

	void pop_back() {
		if (cur_size > 0)
			cur_size--;
	}

	int & at(int pos)
	{
		return els[pos];
	}

	void push_plus(const int & e, const int & a) {

		if (cur_size >= buf_size)
		{
			int * temp;
			buf_size *= 2;
			temp = new int[buf_size];
			for (int i = 0; i < cur_size; i++)
				temp[i] = els[i];
			delete[] els;
			els = temp;
			for (int i = 0; i < buf_size; i++)
			{
				if (i == a)
					els[i] = e;

			}
		}
	}

	void push_dif(const int & e,const int & a) {

		if (cur_size >=a)
		{
			for (int i = 0; i < cur_size; i++)
				if (i == a)
				{
					els[i-1] = e;
				}
		}
	}

	void print(){ 
		for (int i = 0; i < cur_size; i++)
		{
			cout <<left << setw(5) << els[i] ;
		}
	}
	//destructor
	~Vector() {
		delete[] els;
		els = nullptr;
	}

};
