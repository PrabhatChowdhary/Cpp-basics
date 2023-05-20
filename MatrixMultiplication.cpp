#include <iostream>
#include <vector>
using namespace std;
/*

	//	pseudo code logic for one element matrix multiplication
	//       ___________________________________________________________
	//      |                                                           |
	//      | matOutput[x][y] = sumof(mat1[x][all]* mat2[all][y]);	|
	//      |___________________________________________________________|
	//

*/

vector<vector<int>> matrixMult(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
	vector<vector<int>> matOutput;
	int oneElement = 0;
	int x = 0;
	int y = 0;
	cout << "element 1,2 of mat1 is " << mat1[1][1] << endl;
	for (x = 0; x < 3; x++) {
		vector<int> matOutput_row;
		for (y = 0; y < 3; y++) {
			for (int j = 0; j < 3; j++) {
				oneElement = oneElement + (mat1[x][j] * mat2[j][y]);
				cout << "input elements are - mat1 " << mat1[x][j] << " and for mat2 " << mat2[j][y] << endl;
			}
			matOutput_row.push_back(oneElement);
			
			oneElement = 0;
		}
		matOutput.push_back(matOutput_row);
		

	}

	
	return matOutput;
}

int main() {
	std::vector<std::vector<int>> OutputMatrix;

	std::vector<std::vector<int>> mat1{
		{1 , 2, 3},
		{10, 20, 30},
		{100, 200, 300}
	};

	std::vector<std::vector<int>> mat2{
		{1 , 2, 3},
		{10, 20, 30},
		{100, 200, 300}
	};

	std::cout << "dimensions of matrix 2 are " << mat2[0].size() << " x " << mat2.size() << std::endl;

	//function call for matrix multiplication
	OutputMatrix=matrixMult(mat1, mat2);
	cout << "the output of multiplied matrix is " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << OutputMatrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
