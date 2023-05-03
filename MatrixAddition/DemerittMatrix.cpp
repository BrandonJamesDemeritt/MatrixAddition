#include <iostream>
#include "Matrix.h"
#include <fstream>
#include <vector>

using namespace std;

int main() {

	//variables
	unsigned int rows;
	unsigned int columns;
	vector<vector<int>> inputData;
	vector<Matrix> Matricies;

	//open input file
	ifstream fin("matrices.txt");

	//test input file and output error if not found
	if (!fin) {
		cout << "File doesn't exist" << endl;
		system("pause");
		return -1;
	}

	//create output file
	ofstream fout("result.txt");

	//read in rows and columns from file
	fin >> rows;
	fin >> columns;

	//read in the matricies
	//temp vector for data
	vector<int> v1;

	//outer loop vector
	for (int t = 0; t < 2; t++) {
		inputData.clear();
		
		//loop for inner vectors
		for (int i = 0; i < rows; i++) {

			//clear v1 data
			v1.clear();

			//get inner vector data
			for (int j = 0; j < columns; j++) {
				int temp;
				fin >> temp;
				v1.push_back(temp);
			}
			
			//add inner vector to outer vector
			inputData.push_back(v1);
		}
		//Create Matrix object with the inputData vectors
		Matricies.push_back(Matrix::Matrix(rows, columns, inputData));
	}
	
	//Output the added matricies
	fout << Matricies.at(0) + Matricies.at(1);

	//close files and exit
	fin.close();
	fout.close();
	return 0;
}