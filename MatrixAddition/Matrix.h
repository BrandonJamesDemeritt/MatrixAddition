#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>

using namespace std;

class Matrix {

public:

	//Consturctors
	//Default
	Matrix();

	//Construcotr with values
	Matrix(const unsigned int, const unsigned int, const vector<vector<int>>&);

	//getters
	//Get number of rows
	unsigned int getRows() const;
	//Get number of columns
	unsigned int getColumns() const;

	//class functions
	//get function, to get a value from a specific place
	int get(unsigned int i, unsigned int j) const;

	//set function, to update a value at a specific place to a new value
	void set(unsigned int, unsigned int, int);

	//Operator + function declaration
	Matrix operator+ (const Matrix&) const;

	//Operator << function declaration
	friend ostream& operator<< (ostream&, const Matrix&);

private:

	//data fields
	unsigned int numOfRows;
	unsigned int numOfColumns;
	vector<vector<int>> data;
};
#endif

