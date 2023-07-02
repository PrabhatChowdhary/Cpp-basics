#include <iostream>
using namespace std;
/*
Question 1:
Write a code that given an array A of size n, creates a new array B so that B[i]=A[0]+.....+A[i].

Question 2:
Write a code that given an array A of size n, and an integer num, finds all pairs in A whose sum is equal to num.

Question 3:
Write a code that given an array A of size n, finds the most frequent element in A.*/

int* computeB(int* A, int size) {
	int *B=new int[size]; 		//int *B= (int*) malloc(size*sizeof(int))  can also be used but it is recommended to use new.
	int sum=0;
	for (int i = 0; i < size; i++) {
		sum = sum + A[i];
		B[i] = sum;
	}
	return B;
}

void printPair(int* A, int size, int targetSum) {
	
	for (int i = 0; i < size - 1; i++) {
		for (int j = i+1; j < size ; j++) {
			if ((A[i] + A[j]) == targetSum) {
				{
					cout << "val1 is " << A[i] << " val2 is " << A[j] << endl;
					
				}
			}
		}
	}

}

void mostFrequentElement(int* A, int size) {
	int counter = 1, counterMax = 1;
	int maxFreqValue = A[0];

	for (int i = 0; i < size-1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (A[i] == A[j]) {
				counter++;
			}
		}
		
		if (counter > counterMax) {
			counterMax = counter;
			maxFreqValue = A[i];
		}
		counter = 1;
		
	}
	if (counter > counterMax) {
			counterMax = counter;
			maxFreqValue = A[size-1];
		}
	cout << "element with max frequency is " << maxFreqValue << " and its frequency is " << counterMax << endl;
}

void binarySearch(int* A,int size, int searchNumber) {
	
	int left = 0;
	int right = size - 1;
	int mid = (left + right) / 2;

	while (left < right) {
		mid = (left + right) / 2;
		if (A[mid] == searchNumber) {
			cout << "the number is present in binary normal serach " << A[mid]<<endl;
			return; 
		}
		if (searchNumber > A[mid]) {
			//search right
			left = mid + 1;


		}
		if (searchNumber < A[mid]) {
			//search left
			right = mid - 1;
		}
	}
	cout << "number is not present" << endl;
		
}

void binaryRecurssion(int* A, int left, int right, int searchNumber) {
	int mid = (left + right) / 2;
	cout << "mid " << mid << "left " << left << "right " << right << endl;;
	if (A[mid] == searchNumber) {
		cout << "the number is present in recursion search" << A[mid] << endl;
		return;
	}
	else if ( searchNumber > A[mid]) {
		cout << "search right" << endl;
		binaryRecurssion(A, mid + 1, right, searchNumber);
	}
	else if (searchNumber < A[mid]) {
		cout << "search left" << endl;
		binaryRecurssion(A, left, mid - 1, searchNumber);
	}
}

int main() {
	cout << "basic check" << endl;
	int A[] = { 1,2,3,4,5 };
	
	int* B;
	cout << "first element of A is " << A[0] << endl;
	cout << "size of array A is " <<sizeof(A)/sizeof(int) <<endl;
	B=computeB(A, sizeof(A) / sizeof(int));
	cout << "third value of B is " << B[2] << endl;
	printPair(A, sizeof(A) / sizeof(int), 19);
	mostFrequentElement(A, sizeof(A) / sizeof(int));
	binarySearch(A, sizeof(A) / sizeof(int), 7);
	binaryRecurssion(A, 0, sizeof(A) / sizeof(int)-1, 4);
	return 0;
}
