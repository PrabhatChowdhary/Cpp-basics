#include <iostream>
#include <vector>
using namespace std;
/*
void matMult(vector<int>* mat1, vector<int>* mat2) {
	cout << "test first element " << mat1[0][1] << endl;
	mat1[0][0] = 2200;
	vector<vector<int>> matOutput;
	int oneElement = 0;
	int x = 0;
	int y = 0; 

	//	pseudo code logic for one element matrix multiplication
	//       ___________________________________________________________
	//      |                                                           |
	//      | matOutput[x][y] = sumof(mat1[x][all]* mat2[all][y]);	|
	//      |___________________________________________________________|
	//

	for(x=0;x<3;x++){
		for (y = 0; y < 3; y++) {
			for (int j = 0; j < 3; j++) {
					oneElement = oneElement + mat1[x][j] * mat2[j][y];
					cout << "oneElement is " << oneElement << endl;
			}
			matOutput[x][y] = oneElement;
			oneElement = 0;
		}
	}
}
*/
int main() {

	vector<vector<int>> matOutput= {
		{0 , 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	int oneElement = 0;
	int x = 0;
	int y = 0;
	
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

	std::cout << "dimensions of matrix 2 are " << mat2[0].size()<<" x "<<mat2.size() << std::endl;
	
	//function loop starts here
	for (x = 0; x < 3; x++) {
		for (y = 0; y < 3; y++) {
			for (int j = 0; j < 3; j++) {
				oneElement = oneElement + (mat1[x][j] * mat2[j][y]);
				cout << "input elements are - mat1 " << mat1[x][j] << " and for mat2 " << mat2[j][y]<<endl;
			}
			matOutput[x][y] = oneElement;
			cout << "first one element is " << matOutput[x][y] << endl;
			oneElement = 0;
		}

	}
	cout << "the output of multiplied matrix is " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matOutput[i][j] << " ";
		}
		cout << endl;
	}
	//function loop ends here
	
	//matMult(mat1.data(), mat2.data());
	//cout << "modified data is " << mat1[0][0] << endl;
	return 0;
}
