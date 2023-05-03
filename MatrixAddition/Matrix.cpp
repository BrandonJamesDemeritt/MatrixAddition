#include "Matrix.h"
#include <iostream>

using namespace std;

//default constructor
Matrix::Matrix() : numOfRows(0), numOfColumns(0) {}

//constructor with values
Matrix::Matrix(const unsigned int rows, const unsigned int columns, const vector<vector<int>>& data) : numOfRows(rows), numOfColumns(columns), data(data) {}

//getters
//get Rows
unsigned int Matrix::getRows() const { return numOfRows; }
//Get Columns
unsigned int Matrix::getColumns() const { return numOfColumns; }

//Getting a value of a specific location
int Matrix::get(unsigned int i, unsigned int j) const { return data.at(i).at(j); }

//Setting a value of a specific location
void Matrix::set(unsigned int i, unsigned int j, int newValue) { data.at(i).at(j) = newValue; }

/* Operator + function to add two matricies together
*  @Param: Matrix class object
*  @return: Matrix, result of the two matricies added together
*/
Matrix Matrix::operator+ (const Matrix& other) const {
	Matrix result(other.getRows(), other.getColumns(), other.data);
	
	for (int i = 0; i < result.getRows(); i++) {
		for (int j = 0; j < result.getColumns(); j++) {
			result.set(i, j, get(i, j) + other.get(i, j));
		}
	}
	return result;
}

/* Operator << function to output any Matrix object.
*  @Param, ostream, Matrix class object
*  @Return, ostream
*/
ostream& operator<< (ostream& out, const Matrix& outData) {
	out << outData.getRows() << "\t" << outData.getColumns() << endl << endl;
	for (int i = 0; i < outData.getRows(); i++) {
		for (int j = 0; j < outData.getColumns(); j++) {
			out << outData.get(i, j) << "\t";
		}
		out << endl;
	}
	return out;
}


