#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <conio.h>

using namespace std;

class Cell
{
private:
	int value = 0; /*
		   *  0 - nothing
		   *  1 - cross
		   *  2 - zero
		   */
public:
	Cell();
	Cell(const Cell&);
	~Cell();
	int get_value();
	void set_value(int);
	bool is_empty();
	void print() { cout << this->value << endl; }
	Cell& operator = (const Cell&);
	Cell& operator ++ ();
	Cell& operator ++ (int);
	Cell& operator -- ();
	Cell& operator -- (int);
	bool operator == (const Cell&);
	bool operator != (const Cell&);
	bool operator < (const Cell&);
	bool operator > (const Cell&);
	bool operator <= (const Cell&);
	bool operator >= (const Cell&);
	Cell operator + (const Cell&);
	Cell operator - (const Cell&);
	Cell operator * (const Cell&);
	Cell operator / (const Cell&);
	Cell& operator += (const Cell&);
	Cell& operator -= (const Cell&);
	Cell& operator *= (const Cell&);
	Cell& operator /= (const Cell&);
	friend ostream& operator << (ostream&, Cell&);
};
