#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printArr(int* arr, int n){
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void generate(int& n, int* arr, int i){
	if (i == n) {
		printArr(arr, n);
		return;
	}

	arr[i] = 0;
	generate(n, arr, i+1);
	cout << "estamos en: " << i << endl;

	arr[i] = 1;
	generate(n, arr, i+1);

}

int main(int argc, char const *argv[]) {

	int number = 0;

	int n = 2;
	int arr[n];

	generate(n, arr, 0);
	return 0;
}