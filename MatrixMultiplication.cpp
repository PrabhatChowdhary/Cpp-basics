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
int main() {

	vector<vector<int>> matOutput;
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
		vector<int> matOutput_row;
		for (y = 0; y < 3; y++) {
			for (int j = 0; j < 3; j++) {
				oneElement = oneElement + (mat1[x][j] * mat2[j][y]);
				cout << "input elements are - mat1 " << mat1[x][j] << " and for mat2 " << mat2[j][y]<<endl;
			}
			matOutput_row.push_back(oneElement) ;
			oneElement = 0;
		}
		matOutput.push_back(matOutput_row) ;

	}
	cout << "the output of multiplied matrix is " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matOutput[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
